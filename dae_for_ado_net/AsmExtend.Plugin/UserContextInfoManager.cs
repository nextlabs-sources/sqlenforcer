using System;
using System.Threading;
using System.Data.Common;
using System.Data.SqlClient;
using System.Collections.Generic;

namespace AsmExtend.Plugin
{
    sealed class UserContextInfoManager
    {
        private static readonly UserContextInfoManager instance = new UserContextInfoManager();

        // Explicit static constructor to tell C# compiler
        // not to mark type as beforefrieldinit
        static UserContextInfoManager()
        {}
        public static UserContextInfoManager Instance
        {
            get => instance;
        }

        private UserContextInfoManager()
        {
            if (DAEConfig.Instance.UsermodeMode == DAEConfig.Usermode.Database)
            {
                var syncTime = DAEConfig.Instance.UsermodeSyncTime;
                Timer timer = new Timer(new TimerCallback(RefreshContextInfo), null, syncTime, syncTime);
            }
        }

        public void AddUserContextInfo(DbConnection conn)
        {
            var userContext = GetUserContextInfo(conn);

            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                if (userContext != null)
                {
                    // To fix bug 69140 comment 5
                    // When use the SqlConnection.ChangeDatabase method, we will change the user
                    // context's property of database name.
                    // After close the connection and open a connection based on the same connection string,
                    // the database property of new connection is recovered.
                    // So we should change back the user context's property of database name too.
                    userContext.DatabaseName = conn.Database;

                    return;
                }
            }

            UserContextInfo userContextInfo = UserContextInfo.GetCurrentUserContextInfo(conn);

            DAELogger.Trace($"GetCurrentUserContextInfo: {conn.ConnectionString} {userContextInfo.UserName}");

            if (DAEConfig.Instance.UsermodeMode == DAEConfig.Usermode.Database)
            {
                var userAttributes = UserContextInfo.GetDatabaseUserAttributes(userContextInfo.UserName);
                userContextInfo.UserAttributes = userAttributes;
            }

            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                DAELogger.Trace($"userContextInfoDictionary.Add {conn.ConnectionString}");
                userContextInfoDictionary.Add(conn.ConnectionString, userContextInfo);
            }
        }

        public bool RemoveUserContextInfo(DbConnection conn)
        {
            var userContextInfo = GetUserContextInfo(conn);

            if (userContextInfo != null)
            {
                userContextInfo.Free();
            }

            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                return userContextInfoDictionary.Remove(conn.ConnectionString);
            }
        }

        public bool Contains(DbConnection conn)
        {
            using (var writeLock = new Common.ReadLockProxy(rwLock))
            {
                return userContextInfoDictionary.ContainsKey(conn.ConnectionString);
            }
        }

        public UserContextInfo GetUserContextInfo(DbConnection conn)
        {
            using (var readLock = new Common.ReadLockProxy(rwLock))
            {
                if (userContextInfoDictionary.ContainsKey(conn.ConnectionString))
                {
                    return userContextInfoDictionary[conn.ConnectionString];
                }

                return null;
            }
        }

        private void RefreshContextInfo(object info)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                foreach (var userContextInfo in userContextInfoDictionary.Values)
                {
                    var userAttributes
                        = UserContextInfo.GetDatabaseUserAttributes(userContextInfo.UserName);
                    userContextInfo.UserAttributes = userAttributes;
                }
            }
        }

        ~UserContextInfoManager()
        {
            if (rwLock != null)
            {
                rwLock.Dispose();
                rwLock = null;
            }
        }

        private ReaderWriterLockSlim rwLock = new ReaderWriterLockSlim();
        private FixedSizeDictionary<string, UserContextInfo> userContextInfoDictionary
                                                            = new FixedSizeDictionary<string, UserContextInfo>(20);
    }
}

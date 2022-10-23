using System;
using System.Threading;
using System.Data.Common;

using AsmExtend.Plugin.Common;

namespace AsmExtend.Plugin.Binding
{
    static class SqlConnectionProxy
    {
        private static volatile
            ReaderWriterLockSlim rwLockUserContextInfoManager = new ReaderWriterLockSlim();
        private static volatile
            ReaderWriterLockSlim rwLockConnectionWhiteList = new ReaderWriterLockSlim();

        public static void Open(object obSource, Action pOrgMethod)
        {
            try
            {
                if (obSource is DbConnection)
                {
                    DbConnection conn = obSource as DbConnection;

                    var inst = SqlEnforcer.Instance; // To init the DAELogger. TODO: refactor

                    DAELogger.Trace($"Open: {conn.GetHashCode()} | {conn.ConnectionString}");

                    if (!ConnectionWhitelist.Instance.Contains(conn))
                    {
                        using (var readLock = new ReadLockProxy(rwLockConnectionWhiteList))
                        {
                            if (!ConnectionWhitelist.Instance.Contains(conn))
                            {
                                using (var writeLock = new WriteLockProxy(rwLockUserContextInfoManager))
                                {
                                    UserContextInfoManager.Instance.AddUserContextInfo(conn);
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                if (EmdbException.IsNeedToBeThrownOutException(ex))
                {
                    throw;
                }
                else
                {
                    string errMsg = CommonHelper.GetFormatedExceptionMessage(ex);
                    DAELogger.Error(errMsg);
                }
            }
        }

        public static void Close(object obSource, Action pOrgMethod)
        {
            return;
        }

        public static void ChangeDatabase(object obSource, Action<string> pOrgMethod, string strValue)
        {
            try
            {
                if (obSource is DbConnection)
                {
                    DbConnection conn = obSource as DbConnection;

                    DAELogger.Trace($"ChangeDatabase: {conn.GetHashCode()} | {conn.ConnectionString}");

                    using (var writeLock = new WriteLockProxy(rwLockUserContextInfoManager))
                    {
                        var userContextInfo = UserContextInfoManager.Instance.GetUserContextInfo(conn);
                        
                        if (userContextInfo != null && userContextInfo.DatabaseName != strValue)
                        {
                            userContextInfo.DatabaseName = strValue;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                if (EmdbException.IsNeedToBeThrownOutException(ex))
                {
                    throw;
                }
                else
                {
                    string errMsg = CommonHelper.GetFormatedExceptionMessage(ex);
                    DAELogger.Error(errMsg);
                }
            }
        }
    }
}

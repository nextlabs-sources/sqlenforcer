using System;
using System.Threading;
using System.Collections.Generic;

using System.Data.Common;

namespace AsmExtend.Plugin
{
    class ConnectionWhitelist
    {
        private static readonly ConnectionWhitelist instance = new ConnectionWhitelist();

        // Explicit static constructor to tell C# compiler
        // not to mark type as beforefrieldinit
        static ConnectionWhitelist()
        { }

        public static ConnectionWhitelist Instance => instance;

        private ConnectionWhitelist()
        {}

        public bool Add(DbConnection conn)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                bool ret = whitelist.Add(conn);
                DAELogger.Trace($"ConnectionWhitelist {(ret ? "add" : "cannot add")} {conn.ConnectionString}");
                return ret;
            }
        }

        public bool Remove(DbConnection conn)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                bool ret = whitelist.Remove(conn);
                DAELogger.Trace($"ConnectionWhitelist {(ret ? "remove" : "cannot remove")} {conn.ConnectionString}");
                return whitelist.Remove(conn);
            }
        }

        public bool Contains(DbConnection conn)
        {
            using (var readLock = new Common.ReadLockProxy(rwLock))
            {
                bool ret = whitelist.Contains(conn);
                DAELogger.Trace($"ConnectionWhitelist {(ret ? "contains" : "does not contain")} {conn.ConnectionString}");
                return whitelist.Contains(conn);
            }
        }

        ~ConnectionWhitelist()
        {
            if (rwLock != null)
            {
                rwLock.Dispose();
                rwLock = null;
            }
        }

        private ReaderWriterLockSlim rwLock = new ReaderWriterLockSlim();
        private HashSet<DbConnection> whitelist = new HashSet<DbConnection>();
    }
}

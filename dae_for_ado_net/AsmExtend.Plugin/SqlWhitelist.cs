using System.Threading;
using System.Collections.Generic;

namespace AsmExtend.Plugin
{
    class SqlWhitelist
    {
        private static readonly SqlWhitelist instance = new SqlWhitelist();

        // Explicit static constructor to tell C# compiler
        // not to mark type as beforefrieldinit
        static SqlWhitelist()
        { }

        public static SqlWhitelist Instance => instance;

        private SqlWhitelist()
        {
            whitelist = new HashSet<string>() {
                Constants.QueryInfoSql
            };
        }

        public bool Add(string sql)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                bool ret = whitelist.Add(sql);
                DAELogger.Trace($"SqlWhitelist {(ret ? "add" : " can not add")} SQL: {sql}");
                return ret;
            }
        }

        public bool Remove(string sql)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                bool ret = whitelist.Remove(sql);
                DAELogger.Trace($"SqlWhitelist {(ret ? "remove" : "cannot remove")} SQL: {sql}");
                return ret;
            }
        }

        public bool Contains(string sql)
        {
            using (var readLock = new Common.ReadLockProxy(rwLock))
            {
                bool ret = whitelist.Contains(sql);
                DAELogger.Trace($"SqlWhitelist {(ret ? "contains" : "does not contain")} SQL: {sql}");
                return ret;
            }
        }

        ~SqlWhitelist()
        {
            if (rwLock != null)
            {
                rwLock.Dispose();
                rwLock = null;
            }
        }

        private ReaderWriterLockSlim rwLock = new ReaderWriterLockSlim();
        private HashSet<string> whitelist;
    }
}

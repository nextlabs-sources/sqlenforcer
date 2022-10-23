using System;
using System.Data;
using System.Reflection;
using System.Data.Common;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading;

namespace AsmExtend.Plugin
{
    sealed class UserContextInfo
    {
        // To fix bug 68978, it must using a delegate that is stored as a mebmer variable
        // and will be alive as long as the object.
        // For more detail:
        // https://stackoverflow.com/questions/6193711/call-has-been-made-on-garbage-collected-delegate-in-c
        // https://docs.microsoft.com/en-us/dotnet/framework/debug-trace-profile/callbackoncollecteddelegate-mda
        private EmdbSdkWrapper.QueryMetadataFunc cb;

        public UserContextInfo(
            SqlEnforcer sqlEnforcer,
            DbConnection dbConnection,
            string userName,
            string dbServerName,
            string databaseName,
            string schemaName
            )
        {
            this.sqlEnforcer = sqlEnforcer;
            this.dbConnection = dbConnection;
            this.userName = userName;
            this.dbServerName = dbServerName;
            this.databaseName = databaseName;
            this.schemaName = schemaName;
            
            EmdbSdkWrapper.EMDBReturn RT = EmdbSdkWrapper.EMDBNewUserCtx(dbServerName, databaseName, schemaName, "SQL Server", ref ctxHandle);
            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBNewUserCtx Failed!");
            }

            cb = GetColumnMetadata;

            RT = EmdbSdkWrapper.EMDBQueryMetadata_cb_c(ctxHandle, cb);
            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBQueryMetadata_cb_c Failed!");
            }
        }

        private bool GetColumnMetadata(string tableSource, ref IntPtr columnMetadataArray, ref int size)
        {
            List<TableColumnMetadata> metadataList = QueryTableColumnMetadata(dbConnection, tableSource);

            size = metadataList.Count;

            if (size > 0)
            {
                // Manually allocate memory by the COM task memory alloctor, and it should be cleared manually after use.
                IntPtr buff = Marshal.AllocCoTaskMem(Marshal.SizeOf(metadataList[0]) * size);
                IntPtr curr = buff;

                for (int i = 0; i < size; i++)
                {
                    Marshal.StructureToPtr(metadataList[i], curr, false);

                    curr = (IntPtr)((long)curr + Marshal.SizeOf(metadataList[i]));
                }

                columnMetadataArray = buff;
            }
                
            return true;
        }

        private void UpdateUserAttrs()
        {
            foreach (var attr in userAttributes)
            {
                AddUserAttribute(this, attr.Key, attr.Value);
            }
        }

        public void Free()
        {
            if (ctxHandle != IntPtr.Zero)
            {
                ClearUserAttribute(this);
                FreeUserContextInfo(this);
            }
        }

        public static Dictionary<string, string> GetDatabaseUserAttributes(string userName)
        {
            Dictionary<string, string> userAttrs = new Dictionary<string, string>();

            try
            {
                string connString = DAEConfig.Instance.UsermodeAdonetSqlclientConnString;

                using (SqlConnection conn = new SqlConnection(connString))
                {
                    UserInfoTable userInfoTable = UserInfoTable.ParseUserInfo(DAEConfig.Instance.UsermodeUserInfo);

                    // TODO: Remove to reduce coupling
                    string commandString = string.Format(Constants.QueryUserAttributesSqlFormat, userInfoTable.TableName, userInfoTable.ColumnName, userName);

                    if (!SqlWhitelist.Instance.Contains(commandString))
                    {
                        SqlWhitelist.Instance.Add(commandString);
                    }

                    if (!ConnectionWhitelist.Instance.Contains(conn))
                    {
                        ConnectionWhitelist.Instance.Add(conn);
                    }

                    using (SqlCommand command = new SqlCommand(commandString, conn))
                    {
                        conn.Open();

                        using (SqlDataReader reader = command.ExecuteReader())
                        {
                            int fieldCount = reader.FieldCount;

                            if (reader.Read())  // Only read the first row.
                            {
                                for (int i = 0; i < fieldCount; ++i)
                                {
                                    var name = reader.GetName(i);
                                    var value = reader.GetValue(i).ToString();

                                    userAttrs.Add(name, value);
                                }
                            }
                        }
                    }

                    if (SqlWhitelist.Instance.Contains(commandString))
                    {
                        SqlWhitelist.Instance.Remove(commandString);
                    }

                    if (ConnectionWhitelist.Instance.Contains(conn))
                    {
                        ConnectionWhitelist.Instance.Remove(conn);
                    }
                }
            }
            catch (Exception ex)
            {
                string errMsg = string.Format(
                    "Failed to get database user attributes for {0}:\n\t{1}",
                    userName,
                    Common.CommonHelper.GetFormatedExceptionMessage(ex)
                );

                DAELogger.Error(errMsg);
            }

            return userAttrs;
        }

        // https://stackoverflow.com/a/12284267
        private static SqlTransaction GetTransaction(IDbConnection conn)
        {
            PropertyInfo ConnectionInfo = conn.GetType().GetProperty("InnerConnection", BindingFlags.NonPublic | BindingFlags.Instance);
            var internalConn = ConnectionInfo.GetValue(conn, null);
            var currentTransactionProperty = internalConn.GetType().GetProperty("CurrentTransaction", BindingFlags.NonPublic | BindingFlags.Instance);
            var currentTransaction = currentTransactionProperty.GetValue(internalConn, null);

            if (currentTransaction == null)
            {
                return null;
            }

            var realTransactionProperty = currentTransaction.GetType().GetProperty("Parent", BindingFlags.NonPublic | BindingFlags.Instance);
            var realTransaction = realTransactionProperty.GetValue(currentTransaction, null);
            return (SqlTransaction)realTransaction;
        }

        private static List<TableColumnMetadata> QueryTableColumnMetadata(DbConnection dbConnection, string tableSource)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                DAELogger.Trace($"QueryTableColumnMetadata: {dbConnection.GetHashCode()} | {dbConnection.ConnectionString}");
                List<TableColumnMetadata> ret = new List<TableColumnMetadata>();

                string[] arr = tableSource.Split('.'); // The pattern of "tableSource" is "schema.table".

                string queryTableColumnMetadataSql = string.Format(Constants.QueryTableColumnMetadataSqlFormat, arr[0], arr[1], arr[2]);

                if (!SqlWhitelist.Instance.Contains(queryTableColumnMetadataSql))
                {
                    SqlWhitelist.Instance.Add(queryTableColumnMetadataSql);
                }

                ConnectionState initialState = dbConnection.State;

                if (initialState != ConnectionState.Open)
                {
                    dbConnection.Open();
                }

                using (DbCommand command = dbConnection.CreateCommand())
                {
                    command.CommandText = queryTableColumnMetadataSql;
                    command.Transaction = GetTransaction(dbConnection);

                    using (DbDataReader reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            string columnName = reader.GetValue(0).ToString();
                            string dataType = reader.GetValue(1).ToString();
                            TableColumnMetadata metadata = new TableColumnMetadata(columnName, dataType);

                            ret.Add(metadata);
                        }
                    }
                }

                if (initialState != ConnectionState.Open && dbConnection.State == ConnectionState.Open)
                {
                    dbConnection.Close();
                }

                if (SqlWhitelist.Instance.Contains(queryTableColumnMetadataSql))
                {
                    SqlWhitelist.Instance.Remove(queryTableColumnMetadataSql);
                }

                return ret;
            }
        }

        private static void AddUserAttribute(UserContextInfo userContextInfo, string key, string value)
        {
            EmdbSdkWrapper.EMDBReturn RT = EmdbSdkWrapper.EMDBSetUserCtxProperty(userContextInfo.ctxHandle, key, value);
            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBSetUserCtxProperty Failed!");
            }
        }

        private static void ClearUserAttribute(UserContextInfo userContextInfo)
        {
            if (userContextInfo.ctxHandle != IntPtr.Zero)
            {
                EmdbSdkWrapper.EMDBReturn RT = EmdbSdkWrapper.EMDBClearUserCtxProperty(userContextInfo.ctxHandle);
                if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
                {
                    throw new EmdbException("EMDBClearUserCtxProperty Failed!");
                }
            }
        }

        private static void FreeUserContextInfo(UserContextInfo userContextInfo)
        {
            if (userContextInfo.ctxHandle != IntPtr.Zero)
            {
                EmdbSdkWrapper.EMDBReturn RT = EmdbSdkWrapper.EMDBFreeUserCtx(userContextInfo.ctxHandle);
                if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS == RT)
                {
                    userContextInfo.ctxHandle = IntPtr.Zero;
                }
                else
                {
                    throw new EmdbException("EMDBFreeUserCtx Failed!");
                }
            }
        }

        // dbTransaction is used to fix exception about
        // "ExecuteReader requires the command to have a transaction
        // when the connection assigned to the command is in a pending local transaction."
        public static UserContextInfo GetCurrentUserContextInfo(DbConnection dbConnection, DbTransaction dbTransaction = null)
        {
            ConnectionState initialState = dbConnection.State;

            if (initialState != ConnectionState.Open)
            {
                dbConnection.Open();
            }

            string userName = "";
            string serverName = "";
            string databaseName = "";
            string schemaName = "";

            using (DbCommand command = dbConnection.CreateCommand())
            {
                command.CommandText = Constants.QueryInfoSql;
                command.Transaction = dbTransaction;
                
                using (DbDataReader reader = command.ExecuteReader())
                {
                    int fieldCount = reader.FieldCount;

                    while (reader.Read())
                    {
                        userName = reader.GetValue(0).ToString();
                        serverName = reader.GetValue(1).ToString();
                        databaseName = reader.GetValue(2).ToString();
                        schemaName = reader.GetValue(3).ToString();
                    }
                }
            }

            if (initialState != ConnectionState.Open && dbConnection.State == ConnectionState.Open)
            {
                dbConnection.Close();
            }

            // Use the cloned connection to query metadata
            // which is not disposed with dbConnection
            var clonedConnection = (dbConnection as ICloneable).Clone() as DbConnection;

            return SqlEnforcer.Instance.CreateNewUserContextInfo(clonedConnection, userName, serverName, databaseName, schemaName);
        }

        public DbConnection DbConnection
        {
            get
            {
                return dbConnection;
            }
            
            set
            {
                dbConnection = value;
            }
        }

        public IntPtr Handle => ctxHandle;
        public string UserName => userName;
        public string DbServerName
        {
            get
            {
                return dbServerName;
            }

            set
            {
                AddUserAttribute(this, "server", value);
                dbServerName = value;
            }
        }
        
        public string DatabaseName
        {
            get
            {
                return databaseName;
            }

            set
            {
                AddUserAttribute(this, "database", value);
                databaseName = value;
            }
        }

        public string SchemaName
        {
            get
            {
                return schemaName;
            }

            set
            {
                AddUserAttribute(this, "schema", value);
                schemaName = value;
            }
        }

        public Dictionary<string, string> UserAttributes
        {
            get => userAttributes;
            set
            {
                userAttributes = value;
                UpdateUserAttrs();
            }
        }

        ~UserContextInfo()
        {
            if (ctxHandle != IntPtr.Zero)
            {
                Free();
            }
        }

        private static volatile ReaderWriterLockSlim rwLock = new ReaderWriterLockSlim();

        private SqlEnforcer sqlEnforcer;    // To make sure EMDB inited before creat new user context.
        private DbConnection dbConnection;  // Used to query metadata

        private IntPtr ctxHandle;
        private string userName;
        private string dbServerName;
        private string databaseName;
        private string schemaName;
        private Dictionary<string, string> userAttributes;
    }
}

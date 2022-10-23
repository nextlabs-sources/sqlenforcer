using System;
using System.Data.Common;
using System.Runtime.InteropServices;

namespace AsmExtend.Plugin
{
    class SqlEnforcer
    {
        private static readonly SqlEnforcer instance = new SqlEnforcer();

        public static SqlEnforcer Instance => instance;

        private SqlEnforcer()
        {
            EmdbSdkWrapper.EMDBReturn RT = EmdbSdkWrapper.EMDBInit("adonet");

            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBInit Failed!");
            }
        }

        public UserContextInfo CreateNewUserContextInfo(DbConnection dbConnection,
                                                        string userName,
                                                        string dbServerName,
                                                        string databaseName,
                                                        string schemaName)
        {
            return new UserContextInfo(this, dbConnection, userName, dbServerName, databaseName, schemaName);
        }

        public EvalResult EvalSql(UserContextInfo userContextInfo, string sql)
        {
            EvalResult evalResult = new EvalResult();

            var RT = EmdbSdkWrapper.EMDBEvalSql(sql, userContextInfo.Handle, evalResult.Handle);
            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBEvalSql Failed!");
            }

            EmdbSdkWrapper.EMDBResultCode code = default(EmdbSdkWrapper.EMDBResultCode);
            RT = EmdbSdkWrapper.EMDBResultGetCode(evalResult.Handle, ref code);
            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBResultGetCode Failed!");
            }

            IntPtr outDetail;
            RT = EmdbSdkWrapper.EMDBResultGetDetail(evalResult.Handle, out outDetail);
            string detail = Marshal.PtrToStringAnsi(outDetail);
            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBResultGetDetail Failed!");
            }

            evalResult.Code = code;
            evalResult.Detail = detail;

            return evalResult;
        }
    }
}

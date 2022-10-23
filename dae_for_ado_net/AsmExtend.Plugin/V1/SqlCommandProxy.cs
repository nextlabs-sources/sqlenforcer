using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Diagnostics;

using AsmExtend.Plugin.Common;

namespace AsmExtend.Plugin.Binding
{
    static class SqlCommandProxy
    {
        private static readonly HashSet<string> ShouldBeEnforcedMethodNames = new HashSet<string>() // TODO: Change into bottom readonly
        {
            "BeginExecuteNonQuery",
            "BeginExecuteReader",
            "BeginExecuteXmlReader",
            "ExecuteNonQuery",
            "ExecuteNonQueryAsync",
            "ExecuteReader",
            "ExecuteReaderAsync",
            "ExecuteScalar",
            "ExecuteScalarAsync",
            "ExecuteXmlReader",
            "ExecuteXmlReaderAsync"
        };

        public static string GetCommandText(object obSource, Func<string> pOrgMethod)
        {
            string commandText = pOrgMethod.Invoke();
            try
            {
                if (obSource is DbCommand && !SqlWhitelist.Instance.Contains(commandText))
                {
                    DbCommand command = obSource as DbCommand;
                    DbConnection connection = command.Connection;
                
                    if (connection == null || !UserContextInfoManager.Instance.Contains(connection))
                    {
                        return commandText;
                    }

                    if (ShouldBeEnforced())
                    {
                        Logger.WriteLine(string.Format("---ori:{0}", commandText));

                        UserContextInfo userContextInfo = UserContextInfoManager.Instance.GetUserContextInfo(connection);

                        using (EvalResult result = SqlEnforcer.Instance.EvalSql(userContextInfo, commandText))
                        {
                            if (result.Code == EmdbSdkWrapper.EMDBResultCode.EMDB_USE_NEW_TEXT)
                            {
                                Logger.WriteLine(string.Format("---new:{0}", result.Detail));
                                return result.Detail;
                            }
                            else
                            {
                                throw EmdbException.WrapperIntoThrowOutException(new EmdbException("Denied by policy"));
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

            return commandText;
        }

        private static bool ShouldBeEnforced()
        {
            bool res = false;
            StackTrace stackTrace = new StackTrace();

            int index = 0;

            while (index < stackTrace.FrameCount)
            {
                StackFrame stackFrame = stackTrace.GetFrame(index);
                string frameMethodName = stackFrame.GetMethod().Name;

                if (frameMethodName.Equals("ValidateCommand"))
                {
                    break;
                }

                if (ShouldBeEnforcedMethodNames.Contains(frameMethodName))
                {
                    res = true;
                    break;
                }

                ++index;
            }

            // To fix http://bugs.cn.nextlabs.com/show_bug.cgi?id=68986
            // Look back two frames to check whether the method that should be enforced is called by DbCommandBuildere.GetSchemaTable.
            // If true, it should not be enforced.
            // TODO: When user create a custom method "GetSchemaTable" and run "ExecuteReader" in it, it may cause data leak.
            int specialFrameIndex = index + 2;

            if (res && (specialFrameIndex < stackTrace.FrameCount))
            {
                StackFrame stackFrame = stackTrace.GetFrame(specialFrameIndex);
                string frameMethodName = stackFrame.GetMethod().Name;

                if (frameMethodName.Equals("GetSchemaTable"))
                {
                    res = false;
                }
            }

            return res;
        }
    }
}

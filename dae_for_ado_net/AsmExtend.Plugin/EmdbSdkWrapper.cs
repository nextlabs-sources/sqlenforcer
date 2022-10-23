using System;
using System.Text;
using System.Runtime.InteropServices;

using Microsoft.Win32;

namespace AsmExtend.Plugin
{
    enum EMDBLogLevel { TRACE, DEBUG, INFO, WARNING, ERROR, FATAL };

    class EmdbSdkWrapper
    {
        static EmdbSdkWrapper()
        {
            var path = GetDllDirectory();
            SetDllDirectory(path);
        }

        public delegate bool QueryMetadataFunc(string tableName, ref IntPtr metadataArray, ref int size);

        internal enum EMDBReturn { EMDB_SUCCESS, EMDB_ERROR, EMDB_INVALID_HANDLE };
        internal enum EMDBResultCode { EMDB_BLOCK_THIS_TEXT, EMDB_USE_NEW_TEXT, EMDB_DENY_EXECUTE };

        private static string GetDllDirectory()
        {
            string path = "C:\\Program Files\\NextLabs\\DAEforWin";    // Default path

            using (var baseKey = RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64))
            {
                if (baseKey != null)
                {
                    using (var key = baseKey.OpenSubKey("SOFTWARE\\Nextlabs\\DAEforWin"))
                    {
                        if (key != null)
                        {
                            object o = key.GetValue("install_path");

                            if (o != null)
                            {
                                path = o as string;
                            }
                        }
                    }
                }
            }

            path += (Environment.Is64BitProcess ? @"\Common\bin64" : @"\Common\bin32");

            return path;
        }

        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        static extern bool SetDllDirectory(string lpPathName);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBInit(string module_name);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBNewUserCtx(string server_name, string database_name, string schema_name, string dbtype, ref IntPtr output_user_ctx);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBFreeUserCtx(IntPtr user_ctx);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBSetUserCtxProperty(IntPtr user_ctx, string key, string value);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBClearUserCtxProperty(IntPtr user_ctx);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBEvalSql(string sql, IntPtr user_ctx, IntPtr result);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBNewResult(ref IntPtr output_result);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBFreeResult(IntPtr result);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBResultGetCode(IntPtr result, ref EMDBResultCode output_code);

        // Use out string output_detail will cause some errors
        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBResultGetDetail(IntPtr result, out IntPtr output_detail);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern EMDBReturn EMDBQueryMetadata_cb_c(IntPtr user_ctx, QueryMetadataFunc cb);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool DAEDecryptString(string src, StringBuilder target, out uint len);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetCfgUsermodeMode();

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern uint GetCfgUsermodeSyncTime();

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void GetCfgUsermodeAdonetSqlclientConnString(StringBuilder buff, int buff_size);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void GetCfgUsermodeUserInfo(StringBuilder buff, int buff_size);

        [DllImport("sqlenforcer.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SQLEnforcerWriteLogWithTagA(EMDBLogLevel level, string tag, string msg);
    }
}

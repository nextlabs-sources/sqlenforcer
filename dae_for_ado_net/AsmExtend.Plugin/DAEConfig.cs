using System;
using System.Text;

namespace AsmExtend.Plugin
{
    class DAEConfig
    {
        public enum Usermode
        {
            Application = 0,
            Database,
            ActiveDirectory
        };

        private static readonly DAEConfig instance = new DAEConfig();

        // Explicit static constructor to tell C# compiler
        // not to mark type as beforefrieldinit
        static DAEConfig()
        { }

        public static DAEConfig Instance
        {
            get => instance;
        }

        private static string GetConfigFilePath()
        {
            return "C:\\ProgramData\\Nextlabs\\DAEforWin\\Config\\config.ini";
        }

        private DAEConfig()
        {
            string configPath = GetConfigFilePath();
            IniFile iniFile = new IniFile(configPath);

            usermodeMode = (Usermode)EmdbSdkWrapper.GetCfgUsermodeMode();
            usermodeSyncTime = EmdbSdkWrapper.GetCfgUsermodeSyncTime() * 1000; // Change from seconds into milliseconds

            int buffSize = 1024;
            StringBuilder buff = new StringBuilder(buffSize);

            EmdbSdkWrapper.GetCfgUsermodeAdonetSqlclientConnString(buff, buffSize);
            usermodeAdonetSqlclientConnString = buff.ToString();

            buff.Clear();

            EmdbSdkWrapper.GetCfgUsermodeUserInfo(buff, buffSize);
            usermodeUserInfo = buff.ToString();
        }

        public Usermode UsermodeMode => usermodeMode;
        public long UsermodeSyncTime => usermodeSyncTime;
        public string UsermodeAdonetSqlclientConnString => usermodeAdonetSqlclientConnString;
        public string UsermodeUserInfo => usermodeUserInfo;

        private Usermode usermodeMode = Usermode.Database;
        private long usermodeSyncTime = 86400000;
        private string usermodeAdonetSqlclientConnString = "";
        private string usermodeUserInfo = "";
    }

    class UserInfoTable
    {
        public static UserInfoTable ParseUserInfo(string userInfo)
        {
            int index = userInfo.LastIndexOf(Seperator);

            if (index < 0)
            {
                string errMsg = string.Format("Wrong user_info format. Its value is {1}. You should config it as \"schema.table.column\" format.", userInfo);

                throw new ArgumentException(errMsg);
            }

            string tablename = userInfo.Substring(0, index);
            string columnname = userInfo.Substring(index + 1);

            UserInfoTable userInfoTable = new UserInfoTable(tablename, columnname);

            return userInfoTable;
        }

        private UserInfoTable(string tableName, string columnName)
        {
            this.tableName = tableName;
            this.columnName = columnName;
        }

        private static char Seperator = '.';

        public string TableName => tableName;
        public string ColumnName => columnName;

        private string tableName;
        private string columnName;
    }
}

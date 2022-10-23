namespace AsmExtend.Plugin
{
    class Constants
    {
        public const string QueryInfoSql = "SELECT ORIGINAL_LOGIN(), @@servername, DB_NAME(), SCHEMA_NAME();";
        public const string QueryTableColumnMetadataSqlFormat =
            "SELECT COLUMN_NAME, DATA_TYPE FROM {0}.INFORMATION_SCHEMA.COLUMNS" +
            " WHERE TABLE_SCHEMA = '{1}' AND TABLE_NAME = '{2}'";
        public const string QueryUserAttributesSqlFormat = "SELECT * FROM {0} WHERE {1} = '{2}' ORDER BY {1}";
    }
}

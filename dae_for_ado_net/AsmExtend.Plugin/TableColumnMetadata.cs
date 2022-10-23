using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace AsmExtend.Plugin
{
    public enum EMDataType
    {
        EMDATA_STRING,
        EMDATA_NUMBER,
        EMDATA_DATE,
        EMDATA_TIME,
        EMDATA_TIMESTAMP,
        EMDATA_STRING2,
        EMDATA_TIMESTAMP_TZ_ORA,
        EMDATA_YMINTERVAL,
        EMDATA_DSINTERVAL,
        EMDATA_NONSUPPORT
    };

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    sealed class TableColumnMetadata
    {
        public TableColumnMetadata(string columnName, EMDataType dataType)
        {
            this.columnName = columnName;
            this.dataType = dataType;
        }

        public TableColumnMetadata(string columnName, string dataType)
        {
            this.columnName = columnName;
            this.dataType = ParseIntoDataType(dataType);
        }

        private static EMDataType ParseIntoDataType(string value)
        {
            EMDataType type;

            if (EMDataTypeMap.TryGetValue(value, out type))
            {
                return type;
            }
            else
            {
                return EMDataType.EMDATA_NONSUPPORT;
            }
        }

        private static Dictionary<string, EMDataType> EMDataTypeMap = new Dictionary<string, EMDataType>
        {
            // base
            {"STRING", EMDataType.EMDATA_STRING},
            {"NSTRING", EMDataType.EMDATA_STRING2},
            {"TIME", EMDataType.EMDATA_TIME},
            {"DATE", EMDataType.EMDATA_DATE},
            {"NUMBER", EMDataType.EMDATA_NUMBER},
            // sqlserver
            {"bigint", EMDataType.EMDATA_NUMBER},
            {"numeric", EMDataType.EMDATA_NUMBER},
            {"bit", EMDataType.EMDATA_NUMBER},
            {"smallint", EMDataType.EMDATA_NUMBER},
            {"decimal", EMDataType.EMDATA_NUMBER},
            {"smallmoney", EMDataType.EMDATA_NUMBER},
            {"int", EMDataType.EMDATA_NUMBER},
            {"tinyint", EMDataType.EMDATA_NUMBER},
            {"money", EMDataType.EMDATA_NUMBER},

            {"float", EMDataType.EMDATA_NUMBER},
            {"real", EMDataType.EMDATA_NUMBER},

            {"datetimeoffset", EMDataType.EMDATA_TIMESTAMP},
            {"datetime2", EMDataType.EMDATA_TIMESTAMP},
            {"smalldatetime", EMDataType.EMDATA_TIMESTAMP},
            {"datetime", EMDataType.EMDATA_TIMESTAMP},
            {"char", EMDataType.EMDATA_STRING},
            {"varchar", EMDataType.EMDATA_STRING},
            {"text", EMDataType.EMDATA_STRING},
            {"nchar", EMDataType.EMDATA_STRING},
            {"nvarchar", EMDataType.EMDATA_STRING},
            {"ntext", EMDataType.EMDATA_STRING},
            {"image", EMDataType.EMDATA_STRING}
        };

        public string ColumnName => columnName;
        public EMDataType DataType => dataType;

        private string columnName;
        private EMDataType dataType;
    }
}

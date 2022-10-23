
#include "ODBCQueryMetadata.h"
#include "ODBCMgrApi.h"
#include <sqlext.h>
#include "fun.h"
#include "EMMaskDef.h"
#include "SqlException.h"
#include "commfun.h"
#include "DAELogger.h"

bool ODBCQueryMetadata::QueryMetadataFunc(const std::string & table, MetadataVec & vecmeta){
    if(!_conn){
        return false;
    }

    std::vector<std::string> vec;
    CommonFun::SplitString(table,".",vec);
    if(vec.size() != 3){
        return false;
    }

    std::string querysql;
    switch (_dbtype)
    {
        case EMDB_DB_SQLSERVER:{
            querysql = "SELECT COLUMN_NAME, DATA_TYPE FROM " + vec[0] +
                        ".INFORMATION_SCHEMA.COLUMNS WHERE "
                        "TABLE_SCHEMA = '"+vec[1]+"' "
                        "AND TABLE_NAME  = '"+vec[2]+"'";
        } break;
        case EMDB_DB_HANA:{
            querysql = "SELECT column_name AS COLUMN_NAME\n"
                        "\t,DATA_TYPE_NAME AS TYPE_NAME\n"
                        "\tFROM SYS.TABLE_COLUMNS \n"
                        "\tWHERE \tschema_name = '"+vec[1]+"' AND \ttable_name = '"+vec[2]+"'  \n"
                        "\tORDER BY position";
        } break;
        case EMDB_DB_ORACLE:{
            querysql = "SELECT COLUMN_NAME, DATA_TYPE FROM ALL_TAB_COLUMNS WHERE OWNER = '" + vec[1] + "' AND TABLE_NAME = '" + vec[2] + "' ORDER BY COLUMN_ID;";
        } break;
        case EMDB_DB_MYSQL: {
            querysql = "SELECT COLUMN_NAME, COLUMN_TYPE FROM INFORMATION_SCHEMA.COLUMNS "
                       "WHERE LOWER(TABLE_SCHEMA) = LOWER('" + vec[1] + "') "
                       "AND LOWER(TABLE_NAME) = LOWER('" + vec[2] + "')";
        } break;
        case EMDB_DB_POSTGRESQL: {
            querysql = "SELECT COLUMN_NAME, UDT_NAME FROM INFORMATION_SCHEMA.COLUMNS "
                       "WHERE LOWER(TABLE_CATALOG) = LOWER('" + vec[0] + "') "
                       "AND LOWER(TABLE_SCHEMA)=LOWER('" + vec[1] + "') "
                       "AND LOWER(TABLE_NAME) = LOWER('" + vec[2] + "')";
        } break;
        default:{
            DAELogger::Warning("'Select*' only supports three databases(oralce/sqlserver/hana) at the moment");
        } break;
    }
    //allow stmt
    ODBCMgrApi &oriODBCAPI = ODBCMgrApi::Instance();
    SQLHANDLE hdbc = (SQLHANDLE)_conn;
    SQLHANDLE hstmt = nullptr;
    RETCODE rc = oriODBCAPI.SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    if(rc != SQL_SUCCESS){
        DAELogger::Warning("alloc handle failed in QueryMetadata.");
        //
    }
    //execute
    rc = oriODBCAPI.SQLExecDirect(hstmt, (SQLCHAR *)querysql.c_str(), SQL_NTS);
    //get result
    do {
        SQLSMALLINT snum = 0;
        oriODBCAPI.SQLNumResultCols(hstmt, &snum);
        if (snum == 0)
            break;
        ODBC_COL_BINDING         *pFirstBinding=NULL, *pThisBinding=NULL;
	    SQLSMALLINT     cDisplaySize;
	    RETCODE         RetCode = SQL_SUCCESS;
	    int             iCount = 0;
	    // Allocate memory for each column
	    AllocateBindings(hstmt, snum, &pFirstBinding, &cDisplaySize);

        bool fNoData = false;

        do {
            rc = oriODBCAPI.SQLFetch(hstmt);


            if (rc == SQL_NO_DATA_FOUND)
            {
                fNoData = true;
            }
            else
            {
                Metadata meta;
                pThisBinding = pFirstBinding;
                if (pThisBinding && pThisBinding->szBuffer)
                {
                    pThisBinding->szBuffer[pThisBinding->indPtr] = 0;
                    meta._col = pThisBinding->szBuffer;
                }


                if (pThisBinding) {
                    pThisBinding = pThisBinding->sNext;
                    if (pThisBinding && pThisBinding->szBuffer)
                    {
                        pThisBinding->szBuffer[pThisBinding->indPtr] = 0;
                        meta._type = MaskItem::GetDataType(_dbtype, pThisBinding->szBuffer) ;
                    }
                }
                vecmeta.push_back(meta);

            }
        } while (!fNoData);

        while (pFirstBinding)
        {
            pThisBinding = pFirstBinding->sNext;
            free(pFirstBinding->szBuffer);
            free(pFirstBinding);
            pFirstBinding = pThisBinding;
        }

    } while (oriODBCAPI.SQLMoreResults(hstmt) == SQL_SUCCESS);


    return true;
}




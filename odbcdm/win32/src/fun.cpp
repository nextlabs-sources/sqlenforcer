
#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#else
#include <string.h>
#endif
#include <sql.h>
#include <sqlext.h>
#include <map>
#include <string>
#include <algorithm>
#include <atomic>
#include "fun.h"
#include "EnforcerDataMgr.h"
#include "enforcerwrapper.h"
#include "ODBCMgrApi.h"
#include "SqlException.h"
#include "commfun.h"
#include "ODBCQueryMetadata.h"
#include "DAELogger.h"

#define SQL_QUERY_DBINFO_SQLSERVER "SELECT SUSER_SNAME(),SCHEMA_NAME(),@@servername;"
#define SQL_QUERY_DBINFO_MYSQL "select MID(USER(),1,LENGTH(USER())-INSTR(REVERSE(USER()),'@')),database(), @@hostname;"
#define SQL_QUERY_DBINFO_ORACLE  "SELECT (SELECT USERNAME FROM USER_USERS), (select SYS_CONTEXT('USERENV','CURRENT_SCHEMA') from dual) ,(select INSTANCE_NAME from v$instance), (select HOST_NAME from v$instance) from DUAL"
#define SQL_QUERY_DBINFO_HANA "SELECT CURRENT_USER,CURRENT_SCHEMA AS SCHEMA_NAME,(SELECT DATABASE_NAME FROM SYS.M_DATABASES) AS DB_NAME, 'TODU' AS SERVER_NAME FROM DUMMY"
#define SQL_QUERY_DBINFO_BIGQUERY "SELECT SESSION_USER() as user;"
//#define SQL_QUERY_DBINFO_DB2 "select current server from sysibm.sysdummy1"
#define SQL_QUERY_DBINFO_DB2 "select RTRIM(current user) as a,RTRIM(current schema) as b, RTRIM(current server) as c from sysibm.sysdummy1"
#define SQL_QUERY_DBINFO_POSTGRESQL "select current_user, current_schema, current_database() , 'PostgreSQL'";

#include <atomic>
std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;

#include "EMDBConfig.h"
std::atomic_int64_t inti_ret = 0;

// Workaround to fix bug 66860
SqlException storedExc;

//note: we can't call this function in DllMain. because this function will create thread.
//create thread in DllMain will cause deadlock.
bool InitalizeEnforcer(SqlException* pExc)
{
    bool bInit = lock_stream.test_and_set();

    if (!bInit)
    {
        bool bRet = true;
        try
        {
            //load config file
            const std::string strCfgFile = CommonFun::GetConfigFilePath();
            EMDBConfig::GetInstance().Load(strCfgFile);

            //load enforcer
            bRet = Enforcer::Instance()->LoadEnforcer();
            if (bRet) {
                bRet = Enforcer::Instance()->SQLEnforcerInit("odbc", strCfgFile.c_str(), pExc);
            } else {
                pExc->SetInfo(ERR_LIBRARY, detail_err_lib_sqlenfoercer);
            }

            if(bRet){
                inti_ret = 1;
            } else {
                inti_ret = 0;
                storedExc = *pExc;
            }
        }
        catch (const std::exception& e)
        {
            pExc->SetInfo(ERR_CONFIG, e.what());
        }
    }
    else
    {
        *pExc = storedExc;
    }

    return inti_ret==1;
}

bool InitEnforceContext(SQLHDBC hdbc, SqlException * pExc)
{
    ODBCMgrApi &LowODBCAPI = ODBCMgrApi::Instance();
    SQLSMALLINT outlen;
    //get server
    SQLCHAR charServer[1000];
    RETCODE rc = LowODBCAPI.SQLGetInfo(hdbc, SQL_SERVER_NAME, charServer, sizeof(charServer), &outlen);
    if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
    {
        const std::string strLog = "Can't get the server name";
        pExc->SetInfo(ERR_INITCONTEXT, detail_err_context_init1);
        DAELogger::Error(strLog);
        return false;
    }
    else
    {
        charServer[outlen] = 0;
    }

    //get DriverInfo
    char charDriver[1000];
    rc = LowODBCAPI.SQLGetInfo(hdbc, SQL_DBMS_NAME, charDriver, sizeof(charDriver), &outlen);
    if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
    {
        const std::string strLog = "Can't get the driver Type";
        pExc->SetInfo(ERR_INITCONTEXT, detail_err_context_init2);
        DAELogger::Error(strLog);
        return false;
    }
    else
    {
        charDriver[outlen] = 0;
    }

    //get DatabaseInfo
    char charDbName[1000];
    rc = LowODBCAPI.SQLGetInfo(hdbc, SQL_DATABASE_NAME, charDbName, sizeof(charDbName), &outlen);
    if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
    {
        const std::string strLog = "Can't get the database name";
        pExc->SetInfo(ERR_INITCONTEXT, detail_err_context_init3);
        DAELogger::Error(strLog);
        return false;
    }
    else
    {
        charDbName[outlen] = 0;
    }

    std::string strDriver = charDriver;
    //get database type by Driver name
    EMDB_DB_TYPE dbType = get_dbtype_by_drivername(strDriver);
    if (dbType != EMDB_DB_SQLSERVER &&
        dbType != EMDB_DB_ORACLE &&
        dbType != EMDB_DB_HANA &&
        dbType != EMDB_DB_MYSQL &&
        dbType != EMDB_DB_POSTGRESQL)
    {
        //const std::string strLog = "Can't determines the DB Type";
        pExc->SetInfo(ERR_DBTYPE, detail_err_context_init4);
        //DAELogger::Warning(strLog.c_str());
        return false;
    }

    std::string strServer((const char *)charServer);
    std::string strDatabase((const char*)charDbName);
    //query current user and database, schema,
    std::string strUser, strSchema;
    bool retSession = QueryODBCSessionInfo(hdbc, dbType, strUser, strSchema, strServer,strDatabase, pExc);
    if(!retSession){
        return false;
    }


    //create enforcer context and set context info

    USER_CONTEXT enforcerContext = Enforcer::Instance()->SQLEnforcerNewContext(strUser.c_str(), "", pExc);
    Enforcer::Instance()->SetUserContextInfo(enforcerContext, CONTEXT_INFO_SERVER, strServer.c_str());
    Enforcer::Instance()->SetUserContextInfo(enforcerContext, CONTEXT_INFO_DATABASE, strDatabase.c_str());
    Enforcer::Instance()->SetUserContextInfo(enforcerContext, CONTEXT_INFO_SCHEMA, strSchema.c_str());
    Enforcer::Instance()->SetUserContextInfo(enforcerContext, CONTEXT_INFO_DB_TYPE, strDriver.c_str());

    ODBCQueryMetadata * pmeta_opr = new ODBCQueryMetadata((void*)hdbc, dbType );
    QueryMetadataFunc func  = std::bind(&ODBCQueryMetadata::QueryMetadataFunc,pmeta_opr,std::placeholders::_1,std::placeholders::_2);
    Enforcer::Instance()->SQLEnforcerQueryMetadata_cb(enforcerContext, func);

    //set enforcer context info
    ODBC_LOCK();
    EnforcerDataMgr::Instance().bind_enforcer_context(hdbc, enforcerContext, pmeta_opr);
    ODBC_UNLOCK();
    return true;
}


bool parseConnectingStr(const char *src, std::map<std::string, std::string> &data)
{
    size_t i = 0;
    std::string key = "";
    std::string value = "";
    int tks = 0;
    size_t srcLength = strlen(src);
    while (i < srcLength)
    {
        if (src[i] == ';' || 0 == i)
        {
            // eat a key
            if (src[i] == ';')
            {
                ++i;
                if (i >= srcLength)
                    break;
            }
            while (i < srcLength && (src[i] == ' '||src[i] == '\n'||src[i] == '\r'||src[i] == '\t'))
            {
                ++i;
            }
            if (i >= srcLength)
                break;
            int pos1 = i;
            while (i < srcLength && (src[i] != '='))
                ++i;
            key = std::string(src + pos1, src + i);
            std::transform(key.begin(), key.end(), key.begin(), ::tolower);
            tks++;
        }
        else if (src[i] == '=')
        {
            // eat a value
            ++i;
            if (i >= srcLength)
                break;
            int pos1 = i;
            while (i < srcLength && src[i] != ';')
                ++i;
            value = std::string(src + pos1, src + i);
            if (tks != 1)
                return false;
            else
            {
                tks = 0;
                data[key] = value;
            }
        }
    }
    return 0 == tks;
}

bool QueryODBCSessionInfo(HDBC hdbc, EMDB_DB_TYPE dbType, std::string &strUser, std::string &strSchema, std::string& strServer, std::string& strDbName, SqlException * pExc)
{
    SQLRETURN rc = SQL_SUCCESS;
    //prepare sql
    std::string strSQL;
    if (dbType == EMDB_DB_SQLSERVER) {
        strSQL = SQL_QUERY_DBINFO_SQLSERVER;
    }
    else if(dbType == EMDB_DB_MYSQL) {

        strSQL = SQL_QUERY_DBINFO_MYSQL;
    }
    else if (dbType == EMDB_DB_ORACLE)
    {
        strSQL = SQL_QUERY_DBINFO_ORACLE;
    }
    else if (dbType == EMDB_DB_HANA)
    {
        strSQL = SQL_QUERY_DBINFO_HANA;
    }
    else if (dbType == EMDB_DB_BIGQUERY)
    {
        strSQL = SQL_QUERY_DBINFO_BIGQUERY;
    }
    else if(EMDB_DB_DB2 == dbType){
        strSQL = SQL_QUERY_DBINFO_DB2;
    }
    else if(EMDB_DB_POSTGRESQL == dbType){
        strSQL = SQL_QUERY_DBINFO_POSTGRESQL;
    }
    
    std::string value1,value2,value3,value4;
    //Execute sql
    SQLHSTMT hStmt = NULL;
    while (true) {
        if (!strSQL.empty()) {
            ODBCMgrApi &LowODBCAPI = ODBCMgrApi::Instance();

            rc = LowODBCAPI.SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hStmt);
            if (rc == SQL_ERROR) {
                //pExc->SetInfo(ERR_INITCONTEXT, detail_err_context_init5);
                DAELogger::Warning("query resource attribute failed, QueryODBCSessionInfo allocate SQLHSTMT failed");
                break;
            }

            rc = LowODBCAPI.SQLExecDirect(hStmt, (SQLCHAR *)strSQL.c_str(), SQL_NTS);
            if (rc == SQL_ERROR) {
                //pExc->SetInfo(ERR_INITCONTEXT, detail_err_context_init6);
                DAELogger::Warning("query resource attribute failed, QueryODBCSessionInfo SQLExecDirect  failed");
                break;
            }

            SQLSMALLINT sNumResults = 0;
            LowODBCAPI.SQLNumResultCols(hStmt, &sNumResults);

            ODBC_COL_BINDING *pFirstBinding = NULL, *pThisBinding = NULL;
            SQLSMALLINT cDisplaySize;
            AllocateBindings(hStmt, sNumResults, &pFirstBinding, &cDisplaySize);

            RETCODE RetCode = LowODBCAPI.SQLFetch(hStmt);
            if (RetCode != SQL_NO_DATA_FOUND) {
                
                pThisBinding = pFirstBinding;
                if (pThisBinding && pThisBinding->szBuffer)
                {
                    pThisBinding->szBuffer[pThisBinding->indPtr] = 0;
                    value1 = pThisBinding->szBuffer;
                }

                
                if (pThisBinding) {
                    pThisBinding = pThisBinding->sNext;
                    if (pThisBinding && pThisBinding->szBuffer)
                    {
                        pThisBinding->szBuffer[pThisBinding->indPtr] = 0;
                        value2 = pThisBinding->szBuffer;
                    }
                }
                

                //
                if(pThisBinding) {
                    pThisBinding = pThisBinding->sNext;
                    if(pThisBinding && pThisBinding->szBuffer){
                        pThisBinding->szBuffer[pThisBinding->indPtr] = 0;
                        value3 = pThisBinding->szBuffer;
                    }
                }

                 if(pThisBinding) {
                    pThisBinding = pThisBinding->sNext;
                    if(pThisBinding && pThisBinding->szBuffer){
                        pThisBinding->szBuffer[pThisBinding->indPtr] = 0;
                        value4 = pThisBinding->szBuffer;
                    }
                }
                
            }

           //clean
            while (pFirstBinding) {
                pThisBinding = pFirstBinding->sNext;
                free(pFirstBinding->szBuffer);
                free(pFirstBinding);
                pFirstBinding = pThisBinding;
            }
        }
        break;
    }

    //free
    if (hStmt != NULL) {
        ODBCMgrApi::Instance().SQLFreeStmt(hStmt, SQL_DROP);
        hStmt = NULL;
    }

    switch(dbType) { 
        case EMDB_DB_SQLSERVER: {
            strUser = value1;
            strSchema = value2;
            strServer = value3;
        }break;
        case EMDB_DB_MYSQL : {
            strUser = value1;
            strSchema = value2;
            strServer = value3;
        } break;
        case EMDB_DB_ORACLE : {
            strUser = value1;
            strSchema = value2;
            strDbName = value3;
            strServer = value4;    
        } break;
        case EMDB_DB_HANA : {
            strUser = value1;
            strSchema = value2;
            strDbName = value3;
            size_t ifind = strServer.find(':');
            if(ifind != std::string::npos){
                strServer = strServer.substr(0,ifind);
            }
            
            //strServer = value4;
        } break;
        case EMDB_DB_BIGQUERY : {
            strUser = value1;
        } break;
        case EMDB_DB_DB2:{
            strUser = value1;
            strSchema = value2;
            strDbName = value3;
            strServer = "DB2";
        } break;
        case EMDB_DB_POSTGRESQL: {
            strUser = value1;
            strSchema = value2;
            strDbName = value3;
            strServer = "PostgrSQL";
        } break;
        case EMDB_DB_REDSHIFT:
            break;
        case EMDB_DB_UNKNOW:
            break;
    }

    
    return (rc==SQL_ERROR)?false:true;
}

void AllocateBindings(HSTMT hStmt,
                      SQLSMALLINT cCols,
                      ODBC_COL_BINDING **ppBinding,
                      SQLSMALLINT *pDisplay)
{
    SQLSMALLINT iCol;
    ODBC_COL_BINDING *pThisBinding, *pLastBinding = NULL;
    
   // SQLSMALLINT cchColumnNameLength;

    ODBCMgrApi &LowODBCAPI = ODBCMgrApi::Instance();

    for (iCol = 1; iCol <= cCols; iCol++)
    {
        SQLLEN cchDisplay=0;
        SQLLEN ssType=0;
        pThisBinding = (ODBC_COL_BINDING *)(malloc(sizeof(ODBC_COL_BINDING)));
        pThisBinding->indPtr = 0;
        if (!(pThisBinding))
        {
            fwprintf(stderr, L"Out of memory!\n");
            return;
        }

        if (iCol == 1)
        {
            *ppBinding = pThisBinding;
        }
        else
        {
            pLastBinding->sNext = pThisBinding;
        }
        pLastBinding = pThisBinding;

        // Figure out the display length of the column (we will
        // bind to char since we are only displaying data, in general
        // you should bind to the appropriate C type if you are going
        // to manipulate data since it is much faster...)

        LowODBCAPI.SQLColAttribute(hStmt,
                                   iCol,
                                   SQL_DESC_DISPLAY_SIZE,
                                   NULL,
                                   0,
                                   NULL,
                                   &cchDisplay);

        // Figure out if this is a character or numeric column; this is
        // used to determine if we want to display the data left- or right-
        // aligned.

        // SQL_DESC_CONCISE_TYPE maps to the 1.x SQL_COLUMN_TYPE.
        // This is what you must use if you want to work
        // against a 2.x driver.
        LowODBCAPI.SQLColAttribute(hStmt,
                                   iCol,
                                   SQL_DESC_CONCISE_TYPE,
                                   NULL,
                                   0,
                                   NULL,
                                   &ssType);

        pThisBinding->fChar = (ssType == SQL_CHAR ||
                               ssType == SQL_VARCHAR ||
                               ssType == SQL_LONGVARCHAR);

        pThisBinding->sNext = NULL;

        // Allocate a buffer big enough to hold the text representation
        // of the data.  Add one character for the null terminator
        pThisBinding->szBuffer = (char *)malloc(cchDisplay + 1);

        if (!(pThisBinding->szBuffer))
        {
            fwprintf(stderr, L"Out of memory!\n");
            return;
        }

        // Map this buffer to the driver's buffer.   At Fetch time,
        // the driver will fill in this data.  Note that the size is
        // count of bytes (for Unicode).  All ODBC functions that take
        // SQLPOINTER use count of bytes; all functions that take only
        // strings use count of characters.
        LowODBCAPI.SQLBindCol(hStmt,
                              iCol,
                              SQL_C_CHAR,
                              (SQLPOINTER)pThisBinding->szBuffer,
                              (cchDisplay + 1) * sizeof(char),
                              &pThisBinding->indPtr);

        pThisBinding->cDisplaySize = cchDisplay;
    }

    return;
}
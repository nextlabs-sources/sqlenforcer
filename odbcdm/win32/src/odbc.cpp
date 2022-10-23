//#include "odbc.h"
#include "ODBCMgrApi.h"
#include "enforcerwrapper.h"
#include <stdio.h>
#include <string>
#include "fun.h"
#include "commfun.h"
#include "EnforcerDataMgr.h"
#include "iodbc_macros.h"
#include <wchar.h>
#include "SqlException.h"
#include "DAELogger.h"

bool InitalizeEnforcer(SqlException* exc);

#ifdef SQL_WCHART_CONVERT
typedef  std::wstring   emw_string;
#else
typedef  std::u16string emw_string;
#endif

const emw_string char_convert(SQLWCHAR * szstr, SQLINTEGER length){
#ifdef SQL_WCHART_CONVERT
    if(SQL_NTS == length){
        return  emw_string((wchar_t *)szstr) ;
    } else {
        return  emw_string((wchar_t *)szstr, length) ;
    }
#else
    if(SQL_NTS == length){
        return  emw_string((char16_t *)szstr) ;
    } else {
        return  emw_string((char16_t *)szstr, length) ;
    }
#endif
}

#ifndef WIN32
#undef SQL_API
#define SQL_API __attribute__((visibility("default")))
#endif

#if defined __cplusplus && !(defined WIN32)
extern "C" {                         /* Assume C declarations for C++ */
#endif

SQLRETURN  SQL_API   SQLDriverConnect(SQLHDBC hdbc, SQLHWND hwnd, SQLCHAR *szConnStrIn, SQLSMALLINT cbConnStrIn, SQLCHAR *szConnStrOut, SQLSMALLINT cbConnStrOutMax,
                                      SQLSMALLINT *pcbConnStrOut, SQLUSMALLINT fDriverCompletion)
{
    SqlException exc;
    ENTER_HDBC(hdbc, 0);
    
    DAELogger::Trace("Enter SQLDriverConnect");
    ret_code = ODBCMgrApi::Instance().SQLDriverConnect(hdbc, hwnd, szConnStrIn, cbConnStrIn, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        /* todo if EnforcerContext Init failed, what should we do ? */
        DAELogger::Trace("Enter SQLDriverConnect success");
        InitEnforceContext(hdbc, &exc);

        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, hdbc, &exc);
            ret_code = SQL_ERROR;
        }

    }
    LEAVE_HDBC(hdbc, 0);
}

SQLRETURN SQL_API SQLDriverConnectA(SQLHDBC hdbc, SQLHWND hwnd, SQLCHAR *szConnStrIn, SQLSMALLINT cbConnStrIn, SQLCHAR *szConnStrOut, SQLSMALLINT cbConnStrOutMax,
                                    SQLSMALLINT *pcbConnStrOut, SQLUSMALLINT fDriverCompletion)
{
    SqlException exc;
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLDriverConnectA");
    ret_code = ODBCMgrApi::Instance().SQLDriverConnectA(hdbc, hwnd, szConnStrIn, cbConnStrIn, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        /* todo if EnforcerContext Init failed, what should we do ? */
        InitEnforceContext(hdbc, &exc);

        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, hdbc, &exc);
            ret_code = SQL_ERROR;
        }
    }
    LEAVE_HDBC(hdbc, 0);
}

SQLRETURN SQL_API SQLDriverConnectW(HDBC hdbc, HWND hWnd, WCHAR *szConnStrIn, SWORD cbConnStrIn, WCHAR *szConnStrOut, SWORD cbConnStrOut, SWORD *pcbConnStrOut, UWORD uwMode)
{
    SqlException exc;
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLDriverConnectW");
    ret_code = ODBCMgrApi::Instance().SQLDriverConnectW(hdbc, hWnd, szConnStrIn, cbConnStrIn,
                                                        szConnStrOut, cbConnStrOut, pcbConnStrOut, uwMode);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        /* todo if EnforcerContext Init failed, what should we do ? */
        InitEnforceContext(hdbc, &exc);

        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, hdbc, &exc);
            ret_code = SQL_ERROR;
        }
    }
    LEAVE_HDBC(hdbc, 0);
}


RETCODE SQL_API SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE HandleParent, SQLHANDLE *NewHandlePointer)
{
    RETCODE ret;
    SqlException exc;
    if (SQL_HANDLE_ENV == HandleType) {
        // ODBC_LOCK();
        if (!InitalizeEnforcer(&exc))
        {
            EnforcerDataMgr::Instance().alloc_env_handle(*NewHandlePointer);
            EnforcerDataMgr::Instance().push_error(HandleType, (SQLHANDLE) *NewHandlePointer, &exc);
            ret = SQL_ERROR;
            return ret;
        }
        // ODBC_UNLOCK();
    }

    DAELogger::Trace("Enter SQLAllocHandle");
    ret = ODBCMgrApi::Instance().SQLAllocHandle(HandleType, HandleParent, NewHandlePointer);

    if(!SQL_SUCCEEDED(ret)){
        return ret;
    }
    switch (HandleType) {
        case SQL_HANDLE_ENV: {
            ODBC_LOCK();
            EnforcerDataMgr::Instance().alloc_env_handle(*NewHandlePointer);

            if(exc.IsBreak()){
                EnforcerDataMgr::Instance().push_error(HandleType, (SQLHANDLE) *NewHandlePointer, &exc);
                ret = SQL_ERROR;
            }
            ODBC_UNLOCK();
        }
            break;
        case SQL_HANDLE_DBC: {
            ODBC_LOCK();
            EnforcerDataMgr::Instance().alloc_connect_handle(HandleParent, *NewHandlePointer);
            ODBC_UNLOCK();
        }
            break;
        case SQL_HANDLE_STMT: {
            ODBC_LOCK();
            EnforcerDataMgr::Instance().bind_stmt_handle(HandleParent,*NewHandlePointer);
            ODBC_UNLOCK();
        }
            break;
        default:{
            /* do nothing */
        }
    }

    return ret;
}


SQLRETURN SQL_API SQLConnect(
        SQLHDBC ConnectionHandle,
        SQLCHAR *ServerName,
        SQLSMALLINT NameLength1,
        SQLCHAR *UserName,
        SQLSMALLINT NameLength2,
        SQLCHAR *Authentication,
        SQLSMALLINT NameLength3)
{
    SqlException exc;
    ENTER_HDBC(ConnectionHandle, 0);
    DAELogger::Trace("Enter SQLConnect");
    ret_code = ODBCMgrApi::Instance().SQLConnect(ConnectionHandle, ServerName, NameLength1, UserName, NameLength2, Authentication, NameLength3);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        /* todo if EnforcerContext Init failed, what should we do ? */
        InitEnforceContext(ConnectionHandle, &exc);
        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, (SQLHANDLE)ConnectionHandle, &exc);
            ret_code = SQL_ERROR;
        }
    }
    LEAVE_HDBC(ConnectionHandle, 0);
}
SQLRETURN SQL_API SQLConnectA(
        SQLHDBC hdbc,
        SQLCHAR *szDSN,
        SQLSMALLINT cbDSN,
        SQLCHAR *szUID,
        SQLSMALLINT cbUID,
        SQLCHAR *szAuthStr,
        SQLSMALLINT cbAuthStr)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLConnectA");
    ret_code = ODBCMgrApi::Instance().SQLConnectA(hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        SqlException exc;
        InitEnforceContext(hdbc, &exc);
        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, (SQLHANDLE)hdbc, &exc);
            ret_code = SQL_ERROR;
        }

    }
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API SQLConnectW(
        SQLHDBC ConnectionHandle,
        SQLWCHAR *ServerName,
        SQLSMALLINT NameLength1,
        SQLWCHAR *UserName,
        SQLSMALLINT NameLength2,
        SQLWCHAR *Authentication,
        SQLSMALLINT NameLength3)
{
    ENTER_HDBC(ConnectionHandle, 0);
    DAELogger::Trace("Enter SQLConnectW");
    ret_code = ODBCMgrApi::Instance().SQLConnectW(ConnectionHandle, ServerName, NameLength1, UserName, NameLength2, Authentication, NameLength3);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        SqlException exc;
        InitEnforceContext(ConnectionHandle, &exc);
        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, (SQLHANDLE)ConnectionHandle, &exc);
            ret_code = SQL_ERROR;
        }

    }
    LEAVE_HDBC(ConnectionHandle, 0);
}

static SQLRETURN _SQLFreeHandle_ENV(SQLSMALLINT HandleType, SQLHANDLE Handle)
{
    SQLRETURN ret_code = SQL_SUCCESS;
    ODBC_LOCK();
    ret_code = ODBCMgrApi::Instance().SQLFreeHandle(HandleType, Handle);
    if (SQL_SUCCEEDED(ret_code))
        EnforcerDataMgr::Instance().freehandle(HandleType, Handle);
    ODBC_UNLOCK();
    return ret_code;
}

static SQLRETURN _SQLFreeHandle_DBC(SQLSMALLINT HandleType,	SQLHANDLE Handle)/*use to ENTER_HDBC when have "goto" statement*/
{
    SQLRETURN ret_code = SQL_SUCCESS;
    ODBC_LOCK();
    ret_code = ODBCMgrApi::Instance().SQLFreeHandle(HandleType, Handle);
    if (SQL_SUCCEEDED(ret_code))
        EnforcerDataMgr::Instance().freehandle(HandleType, Handle);
    ODBC_UNLOCK();
    return ret_code;
}

static SQLRETURN _SQLFreeHandle_STMT(SQLSMALLINT HandleType, SQLHANDLE Handle) {
    SQLRETURN ret_code = SQL_SUCCESS;
    ODBC_LOCK();
    ret_code = ODBCMgrApi::Instance().SQLFreeHandle(HandleType, Handle);
    if (SQL_SUCCEEDED(ret_code))
        EnforcerDataMgr::Instance().freehandle(HandleType, Handle);
    ODBC_UNLOCK();
    return ret_code;
}

SQLRETURN SQL_API SQLFreeHandle(
        SQLSMALLINT handleType,
        SQLHANDLE handle)
{
    DAELogger::Trace("Enter SQLFreeHandle");
    switch (handleType) {
        case SQL_HANDLE_ENV:
            return _SQLFreeHandle_ENV(handleType, handle);
        case SQL_HANDLE_DBC:
            return _SQLFreeHandle_DBC(handleType, handle);
        case SQL_HANDLE_STMT:
            return _SQLFreeHandle_STMT(handleType, handle);
        default:
            return ODBCMgrApi::Instance().SQLFreeHandle(handleType, handle);
    }
}

SQLRETURN SQL_API SQLSetEnvAttr(SQLHENV EnvironmentHandle,
                                SQLINTEGER Attribute,  SQLPOINTER Value,
                                SQLINTEGER StringLength)
{
    DAELogger::Trace("Enter SQLSetEnvAttr");
    return ODBCMgrApi::Instance().SQLSetEnvAttr(EnvironmentHandle, Attribute, Value, StringLength);
}

#if 1
SQLRETURN SQL_API SQLExecDirect(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
{
    USER_CONTEXT enforcerContext;
    std::string strNewSql ;//= (char *)StatementText;
    if(StatementText)
        strNewSql = (char *)StatementText;
    //bool is_blocked = false;
    SqlException exc;
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLExecDirect");
    if (EnforcerDataMgr::Instance().get_enforcer_context_by_stmt_handle(StatementHandle, enforcerContext))
    {
        strNewSql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, (char *)StatementText, &exc);
    }
    if (!exc.IsBreak())
        ret_code = ODBCMgrApi::Instance().SQLExecDirect(StatementHandle, (SQLCHAR *)strNewSql.c_str(), (SQLINTEGER)strNewSql.length());
    else{
        EnforcerDataMgr::Instance().push_error(SQL_HANDLE_STMT, StatementHandle, &exc);
        ret_code = SQL_ERROR;
    }

    LEAVE_STMT(StatementHandle);
}
SQLRETURN SQL_API SQLExecDirectA(SQLHSTMT hstmt, SQLCHAR *szSqlStr, SQLINTEGER cbSqlStr)
{
    USER_CONTEXT enforcerContext;
    std::string strNewSql ;
    if(szSqlStr)
        strNewSql = (char *)szSqlStr;
    //bool is_blocked = false;
    SqlException exc;
    ENTER_STMT(hstmt);
    DAELogger::Error("Enter SQLExecDirectA");
    if (EnforcerDataMgr::Instance().get_enforcer_context_by_stmt_handle(hstmt, enforcerContext))
    {
        strNewSql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, (char *)szSqlStr, &exc);

    }
    if (!exc.IsBreak())
        ret_code = ODBCMgrApi::Instance().SQLExecDirectA(hstmt, (SQLCHAR *)strNewSql.c_str(), (SQLINTEGER)strNewSql.length());
    else{
        EnforcerDataMgr::Instance().push_error(SQL_HANDLE_STMT, hstmt, &exc);
        ret_code = SQL_ERROR;
    }
    LEAVE_STMT(hstmt);
}
#endif

SQLRETURN SQL_API SQLExecDirectW(
        SQLHSTMT hstmt,
        SQLWCHAR *szSqlStr,
        SQLINTEGER TextLength)
{
    USER_CONTEXT enforcerContext;
    SqlException exc;
    std::string sql;
    if(szSqlStr){
        emw_string str_w = char_convert(szSqlStr, TextLength);
        CommonFun::ToUTF8(str_w,sql);
       // printf("wchar_t to sql:%s\n",sql.c_str());
    }

    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLExecDirectW");
    if (EnforcerDataMgr::Instance().get_enforcer_context_by_stmt_handle(hstmt, enforcerContext))
    {
        sql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, sql.c_str(), &exc);
    }
    if (!exc.IsBreak()) {
        emw_string strw;
        CommonFun::FromUTF8(sql,strw);
        if(TextLength != SQL_NTS) TextLength = (SQLINTEGER)strw.length();
        ret_code = ODBCMgrApi::Instance().SQLExecDirectW(hstmt, (SQLWCHAR *)strw.c_str(), TextLength);
    }
    else{
        EnforcerDataMgr::Instance().push_error(SQL_HANDLE_STMT, hstmt, &exc);
        ret_code = SQL_ERROR;
    }
    LEAVE_STMT(hstmt);

}

SQLRETURN SQL_API SQLDisconnect(SQLHDBC ConnectionHandle)
{
    ENTER_HDBC(ConnectionHandle, 1);
    DAELogger::Trace("Enter SQLDisconnect");
    EnforcerDataMgr::Instance().disconnect(ConnectionHandle);
    ret_code = ODBCMgrApi::Instance().SQLDisconnect(ConnectionHandle);
    LEAVE_HDBC(ConnectionHandle, 1);
}

SQLRETURN SQL_API SQLNumResultCols(SQLHSTMT StatementHandle,
                                   SQLSMALLINT *ColumnCount)
{
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLNumResultCols");
    ret_code = ODBCMgrApi::Instance().SQLNumResultCols(StatementHandle, ColumnCount);
    LEAVE_STMT(StatementHandle);
}

SQLRETURN SQL_API SQLCloseCursor(SQLHSTMT StatementHandle)
{
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLCloseCursor");
    ret_code = ODBCMgrApi::Instance().SQLCloseCursor(StatementHandle);
    LEAVE_STMT(StatementHandle);
}

SQLRETURN SQL_API SQLFreeStmt(SQLHSTMT StatementHandle,
                              SQLUSMALLINT Option)
{
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLFreeStmt");
    ret_code = ODBCMgrApi::Instance().SQLFreeStmt(StatementHandle, Option);
    if(SQL_SUCCEEDED(ret_code) && SQL_DROP == Option){
        EnforcerDataMgr::Instance().freehandle(SQL_HANDLE_STMT, StatementHandle);
    }
    LEAVE_STMT(StatementHandle);
}

SQLRETURN SQL_API SQLBindCol(SQLHSTMT StatementHandle,
                             SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
                             SQLPOINTER TargetValue,
                             SQLLEN BufferLength,  SQLLEN *StrLen_or_Ind)
{
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLBindCol");
    ret_code = ODBCMgrApi::Instance().SQLBindCol(StatementHandle, ColumnNumber, TargetType, TargetValue, BufferLength, StrLen_or_Ind);
    LEAVE_STMT(StatementHandle);
}

SQLRETURN SQL_API SQLFetch(SQLHSTMT StatementHandle)
{
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLFetch");
    ret_code = ODBCMgrApi::Instance().SQLFetch(StatementHandle);
    LEAVE_STMT(StatementHandle);
}

SQLRETURN SQL_API SQLGetData(
        SQLHSTMT StatementHandle,
        SQLUSMALLINT Col_or_Param_Num,
        SQLSMALLINT TargetType,
        SQLPOINTER TargetValuePtr,
        SQLLEN BufferLength,
        SQLLEN *StrLen_or_IndPtr)
{
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLGetData");
    ret_code = ODBCMgrApi::Instance().SQLGetData(StatementHandle, Col_or_Param_Num, TargetType, TargetValuePtr,
                                                 BufferLength, StrLen_or_IndPtr);
    LEAVE_STMT(StatementHandle);
}

SQLRETURN SQL_API
SQLGetDiagRec (
        SQLSMALLINT fHandleType,
        SQLHANDLE handle,
        SQLSMALLINT iRecord,
        SQLCHAR *szSqlState,
        SQLINTEGER *pfNativeError,
        SQLCHAR *szErrorMsg,
        SQLSMALLINT cchErrorMsgMax,
        SQLSMALLINT *pcchErrorMsg)
{
    ODBC_LOCK();
    DAELogger::Trace("Enter SQLGetDiagRec");
    SQLSMALLINT c_;
    pcchErrorMsg = pcchErrorMsg ? pcchErrorMsg : &c_;
    SQLRETURN ret_code = SQL_SUCCESS;
    bool flag = false;
    int out_err_code;
    std::string out_detail;
    if( fHandleType == SQL_HANDLE_DBC||
        fHandleType == SQL_HANDLE_ENV||
        fHandleType == SQL_HANDLE_STMT  )
    {
        flag = EnforcerDataMgr::Instance().get_error(fHandleType, handle, iRecord, out_err_code, out_detail);
        if (flag) {
            /* szSqlState's space is guaranteed by users, >= 6  */
            int result = 0;
            CommonFun::CopyIntToA(out_err_code, (char*)szSqlState, 6, result);
            /* pfNativeError not support */

            if (szErrorMsg == nullptr)
            {
                *pcchErrorMsg = out_detail.length();
            }
            else
            {
                CommonFun::CopyStringToA(out_detail, (char*)szErrorMsg, cchErrorMsgMax, result);
                *pcchErrorMsg = result;
            }

            *pfNativeError = 0;
        }
    }

    if (!flag) //	this means do not have mxl statement err
    {
        if (ODBCMgrApi::Instance().m_bInit)
        {
            ret_code = ODBCMgrApi::Instance().SQLGetDiagRec(fHandleType, handle, iRecord, szSqlState, pfNativeError,
                szErrorMsg, cchErrorMsgMax, pcchErrorMsg);
        }
        else
        {
            ret_code = SQL_NO_DATA;
        }
    }
    ODBC_UNLOCK();
    return ret_code;
}

SQLRETURN SQL_API
SQLGetDiagRecA (
        SQLSMALLINT fHandleType,
        SQLHANDLE handle,
        SQLSMALLINT iRecord,
        SQLCHAR *szSqlState,
        SQLINTEGER *pfNativeError,
        SQLCHAR *szErrorMsg,
        SQLSMALLINT cchErrorMsgMax,
        SQLSMALLINT *pcchErrorMsg)
{
    ODBC_LOCK();
    if(DAELogger::WriteLog){
        DAELogger::Trace("Enter SQLGetDiagRecA");
    }

    SQLSMALLINT c_;
    pcchErrorMsg = pcchErrorMsg ? pcchErrorMsg : &c_;
    SQLRETURN ret_code = SQL_SUCCESS;
    bool flag = false;
    int out_err_code;
    std::string out_detail;
    if( fHandleType == SQL_HANDLE_DBC||
        fHandleType == SQL_HANDLE_ENV||
        fHandleType == SQL_HANDLE_STMT)
    {
        flag = EnforcerDataMgr::Instance().get_error(fHandleType, handle, iRecord, out_err_code, out_detail);
        if (flag) {
            /* szSqlState's space is guaranteed by users, >= 6  */
            int result = 0;
            CommonFun::CopyIntToA(out_err_code, (char*)szSqlState, 6, result);
            /* pfNativeError not support */
            CommonFun::CopyStringToA(out_detail, (char*)szErrorMsg, cchErrorMsgMax, result);
            *pcchErrorMsg = result;
            *pfNativeError = 0;
        }
    }
    if (!flag) //	this means do not have mxl statement err
        ret_code = ODBCMgrApi::Instance().SQLGetDiagRecA(fHandleType, handle, iRecord, szSqlState, pfNativeError,
                                                         szErrorMsg, cchErrorMsgMax, pcchErrorMsg);
    ODBC_UNLOCK();
    return ret_code;
}


SQLRETURN SQL_API SQLGetDiagRecW(
        SQLSMALLINT fHandleType,
        SQLHANDLE handle,
        SQLSMALLINT iRecord,
        SQLWCHAR *szSqlState,
        SQLINTEGER *pfNativeError,
        SQLWCHAR *szErrorMsg,
        SQLSMALLINT cchErrorMsgMax,
        SQLSMALLINT *pcchErrorMsg)
{
    ODBC_LOCK();
    if(DAELogger::WriteLog){
        DAELogger::Trace("Enter SQLGetDiageRecW");
    }
    SQLSMALLINT c_;
    pcchErrorMsg = pcchErrorMsg ? pcchErrorMsg : &c_;
    SQLRETURN ret_code = SQL_SUCCESS;
    bool flag = false;
    int out_err_code;
    std::string out_detail;
    if( fHandleType == SQL_HANDLE_DBC||
        fHandleType == SQL_HANDLE_ENV||
        fHandleType == SQL_HANDLE_STMT)
    {
        flag = EnforcerDataMgr::Instance().get_error(fHandleType, handle, iRecord, out_err_code, out_detail);
        if (flag) {
            /* szSqlState's space is guaranteed by users, >= 6  */
            int result = 0;
            CommonFun::CopyIntToW(out_err_code, (wchar_t*)szSqlState, 6, result);
            /* pfNativeError not support */
            std::wstring w_detail ;
            CommonFun::FromUTF8(out_detail, w_detail);
            CommonFun::CopyWStringToW(w_detail, (wchar_t*)szErrorMsg, cchErrorMsgMax, result);
            *pcchErrorMsg = result;
            *pfNativeError = 0;
        }
    }


    if (!flag) //	this means do not have mxl statement err
        ret_code = ODBCMgrApi::Instance().SQLGetDiagRecW(fHandleType, handle, iRecord, szSqlState, pfNativeError,
                                                         szErrorMsg, cchErrorMsgMax, pcchErrorMsg);
    ODBC_UNLOCK();
    return ret_code;
}

SQLRETURN SQL_API SQLBrowseConnect(
        SQLHDBC hdbc,
        SQLCHAR *szConnStrIn,
        SQLSMALLINT cbConnStrIn,
        SQLCHAR *szConnStrOut,
        SQLSMALLINT cbConnStrOutMax,
        SQLSMALLINT *pcbConnStrOut)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLBrowseConnect");
    ret_code = ODBCMgrApi::Instance().SQLBrowseConnect(hdbc, szConnStrIn, cbConnStrIn, szConnStrOut, cbConnStrOutMax, pcbConnStrOut);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        /* todo if EnforcerContext Init failed, what should we do ? */
        SqlException exc;
        InitEnforceContext(hdbc, &exc);

        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, hdbc, &exc);
            ret_code = SQL_ERROR;
        }

    }
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API SQLBrowseConnectA(
        SQLHDBC hdbc,
        SQLCHAR *szConnStrIn,
        SQLSMALLINT cbConnStrIn,
        SQLCHAR *szConnStrOut,
        SQLSMALLINT cbConnStrOutMax,
        SQLSMALLINT *pcbConnStrOut)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLBrowseConnectA");
    ret_code = ODBCMgrApi::Instance().SQLBrowseConnect(hdbc, szConnStrIn, cbConnStrIn, szConnStrOut, cbConnStrOutMax, pcbConnStrOut);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        /* todo if EnforcerContext Init failed, what should we do ? */
        SqlException exc;
        InitEnforceContext(hdbc, &exc);
        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, hdbc, &exc);
            ret_code = SQL_ERROR;
        }

    }
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API SQLBrowseConnectW(
        SQLHDBC hdbc,
        SQLWCHAR *szConnStrIn,
        SQLSMALLINT cbConnStrIn,
        SQLWCHAR *szConnStrOut,
        SQLSMALLINT cbConnStrOutMax,
        SQLSMALLINT *pcbConnStrOut)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLBrowseConnectW");
    ret_code = ODBCMgrApi::Instance().SQLBrowseConnectW(hdbc, szConnStrIn, cbConnStrIn, szConnStrOut, cbConnStrOutMax, pcbConnStrOut);
    if (ret_code == SQL_SUCCESS || ret_code == SQL_SUCCESS_WITH_INFO)
    {
        /* todo if EnforcerContext Init failed, what should we do ? */
        SqlException exc;
        InitEnforceContext(hdbc, &exc);

        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_DBC, hdbc, &exc);
            ret_code = SQL_ERROR;
        }
    }
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN  SQL_API SQLGetInfo(SQLHDBC ConnectionHandle,SQLUSMALLINT InfoType, SQLPOINTER InfoValue,SQLSMALLINT BufferLength, SQLSMALLINT *StringLength)
{
    ENTER_HDBC(ConnectionHandle, 0);
    DAELogger::Trace("Enter SQLGetInfo");
    ret_code = ODBCMgrApi::Instance().SQLGetInfo(ConnectionHandle,InfoType,InfoValue,BufferLength,StringLength);
    LEAVE_HDBC(ConnectionHandle, 0);
}


SQLRETURN SQL_API SQLCompleteAsync(
        SQLSMALLINT HandleType,
        SQLHANDLE   Handle,
        RETCODE *   AsyncRetCodePtr)
{
    DAELogger::Trace("Enter SQLCompleteAsync");
    RETCODE ret_code =  ODBCMgrApi::Instance().SQLCompleteAsync( HandleType,  Handle, AsyncRetCodePtr) ;
    return ret_code;
}


SQLRETURN SQL_API SQLCancelHandle(
        SQLSMALLINT  HandleType,
        SQLHANDLE    Handle)
{
    DAELogger::Trace("Enter SQLCancelHandle");
    RETCODE ret_code =  ODBCMgrApi::Instance().SQLCancelHandle( HandleType,  Handle) ;
    return ret_code;

}


SQLRETURN SQL_API
SQLGetInfoA (SQLHDBC ConnectionHandle,
             SQLUSMALLINT		  InfoType,
             SQLPOINTER		  InfoValue,
             SQLSMALLINT		  BufferLength,
             SQLSMALLINT 		* StringLength)
{
    ENTER_HDBC(ConnectionHandle, 0);
    DAELogger::Trace("Enter SQLGetInfoA");
    ret_code = ODBCMgrApi::Instance().SQLGetInfoA(ConnectionHandle,InfoType,InfoValue,BufferLength,StringLength);
    LEAVE_HDBC(ConnectionHandle, 0);
}
SQLRETURN SQL_API
SQLGetInfoW (SQLHDBC ConnectionHandle,
             SQLUSMALLINT		  InfoType,
             SQLPOINTER		  InfoValue,
             SQLSMALLINT		  BufferLength,
             SQLSMALLINT 		* StringLength)
{
    ENTER_HDBC(ConnectionHandle, 0);
    DAELogger::Trace("Enter SQLGetInfoW");
    ret_code = ODBCMgrApi::Instance().SQLGetInfoW(ConnectionHandle,InfoType,InfoValue,BufferLength,StringLength);
    LEAVE_HDBC(ConnectionHandle, 0);
}

//add by jeff 19-04-18
SQLRETURN SQL_API
SQLAllocConnect (SQLHENV henv, SQLHDBC * phdbc)
{
    //ODBC_LOCK ();
    DAELogger::Trace("Enter SQLAllocConnect");
    RETCODE ret_code =  ODBCMgrApi::Instance().SQLAllocConnect ( henv,  phdbc) ;
    ODBC_LOCK();
    if(phdbc)
        EnforcerDataMgr::Instance().alloc_connect_handle(henv, (SQLHANDLE)*phdbc);
    ODBC_UNLOCK();
    return ret_code;
    //ODBC_UNLOCK ();
}
//
SQLRETURN SQL_API
SQLAllocEnv (SQLHENV * phenv)
{
    SqlException exc;
    // ODBC_LOCK();
    InitalizeEnforcer(&exc);
    // ODBC_UNLOCK();
    RETCODE ret_code = ODBCMgrApi::Instance().SQLAllocEnv ( phenv) ;
    ODBC_LOCK();
    DAELogger::Trace("Enter SQLAllocEnv end");
    if(SQL_SUCCEEDED(ret_code)){
        EnforcerDataMgr::Instance().alloc_env_handle((SQLHANDLE)*phenv);
        if(exc.IsBreak()){
            EnforcerDataMgr::Instance().push_error(SQL_HANDLE_ENV, (SQLHANDLE)*phenv, &exc);
            ret_code = SQL_ERROR;
        }
    }
    ODBC_UNLOCK();
    return ret_code;
}
//
SQLRETURN SQL_API
SQLAllocStmt (
        SQLHDBC hdbc,
        SQLHSTMT * phstmt)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLAllocStmt");
    ret_code = ODBCMgrApi::Instance().SQLAllocStmt(hdbc,phstmt);
    if (ret_code == SQL_SUCCESS) {
        EnforcerDataMgr::Instance().bind_stmt_handle(hdbc,*phstmt);
    }
    LEAVE_HDBC(hdbc, 0);

}
//use to odbc 3.0 default is SQLAllocHandle api the driver should't recome the interface
RETCODE SQL_API
SQLAllocHandleStd (
        SQLSMALLINT handleType,
        SQLHANDLE inputHandle,
        SQLHANDLE * outputHandlePtr)
{
    SqlException exc;
    if (SQL_HANDLE_ENV == handleType) {
        InitalizeEnforcer(&exc);
    }
    RETCODE ret = SQL_SUCCESS;
    ODBC_LOCK();
    DAELogger::Trace("Enter SQLAllocHandleStd");
    ODBC_UNLOCK();
    ret = ODBCMgrApi::Instance().SQLAllocHandleStd(handleType, inputHandle, outputHandlePtr);
    switch (handleType) {
        case SQL_HANDLE_ENV: {
            ODBC_LOCK();
            EnforcerDataMgr::Instance().alloc_env_handle(*outputHandlePtr);
            if(exc.IsBreak()){
                EnforcerDataMgr::Instance().push_error(handleType, (SQLHANDLE) *outputHandlePtr, &exc);
                ret = SQL_ERROR;
            }

            ODBC_UNLOCK();
        } break;
        case SQL_HANDLE_DBC: {
            ODBC_LOCK();
            EnforcerDataMgr::Instance().alloc_connect_handle(inputHandle, *outputHandlePtr);
            ODBC_UNLOCK();
        } break;
        case SQL_HANDLE_STMT: {
            if (ret == SQL_SUCCESS) {
                ODBC_LOCK();
                EnforcerDataMgr::Instance().bind_stmt_handle(inputHandle,*outputHandlePtr);
                ODBC_UNLOCK();
            }
        } break;
        default:
            break; /* do nothing */
    }

    return ret;
}

//
// SQLRETURN SQL_API
// SQLBindCol (
//     SQLHSTMT hstmt,
//     SQLUSMALLINT icol,
//     SQLSMALLINT fCType,
//     SQLPOINTER rgbValue,
//     SQLLEN cbValueMax,
//     SQLLEN *pcbValue)
// {
//   ENTER_STMT(hstmt);
// 	ret_code = ODBCMgrApi::Instance().SQLBindCol( hstmt,
//      icol,
//      fCType,
//      rgbValue,
//      cbValueMax,
//       pcbValue) ;
// 	LEAVE_STMT(hstmt);
// }
//
SQLRETURN SQL_API
SQLBindParam (
        SQLHSTMT hstmt,
        SQLUSMALLINT ipar,
        SQLSMALLINT fCType,
        SQLSMALLINT fSqlType,
        SQLULEN cbParamDef,
        SQLSMALLINT ibScale,
        SQLPOINTER rgbValue,
        SQLLEN *pcbValue)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLBindParam");
    ret_code = ODBCMgrApi::Instance().SQLBindParam(  hstmt,
                                                     ipar,
                                                     fCType,
                                                     fSqlType,
                                                     cbParamDef,
                                                     ibScale,
                                                     rgbValue,
                                                     pcbValue) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLBindParameter (
        SQLHSTMT		  hstmt,
        SQLUSMALLINT	  ipar,
        SQLSMALLINT		  fParamType,
        SQLSMALLINT		  fCType,
        SQLSMALLINT		  fSqlType,
        SQLULEN		  cbColDef,
        SQLSMALLINT		  ibScale,
        SQLPOINTER		  rgbValue,
        SQLLEN		  cbValueMax,
        SQLLEN		* pcbValue)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLBindParameter");
    ret_code = ODBCMgrApi::Instance().SQLBindParameter(  hstmt,
                                                         ipar,
                                                         fParamType,
                                                         fCType,
                                                         fSqlType,
                                                         cbColDef,
                                                         ibScale,
                                                         rgbValue,
                                                         cbValueMax,
                                                         pcbValue);
    LEAVE_STMT(hstmt);
}
//
RETCODE SQL_API
SQLBulkOperations (
        SQLHSTMT		  StatementHandle,
        SQLSMALLINT 		  Operation)
{
    ENTER_STMT(StatementHandle);
    DAELogger::Trace("Enter SQLBulkOperations");
    ret_code = ODBCMgrApi::Instance().SQLBulkOperations(  StatementHandle,
                                                          Operation) ;
    LEAVE_STMT(StatementHandle);
}
//
// SQLRETURN SQL_API
// SQLCancel (SQLHSTMT hstmt)
// {
// 	//cancel
// }
//
// SQLRETURN SQL_API
// SQLCloseCursor (SQLHSTMT hstmt)
// {
// 	ENTER_STMT(hstmt);
//  DAELogger::Trace("Enter ");
// 	ret_code = ODBCMgrApi::Instance().SQLCloseCursor(  hstmt) ;
// 	LEAVE_STMT(hstmt);
// }
//10

RETCODE SQL_API
SQLColAttribute (
        SQLHSTMT		  statementHandle,
        SQLUSMALLINT		  ColumnNumber,
        SQLUSMALLINT		  FieldIdentifier,
        SQLPOINTER		  CharacterAttributePtr,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr,
        SQLLEN		* NumericAttributePtr)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLColAttribute");
    ret_code = ODBCMgrApi::Instance().SQLColAttribute ( statementHandle,
                                                        ColumnNumber,
                                                        FieldIdentifier,
                                                        CharacterAttributePtr,
                                                        BufferLength,
                                                        StringLengthPtr,
                                                        NumericAttributePtr) ;
    LEAVE_STMT(statementHandle);
}
RETCODE SQL_API
SQLColAttributeA (
        SQLHSTMT		  statementHandle,
        SQLUSMALLINT		  ColumnNumber,
        SQLUSMALLINT		  FieldIdentifier,
        SQLPOINTER		  CharacterAttributePtr,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr,
        SQLLEN		* NumericAttributePtr)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLColAttributeA");
    ret_code = ODBCMgrApi::Instance().SQLColAttributeA ( statementHandle,
                                                         ColumnNumber,
                                                         FieldIdentifier,
                                                         CharacterAttributePtr,
                                                         BufferLength,
                                                         StringLengthPtr,
                                                         NumericAttributePtr) ;
    LEAVE_STMT(statementHandle);
}
RETCODE SQL_API
SQLColAttributeW (
        SQLHSTMT		  statementHandle,
        SQLUSMALLINT		  ColumnNumber,
        SQLUSMALLINT		  FieldIdentifier,
        SQLPOINTER		  CharacterAttributePtr,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr,
        SQLLEN		* NumericAttributePtr)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLColAttributeW");
    ret_code = ODBCMgrApi::Instance().SQLColAttributeW ( statementHandle,
                                                         ColumnNumber,
                                                         FieldIdentifier,
                                                         CharacterAttributePtr,
                                                         BufferLength,
                                                         StringLengthPtr,
                                                         NumericAttributePtr) ;
    LEAVE_STMT(statementHandle);
}
///
RETCODE SQL_API
SQLColAttributes (
        SQLHSTMT 		  hstmt,
        SQLUSMALLINT		  icol,
        SQLUSMALLINT		  fDescType,
        SQLPOINTER		  rgbDesc,
        SQLSMALLINT		  cbDescMax,
        SQLSMALLINT 		* pcbDesc,
        SQLLEN 		* pfDesc)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColAttributes ");
    ret_code = ODBCMgrApi::Instance().SQLColAttributes (hstmt,
                                                        icol,
                                                        fDescType,
                                                        rgbDesc,
                                                        cbDescMax,
                                                        pcbDesc,
                                                        pfDesc) ; ;
    LEAVE_STMT(hstmt);
}
RETCODE SQL_API
SQLColAttributesA (
        SQLHSTMT 		  hstmt,
        SQLUSMALLINT		  icol,
        SQLUSMALLINT		  fDescType,
        SQLPOINTER		  rgbDesc,
        SQLSMALLINT		  cbDescMax,
        SQLSMALLINT 		* pcbDesc,
        SQLLEN 		* pfDesc)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColAttributesA");
    ret_code = ODBCMgrApi::Instance().SQLColAttributesA (hstmt,
                                                         icol,
                                                         fDescType,
                                                         rgbDesc,
                                                         cbDescMax,
                                                         pcbDesc,
                                                         pfDesc) ;
    LEAVE_STMT(hstmt);
}
RETCODE SQL_API
SQLColAttributesW (
        SQLHSTMT 		  hstmt,
        SQLUSMALLINT		  icol,
        SQLUSMALLINT		  fDescType,
        SQLPOINTER		  rgbDesc,
        SQLSMALLINT		  cbDescMax,
        SQLSMALLINT 		* pcbDesc,
        SQLLEN 		* pfDesc)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColAttributesW ");
    ret_code = ODBCMgrApi::Instance().SQLColAttributesW (hstmt,
                                                         icol,
                                                         fDescType,
                                                         rgbDesc,
                                                         cbDescMax,
                                                         pcbDesc,
                                                         pfDesc) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLColumnPrivileges (SQLHSTMT hstmt,
                     SQLCHAR * szTableQualifier,
                     SQLSMALLINT cbTableQualifier,
                     SQLCHAR * szTableOwner,
                     SQLSMALLINT cbTableOwner,
                     SQLCHAR * szTableName,
                     SQLSMALLINT cbTableName,
                     SQLCHAR * szColumnName,
                     SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColumnPrivileges ");
    ret_code = ODBCMgrApi::Instance().SQLColumnPrivileges (hstmt,
                                                           szTableQualifier,
                                                           cbTableQualifier,
                                                           szTableOwner,
                                                           cbTableOwner,
                                                           szTableName,
                                                           cbTableName,
                                                           szColumnName,
                                                           cbColumnName) ; ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLColumnPrivilegesA (SQLHSTMT hstmt,
                      SQLCHAR * szTableQualifier,
                      SQLSMALLINT cbTableQualifier,
                      SQLCHAR * szTableOwner,
                      SQLSMALLINT cbTableOwner,
                      SQLCHAR * szTableName,
                      SQLSMALLINT cbTableName,
                      SQLCHAR * szColumnName,
                      SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColumnPrivilegesA");
    ret_code = ODBCMgrApi::Instance().SQLColumnPrivilegesA (hstmt,
                                                            szTableQualifier,
                                                            cbTableQualifier,
                                                            szTableOwner,
                                                            cbTableOwner,
                                                            szTableName,
                                                            cbTableName,
                                                            szColumnName,
                                                            cbColumnName) ; ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLColumnPrivilegesW (SQLHSTMT hstmt,
                      SQLWCHAR * szTableQualifier,
                      SQLSMALLINT cbTableQualifier,
                      SQLWCHAR * szTableOwner,
                      SQLSMALLINT cbTableOwner,
                      SQLWCHAR * szTableName,
                      SQLSMALLINT cbTableName,
                      SQLWCHAR * szColumnName,
                      SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColumnPrivilegesW");
    ret_code = ODBCMgrApi::Instance().SQLColumnPrivilegesW (hstmt,
                                                            szTableQualifier,
                                                            cbTableQualifier,
                                                            szTableOwner,
                                                            cbTableOwner,
                                                            szTableName,
                                                            cbTableName,
                                                            szColumnName,
                                                            cbColumnName) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLColumns (SQLHSTMT hstmt,
            SQLCHAR * szTableQualifier,
            SQLSMALLINT cbTableQualifier,
            SQLCHAR * szTableOwner,
            SQLSMALLINT cbTableOwner,
            SQLCHAR * szTableName,
            SQLSMALLINT cbTableName,
            SQLCHAR * szColumnName,
            SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColumns");
    ret_code = ODBCMgrApi::Instance().SQLColumns ( hstmt,
                                                   szTableQualifier,
                                                   cbTableQualifier,
                                                   szTableOwner,
                                                   cbTableOwner,
                                                   szTableName,
                                                   cbTableName,
                                                   szColumnName,
                                                   cbColumnName) ;
    LEAVE_STMT(hstmt);
}
//




SQLRETURN SQL_API
SQLColumnsA (SQLHSTMT hstmt,
             SQLCHAR * szTableQualifier,
             SQLSMALLINT cbTableQualifier,
             SQLCHAR * szTableOwner,
             SQLSMALLINT cbTableOwner,
             SQLCHAR * szTableName,
             SQLSMALLINT cbTableName,
             SQLCHAR * szColumnName,
             SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColumnsA");
    ret_code = ODBCMgrApi::Instance().SQLColumnsA ( hstmt,
                                                    szTableQualifier,
                                                    cbTableQualifier,
                                                    szTableOwner,
                                                    cbTableOwner,
                                                    szTableName,
                                                    cbTableName,
                                                    szColumnName,
                                                    cbColumnName) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLColumnsW (SQLHSTMT hstmt,
             SQLWCHAR * szTableQualifier,
             SQLSMALLINT cbTableQualifier,
             SQLWCHAR * szTableOwner,
             SQLSMALLINT cbTableOwner,
             SQLWCHAR * szTableName,
             SQLSMALLINT cbTableName,
             SQLWCHAR * szColumnName,
             SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLColumnsW");
    ret_code = ODBCMgrApi::Instance().SQLColumnsW ( hstmt,
                                                    szTableQualifier,
                                                    cbTableQualifier,
                                                    szTableOwner,
                                                    cbTableOwner,
                                                    szTableName,
                                                    cbTableName,
                                                    szColumnName,
                                                    cbColumnName) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLDescribeCol (SQLHSTMT hstmt,
                SQLUSMALLINT	  icol,
                SQLCHAR		* szColName,
                SQLSMALLINT		  cbColNameMax,
                SQLSMALLINT		* pcbColName,
                SQLSMALLINT		* pfSqlType,
                SQLULEN		* pcbColDef,
                SQLSMALLINT		* pibScale,
                SQLSMALLINT		* pfNullable)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLDescribeCol");
    ret_code = ODBCMgrApi::Instance().SQLDescribeCol ( hstmt,
                                                       icol,
                                                       szColName,
                                                       cbColNameMax,
                                                       pcbColName,
                                                       pfSqlType,
                                                       pcbColDef,
                                                       pibScale,
                                                       pfNullable) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLDescribeColA (SQLHSTMT hstmt,
                 SQLUSMALLINT	  icol,
                 SQLCHAR		* szColName,
                 SQLSMALLINT		  cbColNameMax,
                 SQLSMALLINT		* pcbColName,
                 SQLSMALLINT		* pfSqlType,
                 SQLULEN		* pcbColDef,
                 SQLSMALLINT		* pibScale,
                 SQLSMALLINT		* pfNullable)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLDescribeColA");
    ret_code = ODBCMgrApi::Instance().SQLDescribeColA ( hstmt,
                                                        icol,
                                                        szColName,
                                                        cbColNameMax,
                                                        pcbColName,
                                                        pfSqlType,
                                                        pcbColDef,
                                                        pibScale,
                                                        pfNullable) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLDescribeColW (
        SQLHSTMT		  hstmt,
        SQLUSMALLINT		  icol,
        SQLWCHAR		* szColName,
        SQLSMALLINT		  cbColNameMax,
        SQLSMALLINT		* pcbColName,
        SQLSMALLINT		* pfSqlType,
        SQLULEN		* pcbColDef,
        SQLSMALLINT		* pibScale,
        SQLSMALLINT		* pfNullable)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLDescribeColW");
    ret_code = ODBCMgrApi::Instance().SQLDescribeColW ( hstmt,
                                                        icol,
                                                        szColName,
                                                        cbColNameMax,
                                                        pcbColName,
                                                        pfSqlType,
                                                        pcbColDef,
                                                        pibScale,
                                                        pfNullable) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLDescribeParam (
        SQLHSTMT		  hstmt,
        SQLUSMALLINT		  ipar,
        SQLSMALLINT 		* pfSqlType,
        SQLULEN 		* pcbColDef,
        SQLSMALLINT 		* pibScale,
        SQLSMALLINT 		* pfNullable)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLDescribeParam");
    ret_code = ODBCMgrApi::Instance().SQLDescribeParam (hstmt,
                                                        ipar,
                                                        pfSqlType,
                                                        pcbColDef,
                                                        pibScale,
                                                        pfNullable);
    LEAVE_STMT(hstmt);
}
//
RETCODE SQL_API
SQLEndTran (
        SQLSMALLINT		  handleType,
        SQLHANDLE		  Handle,
        SQLSMALLINT		  completionType)
{
    SQLRETURN ret_code = SQL_SUCCESS;
    //ODBC_LOCK ();
    DAELogger::Trace("Enter SQLEndTran");
    ret_code = ODBCMgrApi::Instance().SQLEndTran (handleType, Handle, completionType) ;
    //ODBC_UNLOCK ();
    return ret_code;
}
//
SQLRETURN SQL_API
SQLError (
        SQLHENV		  henv,
        SQLHDBC		  hdbc,
        SQLHSTMT		  hstmt,
        SQLCHAR 		* szSqlstate,
        SQLINTEGER 		* pfNativeError,
        SQLCHAR 		* szErrorMsg,
        SQLSMALLINT		  cbErrorMsgMax,
        SQLSMALLINT 		* pcbErrorMsg)
{
    ODBC_LOCK();
    if(DAELogger::WriteLog){
        DAELogger::Trace("Enter SQLError");
    }

    SQLSMALLINT c_;
    pcbErrorMsg = pcbErrorMsg ? pcbErrorMsg : &c_;
    SQLRETURN ret_code = SQL_SUCCESS;
    bool flag = false;
    int out_err_code;
    std::string out_detail;
    if(hstmt){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_STMT, hstmt, out_err_code,  out_detail);
    }
    else if(hdbc){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_DBC, hdbc, out_err_code,  out_detail);
    }
    else if(henv){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_ENV, henv, out_err_code,  out_detail);
    }
    if (flag) {
        /* szSqlState's space is guaranteed by users, >= 6  */
        int result = 0;
        CommonFun::CopyIntToA(out_err_code, (char*)szSqlstate, 6, result);
        /* pfNativeError not support */
        CommonFun::CopyStringToA(out_detail, (char*)szErrorMsg, cbErrorMsgMax, result);
        *pcbErrorMsg = result;
        *pfNativeError = 0;
    }
    if (!flag) //	this means do not have mxl statement err
        ret_code = ODBCMgrApi::Instance().SQLError (henv, hdbc, hstmt, szSqlstate, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg) ;
    ODBC_UNLOCK();
    return ret_code;
}
SQLRETURN SQL_API
SQLErrorA (
        SQLHENV		  henv,
        SQLHDBC		  hdbc,
        SQLHSTMT		  hstmt,
        SQLCHAR 		* szSqlstate,
        SQLINTEGER 		* pfNativeError,
        SQLCHAR 		* szErrorMsg,
        SQLSMALLINT		  cbErrorMsgMax,
        SQLSMALLINT 		* pcbErrorMsg)
{

    ODBC_LOCK();
    if(DAELogger::WriteLog){
        DAELogger::Trace("Enter SQLErrorA");
    }
    SQLSMALLINT c_;
    pcbErrorMsg = pcbErrorMsg ? pcbErrorMsg : &c_;
    SQLRETURN ret_code = SQL_SUCCESS;
    bool flag = false;
    int out_err_code;
    std::string out_detail;
    if(hstmt){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_STMT, hstmt, out_err_code,  out_detail);
    }
    else if(hdbc){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_DBC, hdbc, out_err_code,  out_detail);
    }
    else if(henv){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_ENV, henv, out_err_code,  out_detail);
    }

    if (flag) {
        /* szSqlState's space is guaranteed by users, >= 6  */
        int result = 0;
        CommonFun::CopyIntToA(out_err_code, (char*)szSqlstate, 6, result);
        /* pfNativeError not support */
        CommonFun::CopyStringToA(out_detail, (char*)szErrorMsg, cbErrorMsgMax, result);
        *pcbErrorMsg = result;
        *pfNativeError = 0;
    }
    if (!flag) //	this means do not have mxl statement err
        ret_code = ODBCMgrApi::Instance().SQLErrorA (henv, hdbc, hstmt, szSqlstate, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg) ;
    ODBC_UNLOCK();
    return ret_code;
}
SQLRETURN SQL_API
SQLErrorW (
        SQLHENV		  henv,
        SQLHDBC		  hdbc,
        SQLHSTMT		  hstmt,
        SQLWCHAR 		* szSqlstate,
        SQLINTEGER 		* pfNativeError,
        SQLWCHAR 		* szErrorMsg,
        SQLSMALLINT		  cbErrorMsgMax,
        SQLSMALLINT 		* pcbErrorMsg)
{

    ODBC_LOCK();
    if(DAELogger::WriteLog){
        DAELogger::Trace("Enter SQLErrorW");
    }
    SQLSMALLINT c_;
    pcbErrorMsg = pcbErrorMsg ? pcbErrorMsg : &c_;
    SQLRETURN ret_code = SQL_SUCCESS;
    bool flag = false;
    int out_err_code;
    std::string out_detail;
    if(hstmt){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_STMT, hstmt, out_err_code,  out_detail);
    }
    else if(hdbc){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_DBC, hdbc, out_err_code,  out_detail);
    }
    else if(henv){
        flag = EnforcerDataMgr::Instance().get_error_last(SQL_HANDLE_ENV, henv, out_err_code,  out_detail);
    }

    if (flag) {
        /* szSqlState's space is guaranteed by users, >= 6  */
        int result = 0;
        CommonFun::CopyIntToW(out_err_code, (wchar_t*)szSqlstate, 6, result);
        /* pfNativeError not support */
        std::wstring w_detail ;
        CommonFun::FromUTF8(out_detail, w_detail);
        CommonFun::CopyWStringToW(w_detail, (wchar_t*)szErrorMsg, cbErrorMsgMax, result);
        *pcbErrorMsg = result;
        *pfNativeError = 0;
    }

    if (!flag) //	this means do not have mxl statement err
        ret_code = ODBCMgrApi::Instance().SQLErrorW (henv, hdbc, hstmt, szSqlstate, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg) ;
    ODBC_UNLOCK();
    return ret_code;
}
//30



//
SQLRETURN SQL_API
SQLExecute (SQLHSTMT hstmt)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLExecute");
    ret_code = ODBCMgrApi::Instance().SQLExecute (hstmt) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLExtendedFetch (
        SQLHSTMT		  hstmt,
        SQLUSMALLINT		  fFetchType,
        SQLLEN		  irow,
        SQLULEN 		* pcrow,
        SQLUSMALLINT 		* rgfRowStatus)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLExtendedFetch");
    ret_code = ODBCMgrApi::Instance().SQLExtendedFetch ( hstmt, fFetchType, irow, pcrow, rgfRowStatus);
    LEAVE_STMT(hstmt);
}
//
// SQLRETURN SQL_API
// SQLFetch (SQLHSTMT hstmt)
// {
//   ENTER_STMT(hstmt);
// 	ret_code = ODBCMgrApi::Instance().SQLFetch ( hstmt) ;
// 	LEAVE_STMT(hstmt);
// }
//
RETCODE SQL_API
SQLFetchScroll (
        SQLHSTMT		  statementHandle,
        SQLSMALLINT		  fetchOrientation,
        SQLLEN		  fetchOffset)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLFetchScroll ");
    ret_code = ODBCMgrApi::Instance().SQLFetchScroll (statementHandle, fetchOrientation, fetchOffset) ;
    LEAVE_STMT(statementHandle);
}
//
SQLRETURN SQL_API
SQLForeignKeys (SQLHSTMT hstmt,
                SQLCHAR * szPkTableQualifier,
                SQLSMALLINT cbPkTableQualifier,
                SQLCHAR * szPkTableOwner,
                SQLSMALLINT cbPkTableOwner,
                SQLCHAR * szPkTableName,
                SQLSMALLINT cbPkTableName,
                SQLCHAR * szFkTableQualifier,
                SQLSMALLINT cbFkTableQualifier,
                SQLCHAR * szFkTableOwner,
                SQLSMALLINT cbFkTableOwner,
                SQLCHAR * szFkTableName,
                SQLSMALLINT cbFkTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLForeignKeys ");
    ret_code = ODBCMgrApi::Instance().SQLForeignKeys ( hstmt,
                                                       szPkTableQualifier,
                                                       cbPkTableQualifier,
                                                       szPkTableOwner,
                                                       cbPkTableOwner,
                                                       szPkTableName,
                                                       cbPkTableName,
                                                       szFkTableQualifier,
                                                       cbFkTableQualifier,
                                                       szFkTableOwner,
                                                       cbFkTableOwner,
                                                       szFkTableName,
                                                       cbFkTableName);
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLForeignKeysA (SQLHSTMT hstmt,
                 SQLCHAR * szPkTableQualifier,
                 SQLSMALLINT cbPkTableQualifier,
                 SQLCHAR * szPkTableOwner,
                 SQLSMALLINT cbPkTableOwner,
                 SQLCHAR * szPkTableName,
                 SQLSMALLINT cbPkTableName,
                 SQLCHAR * szFkTableQualifier,
                 SQLSMALLINT cbFkTableQualifier,
                 SQLCHAR * szFkTableOwner,
                 SQLSMALLINT cbFkTableOwner,
                 SQLCHAR * szFkTableName,
                 SQLSMALLINT cbFkTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLForeignKeysA ");
    ret_code = ODBCMgrApi::Instance().SQLForeignKeysA ( hstmt,
                                                        szPkTableQualifier,
                                                        cbPkTableQualifier,
                                                        szPkTableOwner,
                                                        cbPkTableOwner,
                                                        szPkTableName,
                                                        cbPkTableName,
                                                        szFkTableQualifier,
                                                        cbFkTableQualifier,
                                                        szFkTableOwner,
                                                        cbFkTableOwner,
                                                        szFkTableName,
                                                        cbFkTableName);
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLForeignKeysW (SQLHSTMT hstmt,
                 SQLWCHAR * szPkTableQualifier,
                 SQLSMALLINT cbPkTableQualifier,
                 SQLWCHAR * szPkTableOwner,
                 SQLSMALLINT cbPkTableOwner,
                 SQLWCHAR * szPkTableName,
                 SQLSMALLINT cbPkTableName,
                 SQLWCHAR * szFkTableQualifier,
                 SQLSMALLINT cbFkTableQualifier,
                 SQLWCHAR * szFkTableOwner,
                 SQLSMALLINT cbFkTableOwner,
                 SQLWCHAR * szFkTableName,
                 SQLSMALLINT cbFkTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLForeignKeysW ");
    ret_code = ODBCMgrApi::Instance().SQLForeignKeysW ( hstmt,
                                                        szPkTableQualifier,
                                                        cbPkTableQualifier,
                                                        szPkTableOwner,
                                                        cbPkTableOwner,
                                                        szPkTableName,
                                                        cbPkTableName,
                                                        szFkTableQualifier,
                                                        cbFkTableQualifier,
                                                        szFkTableOwner,
                                                        cbFkTableOwner,
                                                        szFkTableName,
                                                        cbFkTableName);
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLFreeConnect (SQLHDBC hdbc)
{
    ENTER_HDBC(hdbc, 1);
    DAELogger::Trace("Enter SQLFreeConnect ");
    ret_code = ODBCMgrApi::Instance().SQLFreeConnect ( hdbc);
    if(SQL_SUCCEEDED(ret_code)){
        EnforcerDataMgr::Instance().freehandle(SQL_HANDLE_DBC, hdbc);
    }
    LEAVE_HDBC(hdbc, 1);
}
//
//
RETCODE SQL_API
SQLGetConnectAttr (
        SQLHDBC 		  connectionHandle,
        SQLINTEGER 		  Attribute,
        SQLPOINTER 		  ValuePtr,
        SQLINTEGER 		  StringLength,
        SQLINTEGER		* StringLengthPtr)
{
    ENTER_HDBC(connectionHandle, 0);
    DAELogger::Trace("Enter SQLGetConnectAttr ");
    ret_code = ODBCMgrApi::Instance().SQLGetConnectAttr (
            connectionHandle,
            Attribute,
            ValuePtr,
            StringLength,
            StringLengthPtr);
    LEAVE_HDBC(connectionHandle, 0);
}
//40



RETCODE SQL_API
SQLGetConnectAttrA (
        SQLHDBC 		  connectionHandle,
        SQLINTEGER 		  Attribute,
        SQLPOINTER 		  ValuePtr,
        SQLINTEGER 		  StringLength,
        SQLINTEGER		* StringLengthPtr)
{
    ENTER_HDBC(connectionHandle, 0);
    DAELogger::Trace("Enter SQLGetConnectAttrA ");
    ret_code = ODBCMgrApi::Instance().SQLGetConnectAttrA (
            connectionHandle,
            Attribute,
            ValuePtr,
            StringLength,
            StringLengthPtr);
    LEAVE_HDBC(connectionHandle, 0);
}
RETCODE SQL_API
SQLGetConnectAttrW (
        SQLHDBC 		  connectionHandle,
        SQLINTEGER 		  Attribute,
        SQLPOINTER 		  ValuePtr,
        SQLINTEGER 		  StringLength,
        SQLINTEGER		* StringLengthPtr)
{
    ENTER_HDBC(connectionHandle, 0);
    DAELogger::Trace("Enter SQLGetConnectAttrW");
    ret_code = ODBCMgrApi::Instance().SQLGetConnectAttrW (
            connectionHandle,
            Attribute,
            ValuePtr,
            StringLength,
            StringLengthPtr);
    LEAVE_HDBC(connectionHandle, 0);
}
SQLRETURN SQL_API
SQLGetConnectOption (SQLHDBC hdbc,
                     SQLUSMALLINT fOption,
                     SQLPOINTER pvParam)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLGetConnectOption");
    ret_code = ODBCMgrApi::Instance().SQLGetConnectOption ( hdbc, fOption, pvParam);
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API
SQLGetConnectOptionA (SQLHDBC hdbc,
                      SQLUSMALLINT fOption,
                      SQLPOINTER pvParam)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter  SQLGetConnectOptionA");
    ret_code = ODBCMgrApi::Instance().SQLGetConnectOptionA ( hdbc, fOption, pvParam);
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API
SQLGetConnectOptionW (SQLHDBC hdbc,
                      SQLUSMALLINT fOption,
                      SQLPOINTER pvParam)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLGetConnectOptionW ");
    ret_code = ODBCMgrApi::Instance().SQLGetConnectOptionW ( hdbc, fOption, pvParam);
    LEAVE_HDBC(hdbc, 0);
}
//
SQLRETURN SQL_API
SQLGetCursorName (
        SQLHSTMT 		  hstmt,
        SQLCHAR  		* szCursor,
        SQLSMALLINT 		  cbCursorMax,
        SQLSMALLINT 	 	* pcbCursor)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLGetCursorName");
    ret_code = ODBCMgrApi::Instance().SQLGetCursorName ( hstmt, szCursor, cbCursorMax, pcbCursor);
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLGetCursorNameA (
        SQLHSTMT 		  hstmt,
        SQLCHAR  		* szCursor,
        SQLSMALLINT 		  cbCursorMax,
        SQLSMALLINT 	 	* pcbCursor)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLGetCursorNameA");
    ret_code = ODBCMgrApi::Instance().SQLGetCursorNameA ( hstmt, szCursor, cbCursorMax, pcbCursor);
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLGetCursorNameW (
        SQLHSTMT 		  hstmt,
        SQLWCHAR  		* szCursor,
        SQLSMALLINT 		  cbCursorMax,
        SQLSMALLINT 	 	* pcbCursor)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLGetCursorNameW");
    ret_code = ODBCMgrApi::Instance().SQLGetCursorNameW ( hstmt, szCursor, cbCursorMax, pcbCursor);
    LEAVE_STMT(hstmt);
}
//
// SQLRETURN SQL_API
// SQLGetData (
//     SQLHSTMT		  hstmt,
//     SQLUSMALLINT	  icol,
//     SQLSMALLINT		  fCType,
//     SQLPOINTER		  rgbValue,
//     SQLLEN		  cbValueMax,
//     SQLLEN 		* pcbValue)
// {
//   ENTER_STMT(hstmt);
// 	ret_code = ODBCMgrApi::Instance().SQLGetData (hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue);
// 	LEAVE_STMT(hstmt);
// }
//
RETCODE SQL_API
SQLGetDiagField (
        SQLSMALLINT		  HandleType,
        SQLHANDLE		  Handle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  DiagIdentifier,
        SQLPOINTER		  DiagInfoPtr,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr)
{
    SQLRETURN retcode = SQL_SUCCESS;
    //ODBC_LOCK ();
    DAELogger::Trace("Enter SQLGetDiagField");
    retcode = ODBCMgrApi::Instance().SQLGetDiagField (
            HandleType,
            Handle,
            RecNumber,
            DiagIdentifier,
            DiagInfoPtr,
            BufferLength,
            StringLengthPtr) ;
    //ODBC_UNLOCK ();
    return retcode;

}
//50


RETCODE SQL_API
SQLGetDiagFieldA (
        SQLSMALLINT		  HandleType,
        SQLHANDLE		  Handle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  DiagIdentifier,
        SQLPOINTER		  DiagInfoPtr,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr)
{
    SQLRETURN retcode = SQL_SUCCESS;

    //ODBC_LOCK ();
    DAELogger::Trace("Enter SQLGetDiagFieldA");
    retcode = ODBCMgrApi::Instance().SQLGetDiagFieldA (
            HandleType,
            Handle,
            RecNumber,
            DiagIdentifier,
            DiagInfoPtr,
            BufferLength,
            StringLengthPtr) ;
    //ODBC_UNLOCK ();
    return retcode;
}
RETCODE SQL_API
SQLGetDiagFieldW (
        SQLSMALLINT		  HandleType,
        SQLHANDLE		  Handle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  DiagIdentifier,
        SQLPOINTER		  DiagInfoPtr,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr)
{
    SQLRETURN retcode = SQL_SUCCESS;
    //ODBC_LOCK ();
    DAELogger::Trace("Enter SQLGetDiagFieldW");
    retcode = ODBCMgrApi::Instance().SQLGetDiagFieldW (
            HandleType,
            Handle,
            RecNumber,
            DiagIdentifier,
            DiagInfoPtr,
            BufferLength,
            StringLengthPtr) ;
    //ODBC_UNLOCK ();
    return retcode;
}
//
RETCODE SQL_API
SQLGetEnvAttr (
        SQLHENV		  EnvironmentHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength,
        SQLINTEGER		* StringLengthPtr)
{
    /* ENTER_HENV without EnvironmentHandle check */
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter SQLGetEnvAttr");
    retcode = ODBCMgrApi::Instance().SQLGetEnvAttr ( EnvironmentHandle, Attribute, ValuePtr, BufferLength, StringLengthPtr);
    return retcode;

}
SQLRETURN SQL_API
SQLGetFunctions (
        SQLHDBC		  hdbc,
        SQLUSMALLINT		  fFunc,
        SQLUSMALLINT	 	* pfExists)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLGetFunctions");
    ret_code = ODBCMgrApi::Instance().SQLGetFunctions ( hdbc, fFunc, pfExists);
    LEAVE_HDBC(hdbc, 0);
}
//
RETCODE SQL_API
SQLGetStmtAttr (
        SQLHSTMT		  statementHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength,
        SQLINTEGER		* StringLengthPtr)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLGetStmtAttr");
    ret_code = ODBCMgrApi::Instance().SQLGetStmtAttr (
            statementHandle,
            Attribute,
            ValuePtr,
            BufferLength,
            StringLengthPtr);
    LEAVE_STMT(statementHandle);
}
RETCODE SQL_API
SQLGetStmtAttrA (
        SQLHSTMT		  statementHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength,
        SQLINTEGER		* StringLengthPtr)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLGetStmtAttrA");
    ret_code = ODBCMgrApi::Instance().SQLGetStmtAttrA (
            statementHandle,
            Attribute,
            ValuePtr,
            BufferLength,
            StringLengthPtr);
    LEAVE_STMT(statementHandle);
}
RETCODE SQL_API
SQLGetStmtAttrW (
        SQLHSTMT		  statementHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength,
        SQLINTEGER		* StringLengthPtr)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLGetStmtAttrW");
    ret_code = ODBCMgrApi::Instance().SQLGetStmtAttrW (
            statementHandle,
            Attribute,
            ValuePtr,
            BufferLength,
            StringLengthPtr);
    LEAVE_STMT(statementHandle);
}
//
SQLRETURN SQL_API
SQLGetStmtOption (
        SQLHSTMT hstmt,
        SQLUSMALLINT fOption,
        SQLPOINTER pvParam)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLGetStmtOption");
    ret_code = ODBCMgrApi::Instance().SQLGetStmtOption ( hstmt,
                                                         fOption,
                                                         pvParam) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLGetTypeInfo (SQLHSTMT hstmt,
                SQLSMALLINT fSqlType)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLGetTypeInfo ");
    ret_code = ODBCMgrApi::Instance().SQLGetTypeInfo ( hstmt, fSqlType) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLGetTypeInfoA (SQLHSTMT hstmt,
                 SQLSMALLINT fSqlType)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLGetTypeInfoA ");
    ret_code = ODBCMgrApi::Instance().SQLGetTypeInfoA ( hstmt, fSqlType) ;
    LEAVE_STMT(hstmt);
}
//60

SQLRETURN SQL_API
SQLGetTypeInfoW (SQLHSTMT hstmt,
                 SQLSMALLINT fSqlType)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLGetTypeInfoW ");
    ret_code = ODBCMgrApi::Instance().SQLGetTypeInfoW (hstmt, fSqlType) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLMoreResults (SQLHSTMT hstmt)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLMoreResults ");
    ret_code = ODBCMgrApi::Instance().SQLMoreResults (hstmt) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLNativeSql (
        SQLHDBC hdbc,
        SQLCHAR * szSqlStrIn,
        SQLINTEGER cbSqlStrIn,
        SQLCHAR * szSqlStr,
        SQLINTEGER cbSqlStrMax,
        SQLINTEGER * pcbSqlStr)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLNativeSql");
    ret_code = ODBCMgrApi::Instance().SQLNativeSql (
            hdbc,
            szSqlStrIn,
            cbSqlStrIn,
            szSqlStr,
            cbSqlStrMax,
            pcbSqlStr);
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API
SQLNativeSqlA (
        SQLHDBC hdbc,
        SQLCHAR * szSqlStrIn,
        SQLINTEGER cbSqlStrIn,
        SQLCHAR * szSqlStr,
        SQLINTEGER cbSqlStrMax,
        SQLINTEGER * pcbSqlStr)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLNativeSqlA");
    ret_code = ODBCMgrApi::Instance().SQLNativeSqlA (
            hdbc,
            szSqlStrIn,
            cbSqlStrIn,
            szSqlStr,
            cbSqlStrMax,
            pcbSqlStr);
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API
SQLNativeSqlW (
        SQLHDBC hdbc,
        SQLWCHAR * szSqlStrIn,
        SQLINTEGER cbSqlStrIn,
        SQLWCHAR * szSqlStr,
        SQLINTEGER cbSqlStrMax,
        SQLINTEGER * pcbSqlStr)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLNativeSqlW");
    ret_code = ODBCMgrApi::Instance().SQLNativeSqlW (
            hdbc,
            szSqlStrIn,
            cbSqlStrIn,
            szSqlStr,
            cbSqlStrMax,
            pcbSqlStr);
    LEAVE_HDBC(hdbc, 0);
}
//
SQLRETURN SQL_API
SQLNumParams (SQLHSTMT hstmt, SQLSMALLINT * pcpar)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLNumParams");
    ret_code = ODBCMgrApi::Instance().SQLNumParams ( hstmt,  pcpar);
    LEAVE_STMT(hstmt);
}
//
// SQLRETURN SQL_API
// SQLNumResultCols (
//   SQLHSTMT		  hstmt,
//   SQLSMALLINT 		* pccol)
// {
//   ENTER_STMT(hstmt);
// 	ret_code = ODBCMgrApi::Instance().SQLNumResultCols ( hstmt, pccol) ;
// 	LEAVE_STMT(hstmt);
// }
//
SQLRETURN SQL_API
SQLParamData (SQLHSTMT hstmt, SQLPOINTER * prgbValue)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLParamData");
    ret_code = ODBCMgrApi::Instance().SQLParamData ( hstmt,  prgbValue);
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLParamOptions(
        SQLHSTMT		  hstmt,
        SQLULEN		  crow,
        SQLULEN 		* pirow)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLParamOptions");
    ret_code = ODBCMgrApi::Instance().SQLParamOptions(  hstmt, crow, pirow) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLPrepare (SQLHSTMT hstmt,
            SQLCHAR * szSqlStr,
            SQLINTEGER cbSqlStr)
{
    USER_CONTEXT enforcerContext;
    std::string strNewSql ;
    if(szSqlStr)
        strNewSql = (char *)szSqlStr;
    //bool is_blocked = false;
    SqlException exc;
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLPrepare");

    if (EnforcerDataMgr::Instance().get_enforcer_context_by_stmt_handle(hstmt, enforcerContext))
    {
        strNewSql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, (char *)szSqlStr, &exc);
    }
    if(!exc.IsBreak())
        ret_code = ODBCMgrApi::Instance().SQLPrepare ( hstmt, (SQLCHAR*)strNewSql.c_str(), (SQLINTEGER)strNewSql.length()) ;
    else
    {
        EnforcerDataMgr::Instance().push_error(SQL_HANDLE_STMT, hstmt, &exc);
        ret_code = SQL_ERROR;
    }

    LEAVE_STMT(hstmt);
}
//70


SQLRETURN SQL_API
SQLPrepareA (SQLHSTMT hstmt,
             SQLCHAR * szSqlStr,
             SQLINTEGER cbSqlStr)
{
    SqlException exc;
    USER_CONTEXT enforcerContext;
    std::string strNewSql;// = (char *)szSqlStr;
    if(szSqlStr)
        strNewSql = (char *)szSqlStr;
    //bool is_blocked = false;
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLPrepareA");
    if (EnforcerDataMgr::Instance().get_enforcer_context_by_stmt_handle(hstmt, enforcerContext))
    {

        strNewSql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, (char *)szSqlStr, &exc);

    }
    if(!exc.IsBreak())
        ret_code = ODBCMgrApi::Instance().SQLPrepareA ( hstmt, (SQLCHAR*)strNewSql.c_str(), (SQLINTEGER)strNewSql.length()) ;
    else
    {
        EnforcerDataMgr::Instance().push_error(SQL_HANDLE_STMT, hstmt, &exc);
        ret_code = SQL_ERROR;
    }

    LEAVE_STMT(hstmt);
}

SQLRETURN SQL_API
SQLPrepareW (SQLHSTMT hstmt,
             SQLWCHAR * szSqlStr,
             SQLINTEGER cbSqlStr)
{
    USER_CONTEXT enforcerContext;
    std::string sql;
    SqlException exc;

    if(szSqlStr){
        emw_string sql_w = char_convert(szSqlStr, cbSqlStr);
        CommonFun::ToUTF8(sql_w,sql);
        //printf("wchar_t to sql:%s\n",sql.c_str());
    }

    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLPrepareW");

    if (EnforcerDataMgr::Instance().get_enforcer_context_by_stmt_handle(hstmt, enforcerContext))
    {
        sql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, sql.c_str(), &exc);
    }
    if(!exc.IsBreak()){
        emw_string sql_w;
        CommonFun::FromUTF8( sql, sql_w);
        if(cbSqlStr != SQL_NTS) cbSqlStr = (SQLINTEGER)sql_w.length();
        ret_code = ODBCMgrApi::Instance().SQLPrepareW ( hstmt, (SQLWCHAR*)sql_w.c_str(), cbSqlStr) ;
    }else{
        ret_code = SQL_ERROR;
        EnforcerDataMgr::Instance().push_error(SQL_HANDLE_STMT, hstmt, &exc);
    }
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLPrimaryKeys (SQLHSTMT hstmt,
                SQLCHAR * szTableQualifier,
                SQLSMALLINT cbTableQualifier,
                SQLCHAR * szTableOwner,
                SQLSMALLINT cbTableOwner,
                SQLCHAR * szTableName,
                SQLSMALLINT cbTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLPrimaryKeys");
    ret_code = ODBCMgrApi::Instance().SQLPrimaryKeys (hstmt,
                                                      szTableQualifier,
                                                      cbTableQualifier,
                                                      szTableOwner,
                                                      cbTableOwner,
                                                      szTableName,
                                                      cbTableName) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLPrimaryKeysA (SQLHSTMT hstmt,
                 SQLCHAR * szTableQualifier,
                 SQLSMALLINT cbTableQualifier,
                 SQLCHAR * szTableOwner,
                 SQLSMALLINT cbTableOwner,
                 SQLCHAR * szTableName,
                 SQLSMALLINT cbTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLPrimaryKeysA");
    ret_code = ODBCMgrApi::Instance().SQLPrimaryKeysA (hstmt,
                                                       szTableQualifier,
                                                       cbTableQualifier,
                                                       szTableOwner,
                                                       cbTableOwner,
                                                       szTableName,
                                                       cbTableName) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLPrimaryKeysW (SQLHSTMT hstmt,
                 SQLWCHAR * szTableQualifier,
                 SQLSMALLINT cbTableQualifier,
                 SQLWCHAR * szTableOwner,
                 SQLSMALLINT cbTableOwner,
                 SQLWCHAR * szTableName,
                 SQLSMALLINT cbTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLPrimaryKeysW");
    ret_code = ODBCMgrApi::Instance().SQLPrimaryKeysW (hstmt,
                                                       szTableQualifier,
                                                       cbTableQualifier,
                                                       szTableOwner,
                                                       cbTableOwner,
                                                       szTableName,
                                                       cbTableName) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLProcedureColumns (SQLHSTMT hstmt,
                     SQLCHAR * szProcQualifier,
                     SQLSMALLINT cbProcQualifier,
                     SQLCHAR * szProcOwner,
                     SQLSMALLINT cbProcOwner,
                     SQLCHAR * szProcName,
                     SQLSMALLINT cbProcName,
                     SQLCHAR * szColumnName,
                     SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLProcedureColumns");
    ret_code = ODBCMgrApi::Instance().SQLProcedureColumns ( hstmt,
                                                            szProcQualifier,
                                                            cbProcQualifier,
                                                            szProcOwner,
                                                            cbProcOwner,
                                                            szProcName,
                                                            cbProcName,
                                                            szColumnName,
                                                            cbColumnName) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLProcedureColumnsA (SQLHSTMT hstmt,
                      SQLCHAR * szProcQualifier,
                      SQLSMALLINT cbProcQualifier,
                      SQLCHAR * szProcOwner,
                      SQLSMALLINT cbProcOwner,
                      SQLCHAR * szProcName,
                      SQLSMALLINT cbProcName,
                      SQLCHAR * szColumnName,
                      SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLProcedureColumnsA");
    ret_code = ODBCMgrApi::Instance().SQLProcedureColumnsA ( hstmt,
                                                             szProcQualifier,
                                                             cbProcQualifier,
                                                             szProcOwner,
                                                             cbProcOwner,
                                                             szProcName,
                                                             cbProcName,
                                                             szColumnName,
                                                             cbColumnName) ;
    LEAVE_STMT(hstmt);
}

SQLRETURN SQL_API
SQLProcedureColumnsW (SQLHSTMT hstmt,
                      SQLWCHAR * szProcQualifier,
                      SQLSMALLINT cbProcQualifier,
                      SQLWCHAR * szProcOwner,
                      SQLSMALLINT cbProcOwner,
                      SQLWCHAR * szProcName,
                      SQLSMALLINT cbProcName,
                      SQLWCHAR * szColumnName,
                      SQLSMALLINT cbColumnName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLProcedureColumnsW");
    ret_code = ODBCMgrApi::Instance().SQLProcedureColumnsW ( hstmt,
                                                             szProcQualifier,
                                                             cbProcQualifier,
                                                             szProcOwner,
                                                             cbProcOwner,
                                                             szProcName,
                                                             cbProcName,
                                                             szColumnName,
                                                             cbColumnName);
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLProcedures (SQLHSTMT hstmt,
               SQLCHAR * szProcQualifier,
               SQLSMALLINT cbProcQualifier,
               SQLCHAR * szProcOwner,
               SQLSMALLINT cbProcOwner,
               SQLCHAR * szProcName,
               SQLSMALLINT cbProcName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLProcedures");
    ret_code = ODBCMgrApi::Instance().SQLProcedures (hstmt,
                                                     szProcQualifier,
                                                     cbProcQualifier,
                                                     szProcOwner,
                                                     cbProcOwner,
                                                     szProcName,
                                                     cbProcName);
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLProceduresA (SQLHSTMT hstmt,
                SQLCHAR * szProcQualifier,
                SQLSMALLINT cbProcQualifier,
                SQLCHAR * szProcOwner,
                SQLSMALLINT cbProcOwner,
                SQLCHAR * szProcName,
                SQLSMALLINT cbProcName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLProceduresA");
    ret_code = ODBCMgrApi::Instance().SQLProceduresA ( hstmt,
                                                       szProcQualifier,
                                                       cbProcQualifier,
                                                       szProcOwner,
                                                       cbProcOwner,
                                                       szProcName,
                                                       cbProcName);
    LEAVE_STMT(hstmt);
}
//80



SQLRETURN SQL_API
SQLProceduresW (SQLHSTMT hstmt,
                SQLWCHAR * szProcQualifier,
                SQLSMALLINT cbProcQualifier,
                SQLWCHAR * szProcOwner,
                SQLSMALLINT cbProcOwner,
                SQLWCHAR * szProcName,
                SQLSMALLINT cbProcName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLProceduresW");
    ret_code = ODBCMgrApi::Instance().SQLProceduresW ( hstmt,
                                                       szProcQualifier,
                                                       cbProcQualifier,
                                                       szProcOwner,
                                                       cbProcOwner,
                                                       szProcName,
                                                       cbProcName) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLPutData (
        SQLHSTMT		  hstmt,
        SQLPOINTER		  rgbValue,
        SQLLEN		  cbValue)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLPutData");
    ret_code = ODBCMgrApi::Instance().SQLPutData (
            hstmt,
            rgbValue,
            cbValue);
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLRowCount (
        SQLHSTMT		  hstmt,
        SQLLEN 		* pcrow)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLRowCount");
    ret_code = ODBCMgrApi::Instance().SQLRowCount (
            hstmt,
            pcrow) ;
    LEAVE_STMT(hstmt);
}
//
RETCODE SQL_API
SQLSetConnectAttr (
        SQLHDBC		  connectionHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  StringLength)
{
    ENTER_HDBC(connectionHandle, 0);
    DAELogger::Trace("Enter SQLSetConnectAttr");
    ret_code = ODBCMgrApi::Instance().SQLSetConnectAttr (
            connectionHandle,
            Attribute,
            ValuePtr,
            StringLength);
    LEAVE_HDBC(connectionHandle, 0);
}
RETCODE SQL_API
SQLSetConnectAttrA (
        SQLHDBC		  connectionHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  StringLength)
{
    ENTER_HDBC(connectionHandle, 0);
    DAELogger::Trace("Enter SQLSetConnectAttrA");
    ret_code = ODBCMgrApi::Instance().SQLSetConnectAttrA (
            connectionHandle,
            Attribute,
            ValuePtr,
            StringLength);
    LEAVE_HDBC(connectionHandle, 0);
}
RETCODE SQL_API
SQLSetConnectAttrW (
        SQLHDBC		  connectionHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  StringLength)
{
    ENTER_HDBC(connectionHandle, 0);
    DAELogger::Trace("Enter SQLSetConnectAttrW");
    ret_code = ODBCMgrApi::Instance().SQLSetConnectAttrW (
            connectionHandle,
            Attribute,
            ValuePtr,
            StringLength);
    LEAVE_HDBC(connectionHandle, 0);
}
//
SQLRETURN SQL_API
SQLSetConnectOption (
        SQLHDBC		  hdbc,
        SQLUSMALLINT		  fOption,
        SQLULEN		  vParam)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLSetConnectOption ");
    ret_code = ODBCMgrApi::Instance().SQLSetConnectOption (
            hdbc,
            fOption,
            vParam);
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API
SQLSetConnectOptionA (
        SQLHDBC		  hdbc,
        SQLUSMALLINT		  fOption,
        SQLULEN		  vParam)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLSetConnectOptionA");
    ret_code = ODBCMgrApi::Instance().SQLSetConnectOptionA (
            hdbc,
            fOption,
            vParam);
    LEAVE_HDBC(hdbc, 0);
}
SQLRETURN SQL_API
SQLSetConnectOptionW (
        SQLHDBC		  hdbc,
        SQLUSMALLINT		  fOption,
        SQLULEN		  vParam)
{
    ENTER_HDBC(hdbc, 0);
    DAELogger::Trace("Enter SQLSetConnectOptionW");
    ret_code = ODBCMgrApi::Instance().SQLSetConnectOptionW ( hdbc, fOption, vParam);
    LEAVE_HDBC(hdbc, 0);
}
//
SQLRETURN SQL_API
SQLSetCursorName (
        SQLHSTMT		  hstmt,
        SQLCHAR		* szCursor,
        SQLSMALLINT		  cbCursor)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSetCursorName");
    ret_code = ODBCMgrApi::Instance().SQLSetCursorName (
            hstmt,
            szCursor,
            cbCursor) ;
    LEAVE_STMT(hstmt);
}

//90




SQLRETURN SQL_API
SQLSetCursorNameA (
        SQLHSTMT		  hstmt,
        SQLCHAR		* szCursor,
        SQLSMALLINT		  cbCursor)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSetCursorNameA");
    ret_code = ODBCMgrApi::Instance().SQLSetCursorNameA (
            hstmt,
            szCursor,
            cbCursor) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLSetCursorNameW (
        SQLHSTMT		  hstmt,
        SQLWCHAR		* szCursor,
        SQLSMALLINT		  cbCursor)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSetCursorNameW");
    ret_code = ODBCMgrApi::Instance().SQLSetCursorNameW (
            hstmt,
            szCursor,
            cbCursor) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLSetParam (
        SQLHSTMT		  hstmt,
        SQLUSMALLINT		  ipar,
        SQLSMALLINT		  fCType,
        SQLSMALLINT		  fSqlType,
        SQLULEN		  cbColDef,
        SQLSMALLINT		  ibScale,
        SQLPOINTER		  rgbValue,
        SQLLEN 		* pcbValue)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSetParam");
    ret_code = ODBCMgrApi::Instance().SQLSetParam ( hstmt,
                                                    ipar,
                                                    fCType,
                                                    fSqlType,
                                                    cbColDef,
                                                    ibScale,
                                                    rgbValue,
                                                    pcbValue) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLSetPos (
        SQLHSTMT		  hstmt,
        SQLSETPOSIROW		  irow,
        SQLUSMALLINT		  fOption,
        SQLUSMALLINT		  fLock)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSetPos");
    ret_code = ODBCMgrApi::Instance().SQLSetPos ( hstmt, irow, fOption, fLock) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLSetScrollOptions (
        SQLHSTMT		  hstmt,
        SQLUSMALLINT		  fConcurrency,
        SQLLEN		  crowKeyset,
        SQLUSMALLINT		  crowRowset)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSetScrollOptions");
    ret_code = ODBCMgrApi::Instance().SQLSetScrollOptions (hstmt, fConcurrency, crowKeyset, crowRowset);
    LEAVE_STMT(hstmt);
}
//
RETCODE SQL_API
SQLSetStmtAttr (
        SQLHSTMT 		  statementHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  StringLength)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLSetStmtAttr");
    ret_code = ODBCMgrApi::Instance().SQLSetStmtAttr ( statementHandle, Attribute, ValuePtr, StringLength) ;
    LEAVE_STMT(statementHandle);
}
RETCODE SQL_API
SQLSetStmtAttrA (
        SQLHSTMT 		  statementHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  StringLength)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLSetStmtAttrA");
    ret_code = ODBCMgrApi::Instance().SQLSetStmtAttrA ( statementHandle, Attribute, ValuePtr, StringLength) ;
    LEAVE_STMT(statementHandle);
}
RETCODE SQL_API
SQLSetStmtAttrW (
        SQLHSTMT 		  statementHandle,
        SQLINTEGER		  Attribute,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  StringLength)
{
    ENTER_STMT(statementHandle);
    DAELogger::Trace("Enter SQLSetStmtAttrW");
    ret_code = ODBCMgrApi::Instance().SQLSetStmtAttrW ( statementHandle, Attribute, ValuePtr, StringLength) ;
    LEAVE_STMT(statementHandle);
}
//
SQLRETURN SQL_API
SQLSetStmtOption (
        SQLHSTMT		  hstmt,
        SQLUSMALLINT		  fOption,
        SQLULEN		  vParam)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSetStmtOption");
    ret_code = ODBCMgrApi::Instance().SQLSetStmtOption ( hstmt, fOption, vParam) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLSpecialColumns (SQLHSTMT hstmt,
                   SQLUSMALLINT fColType,
                   SQLCHAR * szTableQualifier,
                   SQLSMALLINT cbTableQualifier,
                   SQLCHAR * szTableOwner,
                   SQLSMALLINT cbTableOwner,
                   SQLCHAR * szTableName,
                   SQLSMALLINT cbTableName,
                   SQLUSMALLINT fScope,
                   SQLUSMALLINT fNullable)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSpecialColumns");
    ret_code = ODBCMgrApi::Instance().SQLSpecialColumns ( hstmt,
                                                          fColType,
                                                          szTableQualifier,
                                                          cbTableQualifier,
                                                          szTableOwner,
                                                          cbTableOwner,
                                                          szTableName,
                                                          cbTableName,
                                                          fScope,
                                                          fNullable);
    LEAVE_STMT(hstmt);
}

//100



SQLRETURN SQL_API
SQLSpecialColumnsA (SQLHSTMT hstmt,
                    SQLUSMALLINT fColType,
                    SQLCHAR * szTableQualifier,
                    SQLSMALLINT cbTableQualifier,
                    SQLCHAR * szTableOwner,
                    SQLSMALLINT cbTableOwner,
                    SQLCHAR * szTableName,
                    SQLSMALLINT cbTableName,
                    SQLUSMALLINT fScope,
                    SQLUSMALLINT fNullable)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSpecialColumnsA");
    ret_code = ODBCMgrApi::Instance().SQLSpecialColumnsA ( hstmt,
                                                           fColType,
                                                           szTableQualifier,
                                                           cbTableQualifier,
                                                           szTableOwner,
                                                           cbTableOwner,
                                                           szTableName,
                                                           cbTableName,
                                                           fScope,
                                                           fNullable);
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLSpecialColumnsW (SQLHSTMT hstmt,
                    SQLUSMALLINT fColType,
                    SQLWCHAR * szTableQualifier,
                    SQLSMALLINT cbTableQualifier,
                    SQLWCHAR * szTableOwner,
                    SQLSMALLINT cbTableOwner,
                    SQLWCHAR * szTableName,
                    SQLSMALLINT cbTableName,
                    SQLUSMALLINT fScope,
                    SQLUSMALLINT fNullable)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLSpecialColumnsW");
    ret_code = ODBCMgrApi::Instance().SQLSpecialColumnsW ( hstmt,
                                                           fColType,
                                                           szTableQualifier,
                                                           cbTableQualifier,
                                                           szTableOwner,
                                                           cbTableOwner,
                                                           szTableName,
                                                           cbTableName,
                                                           fScope,
                                                           fNullable);
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLStatistics (SQLHSTMT hstmt,
               SQLCHAR * szTableQualifier,
               SQLSMALLINT cbTableQualifier,
               SQLCHAR * szTableOwner,
               SQLSMALLINT cbTableOwner,
               SQLCHAR * szTableName,
               SQLSMALLINT cbTableName,
               SQLUSMALLINT fUnique,
               SQLUSMALLINT fAccuracy)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter .SQLStatistics");
    ret_code = ODBCMgrApi::Instance().SQLStatistics ( hstmt,
                                                      szTableQualifier, cbTableQualifier,
                                                      szTableOwner, cbTableOwner, szTableName,
                                                      cbTableName, fUnique, fAccuracy) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLStatisticsA (SQLHSTMT hstmt,
                SQLCHAR * szTableQualifier,
                SQLSMALLINT cbTableQualifier,
                SQLCHAR * szTableOwner,
                SQLSMALLINT cbTableOwner,
                SQLCHAR * szTableName,
                SQLSMALLINT cbTableName,
                SQLUSMALLINT fUnique,
                SQLUSMALLINT fAccuracy)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter .SQLStatisticsA ");
    ret_code = ODBCMgrApi::Instance().SQLStatisticsA ( hstmt,
                                                       szTableQualifier, cbTableQualifier,
                                                       szTableOwner, cbTableOwner, szTableName,
                                                       cbTableName, fUnique, fAccuracy) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLStatisticsW (SQLHSTMT hstmt,
                SQLWCHAR * szTableQualifier,
                SQLSMALLINT cbTableQualifier,
                SQLWCHAR * szTableOwner,
                SQLSMALLINT cbTableOwner,
                SQLWCHAR * szTableName,
                SQLSMALLINT cbTableName,
                SQLUSMALLINT fUnique,
                SQLUSMALLINT fAccuracy)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter .SQLStatisticsW");
    ret_code = ODBCMgrApi::Instance().SQLStatisticsW ( hstmt,
                                                       szTableQualifier, cbTableQualifier,
                                                       szTableOwner, cbTableOwner, szTableName,
                                                       cbTableName, fUnique, fAccuracy) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLTablePrivileges (SQLHSTMT hstmt,
                    SQLCHAR * szTableQualifier,
                    SQLSMALLINT cbTableQualifier,
                    SQLCHAR * szTableOwner,
                    SQLSMALLINT cbTableOwner,
                    SQLCHAR * szTableName,
                    SQLSMALLINT cbTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter .SQLTablePrivileges");
    ret_code = ODBCMgrApi::Instance().SQLTablePrivileges ( hstmt,
                                                           szTableQualifier,
                                                           cbTableQualifier,
                                                           szTableOwner,
                                                           cbTableOwner,
                                                           szTableName,
                                                           cbTableName) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLTablePrivilegesA (SQLHSTMT hstmt,
                     SQLCHAR * szTableQualifier,
                     SQLSMALLINT cbTableQualifier,
                     SQLCHAR * szTableOwner,
                     SQLSMALLINT cbTableOwner,
                     SQLCHAR * szTableName,
                     SQLSMALLINT cbTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter .SQLTablePrivilegesA");
    ret_code = ODBCMgrApi::Instance().SQLTablePrivilegesA ( hstmt,
                                                            szTableQualifier,
                                                            cbTableQualifier,
                                                            szTableOwner,
                                                            cbTableOwner,
                                                            szTableName,
                                                            cbTableName) ;
    LEAVE_STMT(hstmt);
}

SQLRETURN SQL_API
SQLTablePrivilegesW (SQLHSTMT hstmt,
                     SQLWCHAR * szTableQualifier,
                     SQLSMALLINT cbTableQualifier,
                     SQLWCHAR * szTableOwner,
                     SQLSMALLINT cbTableOwner,
                     SQLWCHAR * szTableName,
                     SQLSMALLINT cbTableName)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter .SQLTablePrivilegesW");
    ret_code = ODBCMgrApi::Instance().SQLTablePrivilegesW ( hstmt,
                                                            szTableQualifier,
                                                            cbTableQualifier,
                                                            szTableOwner,
                                                            cbTableOwner,
                                                            szTableName,
                                                            cbTableName) ;
    LEAVE_STMT(hstmt);

}
//
SQLRETURN SQL_API
SQLTables (SQLHSTMT hstmt,
           SQLCHAR * szTableQualifier,
           SQLSMALLINT cbTableQualifier,
           SQLCHAR * szTableOwner,
           SQLSMALLINT cbTableOwner,
           SQLCHAR * szTableName,
           SQLSMALLINT cbTableName,
           SQLCHAR * szTableType,
           SQLSMALLINT cbTableType)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLTables");
    ret_code = ODBCMgrApi::Instance().SQLTables (hstmt,
                                                 szTableQualifier,
                                                 cbTableQualifier,
                                                 szTableOwner,
                                                 cbTableOwner,
                                                 szTableName,
                                                 cbTableName,
                                                 szTableType,
                                                 cbTableType) ;
    LEAVE_STMT(hstmt);
}
SQLRETURN SQL_API
SQLTablesA (SQLHSTMT hstmt,
            SQLCHAR * szTableQualifier,
            SQLSMALLINT cbTableQualifier,
            SQLCHAR * szTableOwner,
            SQLSMALLINT cbTableOwner,
            SQLCHAR * szTableName,
            SQLSMALLINT cbTableName,
            SQLCHAR * szTableType,
            SQLSMALLINT cbTableType)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter SQLTablesA");
    ret_code = ODBCMgrApi::Instance().SQLTablesA (hstmt,
                                                  szTableQualifier, cbTableQualifier, szTableOwner,
                                                  cbTableOwner, szTableName, cbTableName, szTableType, cbTableType);
    LEAVE_STMT(hstmt);
}
//110


SQLRETURN SQL_API
SQLTablesW (SQLHSTMT hstmt,
            SQLWCHAR * szTableQualifier,
            SQLSMALLINT cbTableQualifier,
            SQLWCHAR * szTableOwner,
            SQLSMALLINT cbTableOwner,
            SQLWCHAR * szTableName,
            SQLSMALLINT cbTableName,
            SQLWCHAR * szTableType,
            SQLSMALLINT cbTableType)
{
    ENTER_STMT(hstmt);
    DAELogger::Trace("Enter  SQLTablesW");
    ret_code = ODBCMgrApi::Instance().SQLTablesW ( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType) ;
    LEAVE_STMT(hstmt);
}
//
SQLRETURN SQL_API
SQLTransact (
        SQLHENV		  henv,
        SQLHDBC		  hdbc,
        SQLUSMALLINT		  fType)
{
    SQLRETURN retcode = SQL_SUCCESS;
    //ODBC_LOCK ();
    DAELogger::Trace("Enter  SQLTransact");
    retcode = ODBCMgrApi::Instance().SQLTransact (henv, hdbc, fType) ;
    //ODBC_UNLOCK ();
    return retcode;
}








//add by jeff 19-04-24
SQLRETURN SQL_API
SQLCancel (SQLHSTMT hstmt)
{
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLCancel");
    retcode = ODBCMgrApi::Instance().SQLCancel ( hstmt) ;
    return retcode;
}
RETCODE SQL_API
SQLCopyDesc (
        SQLHDESC		  SourceDescHandle,
        SQLHDESC		  TargetDescHandle)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLCopyDesc");
    retcode = ODBCMgrApi::Instance().SQLCopyDesc (SourceDescHandle, TargetDescHandle) ;
    return retcode;
}


SQLRETURN SQL_API
SQLDataSources (
        SQLHENV		  henv,
        SQLUSMALLINT		  fDir,
        SQLCHAR 		* szDSN,
        SQLSMALLINT		  cbDSNMax,
        SQLSMALLINT 		* pcbDSN,
        SQLCHAR 		* szDesc,
        SQLSMALLINT		  cbDescMax,
        SQLSMALLINT 		* pcbDesc)
{
    //ENTER_HENV
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLDataSources");
    retcode = ODBCMgrApi::Instance().SQLDataSources (		  henv,
                                                               fDir,
                                                               szDSN,
                                                               cbDSNMax,
                                                               pcbDSN,
                                                               szDesc,
                                                               cbDescMax,
                                                               pcbDesc);
    return retcode;
}
SQLRETURN SQL_API
SQLDataSourcesA (
        SQLHENV		  henv,
        SQLUSMALLINT		  fDir,
        SQLCHAR 		* szDSN,
        SQLSMALLINT		  cbDSNMax,
        SQLSMALLINT 		* pcbDSN,
        SQLCHAR 		* szDesc,
        SQLSMALLINT		  cbDescMax,
        SQLSMALLINT		* pcbDesc)
{
    //ENTER_HENV
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLDataSourcesA");
    retcode = ODBCMgrApi::Instance().SQLDataSourcesA (henv,
                                                      fDir,
                                                      szDSN,
                                                      cbDSNMax,
                                                      pcbDSN,
                                                      szDesc,
                                                      cbDescMax,
                                                      pcbDesc) ;
    return retcode;
}
SQLRETURN SQL_API
SQLDataSourcesW (
        SQLHENV		  henv,
        SQLUSMALLINT		  fDir,
        SQLWCHAR 		* szDSN,
        SQLSMALLINT		  cbDSNMax,
        SQLSMALLINT 		* pcbDSN,
        SQLWCHAR 		* szDesc,
        SQLSMALLINT		  cbDescMax,
        SQLSMALLINT 		* pcbDesc)
{
    // SQLCHAR *_DSN = NULL;
    // SQLCHAR *_Desc = NULL;

    // ENTER_HENV
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLDataSourcesW");
    retcode = ODBCMgrApi::Instance().SQLDataSourcesW (henv, fDir,szDSN,  cbDSNMax, pcbDSN,szDesc, cbDescMax, pcbDesc) ;
    return retcode;
}

SQLRETURN SQL_API
SQLDrivers (
        SQLHENV		  henv,
        SQLUSMALLINT		  fDir,
        SQLCHAR 		* szDrvDesc,
        SQLSMALLINT		  cbDrvDescMax,
        SQLSMALLINT 		* pcbDrvDesc,
        SQLCHAR 		* szDrvAttr,
        SQLSMALLINT		  cbDrvAttrMax,
        SQLSMALLINT 		* pcbDrvAttr)
{
    //ENTER_HENV
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLDrivers");
    retcode = ODBCMgrApi::Instance().SQLDrivers (henv,  fDir,szDrvDesc, cbDrvDescMax, pcbDrvDesc, szDrvAttr, cbDrvAttrMax, pcbDrvAttr);
    return retcode;
}


SQLRETURN SQL_API
SQLDriversA (
        SQLHENV		  henv,
        SQLUSMALLINT		  fDir,
        SQLCHAR  		* szDrvDesc,
        SQLSMALLINT		  cbDrvDescMax,
        SQLSMALLINT 	 	* pcbDrvDesc,
        SQLCHAR  		* szDrvAttr,
        SQLSMALLINT		  cbDrvAttrMax,
        SQLSMALLINT 	 	* pcbDrvAttr)
{
    //ENTER_HENV
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLDriversA");
    retcode = ODBCMgrApi::Instance().SQLDriversA (henv,  fDir,szDrvDesc, cbDrvDescMax, pcbDrvDesc, szDrvAttr, cbDrvAttrMax, pcbDrvAttr);
    return retcode;
}

SQLRETURN SQL_API
SQLDriversW (SQLHENV henv,
             SQLUSMALLINT 	  fDir,
             SQLWCHAR		* szDrvDesc,
             SQLSMALLINT		  cbDrvDescMax,
             SQLSMALLINT		* pcbDrvDesc,
             SQLWCHAR		* szDrvAttr,
             SQLSMALLINT		  cbDrvAttrMax,
             SQLSMALLINT		* pcbDrvAttr)
{
    // SQLCHAR *_Driver = NULL;
    // SQLCHAR *_Attrs = NULL;

    // ENTER_HENV
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLDriversW");
    retcode = ODBCMgrApi::Instance().SQLDriversW (henv, fDir,szDrvDesc, cbDrvDescMax, pcbDrvDesc, szDrvAttr, cbDrvAttrMax, pcbDrvAttr) ;
    return retcode;
}







SQLRETURN SQL_API
SQLFreeEnv (SQLHENV henv)
{
    SQLRETURN retcode = SQL_SUCCESS;
    ODBC_LOCK ();
    DAELogger::Trace("Enter  SQLFreeEnv");
    retcode = ODBCMgrApi::Instance().SQLFreeEnv (henv) ;
    if(SQL_SUCCEEDED(retcode)){
        EnforcerDataMgr::Instance().freehandle(SQL_HANDLE_ENV, henv);
    }
    ODBC_UNLOCK ();
    return retcode;
}




RETCODE SQL_API
SQLGetDescField (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  FieldIdentifier,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength,
        SQLINTEGER		* StringLengthPtr)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLGetDescField");
    retcode = ODBCMgrApi::Instance().SQLGetDescField (descriptorHandle, RecNumber, FieldIdentifier, ValuePtr,  BufferLength, StringLengthPtr) ;
    return retcode;
}

RETCODE SQL_API
SQLGetDescFieldA (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  FieldIdentifier,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength,
        SQLINTEGER		* StringLengthPtr)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLGetDescFieldA");
    retcode = ODBCMgrApi::Instance().SQLGetDescFieldA (descriptorHandle, RecNumber,  FieldIdentifier, ValuePtr, BufferLength, StringLengthPtr) ;
    return retcode;
}

RETCODE SQL_API
SQLGetDescFieldW (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  FieldIdentifier,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength,
        SQLINTEGER		* StringLengthPtr)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLGetDescFieldW");
    retcode = ODBCMgrApi::Instance().SQLGetDescFieldW (descriptorHandle,  RecNumber, FieldIdentifier, ValuePtr, BufferLength, StringLengthPtr);
    return retcode;
}


RETCODE SQL_API
SQLGetDescRec (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLCHAR		* Name,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr,
        SQLSMALLINT		* TypePtr,
        SQLSMALLINT		* SubTypePtr,
        SQLLEN		* LengthPtr,
        SQLSMALLINT		* PrecisionPtr,
        SQLSMALLINT		* ScalePtr,
        SQLSMALLINT		* NullablePtr)
{
    // ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLGetDescRec");
    retcode = ODBCMgrApi::Instance().SQLGetDescRec (descriptorHandle,  RecNumber, Name, BufferLength, StringLengthPtr, TypePtr, SubTypePtr, LengthPtr, PrecisionPtr,
                                                    ScalePtr,
                                                    NullablePtr);
    return retcode;
}


RETCODE SQL_API
SQLGetDescRecA (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLCHAR		* Name,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr,
        SQLSMALLINT		* TypePtr,
        SQLSMALLINT		* SubTypePtr,
        SQLLEN		* LengthPtr,
        SQLSMALLINT		* PrecisionPtr,
        SQLSMALLINT		* ScalePtr,
        SQLSMALLINT		* NullablePtr)
{
    // ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLGetDescRecA");
    retcode = ODBCMgrApi::Instance().SQLGetDescRecA (descriptorHandle, RecNumber, Name,  BufferLength, StringLengthPtr,
                                                     TypePtr, SubTypePtr, LengthPtr, PrecisionPtr, ScalePtr, NullablePtr);
    return retcode;
}
RETCODE SQL_API
SQLGetDescRecW (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLWCHAR		* Name,
        SQLSMALLINT		  BufferLength,
        SQLSMALLINT		* StringLengthPtr,
        SQLSMALLINT		* TypePtr,
        SQLSMALLINT		* SubTypePtr,
        SQLLEN		* LengthPtr,
        SQLSMALLINT		* PrecisionPtr,
        SQLSMALLINT		* ScalePtr,
        SQLSMALLINT		* NullablePtr)
{
    // ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLGetDescRecW");
    retcode = ODBCMgrApi::Instance().SQLGetDescRecW (descriptorHandle, RecNumber, Name, BufferLength,
                                                     StringLengthPtr, TypePtr, SubTypePtr, LengthPtr, PrecisionPtr, ScalePtr, NullablePtr);
    return retcode;
}
RETCODE SQL_API
SQLSetDescField (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  FieldIdentifier,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLSetDescField");
    retcode = ODBCMgrApi::Instance().SQLSetDescField (descriptorHandle, RecNumber, FieldIdentifier, ValuePtr, BufferLength) ;
    return retcode;
}
RETCODE SQL_API
SQLSetDescFieldA (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  FieldIdentifier,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLSetDescFieldA");
    retcode = ODBCMgrApi::Instance().SQLSetDescFieldA (descriptorHandle,RecNumber, FieldIdentifier, ValuePtr,  BufferLength);
    return retcode;
}
RETCODE SQL_API
SQLSetDescFieldW (
        SQLHDESC		  descriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  FieldIdentifier,
        SQLPOINTER		  ValuePtr,
        SQLINTEGER		  BufferLength)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLSetDescFieldW");
    retcode = ODBCMgrApi::Instance().SQLSetDescFieldW (descriptorHandle, RecNumber, FieldIdentifier, ValuePtr,BufferLength);
    return retcode;
}

RETCODE SQL_API
SQLSetDescRec (
        SQLHDESC		  DescriptorHandle,
        SQLSMALLINT		  RecNumber,
        SQLSMALLINT		  Type,
        SQLSMALLINT		  SubType,
        SQLLEN		  Length,
        SQLSMALLINT		  Precision,
        SQLSMALLINT		  Scale,
        SQLPOINTER		  Data,
        SQLLEN		* StringLength,
        SQLLEN		* Indicator)
{
    //ENTER_DESC
    SQLRETURN retcode = SQL_SUCCESS;
    DAELogger::Trace("Enter  SQLSetDescRec");
    retcode = ODBCMgrApi::Instance().SQLSetDescRec (DescriptorHandle, RecNumber, Type,  SubType, Length,  Precision, Scale,  Data, StringLength, Indicator);
    return retcode;
}

//   RETCODE SQL_API
// SQLSetEnvAttr (
//   SQLHENV		  EnvironmentHandle,
//   SQLINTEGER		  Attribute,
//   SQLPOINTER		  ValuePtr,
//   SQLINTEGER		  StringLength)
// {
// //	ODBC_LOCK
// SQLRETURN retcode = SQL_SUCCESS;
//   DAELogger::Trace("Enter  SQLSetEnvAttr");
//   retcode = ODBCMgrApi::Instance().SQLSetEnvAttr (henv, hdbc, fType) ;
//   return retcode;
// }



#if defined __cplusplus  &&  !(defined WIN32)
}
#endif
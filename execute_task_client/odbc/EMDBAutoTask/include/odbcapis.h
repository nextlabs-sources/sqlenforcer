#ifndef ODBC_APIS_H
#define ODBC_APIS_H


#ifdef _WIN32
#include <windows.h>
#define GET_ODBC_PROC(funname) this->funname=(funname##Fun)::GetProcAddress((HMODULE)hODBCMgr, #funname);
#else
#include <dlfcn.h>
#include <sys/stat.h>
#define GET_ODBC_PROC(funname) this->funname=(funname##Fun)dlsym(hODBCMgr, #funname);
#endif

#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>

#define odbcapis_ori_ins odbcapis<0>::ins()
#define odbcapis_nxl_ins odbcapis<1>::ins()




typedef  RETCODE(SQL_API *SQLAllocHandleFun)(

	SQLSMALLINT HandleType,
	SQLHANDLE HandleParent,
	SQLHANDLE* NewHandlePointer);
typedef SQLRETURN(SQL_API *SQLSetEnvAttrFun)(
	SQLHENV EnvironmentHandle,
	SQLINTEGER Attribute,
	SQLPOINTER Value,
	SQLINTEGER StringLength);

typedef SQLRETURN(SQL_API *SQLDriverConnectFun)(
	SQLHDBC           hdbc,
	SQLHWND            hwnd,
	SQLCHAR           *szConnStrIn,
	SQLSMALLINT       cbConnStrIn,
	SQLCHAR          *szConnStrOut,
	SQLSMALLINT       cbConnStrOutMax,
	SQLSMALLINT 	  *pcbConnStrOut,
	SQLUSMALLINT       fDriverCompletion);

typedef SQLRETURN(SQL_API *SQLDriverConnectWFun)
(
	SQLHDBC             hdbc,
	SQLHWND             hwnd,
	SQLWCHAR* szConnStrIn,
	SQLSMALLINT         cchConnStrIn,
	SQLWCHAR* szConnStrOut,
	SQLSMALLINT         cchConnStrOutMax,
	SQLSMALLINT*        pcchConnStrOut,
	SQLUSMALLINT        fDriverCompletion);

typedef SQLRETURN(SQL_API *SQLDriverConnectAFun)(
	SQLHDBC            hdbc,
	SQLHWND            hwnd,
	SQLCHAR        *szConnStrIn,
	SQLSMALLINT        cbConnStrIn,
	SQLCHAR        *szConnStrOut,
	SQLSMALLINT        cbConnStrOutMax,
	SQLSMALLINT    *pcbConnStrOut,
	SQLUSMALLINT       fDriverCompletion);

typedef SQLRETURN(SQL_API *SQLExecDirectFun)(
	SQLHSTMT StatementHandle,
	SQLCHAR *StatementText,
	SQLINTEGER TextLength);

typedef SQLRETURN(SQL_API *SQLExecDirectAFun)(
	SQLHSTMT           hstmt,
	SQLCHAR           *szSqlStr,
	SQLINTEGER         cbSqlStr);

typedef SQLRETURN(SQL_API *SQLExecDirectWFun)(
	SQLHSTMT    hstmt,
	SQLWCHAR* szSqlStr,
	SQLINTEGER  TextLength);

typedef SQLRETURN(SQL_API *SQLNumResultColsFun)(SQLHSTMT StatementHandle,
	SQLSMALLINT *ColumnCount);

typedef SQLRETURN(SQL_API *SQLCloseCursorFun)(SQLHSTMT StatementHandle);

typedef SQLRETURN(SQL_API *SQLFreeStmtFun)(SQLHSTMT StatementHandle,
	SQLUSMALLINT Option);

typedef SQLRETURN(SQL_API *SQLBindColFun)(SQLHSTMT StatementHandle,
	SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
	SQLPOINTER TargetValue,
	SQLLEN BufferLength, SQLLEN *StrLen_or_Ind);



typedef SQLRETURN(SQL_API *SQLFetchFun)(SQLHSTMT StatementHandle);

typedef SQLRETURN(SQL_API *SQLGetDataFun)(
	SQLHSTMT       StatementHandle,
	SQLUSMALLINT   Col_or_Param_Num,
	SQLSMALLINT    TargetType,
	SQLPOINTER     TargetValuePtr,
	SQLLEN         BufferLength,
	SQLLEN *       StrLen_or_IndPtr);

typedef SQLRETURN(SQL_API *SQLGetDiagRecFun)
(
	SQLSMALLINT     fHandleType,
	SQLHANDLE       handle,
	SQLSMALLINT     iRecord,
	SQLCHAR* szSqlState,
	SQLINTEGER*     pfNativeError,
	SQLCHAR* szErrorMsg,
	SQLSMALLINT     cchErrorMsgMax,
	SQLSMALLINT*    pcchErrorMsg
	);

typedef SQLRETURN(SQL_API *SQLGetDiagRecAFun)
(
	SQLSMALLINT     fHandleType,
	SQLHANDLE       handle,
	SQLSMALLINT     iRecord,
	SQLCHAR* szSqlState,
	SQLINTEGER*     pfNativeError,
	SQLCHAR* szErrorMsg,
	SQLSMALLINT     cchErrorMsgMax,
	SQLSMALLINT*    pcchErrorMsg
	);

typedef SQLRETURN(SQL_API *SQLGetDiagRecWFun)
(
	SQLSMALLINT     fHandleType,
	SQLHANDLE       handle,
	SQLSMALLINT     iRecord,
	SQLWCHAR* szSqlState,
	SQLINTEGER*     pfNativeError,
	SQLWCHAR* szErrorMsg,
	SQLSMALLINT     cchErrorMsgMax,
	SQLSMALLINT*    pcchErrorMsg
	);
typedef SQLRETURN(SQL_API *SQLConnectFun)(
	SQLHDBC ConnectionHandle,
	SQLCHAR *ServerName,
	SQLSMALLINT NameLength1,
	SQLCHAR *UserName,
	SQLSMALLINT NameLength2,
	SQLCHAR *Authentication,
	SQLSMALLINT NameLength3);
typedef SQLRETURN(SQL_API *SQLConnectAFun)(
	SQLHDBC         hdbc,
	SQLCHAR         *szDSN,
	SQLSMALLINT     cbDSN,
	SQLCHAR         *szUID,
	SQLSMALLINT     cbUID,
	SQLCHAR         *szAuthStr,
	SQLSMALLINT     cbAuthStr);
typedef SQLRETURN(SQL_API *SQLConnectWFun)(
	SQLHDBC            hdbc,
	SQLWCHAR        *szDSN,
	SQLSMALLINT        cbDSN,
	SQLWCHAR        *szUID,
	SQLSMALLINT        cbUID,
	SQLWCHAR        *szAuthStr,
	SQLSMALLINT        cbAuthStr);
typedef SQLRETURN(SQL_API *SQLBrowseConnectFun)(
	SQLHDBC            hdbc,
	SQLCHAR 		  *szConnStrIn,
	SQLSMALLINT        cbConnStrIn,
	SQLCHAR 		  *szConnStrOut,
	SQLSMALLINT        cbConnStrOutMax,
	SQLSMALLINT       *pcbConnStrOut);
typedef SQLRETURN(SQL_API *SQLBrowseConnectAFun)(
	SQLHDBC            hdbc,
	SQLCHAR        *szConnStrIn,
	SQLSMALLINT        cbConnStrIn,
	SQLCHAR        *szConnStrOut,
	SQLSMALLINT        cbConnStrOutMax,
	SQLSMALLINT    *pcbConnStrOut);
typedef SQLRETURN(SQL_API *SQLBrowseConnectWFun)(
	SQLHDBC            hdbc,
	SQLWCHAR        *szConnStrIn,
	SQLSMALLINT        cbConnStrIn,
	SQLWCHAR        *szConnStrOut,
	SQLSMALLINT        cbConnStrOutMax,
	SQLSMALLINT    *pcbConnStrOut);
typedef SQLRETURN(SQL_API *SQLFreeHandleFun)(
	SQLSMALLINT       HandleType,
	SQLHANDLE         Handle);
typedef SQLRETURN(SQL_API *SQLDisconnectFun)(
	SQLHDBC           ConnectionHandle);
typedef SQLRETURN(SQL_API *SQLGetInfoFun)(
	SQLHDBC ConnectionHandle,
	SQLUSMALLINT InfoType,
	SQLPOINTER InfoValue,
	SQLSMALLINT BufferLength,
	SQLSMALLINT *StringLength);

typedef SQLRETURN(SQL_API *SQLCancelHandleFun)(
	SQLSMALLINT  HandleType,
	SQLHANDLE    Handle);
typedef SQLRETURN(SQL_API *SQLCompleteAsyncFun)(
	SQLSMALLINT  HandleType,
	SQLHANDLE    Handle,
	RETCODE *   AsyncRetCodePtr);

typedef SQLRETURN(SQL_API * SQLGetInfoAFun)(SQLHDBC ConnectionHandle,
	SQLUSMALLINT		  InfoType,
	SQLPOINTER		  InfoValue,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT 		* StringLength);
typedef SQLRETURN(SQL_API * SQLGetInfoWFun)(SQLHDBC ConnectionHandle,
	SQLUSMALLINT		  InfoType,
	SQLPOINTER		  InfoValue,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT 		* StringLength);


//add by jeff 19-04-18
typedef SQLRETURN(SQL_API *SQLAllocConnectFun)(
	SQLHENV henv,
	SQLHDBC * phdbc);
typedef SQLRETURN(SQL_API *SQLAllocEnvFun)(
	SQLHENV * phenv);
typedef SQLRETURN(SQL_API *SQLAllocHandleStdFun)(
	SQLSMALLINT handleType,
	SQLHANDLE inputHandle,
	SQLHANDLE * outputHandlePtr);
typedef SQLRETURN(SQL_API *SQLAllocStmtFun)(
	SQLHDBC hdbc,
	SQLHSTMT * phstmt);
// typedef SQLRETURN(SQL_API *SQLBindColFun )(
//     SQLHSTMT hstmt,
//     SQLUSMALLINT icol,
//     SQLSMALLINT fCType,
//     SQLPOINTER rgbValue,
//     SQLLEN cbValueMax,
//     SQLLEN *pcbValue);
typedef SQLRETURN(SQL_API * SQLBindParamFun)(
	SQLHSTMT hstmt,
	SQLUSMALLINT ipar,
	SQLSMALLINT fCType,
	SQLSMALLINT fSqlType,
	SQLULEN cbParamDef,
	SQLSMALLINT ibScale,
	SQLPOINTER rgbValue,
	SQLLEN *pcbValue);
typedef SQLRETURN(SQL_API * SQLBindParameterFun)(
	SQLHSTMT		  hstmt,
	SQLUSMALLINT	  ipar,
	SQLSMALLINT		  fParamType,
	SQLSMALLINT		  fCType,
	SQLSMALLINT		  fSqlType,
	SQLULEN		  cbColDef,
	SQLSMALLINT		  ibScale,
	SQLPOINTER		  rgbValue,
	SQLLEN		  cbValueMax,
	SQLLEN		* pcbValue);
typedef SQLRETURN(SQL_API * SQLBulkOperationsFun)(
	SQLHSTMT		  StatementHandle,
	SQLSMALLINT 		  Operation);
typedef SQLRETURN(SQL_API * SQLCancelFun)(SQLHSTMT hstmt);
//typedef SQLRETURN(SQL_API * SQLCloseCursorFun )(SQLHSTMT hstmt);







typedef SQLRETURN(SQL_API * SQLColAttributeFun )(
	SQLHSTMT		  statementHandle,
	SQLUSMALLINT		  ColumnNumber,
	SQLUSMALLINT		  FieldIdentifier,
	SQLPOINTER		  CharacterAttributePtr,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT		* StringLengthPtr,
	SQLLEN		* NumericAttributePtr);
typedef SQLRETURN(SQL_API * SQLColAttributeAFun)(
	SQLHSTMT		  statementHandle,
	SQLUSMALLINT		  ColumnNumber,
	SQLUSMALLINT		  FieldIdentifier,
	SQLPOINTER		  CharacterAttributePtr,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT		* StringLengthPtr,
	SQLLEN		* NumericAttributePtr);
typedef SQLRETURN(SQL_API * SQLColAttributeWFun )(
	SQLHSTMT		  statementHandle,
	SQLUSMALLINT		  ColumnNumber,
	SQLUSMALLINT		  FieldIdentifier,
	SQLPOINTER		  CharacterAttributePtr,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT		* StringLengthPtr,
	SQLLEN		* NumericAttributePtr);
typedef SQLRETURN(SQL_API * SQLColAttributesFun)(
	SQLHSTMT 		  statementHandle,
	SQLUSMALLINT		  icol,
	SQLUSMALLINT		  fDescType,
	SQLPOINTER		  rgbDesc,
	SQLSMALLINT		  cbDescMax,
	SQLSMALLINT 		* pcbDesc,
	SQLLEN 		* pfDesc);
typedef SQLRETURN(SQL_API * SQLColAttributesAFun)(
	SQLHSTMT 		  statementHandle,
	SQLUSMALLINT		  icol,
	SQLUSMALLINT		  fDescType,
	SQLPOINTER		  rgbDesc,
	SQLSMALLINT		  cbDescMax,
	SQLSMALLINT 		* pcbDesc,
	SQLLEN 		* pfDesc);
typedef SQLRETURN(SQL_API * SQLColAttributesWFun)(
	SQLHSTMT 		  statementHandle,
	SQLUSMALLINT		  icol,
	SQLUSMALLINT		  fDescType,
	SQLPOINTER		  rgbDesc,
	SQLSMALLINT		  cbDescMax,
	SQLSMALLINT 		* pcbDesc,
	SQLLEN 		* pfDesc);
typedef SQLRETURN(SQL_API * SQLColumnPrivilegesFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLColumnPrivilegesAFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLColumnPrivilegesWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLWCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLWCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLWCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLColumnsFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLCHAR * szColumnName,
	SQLSMALLINT cbColumnName);






typedef SQLRETURN(SQL_API * SQLColumnsAFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLColumnsWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLWCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLWCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLWCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLDescribeColFun)(SQLHSTMT hstmt,
	SQLUSMALLINT	  icol,
	SQLCHAR		* szColName,
	SQLSMALLINT		  cbColNameMax,
	SQLSMALLINT		* pcbColName,
	SQLSMALLINT		* pfSqlType,
	SQLULEN		* pcbColDef,
	SQLSMALLINT		* pibScale,
	SQLSMALLINT		* pfNullable);
typedef SQLRETURN(SQL_API * SQLDescribeColAFun)(SQLHSTMT hstmt,
	SQLUSMALLINT	  icol,
	SQLCHAR		* szColName,
	SQLSMALLINT		  cbColNameMax,
	SQLSMALLINT		* pcbColName,
	SQLSMALLINT		* pfSqlType,
	SQLULEN		* pcbColDef,
	SQLSMALLINT		* pibScale,
	SQLSMALLINT		* pfNullable);
typedef SQLRETURN(SQL_API * SQLDescribeColWFun)(
	SQLHSTMT		  hstmt,
	SQLUSMALLINT		  icol,
	SQLWCHAR		* szColName,
	SQLSMALLINT		  cbColNameMax,
	SQLSMALLINT		* pcbColName,
	SQLSMALLINT		* pfSqlType,
	SQLULEN		* pcbColDef,
	SQLSMALLINT		* pibScale,
	SQLSMALLINT		* pfNullable);
typedef SQLRETURN(SQL_API * SQLDescribeParamFun)(
	SQLHSTMT		  hstmt,
	SQLUSMALLINT		  ipar,
	SQLSMALLINT 		* pfSqlType,
	SQLULEN 		* pcbColDef,
	SQLSMALLINT 		* pibScale,
	SQLSMALLINT 		* pfNullable);
typedef SQLRETURN(SQL_API * SQLEndTranFun)(
	SQLSMALLINT		  handleType,
	SQLHANDLE		  Handle,
	SQLSMALLINT		  completionType);
typedef SQLRETURN(SQL_API * SQLErrorFun)(
	SQLHENV		  henv,
	SQLHDBC		  hdbc,
	SQLHSTMT		  hstmt,
	SQLCHAR 		* szSqlstate,
	SQLINTEGER 		* pfNativeError,
	SQLCHAR 		* szErrorMsg,
	SQLSMALLINT		  cbErrorMsgMax,
	SQLSMALLINT 		* pcbErrorMsg);
typedef SQLRETURN(SQL_API * SQLErrorAFun)(
	SQLHENV		  henv,
	SQLHDBC		  hdbc,
	SQLHSTMT		  hstmt,
	SQLCHAR 		* szSqlstate,
	SQLINTEGER 		* pfNativeError,
	SQLCHAR 		* szErrorMsg,
	SQLSMALLINT		  cbErrorMsgMax,
	SQLSMALLINT 		* pcbErrorMsg);
typedef SQLRETURN(SQL_API * SQLErrorWFun)(
	SQLHENV		  henv,
	SQLHDBC		  hdbc,
	SQLHSTMT		  hstmt,
	SQLWCHAR 		* szSqlstate,
	SQLINTEGER 		* pfNativeError,
	SQLWCHAR 		* szErrorMsg,
	SQLSMALLINT		  cbErrorMsgMax,
	SQLSMALLINT 		* pcbErrorMsg);







typedef SQLRETURN(SQL_API * SQLExecuteFun)(SQLHSTMT hstmt);
typedef SQLRETURN(SQL_API * SQLExtendedFetchFun)(
	SQLHSTMT		  hstmt,
	SQLUSMALLINT		  fFetchType,
	SQLLEN		  irow,
	SQLULEN 		* pcrow,
	SQLUSMALLINT 		* rgfRowStatus);
//typedef SQLRETURN(SQL_API * SQLFetchFun ) (SQLHSTMT hstmt);
typedef SQLRETURN(SQL_API * SQLFetchScrollFun)(
	SQLHSTMT		  StatementHandle,
	SQLSMALLINT		  FetchOrientation,
	SQLLEN		  FetchOffset);
typedef SQLRETURN(SQL_API * SQLForeignKeysFun)(SQLHSTMT hstmt,
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
	SQLSMALLINT cbFkTableName);
typedef SQLRETURN(SQL_API * SQLForeignKeysAFun)(SQLHSTMT hstmt,
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
	SQLSMALLINT cbFkTableName);
typedef SQLRETURN(SQL_API * SQLForeignKeysWFun)(SQLHSTMT hstmt,
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
	SQLSMALLINT cbFkTableName);
typedef SQLRETURN(SQL_API * SQLFreeConnectFun)(SQLHDBC hdbc);
// typedef SQLRETURN(SQL_API * SQLFreeStmtFun )(
//     SQLHSTMT hstmt,
//     SQLUSMALLINT fOption);
typedef SQLRETURN(SQL_API * SQLGetConnectAttrFun)(
	SQLHDBC 		  connectionHandle,
	SQLINTEGER 		  Attribute,
	SQLPOINTER 		  ValuePtr,
	SQLINTEGER 		  StringLength,
	SQLINTEGER		* StringLengthPtr);






typedef SQLRETURN(SQL_API * SQLGetConnectAttrAFun)(
	SQLHDBC 		  connectionHandle,
	SQLINTEGER 		  Attribute,
	SQLPOINTER 		  ValuePtr,
	SQLINTEGER 		  StringLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API * SQLGetConnectAttrWFun)(
	SQLHDBC 		  connectionHandle,
	SQLINTEGER 		  Attribute,
	SQLPOINTER 		  ValuePtr,
	SQLINTEGER 		  StringLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API * SQLGetConnectOptionFun)(SQLHDBC hdbc,
	SQLUSMALLINT fOption,
	SQLPOINTER pvParam);
typedef SQLRETURN(SQL_API * SQLGetConnectOptionAFun)(SQLHDBC hdbc,
	SQLUSMALLINT fOption,
	SQLPOINTER pvParam);
typedef SQLRETURN(SQL_API * SQLGetConnectOptionWFun)(SQLHDBC hdbc,
	SQLUSMALLINT fOption,
	SQLPOINTER pvParam);
typedef SQLRETURN(SQL_API * SQLGetCursorNameFun)(
	SQLHSTMT 		  hstmt,
	SQLCHAR  		* szCursor,
	SQLSMALLINT 		  cbCursorMax,
	SQLSMALLINT 	 	* pcbCursor);
typedef SQLRETURN(SQL_API * SQLGetCursorNameAFun)(
	SQLHSTMT 		  hstmt,
	SQLCHAR  		* szCursor,
	SQLSMALLINT 		  cbCursorMax,
	SQLSMALLINT 	 	* pcbCursor);
typedef SQLRETURN(SQL_API * SQLGetCursorNameWFun)(
	SQLHSTMT 		  hstmt,
	SQLWCHAR  		* szCursor,
	SQLSMALLINT 		  cbCursorMax,
	SQLSMALLINT 	 	* pcbCursor);
// typedef SQLRETURN(SQL_API * SQLGetDataFun )(
//     SQLHSTMT		  hstmt,
//     SQLUSMALLINT	  icol,
//     SQLSMALLINT		  fCType,
//     SQLPOINTER		  rgbValue,
//     SQLLEN		  cbValueMax,
//     SQLLEN 		* pcbValue);
typedef SQLRETURN(SQL_API * SQLGetDiagFieldFun)(
	SQLSMALLINT		  HandleType,
	SQLHANDLE		  Handle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  DiagIdentifier,
	SQLPOINTER		  DiagInfoPtr,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT		* StringLengthPtr);





//50

typedef SQLRETURN(SQL_API * SQLGetDiagFieldAFun)(
	SQLSMALLINT		  HandleType,
	SQLHANDLE		  Handle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  DiagIdentifier,
	SQLPOINTER		  DiagInfoPtr,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT		* StringLengthPtr);
typedef SQLRETURN(SQL_API * SQLGetDiagFieldWFun)(
	SQLSMALLINT		  HandleType,
	SQLHANDLE		  Handle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  DiagIdentifier,
	SQLPOINTER		  DiagInfoPtr,
	SQLSMALLINT		  BufferLength,
	SQLSMALLINT		* StringLengthPtr);
typedef SQLRETURN(SQL_API * SQLGetEnvAttrFun)(
	SQLHENV		  EnvironmentHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API * SQLGetFunctionsFun)(
	SQLHDBC		  hdbc,
	SQLUSMALLINT		  fFunc,
	SQLUSMALLINT	 	* pfExists);
typedef SQLRETURN(SQL_API * SQLGetStmtAttrFun)(
	SQLHSTMT		  statementHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API * SQLGetStmtAttrAFun)(
	SQLHSTMT		  statementHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API * SQLGetStmtAttrWFun)(
	SQLHSTMT		  statementHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API *SQLGetStmtOptionFun)(
	SQLHSTMT hstmt,
	SQLUSMALLINT fOption,
	SQLPOINTER pvParam);
typedef SQLRETURN(SQL_API * SQLGetTypeInfoFun)(SQLHSTMT hstmt,
	SQLSMALLINT fSqlType);
typedef SQLRETURN(SQL_API * SQLGetTypeInfoAFun)(SQLHSTMT hstmt,
	SQLSMALLINT fSqlType);

//60






typedef SQLRETURN(SQL_API * SQLGetTypeInfoWFun)(SQLHSTMT hstmt,
	SQLSMALLINT fSqlType);
typedef SQLRETURN(SQL_API * SQLMoreResultsFun)(SQLHSTMT hstmt);
typedef SQLRETURN(SQL_API * SQLNativeSqlFun)(SQLHDBC hdbc,
	SQLCHAR * szSqlStrIn,
	SQLINTEGER cbSqlStrIn,
	SQLCHAR * szSqlStr,
	SQLINTEGER cbSqlStrMax,
	SQLINTEGER * pcbSqlStr);
typedef SQLRETURN(SQL_API * SQLNativeSqlAFun)(SQLHDBC hdbc,
	SQLCHAR * szSqlStrIn,
	SQLINTEGER cbSqlStrIn,
	SQLCHAR * szSqlStr,
	SQLINTEGER cbSqlStrMax,
	SQLINTEGER * pcbSqlStr);
typedef SQLRETURN(SQL_API * SQLNativeSqlWFun)(SQLHDBC hdbc,
	SQLWCHAR * szSqlStrIn,
	SQLINTEGER cbSqlStrIn,
	SQLWCHAR * szSqlStr,
	SQLINTEGER cbSqlStrMax,
	SQLINTEGER * pcbSqlStr);
typedef SQLRETURN(SQL_API * SQLNumParamsFun)(SQLHSTMT hstmt, SQLSMALLINT * pcpar);
// typedef SQLRETURN(SQL_API * SQLNumResultColsFun )(
//   SQLHSTMT		  hstmt,
//   SQLSMALLINT 		* pccol);
typedef SQLRETURN(SQL_API * SQLParamDataFun)(SQLHSTMT hstmt, SQLPOINTER * prgbValue);
typedef SQLRETURN(SQL_API * SQLParamOptionsFun)(
	SQLHSTMT		  hstmt,
	SQLULEN		  crow,
	SQLULEN 		* pirow);
typedef SQLRETURN(SQL_API * SQLPrepareFun)(SQLHSTMT hstmt,
	SQLCHAR * szSqlStr,
	SQLINTEGER cbSqlStr);




typedef SQLRETURN(SQL_API * SQLPrepareAFun)(SQLHSTMT hstmt,
	SQLCHAR * szSqlStr,
	SQLINTEGER cbSqlStr);
typedef SQLRETURN(SQL_API * SQLPrepareWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szSqlStr,
	SQLINTEGER cbSqlStr);
typedef SQLRETURN(SQL_API * SQLPrimaryKeysFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName);
typedef SQLRETURN(SQL_API * SQLPrimaryKeysAFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName);
typedef SQLRETURN(SQL_API * SQLPrimaryKeysWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLWCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLWCHAR * szTableName,
	SQLSMALLINT cbTableName);
typedef SQLRETURN(SQL_API * SQLProcedureColumnsFun)(SQLHSTMT hstmt,
	SQLCHAR * szProcQualifier,
	SQLSMALLINT cbProcQualifier,
	SQLCHAR * szProcOwner,
	SQLSMALLINT cbProcOwner,
	SQLCHAR * szProcName,
	SQLSMALLINT cbProcName,
	SQLCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLProcedureColumnsAFun)(SQLHSTMT hstmt,
	SQLCHAR * szProcQualifier,
	SQLSMALLINT cbProcQualifier,
	SQLCHAR * szProcOwner,
	SQLSMALLINT cbProcOwner,
	SQLCHAR * szProcName,
	SQLSMALLINT cbProcName,
	SQLCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLProcedureColumnsWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szProcQualifier,
	SQLSMALLINT cbProcQualifier,
	SQLWCHAR * szProcOwner,
	SQLSMALLINT cbProcOwner,
	SQLWCHAR * szProcName,
	SQLSMALLINT cbProcName,
	SQLWCHAR * szColumnName,
	SQLSMALLINT cbColumnName);
typedef SQLRETURN(SQL_API * SQLProceduresFun)(SQLHSTMT hstmt,
	SQLCHAR * szProcQualifier,
	SQLSMALLINT cbProcQualifier,
	SQLCHAR * szProcOwner,
	SQLSMALLINT cbProcOwner,
	SQLCHAR * szProcName,
	SQLSMALLINT cbProcName);
typedef SQLRETURN(SQL_API * SQLProceduresAFun)(SQLHSTMT hstmt,
	SQLCHAR * szProcQualifier,
	SQLSMALLINT cbProcQualifier,
	SQLCHAR * szProcOwner,
	SQLSMALLINT cbProcOwner,
	SQLCHAR * szProcName,
	SQLSMALLINT cbProcName);






typedef SQLRETURN(SQL_API * SQLProceduresWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szProcQualifier,
	SQLSMALLINT cbProcQualifier,
	SQLWCHAR * szProcOwner,
	SQLSMALLINT cbProcOwner,
	SQLWCHAR * szProcName,
	SQLSMALLINT cbProcName);
typedef SQLRETURN(SQL_API * SQLPutDataFun)(
	SQLHSTMT		  hstmt,
	SQLPOINTER		  rgbValue,
	SQLLEN		  cbValue);
typedef SQLRETURN(SQL_API * SQLRowCountFun)(
	SQLHSTMT		  hstmt,
	SQLLEN 		* pcrow);
typedef SQLRETURN(SQL_API * SQLSetConnectAttrFun)(
	SQLHDBC		  connectionHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  StringLength);
typedef SQLRETURN(SQL_API * SQLSetConnectAttrAFun)(
	SQLHDBC		  connectionHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  StringLength);
typedef SQLRETURN(SQL_API * SQLSetConnectAttrWFun)(
	SQLHDBC		  connectionHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  StringLength);
typedef SQLRETURN(SQL_API * SQLSetConnectOptionFun)(
	SQLHDBC		  hdbc,
	SQLUSMALLINT		  fOption,
	SQLULEN		  vParam);
typedef SQLRETURN(SQL_API * SQLSetConnectOptionAFun)(
	SQLHDBC		  hdbc,
	SQLUSMALLINT		  fOption,
	SQLULEN		  vParam);
typedef SQLRETURN(SQL_API * SQLSetConnectOptionWFun)(
	SQLHDBC		  hdbc,
	SQLUSMALLINT		  fOption,
	SQLULEN		  vParam);
typedef SQLRETURN(SQL_API * SQLSetCursorNameFun)(
	SQLHSTMT		  hstmt,
	SQLCHAR		* szCursor,
	SQLSMALLINT		  cbCursor);




typedef SQLRETURN(SQL_API * SQLSetCursorNameAFun)(
	SQLHSTMT		  hstmt,
	SQLCHAR		* szCursor,
	SQLSMALLINT		  cbCursor);
typedef SQLRETURN(SQL_API * SQLSetCursorNameWFun)(
	SQLHSTMT		  hstmt,
	SQLWCHAR		* szCursor,
	SQLSMALLINT		  cbCursor);
typedef SQLRETURN(SQL_API * SQLSetParamFun)(
	SQLHSTMT		  hstmt,
	SQLUSMALLINT		  ipar,
	SQLSMALLINT		  fCType,
	SQLSMALLINT		  fSqlType,
	SQLULEN		  cbColDef,
	SQLSMALLINT		  ibScale,
	SQLPOINTER		  rgbValue,
	SQLLEN 		* pcbValue);
typedef SQLRETURN(SQL_API * SQLSetPosFun)(
	SQLHSTMT		  hstmt,
	SQLSETPOSIROW		  irow,
	SQLUSMALLINT		  fOption,
	SQLUSMALLINT		  fLock);
typedef SQLRETURN(SQL_API * SQLSetScrollOptionsFun)(
	SQLHSTMT		  hstmt,
	SQLUSMALLINT		  fConcurrency,
	SQLLEN		  crowKeyset,
	SQLUSMALLINT		  crowRowset);
typedef SQLRETURN(SQL_API * SQLSetStmtAttrFun)(
	SQLHSTMT 		  statementHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  StringLength);
typedef SQLRETURN(SQL_API * SQLSetStmtAttrAFun)(
	SQLHSTMT 		  statementHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  StringLength);
typedef SQLRETURN(SQL_API * SQLSetStmtAttrWFun)(
	SQLHSTMT 		  statementHandle,
	SQLINTEGER		  Attribute,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  StringLength);
typedef SQLRETURN(SQL_API * SQLSetStmtOptionFun)(
	SQLHSTMT		  hstmt,
	SQLUSMALLINT		  fOption,
	SQLULEN		  vParam);
typedef SQLRETURN(SQL_API * SQLSpecialColumnsFun)(SQLHSTMT hstmt,
	SQLUSMALLINT fColType,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLUSMALLINT fScope,
	SQLUSMALLINT fNullable);




typedef SQLRETURN(SQL_API * SQLSpecialColumnsAFun)(SQLHSTMT hstmt,
	SQLUSMALLINT fColType,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLUSMALLINT fScope,
	SQLUSMALLINT fNullable);
typedef SQLRETURN(SQL_API * SQLSpecialColumnsWFun)(SQLHSTMT hstmt,
	SQLUSMALLINT fColType,
	SQLWCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLWCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLWCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLUSMALLINT fScope,
	SQLUSMALLINT fNullable);
typedef SQLRETURN(SQL_API * SQLStatisticsFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLUSMALLINT fUnique,
	SQLUSMALLINT fAccuracy);
typedef SQLRETURN(SQL_API * SQLStatisticsAFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLUSMALLINT fUnique,
	SQLUSMALLINT fAccuracy);
typedef SQLRETURN(SQL_API * SQLStatisticsWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLWCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLWCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLUSMALLINT fUnique,
	SQLUSMALLINT fAccuracy);
typedef SQLRETURN(SQL_API * SQLTablePrivilegesFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName);
typedef SQLRETURN(SQL_API * SQLTablePrivilegesAFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName);
typedef SQLRETURN(SQL_API * SQLTablePrivilegesWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLWCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLWCHAR * szTableName,
	SQLSMALLINT cbTableName);
typedef SQLRETURN(SQL_API * SQLTablesFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLCHAR * szTableType,
	SQLSMALLINT cbTableType);
typedef SQLRETURN(SQL_API * SQLTablesAFun)(SQLHSTMT hstmt,
	SQLCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLCHAR * szTableType,
	SQLSMALLINT cbTableType);



typedef SQLRETURN(SQL_API * SQLTablesWFun)(SQLHSTMT hstmt,
	SQLWCHAR * szTableQualifier,
	SQLSMALLINT cbTableQualifier,
	SQLWCHAR * szTableOwner,
	SQLSMALLINT cbTableOwner,
	SQLWCHAR * szTableName,
	SQLSMALLINT cbTableName,
	SQLWCHAR * szTableType,
	SQLSMALLINT cbTableType);
typedef SQLRETURN(SQL_API * SQLTransactFun)(
	SQLHENV		  henv,
	SQLHDBC		  hdbc,
	SQLUSMALLINT		  fType);









//add by jeff 19-04-24
// typedef SQLRETURN (SQL_API* 
// SQLCancelFun )(SQLHSTMT hstmt);
// typedef SQLRETURN (SQL_API* 
// SQLCancelFun )(SQLHSTMT hstmt);
typedef SQLRETURN(SQL_API*
	SQLCancelFun)(SQLHSTMT hstmt);
typedef SQLRETURN(SQL_API* SQLCopyDescFun) (
	SQLHDESC		  SourceDescHandle,
	SQLHDESC		  TargetDescHandle);
typedef SQLRETURN(SQL_API* SQLDataSourcesFun) (
	SQLHENV		  henv,
	SQLUSMALLINT		  fDir,
	SQLCHAR 		* szDSN,
	SQLSMALLINT		  cbDSNMax,
	SQLSMALLINT 		* pcbDSN,
	SQLCHAR 		* szDesc,
	SQLSMALLINT		  cbDescMax,
	SQLSMALLINT 		* pcbDesc);
typedef SQLRETURN(SQL_API* SQLDataSourcesAFun) (
	SQLHENV		  henv,
	SQLUSMALLINT		  fDir,
	SQLCHAR 		* szDSN,
	SQLSMALLINT		  cbDSNMax,
	SQLSMALLINT 		* pcbDSN,
	SQLCHAR 		* szDesc,
	SQLSMALLINT		  cbDescMax,
	SQLSMALLINT		* pcbDesc);
typedef SQLRETURN(SQL_API* SQLDataSourcesWFun) (
	SQLHENV		  henv,
	SQLUSMALLINT		  fDir,
	SQLWCHAR 		* szDSN,
	SQLSMALLINT		  cbDSNMax,
	SQLSMALLINT 		* pcbDSN,
	SQLWCHAR 		* szDesc,
	SQLSMALLINT		  cbDescMax,
	SQLSMALLINT 		* pcbDesc);
typedef SQLRETURN(SQL_API* SQLDriversFun) (
	SQLHENV		  henv,
	SQLUSMALLINT		  fDir,
	SQLCHAR 		* szDrvDesc,
	SQLSMALLINT		  cbDrvDescMax,
	SQLSMALLINT 		* pcbDrvDesc,
	SQLCHAR 		* szDrvAttr,
	SQLSMALLINT		  cbDrvAttrMax,
	SQLSMALLINT 		* pcbDrvAttr);
typedef SQLRETURN(SQL_API* SQLDriversAFun)(
	SQLHENV		  henv,
	SQLUSMALLINT		  fDir,
	SQLCHAR  		* szDrvDesc,
	SQLSMALLINT		  cbDrvDescMax,
	SQLSMALLINT 	 	* pcbDrvDesc,
	SQLCHAR  		* szDrvAttr,
	SQLSMALLINT		  cbDrvAttrMax,
	SQLSMALLINT 	 	* pcbDrvAttr);
typedef SQLRETURN(SQL_API* SQLDriversWFun) (SQLHENV henv,
	SQLUSMALLINT 	  fDir,
	SQLWCHAR		* szDrvDesc,
	SQLSMALLINT		  cbDrvDescMax,
	SQLSMALLINT		* pcbDrvDesc,
	SQLWCHAR		* szDrvAttr,
	SQLSMALLINT		  cbDrvAttrMax,
	SQLSMALLINT		* pcbDrvAttr);



typedef SQLRETURN(SQL_API*
	SQLFreeEnvFun) (SQLHENV henv);
// typedef SQLRETURN (SQL_API* 
// SQLCancelFun )(SQLHSTMT hstmt);
typedef SQLRETURN(SQL_API* SQLGetDescFieldFun) (
	SQLHDESC		  descriptorHandle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  FieldIdentifier,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API* SQLGetDescFieldAFun)(
	SQLHDESC		  descriptorHandle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  FieldIdentifier,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API* SQLGetDescFieldWFun) (
	SQLHDESC		  descriptorHandle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  FieldIdentifier,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength,
	SQLINTEGER		* StringLengthPtr);
typedef SQLRETURN(SQL_API* SQLGetDescRecFun)(
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
	SQLSMALLINT		* NullablePtr);
typedef SQLRETURN(SQL_API* SQLGetDescRecAFun) (
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
	SQLSMALLINT		* NullablePtr);
typedef SQLRETURN(SQL_API* SQLGetDescRecWFun)(
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
	SQLSMALLINT		* NullablePtr);
typedef SQLRETURN(SQL_API* SQLSetDescFieldFun) (
	SQLHDESC		  descriptorHandle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  FieldIdentifier,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength);
typedef SQLRETURN(SQL_API* SQLSetDescFieldAFun) (
	SQLHDESC		  descriptorHandle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  FieldIdentifier,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength);



typedef SQLRETURN(SQL_API* SQLSetDescFieldWFun)(
	SQLHDESC		  descriptorHandle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  FieldIdentifier,
	SQLPOINTER		  ValuePtr,
	SQLINTEGER		  BufferLength);
typedef SQLRETURN(SQL_API* SQLSetDescRecFun) (
	SQLHDESC		  DescriptorHandle,
	SQLSMALLINT		  RecNumber,
	SQLSMALLINT		  Type,
	SQLSMALLINT		  SubType,
	SQLLEN		  Length,
	SQLSMALLINT		  Precision,
	SQLSMALLINT		  Scale,
	SQLPOINTER		  Data,
	SQLLEN		* StringLength,
	SQLLEN		* Indicator);



template <int m>
struct odbcapis {
	static odbcapis& ins() {
		static odbcapis ins_;
		return ins_;
	}
	
	SQLAllocHandleFun  SQLAllocHandle;
	SQLSetEnvAttrFun   SQLSetEnvAttr;
	SQLDriverConnectFun SQLDriverConnect;
	SQLDriverConnectAFun SQLDriverConnectA;
	SQLDriverConnectWFun SQLDriverConnectW;
	SQLExecDirectFun SQLExecDirect;
	SQLExecDirectAFun SQLExecDirectA;
	SQLExecDirectWFun    SQLExecDirectW;
	SQLNumResultColsFun  SQLNumResultCols;
	SQLCloseCursorFun   SQLCloseCursor;
	SQLFreeStmtFun   SQLFreeStmt;
	SQLBindColFun  SQLBindCol;
	SQLFetchFun  SQLFetch;
	SQLGetDataFun SQLGetData;
	SQLGetDiagRecFun SQLGetDiagRec;
	SQLGetDiagRecAFun SQLGetDiagRecA;
	SQLGetDiagRecWFun SQLGetDiagRecW;
	SQLConnectFun SQLConnect;
	SQLConnectAFun SQLConnectA;
	SQLConnectWFun SQLConnectW;
	SQLBrowseConnectFun SQLBrowseConnect;
	SQLBrowseConnectAFun SQLBrowseConnectA;
	SQLBrowseConnectWFun SQLBrowseConnectW;
	SQLFreeHandleFun SQLFreeHandle;
	SQLDisconnectFun SQLDisconnect;
	SQLGetInfoFun SQLGetInfo;
	//add by jeff 19-04-18

	SQLCompleteAsyncFun SQLCompleteAsync;
	SQLCancelHandleFun SQLCancelHandle;
	SQLGetInfoAFun SQLGetInfoA;
	SQLGetInfoWFun SQLGetInfoW;
	//
	SQLAllocConnectFun SQLAllocConnect;
	SQLAllocEnvFun SQLAllocEnv;
	SQLAllocHandleStdFun SQLAllocHandleStd;
	SQLAllocStmtFun  SQLAllocStmt;
	//SQLBindColFun SQLBindCol;
	SQLBindParamFun SQLBindParam;
	SQLBindParameterFun SQLBindParameter;
	SQLBulkOperationsFun SQLBulkOperations;
	//Sqlcancel Sqlcancel;
	//SQLCloseCursor SQLCloseCursor;

	SQLColAttributeFun SQLColAttribute;
	SQLColAttributeAFun SQLColAttributeA;
	SQLColAttributeWFun SQLColAttributeW;
	SQLColAttributesFun SQLColAttributes;
	SQLColAttributesAFun SQLColAttributesA;
	SQLColAttributesWFun SQLColAttributesW;
	SQLColumnPrivilegesFun SQLColumnPrivileges;
	SQLColumnPrivilegesAFun SQLColumnPrivilegesA;
	SQLColumnPrivilegesWFun SQLColumnPrivilegesW;
	SQLColumnsFun SQLColumns;

	SQLColumnsAFun SQLColumnsA;
	SQLColumnsWFun SQLColumnsW;
	SQLDescribeColFun  SQLDescribeCol;
	SQLDescribeColAFun SQLDescribeColA;
	SQLDescribeColWFun SQLDescribeColW;
	SQLDescribeParamFun SQLDescribeParam;
	SQLEndTranFun SQLEndTran;
	SQLErrorFun SQLError;
	SQLErrorAFun SQLErrorA;
	SQLErrorWFun SQLErrorW;

	SQLExecuteFun SQLExecute;
	SQLExtendedFetchFun SQLExtendedFetch;
	//SQLFetchFun SQLFetch;
	SQLFetchScrollFun SQLFetchScroll;
	SQLForeignKeysFun SQLForeignKeys;
	SQLForeignKeysAFun SQLForeignKeysA;
	SQLForeignKeysWFun SQLForeignKeysW;
	SQLFreeConnectFun SQLFreeConnect;
	//SQLFreeStmtFun SQLFreeStmt;
	SQLGetConnectAttrFun SQLGetConnectAttr;

	SQLGetConnectAttrAFun SQLGetConnectAttrA;
	SQLGetConnectAttrWFun SQLGetConnectAttrW;
	SQLGetConnectOptionFun SQLGetConnectOption;
	SQLGetConnectOptionAFun SQLGetConnectOptionA;
	SQLGetConnectOptionWFun SQLGetConnectOptionW;
	SQLGetCursorNameFun SQLGetCursorName;
	SQLGetCursorNameAFun SQLGetCursorNameA;
	SQLGetCursorNameWFun SQLGetCursorNameW;
	//SQLGetDataFun SQLGetData;
	SQLGetDiagFieldFun SQLGetDiagField;

	SQLGetDiagFieldAFun SQLGetDiagFieldA;
	SQLGetDiagFieldWFun SQLGetDiagFieldW;
	SQLGetEnvAttrFun SQLGetEnvAttr;
	SQLGetFunctionsFun SQLGetFunctions;
	SQLGetStmtAttrFun SQLGetStmtAttr;
	SQLGetStmtAttrAFun SQLGetStmtAttrA;
	SQLGetStmtAttrWFun SQLGetStmtAttrW;
	SQLGetStmtOptionFun SQLGetStmtOption;
	SQLGetTypeInfoFun SQLGetTypeInfo;
	SQLGetTypeInfoAFun SQLGetTypeInfoA;

	SQLGetTypeInfoWFun SQLGetTypeInfoW;
	SQLMoreResultsFun SQLMoreResults;
	SQLNativeSqlFun SQLNativeSql;
	SQLNativeSqlAFun SQLNativeSqlA;
	SQLNativeSqlWFun SQLNativeSqlW;
	SQLNumParamsFun SQLNumParams;
	//SQLNumResultColsFun SQLNumResultCols;
	SQLParamDataFun SQLParamData;
	SQLParamOptionsFun SQLParamOptions;
	SQLPrepareFun SQLPrepare;

	SQLPrepareAFun SQLPrepareA;
	SQLPrepareWFun SQLPrepareW;
	SQLPrimaryKeysFun SQLPrimaryKeys;
	SQLPrimaryKeysAFun SQLPrimaryKeysA;
	SQLPrimaryKeysWFun SQLPrimaryKeysW;
	SQLProcedureColumnsFun SQLProcedureColumns;
	SQLProcedureColumnsAFun SQLProcedureColumnsA;
	SQLProcedureColumnsWFun SQLProcedureColumnsW;
	SQLProceduresFun SQLProcedures;
	SQLProceduresAFun SQLProceduresA;

	SQLProceduresWFun SQLProceduresW;
	SQLPutDataFun SQLPutData;
	SQLRowCountFun SQLRowCount;
	SQLSetConnectAttrFun SQLSetConnectAttr;
	SQLSetConnectAttrAFun SQLSetConnectAttrA;
	SQLSetConnectAttrWFun SQLSetConnectAttrW;
	SQLSetConnectOptionFun SQLSetConnectOption;
	SQLSetConnectOptionAFun SQLSetConnectOptionA;
	SQLSetConnectOptionWFun SQLSetConnectOptionW;
	SQLSetCursorNameFun SQLSetCursorName;

	SQLSetCursorNameAFun SQLSetCursorNameA;
	SQLSetCursorNameWFun SQLSetCursorNameW;
	SQLSetParamFun SQLSetParam;
	SQLSetPosFun SQLSetPos;
	SQLSetScrollOptionsFun SQLSetScrollOptions;
	SQLSetStmtAttrFun SQLSetStmtAttr;
	SQLSetStmtAttrAFun SQLSetStmtAttrA;
	SQLSetStmtAttrWFun SQLSetStmtAttrW;
	SQLSetStmtOptionFun SQLSetStmtOption;
	SQLSpecialColumnsFun SQLSpecialColumns;

	SQLSpecialColumnsAFun SQLSpecialColumnsA;
	SQLSpecialColumnsWFun SQLSpecialColumnsW;
	SQLStatisticsFun SQLStatistics;
	SQLStatisticsAFun SQLStatisticsA;
	SQLStatisticsWFun SQLStatisticsW;
	SQLTablePrivilegesFun SQLTablePrivileges;
	SQLTablePrivilegesAFun SQLTablePrivilegesA;
	SQLTablePrivilegesWFun SQLTablePrivilegesW;
	SQLTablesFun SQLTables;
	SQLTablesAFun SQLTablesA;

	SQLTablesWFun SQLTablesW;
	SQLTransactFun SQLTransact;

	//19-04-24
	SQLCancelFun SQLCancel;
	SQLCopyDescFun SQLCopyDesc;
	SQLDataSourcesFun SQLDataSources;
	SQLDataSourcesAFun SQLDataSourcesA;
	SQLDataSourcesWFun SQLDataSourcesW;
	SQLDriversFun SQLDrivers;
	SQLDriversAFun SQLDriversA;
	SQLDriversWFun SQLDriversW;
	SQLFreeEnvFun SQLFreeEnv;
	SQLGetDescFieldFun SQLGetDescField;

	SQLGetDescFieldAFun SQLGetDescFieldA;
	SQLGetDescFieldWFun SQLGetDescFieldW;
	SQLGetDescRecFun SQLGetDescRec;
	SQLGetDescRecAFun SQLGetDescRecA;
	SQLGetDescRecWFun SQLGetDescRecW;
	SQLSetDescFieldFun SQLSetDescField;
	SQLSetDescFieldAFun SQLSetDescFieldA;
	SQLSetDescFieldWFun SQLSetDescFieldW;
	SQLSetDescRecFun SQLSetDescRec;
	//SQLSetEnvAttrFun SQLSetEnvAttr;
private:
	void init() {
        void * hODBCMgr = nullptr;
#ifdef WIN32
        if (m == 0) {
			hODBCMgr = ::LoadLibraryW(L"odbc32_ms.dll");
		}
		else if (m == 1) {
			hODBCMgr = ::LoadLibraryW(L"odbc32.dll");
		}
#else
        if (m == 0) {
            hODBCMgr = dlopen("libodbc_ms.so", RTLD_NOW|RTLD_GLOBAL);
        }
        else if (m == 1) {
            hODBCMgr = dlopen("libodbc.so", RTLD_NOW|RTLD_GLOBAL);
        }
#endif

		if (nullptr == hODBCMgr)
			return;
		GET_ODBC_PROC(SQLAllocHandle);
		GET_ODBC_PROC(SQLSetEnvAttr);
		GET_ODBC_PROC(SQLDriverConnect);
		GET_ODBC_PROC(SQLDriverConnectA);
		GET_ODBC_PROC(SQLDriverConnectW);
		GET_ODBC_PROC(SQLExecDirect);
		GET_ODBC_PROC(SQLExecDirectA);
		GET_ODBC_PROC(SQLExecDirectW);
		GET_ODBC_PROC(SQLNumResultCols);
		GET_ODBC_PROC(SQLCloseCursor);
		GET_ODBC_PROC(SQLFreeStmt);
		GET_ODBC_PROC(SQLBindCol);
		GET_ODBC_PROC(SQLFetch);
		GET_ODBC_PROC(SQLGetData);
		GET_ODBC_PROC(SQLGetDiagRec);
		GET_ODBC_PROC(SQLGetDiagRecA);
		GET_ODBC_PROC(SQLGetDiagRecW);
		GET_ODBC_PROC(SQLConnect);
		GET_ODBC_PROC(SQLConnectA);
		GET_ODBC_PROC(SQLConnectW);
		GET_ODBC_PROC(SQLBrowseConnect);
		GET_ODBC_PROC(SQLBrowseConnectA);
		GET_ODBC_PROC(SQLBrowseConnectW);
		GET_ODBC_PROC(SQLFreeHandle);
		GET_ODBC_PROC(SQLDisconnect);
		GET_ODBC_PROC(SQLGetInfo);

		GET_ODBC_PROC(SQLGetInfoA);
		GET_ODBC_PROC(SQLGetInfoW);

		//add by  jeff 19-04-18
		GET_ODBC_PROC(SQLAllocConnect);
		GET_ODBC_PROC(SQLAllocEnv);
		GET_ODBC_PROC(SQLAllocHandleStd);
		GET_ODBC_PROC(SQLAllocStmt);
		//GET_ODBC_PROC(SQLBindCol);
		GET_ODBC_PROC(SQLBindParam);
		GET_ODBC_PROC(SQLBindParameter);
		GET_ODBC_PROC(SQLBulkOperations);
		//Sqlcancel
		//GET_ODBC_PROC(SQLCloseCursor);

		GET_ODBC_PROC(SQLColAttribute);
		GET_ODBC_PROC(SQLColAttributeA);
		GET_ODBC_PROC(SQLColAttributeW);
		GET_ODBC_PROC(SQLColAttributes);
		GET_ODBC_PROC(SQLColAttributesA);
		GET_ODBC_PROC(SQLColAttributesW);
		GET_ODBC_PROC(SQLColumnPrivileges);
		GET_ODBC_PROC(SQLColumnPrivilegesA);
		GET_ODBC_PROC(SQLColumnPrivilegesW);
		GET_ODBC_PROC(SQLColumns);

		GET_ODBC_PROC(SQLColumnsA);
		GET_ODBC_PROC(SQLColumnsW);
		GET_ODBC_PROC(SQLDescribeCol);
		GET_ODBC_PROC(SQLDescribeColA);
		GET_ODBC_PROC(SQLDescribeColW);
		GET_ODBC_PROC(SQLDescribeParam);
		GET_ODBC_PROC(SQLEndTran);
		GET_ODBC_PROC(SQLError);
		GET_ODBC_PROC(SQLErrorA);
		GET_ODBC_PROC(SQLErrorW);

		GET_ODBC_PROC(SQLExecute);
		GET_ODBC_PROC(SQLExtendedFetch);
		//GET_ODBC_PROC(SQLFetch);
		GET_ODBC_PROC(SQLFetchScroll);
		GET_ODBC_PROC(SQLForeignKeys);
		GET_ODBC_PROC(SQLForeignKeysA);
		GET_ODBC_PROC(SQLForeignKeysW);
		GET_ODBC_PROC(SQLFreeConnect);
		//GET_ODBC_PROC(SQLFreeStmt);
		GET_ODBC_PROC(SQLGetConnectAttr);

		GET_ODBC_PROC(SQLGetConnectAttrA);
		GET_ODBC_PROC(SQLGetConnectAttrW);
		GET_ODBC_PROC(SQLGetConnectOption);
		GET_ODBC_PROC(SQLGetConnectOptionA);
		GET_ODBC_PROC(SQLGetConnectOptionW);
		GET_ODBC_PROC(SQLGetCursorName);
		GET_ODBC_PROC(SQLGetCursorNameA);
		GET_ODBC_PROC(SQLGetCursorNameW);
		//GET_ODBC_PROC(SQLGetData);
		GET_ODBC_PROC(SQLGetDiagField);


		GET_ODBC_PROC(SQLGetDiagFieldA);
		GET_ODBC_PROC(SQLGetDiagFieldW);
		GET_ODBC_PROC(SQLGetEnvAttr);
		GET_ODBC_PROC(SQLGetFunctions);
		GET_ODBC_PROC(SQLGetStmtAttr);
		GET_ODBC_PROC(SQLGetStmtAttrA);
		GET_ODBC_PROC(SQLGetStmtAttrW);
		GET_ODBC_PROC(SQLGetStmtOption);
		GET_ODBC_PROC(SQLGetTypeInfo);
		GET_ODBC_PROC(SQLGetTypeInfoA);

		GET_ODBC_PROC(SQLGetTypeInfoW);
		GET_ODBC_PROC(SQLMoreResults);
		GET_ODBC_PROC(SQLNativeSql);
		GET_ODBC_PROC(SQLNativeSqlA);
		GET_ODBC_PROC(SQLNativeSqlW);
		GET_ODBC_PROC(SQLNumParams);
		//GET_ODBC_PROC(SQLNumResultCols);
		GET_ODBC_PROC(SQLParamData);
		GET_ODBC_PROC(SQLParamOptions);
		GET_ODBC_PROC(SQLPrepare);


		GET_ODBC_PROC(SQLPrepareA);
		GET_ODBC_PROC(SQLPrepareW);
		GET_ODBC_PROC(SQLPrimaryKeys);
		GET_ODBC_PROC(SQLPrimaryKeysA);
		GET_ODBC_PROC(SQLPrimaryKeysW);
		GET_ODBC_PROC(SQLProcedureColumns);
		GET_ODBC_PROC(SQLProcedureColumnsA);
		GET_ODBC_PROC(SQLProcedureColumnsW);
		GET_ODBC_PROC(SQLProcedures);
		GET_ODBC_PROC(SQLProceduresA);


		GET_ODBC_PROC(SQLProceduresW);
		GET_ODBC_PROC(SQLPutData);
		GET_ODBC_PROC(SQLRowCount);
		GET_ODBC_PROC(SQLSetConnectAttr);
		GET_ODBC_PROC(SQLSetConnectAttrA);
		GET_ODBC_PROC(SQLSetConnectAttrW);
		GET_ODBC_PROC(SQLSetConnectOption);
		GET_ODBC_PROC(SQLSetConnectOptionA);
		GET_ODBC_PROC(SQLSetConnectOptionW);
		GET_ODBC_PROC(SQLSetCursorName);


		GET_ODBC_PROC(SQLSetCursorNameA);
		GET_ODBC_PROC(SQLSetCursorNameW);
		GET_ODBC_PROC(SQLSetParam);
		GET_ODBC_PROC(SQLSetPos);
		GET_ODBC_PROC(SQLSetScrollOptions);
		GET_ODBC_PROC(SQLSetStmtAttr);
		GET_ODBC_PROC(SQLSetStmtAttrA);
		GET_ODBC_PROC(SQLSetStmtAttrW);
		GET_ODBC_PROC(SQLSetStmtOption);
		GET_ODBC_PROC(SQLSpecialColumns);



		GET_ODBC_PROC(SQLSpecialColumnsA);
		GET_ODBC_PROC(SQLSpecialColumnsW);
		GET_ODBC_PROC(SQLStatistics);
		GET_ODBC_PROC(SQLStatisticsA);
		GET_ODBC_PROC(SQLStatisticsW);
		GET_ODBC_PROC(SQLTablePrivileges);
		GET_ODBC_PROC(SQLTablePrivilegesA);
		GET_ODBC_PROC(SQLTablePrivilegesW);
		GET_ODBC_PROC(SQLTables);
		GET_ODBC_PROC(SQLTablesA);


		GET_ODBC_PROC(SQLTablesW);
		GET_ODBC_PROC(SQLTransact);


		//19-04-24
		GET_ODBC_PROC(SQLCancel);
		GET_ODBC_PROC(SQLCancelHandle);
		GET_ODBC_PROC(SQLCompleteAsync);
		GET_ODBC_PROC(SQLCopyDesc);
		GET_ODBC_PROC(SQLDataSources);
		GET_ODBC_PROC(SQLDataSourcesA);
		GET_ODBC_PROC(SQLDataSourcesW);
		GET_ODBC_PROC(SQLDrivers);
		GET_ODBC_PROC(SQLDriversA);
		GET_ODBC_PROC(SQLDriversW);
		GET_ODBC_PROC(SQLFreeEnv);
		//GET_ODBC_PROC(SQLFreeHandle);
		GET_ODBC_PROC(SQLGetDescField);

		GET_ODBC_PROC(SQLGetDescFieldA);
		GET_ODBC_PROC(SQLGetDescFieldW);
		GET_ODBC_PROC(SQLGetDescRec);
		GET_ODBC_PROC(SQLGetDescRecA);
		GET_ODBC_PROC(SQLGetDescRecW);
		GET_ODBC_PROC(SQLSetDescField);
		GET_ODBC_PROC(SQLSetDescFieldA);
		GET_ODBC_PROC(SQLSetDescFieldW);
		GET_ODBC_PROC(SQLSetDescRec);
		//GET_ODBC_PROC(SQLSetEnvAttr);
	}
	odbcapis() { init(); }
};




#endif

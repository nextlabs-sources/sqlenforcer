#include <stdlib.h>
#include "odbctype.h"

class COdbcProxy
{
   private:
   COdbcProxy();
   COdbcProxy(const COdbcProxy&){}

   public:
   static COdbcProxy* Instance()
   {
       static COdbcProxy* pInstance = new COdbcProxy();
       return pInstance;
   }

   public:
   bool Init();
   void UnInit();

   //odbc function point
   public:
   SQLGetDiagRecFun SQLGetDiagRec;
   SQLAllocHandleFun SQLAllocHandle;
   SQLSetEnvAttrFun SQLSetEnvAttr;
   SQLConnectFun   SQLConnect;
   SQLDriverConnectFun SQLDriverConnect;
   SQLExecDirectFun SQLExecDirect;
   SQLNumResultColsFun SQLNumResultCols;
   SQLRowCountFun SQLRowCount;
   SQLCloseCursorFun SQLCloseCursor;
   SQLFreeStmtFun SQLFreeStmt;
   SQLFreeHandleFun SQLFreeHandle;
   SQLDisconnectFun SQLDisconnect;
   SQLGetFunctionsFun SQLGetFunctions;
   SQLColumnsFun SQLColumns;
   SQLFetchFun SQLFetch;
   SQLFreeEnvFun SQLFreeEnv;
   SQLFreeConnectFun SQLFreeConnect;
   SQLDescribeColFun SQLDescribeCol;
   SQLAllocStmtFun SQLAllocStmt;
   SQLSetConnectOptionFun SQLSetConnectOption;
   SQLColAttributeFun SQLColAttribute;         
   SQLPrepareFun SQLPrepare;      
   SQLErrorFun SQLError;        
   SQLSetConnectAttrFun SQLSetConnectAttr;
   SQLAllocEnvFun SQLAllocEnv;     
   SQLTransactFun SQLTransact;     
   SQLExecuteFun SQLExecute;      
   SQLAllocConnectFun SQLAllocConnect;         
   SQLEndTranFun SQLEndTran;      
   SQLGetDataFun SQLGetData;      
   SQLTablesFun SQLTables;       
   SQLMoreResultsFun SQLMoreResults;
   SQLBulkOperationsFun SQLBulkOperations;
   SQLCancelFun SQLCancel;
   SQLBindColFun SQLBindCol;
   SQLBindParamFun SQLBindParam;
   SQLBindParameterFun SQLBindParameter;
   SQLBrowseConnectFun SQLBrowseConnect;
   SQLBrowseConnectAFun SQLBrowseConnectA;
   SQLBrowseConnectWFun SQLBrowseConnectW;
   SQLColAttributeAFun SQLColAttributeA;
   SQLColAttributeWFun SQLColAttributeW;
   SQLColAttributesFun SQLColAttributes;
   SQLColAttributesAFun SQLColAttributesA;
   SQLColAttributesWFun SQLColAttributesW;
   SQLColumnPrivilegesFun SQLColumnPrivileges;
   SQLColumnPrivilegesAFun SQLColumnPrivilegesA;
   SQLColumnPrivilegesWFun SQLColumnPrivilegesW;
   SQLColumnsAFun SQLColumnsA;
   SQLColumnsWFun SQLColumnsW;
   SQLConnectAFun SQLConnectA;
   SQLConnectWFun SQLConnectW;
   SQLCopyDescFun SQLCopyDesc;
   SQLDataSourcesFun SQLDataSources;
   SQLDataSourcesAFun SQLDataSourcesA;
   SQLDataSourcesWFun SQLDataSourcesW;
   SQLDescribeColAFun SQLDescribeColA;
   SQLDescribeColWFun SQLDescribeColW;
   SQLDescribeParamFun SQLDescribeParam;
   SQLDriverConnectAFun SQLDriverConnectA;
   SQLDriverConnectWFun SQLDriverConnectW;
   SQLDriversFun SQLDrivers;
   SQLDriversAFun SQLDriversA;
   SQLDriversWFun SQLDriversW;
   SQLErrorAFun SQLErrorA;
   SQLErrorWFun SQLErrorW;
   SQLExecDirectAFun SQLExecDirectA;
   SQLExecDirectWFun SQLExecDirectW;
   SQLExtendedFetchFun SQLExtendedFetch;
   SQLFetchScrollFun SQLFetchScroll;
   SQLForeignKeysFun SQLForeignKeys;
   SQLForeignKeysAFun SQLForeignKeysA;
   SQLForeignKeysWFun SQLForeignKeysW;
   SQLGetConnectAttrFun SQLGetConnectAttr;
   SQLGetConnectAttrAFun SQLGetConnectAttrA;
   SQLGetConnectAttrWFun SQLGetConnectAttrW;
   SQLGetConnectOptionAFun SQLGetConnectOptionA;
   SQLGetConnectOptionWFun SQLGetConnectOptionW;
   SQLGetCursorNameFun SQLGetCursorName;
   SQLGetCursorNameAFun SQLGetCursorNameA;
   SQLGetCursorNameWFun SQLGetCursorNameW;
   SQLGetDescFieldFun SQLGetDescField;
   SQLGetDescFieldAFun SQLGetDescFieldA;
   SQLGetDescFieldWFun SQLGetDescFieldW;
   SQLGetDescRecFun SQLGetDescRec;
   SQLGetDescRecAFun SQLGetDescRecA;
   SQLGetDescRecWFun SQLGetDescRecW;
   SQLGetDiagFieldFun SQLGetDiagField;
   SQLGetDiagFieldAFun SQLGetDiagFieldA;
   SQLGetDiagFieldWFun SQLGetDiagFieldW;
   SQLGetDiagRecAFun SQLGetDiagRecA;
   SQLGetDiagRecWFun SQLGetDiagRecW;
   SQLGetEnvAttrFun SQLGetEnvAttr;
   SQLGetInfoFun SQLGetInfo;
   SQLGetInfoAFun SQLGetInfoA;
   SQLGetInfoWFun SQLGetInfoW;
   SQLGetStmtAttrFun SQLGetStmtAttr;
   SQLGetStmtAttrAFun SQLGetStmtAttrA;
   SQLGetStmtAttrWFun SQLGetStmtAttrW;
   SQLGetStmtOptionFun SQLGetStmtOption;
   SQLGetStmtOptionAFun SQLGetStmtOptionA;
   SQLGetTypeInfoFun SQLGetTypeInfo;
   SQLGetTypeInfoAFun SQLGetTypeInfoA;
   SQLGetTypeInfoWFun SQLGetTypeInfoW;
   SQLNativeSqlFun SQLNativeSql;
   SQLNativeSqlAFun SQLNativeSqlA;
   SQLNativeSqlWFun SQLNativeSqlW;
   SQLNumParamsFun SQLNumParams;
   SQLParamDataFun SQLParamData;
   SQLParamOptionsFun SQLParamOptions;
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
   SQLSetConnectAttrAFun SQLSetConnectAttrA;
   SQLSetConnectAttrWFun SQLSetConnectAttrW;
   SQLSetConnectOptionAFun SQLSetConnectOptionA;
   SQLSetConnectOptionWFun SQLSetConnectOptionW;
   SQLSetCursorNameFun SQLSetCursorName;
   SQLSetCursorNameAFun SQLSetCursorNameA;
   SQLSetCursorNameWFun SQLSetCursorNameW;
   SQLSetDescFieldFun SQLSetDescField;
   SQLSetDescFieldWFun SQLSetDescFieldW;
   SQLSetDescRecFun SQLSetDescRec;
   SQLSetParamFun SQLSetParam;
   SQLSetPosFun SQLSetPos;
   SQLSetScrollOptionsFun SQLSetScrollOptions;
   SQLSetStmtAttrFun SQLSetStmtAttr;
   SQLSetStmtAttrWFun SQLSetStmtAttrW;
   SQLSetStmtOptionFun SQLSetStmtOption;
   SQLSetStmtOptionAFun SQLSetStmtOptionA;
   SQLSpecialColumnsFun SQLSpecialColumns;
   SQLSpecialColumnsAFun SQLSpecialColumnsA;
   SQLSpecialColumnsWFun SQLSpecialColumnsW;
   SQLStatisticsFun SQLStatistics;
   SQLStatisticsAFun SQLStatisticsA;
   SQLStatisticsWFun SQLStatisticsW;
   SQLTablePrivilegesFun SQLTablePrivileges;
   SQLTablePrivilegesAFun SQLTablePrivilegesA;
   SQLTablePrivilegesWFun SQLTablePrivilegesW;
   SQLTablesAFun SQLTablesA;
   SQLTablesWFun SQLTablesW;

   //
   private:
   void* m_pProxyODBC;
};

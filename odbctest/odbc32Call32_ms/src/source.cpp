#include <windows.h>
#include "source.h"
#include <iostream>  
#include <fstream>
#include <string> 
#include <sql.h>
#include <sqlext.h>
#include <vector>
#include <Shlobj.h>

std::string GetProgramDir()
{
	char exeFullPath[MAX_PATH]; // Full path
	std::string strPath = "";

	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = (std::string)exeFullPath;    // Get full path of the file
	int pos = strPath.find_last_of('\\', strPath.length());
	return strPath.substr(0, pos);  // Return the directory without the file name
}
void* LoadShareLibrary(bool isEnforcered)
{
	std::string path = GetProgramDir();
	std::string enforcePath;
	if (isEnforcered)
	{
		enforcePath = path + "\\odbc32.dll";
	}
	else
	{
	   enforcePath = path + "\\odbc32_ms.dll";
	}
	return LoadLibraryA(enforcePath.c_str());
}

void* GetProcAddress(void* libhandle, const char* funname)
{
	return ::GetProcAddress((HMODULE)libhandle, funname);
}

#define GET_Enforcer_PROC(funname) funname=(funname##Fun)GetProcAddress(hEnforcer, #funname);
Enforcer::Enforcer()
{
	SQLGetDiagRec = NULL;
}
bool Enforcer::LoadEnforcer(bool isEnforcered)
{
	void* hEnforcer = LoadShareLibrary(isEnforcered);
	if (hEnforcer == NULL)
	{
      printf("load dll failed, lasterror=%d\n", GetLastError());
	  return false;
	}
	GET_Enforcer_PROC(SQLGetDiagRec);
	GET_Enforcer_PROC(SQLAllocHandle);
	GET_Enforcer_PROC(SQLSetEnvAttr);
	GET_Enforcer_PROC(SQLConnect);
	GET_Enforcer_PROC(SQLExecDirect);
	GET_Enforcer_PROC(SQLNumResultCols);
	GET_Enforcer_PROC(SQLRowCount);
	GET_Enforcer_PROC(SQLCloseCursor);
	GET_Enforcer_PROC(SQLFreeStmt);
	GET_Enforcer_PROC(SQLFreeHandle);
	GET_Enforcer_PROC(SQLDisconnect);
	GET_Enforcer_PROC(SQLGetFunctions);
	GET_Enforcer_PROC(SQLColumns);
	GET_Enforcer_PROC(SQLFetch);
	GET_Enforcer_PROC(SQLFreeEnv);
	GET_Enforcer_PROC(SQLDriverConnect);
	GET_Enforcer_PROC(SQLFreeConnect);
	GET_Enforcer_PROC(SQLDescribeCol);
	GET_Enforcer_PROC(SQLAllocStmt);
	GET_Enforcer_PROC(SQLSetConnectOption);
	GET_Enforcer_PROC(SQLColAttribute);
	GET_Enforcer_PROC(SQLPrepare);
	GET_Enforcer_PROC(SQLError);
	GET_Enforcer_PROC(SQLSetConnectAttr);
	GET_Enforcer_PROC(SQLAllocEnv);
	GET_Enforcer_PROC(SQLTransact);
	GET_Enforcer_PROC(SQLExecute);
	GET_Enforcer_PROC(SQLAllocConnect);
	GET_Enforcer_PROC(SQLEndTran);
	GET_Enforcer_PROC(SQLGetData);
	GET_Enforcer_PROC(SQLTables);
	GET_Enforcer_PROC(SQLMoreResults);
	GET_Enforcer_PROC(SQLBulkOperations);
	GET_Enforcer_PROC(SQLCancel);
	GET_Enforcer_PROC(SQLBindCol);
	GET_Enforcer_PROC(SQLBindParam);
	GET_Enforcer_PROC(SQLBindParameter);
	GET_Enforcer_PROC(SQLBrowseConnect);
	GET_Enforcer_PROC(SQLBrowseConnectA);
	GET_Enforcer_PROC(SQLBrowseConnectW);
	GET_Enforcer_PROC(SQLColAttributeA);
	GET_Enforcer_PROC(SQLColAttributeW);
	GET_Enforcer_PROC(SQLColAttributes);
	GET_Enforcer_PROC(SQLColAttributesA);
	GET_Enforcer_PROC(SQLColAttributesW);
	GET_Enforcer_PROC(SQLColumnPrivileges);
	GET_Enforcer_PROC(SQLColumnPrivilegesA);
	GET_Enforcer_PROC(SQLColumnPrivilegesW);
	GET_Enforcer_PROC(SQLColumnsA);
	GET_Enforcer_PROC(SQLColumnsW);
	GET_Enforcer_PROC(SQLConnectA);
	GET_Enforcer_PROC(SQLConnectW);
	GET_Enforcer_PROC(SQLCopyDesc);
	GET_Enforcer_PROC(SQLDataSources);
	GET_Enforcer_PROC(SQLDataSourcesA);
	GET_Enforcer_PROC(SQLDataSourcesW);
	GET_Enforcer_PROC(SQLDescribeColA);
	GET_Enforcer_PROC(SQLDescribeColW);
	GET_Enforcer_PROC(SQLDescribeParam);
	GET_Enforcer_PROC(SQLDriverConnectA);
	GET_Enforcer_PROC(SQLDriverConnectW);
	GET_Enforcer_PROC(SQLDrivers);
	GET_Enforcer_PROC(SQLDriversA);
	GET_Enforcer_PROC(SQLDriversW);
	GET_Enforcer_PROC(SQLErrorA);
	GET_Enforcer_PROC(SQLErrorW);
	GET_Enforcer_PROC(SQLExecDirectA);
	GET_Enforcer_PROC(SQLExecDirectW);
	GET_Enforcer_PROC(SQLExtendedFetch);
	GET_Enforcer_PROC(SQLFetchScroll);
	GET_Enforcer_PROC(SQLForeignKeys);
	GET_Enforcer_PROC(SQLForeignKeysA);
	GET_Enforcer_PROC(SQLForeignKeysW);
	GET_Enforcer_PROC(SQLGetConnectAttr);
	GET_Enforcer_PROC(SQLGetConnectAttrA);
	GET_Enforcer_PROC(SQLGetConnectAttrW);
	GET_Enforcer_PROC(SQLGetConnectOptionA);
	GET_Enforcer_PROC(SQLGetConnectOptionW);
	GET_Enforcer_PROC(SQLGetCursorName);
	GET_Enforcer_PROC(SQLGetCursorNameA);
	GET_Enforcer_PROC(SQLGetCursorNameW);
	GET_Enforcer_PROC(SQLGetDescField);
	GET_Enforcer_PROC(SQLGetDescFieldA);
	GET_Enforcer_PROC(SQLGetDescFieldW);
	GET_Enforcer_PROC(SQLGetDescRec);
	GET_Enforcer_PROC(SQLGetDescRecA);
	GET_Enforcer_PROC(SQLGetDescRecW);
	GET_Enforcer_PROC(SQLGetDiagField);
	GET_Enforcer_PROC(SQLGetDiagFieldA);
	GET_Enforcer_PROC(SQLGetDiagFieldW);
	GET_Enforcer_PROC(SQLGetDiagRecA);
	GET_Enforcer_PROC(SQLGetDiagRecW);
	GET_Enforcer_PROC(SQLGetEnvAttr);
	GET_Enforcer_PROC(SQLGetInfo);
	GET_Enforcer_PROC(SQLGetInfoA);
	GET_Enforcer_PROC(SQLGetInfoW);
	GET_Enforcer_PROC(SQLGetStmtAttr);
	GET_Enforcer_PROC(SQLGetStmtAttrA);
	GET_Enforcer_PROC(SQLGetStmtAttrW);
	GET_Enforcer_PROC(SQLGetStmtOption);
	GET_Enforcer_PROC(SQLGetTypeInfo);
	GET_Enforcer_PROC(SQLGetTypeInfoA);
	GET_Enforcer_PROC(SQLGetTypeInfoW);
	GET_Enforcer_PROC(SQLNativeSql);
	GET_Enforcer_PROC(SQLNativeSqlA);
	GET_Enforcer_PROC(SQLNativeSqlW);
	GET_Enforcer_PROC(SQLNumParams);
	GET_Enforcer_PROC(SQLParamData);
	GET_Enforcer_PROC(SQLParamOptions);
	GET_Enforcer_PROC(SQLPrepareA);
	GET_Enforcer_PROC(SQLPrepareW);
	GET_Enforcer_PROC(SQLPrimaryKeys);
	GET_Enforcer_PROC(SQLPrimaryKeysA);
	GET_Enforcer_PROC(SQLPrimaryKeysW);
	GET_Enforcer_PROC(SQLProcedureColumns);
	GET_Enforcer_PROC(SQLProcedureColumnsA);
	GET_Enforcer_PROC(SQLProcedureColumnsW);
	GET_Enforcer_PROC(SQLProcedures);
	GET_Enforcer_PROC(SQLProceduresA);
	GET_Enforcer_PROC(SQLProceduresW);
	GET_Enforcer_PROC(SQLPutData);
	GET_Enforcer_PROC(SQLSetConnectAttrA);
	GET_Enforcer_PROC(SQLSetConnectAttrW);
	GET_Enforcer_PROC(SQLSetConnectOptionA);
	GET_Enforcer_PROC(SQLSetConnectOptionW);
	GET_Enforcer_PROC(SQLSetCursorName);
	GET_Enforcer_PROC(SQLSetCursorNameA);
	GET_Enforcer_PROC(SQLSetCursorNameW);
	GET_Enforcer_PROC(SQLSetDescField);
	GET_Enforcer_PROC(SQLSetDescFieldW);
	GET_Enforcer_PROC(SQLSetDescRec);
	GET_Enforcer_PROC(SQLSetParam);
	GET_Enforcer_PROC(SQLSetPos);
	GET_Enforcer_PROC(SQLSetScrollOptions);
	GET_Enforcer_PROC(SQLSetStmtAttr);
	GET_Enforcer_PROC(SQLSetStmtAttrW);
	GET_Enforcer_PROC(SQLSetStmtOption);
	GET_Enforcer_PROC(SQLSpecialColumns);
	GET_Enforcer_PROC(SQLSpecialColumnsA);
	GET_Enforcer_PROC(SQLSpecialColumnsW);
	GET_Enforcer_PROC(SQLStatistics);
	GET_Enforcer_PROC(SQLStatisticsA);
	GET_Enforcer_PROC(SQLStatisticsW);
	GET_Enforcer_PROC(SQLTablePrivileges);
	GET_Enforcer_PROC(SQLTablePrivilegesA);
	GET_Enforcer_PROC(SQLTablePrivilegesW);
	GET_Enforcer_PROC(SQLTablesA);
	GET_Enforcer_PROC(SQLTablesW);
	GET_Enforcer_PROC(SQLCancelHandle);
	GET_Enforcer_PROC(SQLCompleteAsync);
	GET_Enforcer_PROC(SQLAllocHandleStd);
	return true;
}

void LoadMethod()
{
	Enforcer::Instance()->SQLGetDiagRec(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLAllocHandle(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetEnvAttr(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLConnect(NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL);
	Enforcer::Instance()->SQLExecDirect(NULL, (SQLCHAR*)"", NULL);
	Enforcer::Instance()->SQLNumResultCols(NULL, NULL);
	Enforcer::Instance()->SQLRowCount(NULL, NULL);
	Enforcer::Instance()->SQLCloseCursor(NULL);
	Enforcer::Instance()->SQLFreeStmt(NULL, NULL);
	Enforcer::Instance()->SQLFreeHandle(NULL, NULL);
	Enforcer::Instance()->SQLDisconnect(NULL);
	Enforcer::Instance()->SQLGetFunctions(NULL, NULL, NULL);
	Enforcer::Instance()->SQLColumns(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLFetch(NULL);
	Enforcer::Instance()->SQLFreeEnv(NULL);
	Enforcer::Instance()->SQLDriverConnect(NULL, NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL, NULL);
	Enforcer::Instance()->SQLFreeConnect(NULL);
	Enforcer::Instance()->SQLDescribeCol(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLAllocStmt(NULL, NULL);
	Enforcer::Instance()->SQLSetConnectOption(NULL, NULL, NULL);
	Enforcer::Instance()->SQLColAttribute(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLPrepare(NULL, NULL, NULL);
	Enforcer::Instance()->SQLError(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetConnectAttr(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLAllocEnv(NULL);
	Enforcer::Instance()->SQLTransact(NULL, NULL, NULL);
	Enforcer::Instance()->SQLExecute(NULL);
	Enforcer::Instance()->SQLAllocConnect(NULL, NULL);
	Enforcer::Instance()->SQLEndTran(NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetData(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLTables(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLMoreResults(NULL);
	Enforcer::Instance()->SQLBulkOperations(NULL, NULL);
	Enforcer::Instance()->SQLCancel(NULL);
	Enforcer::Instance()->SQLBindCol(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLBindParam(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLBindParameter(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLBrowseConnect(NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL);
	Enforcer::Instance()->SQLBrowseConnectA(NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL);
	Enforcer::Instance()->SQLBrowseConnectW(NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL, NULL);
	Enforcer::Instance()->SQLColAttributeA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColAttributeW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColAttributes(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColAttributesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColAttributesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColumnPrivileges(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColumnPrivilegesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColumnPrivilegesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColumnsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLColumnsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLConnectA(NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL);
	Enforcer::Instance()->SQLConnectW(NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL);
	Enforcer::Instance()->SQLCopyDesc(NULL, NULL);
	Enforcer::Instance()->SQLDataSources(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDataSourcesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDataSourcesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDescribeColA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDescribeColW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDescribeParam(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDriverConnectA(NULL, NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL, NULL);
	Enforcer::Instance()->SQLDriverConnectW(NULL, NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL, NULL, NULL);
	Enforcer::Instance()->SQLDrivers(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDriversA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLDriversW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLErrorA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLErrorW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLExecDirectA(NULL, (SQLCHAR*)"", NULL);
	Enforcer::Instance()->SQLExecDirectW(NULL, (SQLWCHAR*)"", NULL);
	Enforcer::Instance()->SQLExtendedFetch(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLFetchScroll(NULL, NULL, NULL);
	Enforcer::Instance()->SQLForeignKeys(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLForeignKeysA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLForeignKeysW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetConnectAttr(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetConnectAttrA(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetConnectAttrW(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetConnectOptionA(NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetConnectOptionW(NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetCursorName(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetCursorNameA(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetCursorNameW(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDescField(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDescFieldA(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDescFieldW(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDescRec(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDescRecA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDescRecW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDiagField(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDiagFieldA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDiagFieldW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDiagRecA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetDiagRecW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetEnvAttr(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetInfo(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetInfoA(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetInfoW(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetStmtAttr(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetStmtAttrA(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetStmtAttrW(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetStmtOption(NULL, NULL, NULL);
	Enforcer::Instance()->SQLGetTypeInfo(NULL, NULL);
	Enforcer::Instance()->SQLGetTypeInfoA(NULL, NULL);
	Enforcer::Instance()->SQLGetTypeInfoW(NULL, NULL);
	Enforcer::Instance()->SQLNativeSql(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLNativeSqlA(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLNativeSqlW(NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLNumParams(NULL, NULL);
	Enforcer::Instance()->SQLParamData(NULL, NULL);
	Enforcer::Instance()->SQLParamOptions(NULL, NULL, NULL);
	Enforcer::Instance()->SQLPrepareA(NULL, NULL, NULL);
	Enforcer::Instance()->SQLPrepareW(NULL, NULL, NULL);
	Enforcer::Instance()->SQLPrimaryKeys(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLPrimaryKeysA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLPrimaryKeysW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLProcedureColumns(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLProcedureColumnsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLProcedureColumnsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLProcedures(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLProceduresA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLProceduresW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLPutData(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetConnectAttrA(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetConnectAttrW(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetConnectOptionA(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetConnectOptionW(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetCursorName(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetCursorNameA(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetCursorNameW(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetDescField(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetDescFieldW(NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetDescRec(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetParam(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetPos(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetScrollOptions(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetStmtAttr(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetStmtAttrW(NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSetStmtOption(NULL, NULL, NULL);
	Enforcer::Instance()->SQLSpecialColumns(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSpecialColumnsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLSpecialColumnsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLStatistics(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLStatisticsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLStatisticsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLTablePrivileges(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLTablePrivilegesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLTablePrivilegesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLTablesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLTablesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	Enforcer::Instance()->SQLCancelHandle(NULL, NULL);
	Enforcer::Instance()->SQLCompleteAsync(NULL, NULL, NULL);
	Enforcer::Instance()->SQLAllocHandleStd(NULL, NULL, NULL);
}
std::string readFile()
{
	std::ifstream logFile(GetProgramDir() + "\\hello.txt");
	if (!logFile.is_open())
	{
		std::cout << "can not open file,test failed!\n" << std::endl;
	}
	std::istreambuf_iterator<char> begin(logFile);
	std::istreambuf_iterator<char> end;
	std::string log(begin, end);
	logFile.close();
	std::cout << "\n" << std::endl;
	return log;
}
int main(int argc, char* argv[])
{
	if (Enforcer::Instance()->LoadEnforcer(true))
	{
		LoadMethod();
	}
	std::string log1 = readFile();

	if (Enforcer::Instance()->LoadEnforcer(false))
	{
		LoadMethod();
	}
	std::string log2 = readFile();

	if (log1 == log2)
	{
		std::cout << "test success!\n" << std::endl;
	}
	else
	{
		std::cout << "test failed!\n" << std::endl;
	}
	return 0;
}
int m2ain(int argc, char* argv[])
{
	SQLGetDiagRec(55, NULL, 1, NULL, NULL, NULL, NULL, NULL);
	SQLAllocHandle(NULL, NULL, NULL);
	SQLSetEnvAttr(NULL, NULL, NULL, NULL);
	SQLConnect(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLExecDirect(NULL, (SQLCHAR*)"", NULL);
	SQLNumResultCols(NULL, NULL );
	SQLRowCount(NULL, NULL);
	SQLCloseCursor(NULL);
	SQLFreeStmt(NULL, NULL);
	SQLFreeHandle(NULL, NULL);
	SQLDisconnect(NULL);
	SQLGetFunctions(NULL, NULL, NULL);
	SQLColumns(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLFetch(NULL);
	SQLFreeEnv(NULL);
	SQLDriverConnect(NULL, NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL, NULL);
	SQLFreeConnect(NULL);
	SQLDescribeCol(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLAllocStmt(NULL, NULL);
	//SQLSetConnectOption(NULL, NULL, NULL);
	SQLColAttribute(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLPrepare(NULL, NULL, NULL);
	SQLError(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLSetConnectAttr(NULL, NULL, NULL, NULL);
	SQLAllocEnv(NULL);
	SQLTransact(NULL, NULL, NULL);
	SQLExecute(NULL);
	SQLAllocConnect(NULL, NULL);
	SQLEndTran(NULL, NULL, NULL);
	SQLGetData(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLTables(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLMoreResults(NULL);
	SQLBulkOperations(NULL, NULL);
	SQLCancel(NULL);
	SQLBindCol(NULL, NULL, NULL, NULL, NULL, NULL);
//	SQLBindParam(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLBindParameter(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLBrowseConnect(NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL);
	SQLBrowseConnectA(NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL);
	SQLBrowseConnectW(NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL, NULL);
	SQLColAttributeA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColAttributeW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColAttributes(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColAttributesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColAttributesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColumnPrivileges(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColumnPrivilegesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColumnPrivilegesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColumnsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLColumnsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLConnectA(NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL);
	SQLConnectW(NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL);
	SQLCopyDesc(NULL, NULL);
	SQLDataSources(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDataSourcesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDataSourcesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDescribeColA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDescribeColW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDescribeParam(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDriverConnectA(NULL, NULL, (SQLCHAR*)"", NULL, (SQLCHAR*)"", NULL, NULL, NULL);
	SQLDriverConnectW(NULL, NULL, (SQLWCHAR*)"", NULL, (SQLWCHAR*)"", NULL, NULL, NULL);
	SQLDrivers(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDriversA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLDriversW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLErrorA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLErrorW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLExecDirectA(NULL, (SQLCHAR*)"", NULL);
	SQLExecDirectW(NULL, (SQLWCHAR*)"", NULL);
	SQLExtendedFetch(NULL, NULL, NULL, NULL, NULL);
	SQLFetchScroll(NULL, NULL, NULL);
	SQLForeignKeys(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLForeignKeysA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLForeignKeysW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetConnectAttr(NULL, NULL, NULL, NULL, NULL);
	SQLGetConnectAttrA(NULL, NULL, NULL, NULL, NULL);
	SQLGetConnectAttrW(NULL, NULL, NULL, NULL, NULL);
	SQLGetConnectOptionA(NULL, NULL, NULL);
	SQLGetConnectOptionW(NULL, NULL, NULL);
	SQLGetCursorName(NULL, NULL, NULL, NULL);
	SQLGetCursorNameA(NULL, NULL, NULL, NULL);
	SQLGetCursorNameW(NULL, NULL, NULL, NULL);
	SQLGetDescField(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDescFieldA(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDescFieldW(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDescRec(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDescRecA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDescRecW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDiagField(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDiagFieldA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDiagFieldW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDiagRecA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetDiagRecW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLGetEnvAttr(NULL, NULL, NULL, NULL, NULL);
	SQLGetInfo(NULL, NULL, NULL, NULL, NULL);
	SQLGetInfoA(NULL, NULL, NULL, NULL, NULL);
	SQLGetInfoW(NULL, NULL, NULL, NULL, NULL);
	SQLGetStmtAttr(NULL, NULL, NULL, NULL, NULL);
	SQLGetStmtAttrA(NULL, NULL, NULL, NULL, NULL);
	SQLGetStmtAttrW(NULL, NULL, NULL, NULL, NULL);
	//SQLGetStmtOption(NULL, NULL, NULL);
	SQLGetTypeInfo(NULL, NULL);
	SQLGetTypeInfoA(NULL, NULL);
	SQLGetTypeInfoW(NULL, NULL);
	SQLNativeSql(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLNativeSqlA(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLNativeSqlW(NULL, NULL, NULL, NULL, NULL, NULL);
	SQLNumParams(NULL, NULL);
	SQLParamData(NULL, NULL);
	SQLParamOptions(NULL, NULL, NULL);
	SQLPrepareA(NULL, NULL, NULL);
	SQLPrepareW(NULL, NULL, NULL);
	SQLPrimaryKeys(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLPrimaryKeysA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLPrimaryKeysW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLProcedureColumns(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLProcedureColumnsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLProcedureColumnsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLProcedures(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLProceduresA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLProceduresW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLPutData(NULL, NULL, NULL);
	SQLSetConnectAttrA(NULL, NULL, NULL, NULL);
	SQLSetConnectAttrW(NULL, NULL, NULL, NULL);
	SQLSetConnectOptionA(NULL, NULL, NULL);
	SQLSetConnectOptionW(NULL, NULL, NULL);
	SQLSetCursorName(NULL, NULL, NULL);
	SQLSetCursorNameA(NULL, NULL, NULL);
	SQLSetCursorNameW(NULL, NULL, NULL);
	SQLSetDescField(NULL, NULL, NULL, NULL, NULL);
	SQLSetDescFieldW(NULL, NULL, NULL, NULL, NULL);
	SQLSetDescRec(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	//SQLSetParam(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLSetPos(NULL, NULL, NULL, NULL);
	SQLSetScrollOptions(NULL, NULL, NULL, NULL);
	SQLSetStmtAttr(NULL, NULL, NULL, NULL);
	SQLSetStmtAttrW(NULL, NULL, NULL, NULL);
	//SQLSetStmtOption(NULL, NULL, NULL);
	SQLSpecialColumns(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLSpecialColumnsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLSpecialColumnsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLStatistics(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLStatisticsA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLStatisticsW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLTablePrivileges(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLTablePrivilegesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLTablePrivilegesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLTablesA(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLTablesW(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	SQLCancelHandle(NULL, NULL);
	SQLCompleteAsync(NULL, NULL, NULL);
	SQLAllocHandleStd(NULL, NULL, NULL);
	//CloseODBCPerfData();
	return 0;
}

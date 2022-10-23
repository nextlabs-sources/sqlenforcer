#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream> 
#include <iostream> 
#include <Shlobj.h>

std::string sds="";

std::string GetProgramDir()
{
	char exeFullPath[MAX_PATH]; // Full path
	std::string strPath = "";

	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = (std::string)exeFullPath;    // Get full path of the file
	int pos = strPath.find_last_of('\\', strPath.length());
	return strPath.substr(0, pos);  // Return the directory without the file name
}

    SQLRETURN  SQL_API SQLGetDiagRec(SQLSMALLINT HandleType, SQLHANDLE Handle,
                                          SQLSMALLINT RecNumber, SQLCHAR *Sqlstate,
                                          SQLINTEGER *NativeError, SQLCHAR *MessageText,
                                          SQLSMALLINT BufferLength, SQLSMALLINT *TextLength)
    {
        sds="SQLGetDiagRec\n";
        wprintf(L"SQLGetDiagRec called\n");
        return NULL;
    }

    SQLRETURN  SQL_API SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle)
    {
        sds+="SQLAllocHandle\n";
       wprintf(L"SQLAllocHandle called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLSetEnvAttr(SQLHENV EnvironmentHandle,
                                           SQLINTEGER Attribute, SQLPOINTER Value,
                                           SQLINTEGER StringLength)
     {
         sds+="SQLSetEnvAttr\n";
         wprintf(L"SQLSetEnvAttr called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLConnect(SQLHDBC ConnectionHandle,
                                        SQLCHAR *ServerName, SQLSMALLINT NameLength1,
                                        SQLCHAR *UserName, SQLSMALLINT NameLength2,
                                        SQLCHAR *Authentication, SQLSMALLINT NameLength3)
     {
         sds+="SQLConnect\n";
         wprintf(L"SQLConnect called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLExecDirect(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
     {
         sds+="SQLExecDirect\n";
        wprintf(L"SQLExecDirect called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLNumResultCols(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount)
     {
         sds+="SQLNumResultCols\n";
         wprintf(L"SQLNumResultCols called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLRowCount(SQLHSTMT StatementHandle, SQLLEN *RowCount)
     {
         sds+="SQLRowCount\n";
         wprintf(L"SQLRowCount called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLCloseCursor(SQLHSTMT StatementHandle)
     {
         sds+="SQLCloseCursor\n";
         wprintf(L"SQLCloseCursor called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLFreeStmt(SQLHSTMT StatementHandle, SQLUSMALLINT Option)
     {
         sds+="SQLFreeStmt\n";
         wprintf(L"SQLFreeStmt called\n");
        return NULL;
     }

    SQLRETURN SQL_API  SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
    {
        sds+="SQLFreeHandle\n";
        wprintf(L"SQLFreeHandle called\n");
        return NULL;
    }

    SQLRETURN SQL_API   SQLDisconnect(SQLHDBC ConnectionHandle)
    {
        sds+="SQLDisconnect\n";
      wprintf(L"SQLDisconnect called\n");
        return NULL;
    }

     SQLRETURN SQL_API   SQLGetFunctions(SQLHDBC ConnectionHandle,  SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported)
     {
         sds+="SQLGetFunctions\n";
        wprintf(L"SQLGetFunctions called\n");
        return NULL;
     }

     SQLRETURN SQL_API   SQLColumns(SQLHSTMT StatementHandle,
                                  SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                                  SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
                                  SQLCHAR *TableName, SQLSMALLINT NameLength3,
                                  SQLCHAR *ColumnName, SQLSMALLINT NameLength4)
    {
        sds+="SQLColumns\n";
       wprintf(L"SQLColumns called\n");
        return NULL;
    }

    SQLRETURN SQL_API   SQLFetch(SQLHSTMT StatementHandle)
    {
        sds+="SQLFetch\n";
        wprintf(L"SQLFetch called\n");
        return NULL;
    }

    SQLRETURN SQL_API   SQLFreeEnv(SQLHENV EnvironmentHandle)
    {
        sds+="SQLFreeEnv\n";
       wprintf(L"SQLFreeEnv called\n");
        return NULL;
    }

    SQLRETURN SQL_API  SQLDriverConnect(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLCHAR 		  *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR           *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT 	  *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion)
    {
        sds+="SQLDriverConnect\n";
        wprintf(L"SQLDriverConnect called\n");
        return NULL;
    }

    SQLRETURN SQL_API  SQLFreeConnect(SQLHDBC ConnectionHandle)
    {
        sds+="SQLFreeConnect\n";
        wprintf(L"SQLFreeConnect called\n");
        return NULL;
     }

     SQLRETURN SQL_API   SQLDescribeCol(SQLHSTMT StatementHandle,
                                      SQLUSMALLINT ColumnNumber, SQLCHAR *ColumnName,
                                      SQLSMALLINT BufferLength, SQLSMALLINT *NameLength,
                                      SQLSMALLINT *DataType, SQLULEN *ColumnSize,
                                      SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable)
     {
         sds+="SQLDescribeCol\n";
         wprintf(L"SQLDescribeCol called\n");
        return NULL;
     }

     SQLRETURN SQL_API   SQLAllocStmt(SQLHDBC ConnectionHandle, SQLHSTMT *StatementHandle)  
     {
         sds+="SQLAllocStmt\n";
        wprintf(L"SQLAllocStmt called\n");
        return NULL;
     } 

    SQLRETURN SQL_API   SQLSetConnectOption(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLULEN Value)
    {
        sds+="SQLSetConnectOption\n";
       wprintf(L"SQLSetConnectOption called\n");
        return NULL;
    }

    SQLRETURN SQL_API  SQLColAttribute(SQLHSTMT StatementHandle,SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength, SQLSMALLINT *StringLength, SQLLEN *NumericAttribute )
    {
        sds+="SQLColAttribute\n";
        wprintf(L"SQLColAttribute called\n");
        return NULL;
    }

     SQLRETURN SQL_API  SQLPrepare(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
     {
         sds+="SQLPrepare\n";
        wprintf(L"SQLPrepare called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLError(SQLHENV EnvironmentHandle,SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,SQLCHAR *Sqlstate, SQLINTEGER *NativeError,SQLCHAR *MessageText, SQLSMALLINT BufferLength,SQLSMALLINT *TextLength)
     {
         sds+="SQLError\n";
        wprintf(L"SQLError called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLSetConnectAttr(SQLHDBC ConnectionHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER StringLength)
     {
         sds+="SQLSetConnectAttr\n";
        wprintf(L"SQLSetConnectAttr called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLAllocEnv(SQLHENV *EnvironmentHandle)
     {
         sds+="SQLAllocEnv\n";
         wprintf(L"SQLAllocEnv called\n");
        return NULL;
     }

    SQLRETURN SQL_API  SQLTransact(SQLHENV EnvironmentHandle,SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType)
    {
        sds+="SQLTransact\n";
        wprintf(L"SQLTransact called\n");
        return NULL;
    }

    SQLRETURN SQL_API  SQLExecute(SQLHSTMT StatementHandle)
    {
        sds+="SQLExecute\n";
        wprintf(L"SQLExecute called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLAllocConnect(SQLHENV EnvironmentHandle, SQLHDBC *ConnectionHandle)
    {
        sds+="SQLAllocConnect\n";
        wprintf(L"SQLAllocConnect called\n");
        return NULL;
    }

    SQLRETURN SQL_API  SQLEndTran(SQLSMALLINT HandleType, SQLHANDLE Handle,SQLSMALLINT CompletionType)
    {
        sds+="SQLEndTran\n";
        wprintf(L"SQLEndTran called\n");
        return NULL;
    }

    SQLRETURN SQL_API  SQLGetData(SQLHSTMT StatementHandle,SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,SQLPOINTER TargetValue, SQLLEN BufferLength,SQLLEN *StrLen_or_Ind)
    {
        sds+="SQLGetData\n";
        wprintf(L"SQLGetData called\n");
        return NULL;
    }

     SQLRETURN SQL_API  SQLTables(SQLHSTMT StatementHandle,SQLCHAR *CatalogName, SQLSMALLINT NameLength1,SQLCHAR *SchemaName, SQLSMALLINT NameLength2,SQLCHAR *TableName, SQLSMALLINT NameLength3,SQLCHAR *TableType, SQLSMALLINT NameLength4)
     {
         sds+="SQLTables\n";
         wprintf(L"SQLTables called\n");
        return NULL;
     }

     SQLRETURN SQL_API  SQLMoreResults(SQLHSTMT hstmt)
     {
         sds+="SQLMoreResults\n";
         wprintf(L"SQLMoreResults called\n");
        return NULL;
     }
     SQLRETURN SQL_API    SQLBulkOperations(
    SQLHSTMT            StatementHandle,
    SQLSMALLINT         Operation)
    {
        sds+="SQLBulkOperations\n";
        wprintf(L"SQLBulkOperations called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLCancel(SQLHSTMT StatementHandle)
    {
        sds+="SQLCancel\n";
       wprintf(L"SQLCancel called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLBindCol(SQLHSTMT StatementHandle,
                                       SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
                                       SQLPOINTER TargetValue,
                                       SQLLEN BufferLength, SQLLEN *StrLen_or_Ind)
    {
        sds+="SQLBindCol\n";
        wprintf(L"SQLBindCol called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLBindParam(SQLHSTMT StatementHandle,
                                         SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                                         SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
                                         SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
                                         SQLLEN *StrLen_or_Ind)
    {
        sds+="SQLBindParam\n";
        wprintf(L"SQLBindParam called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLBindParameter(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       ipar,
    SQLSMALLINT        fParamType,
    SQLSMALLINT        fCType,
    SQLSMALLINT        fSqlType,
    SQLULEN            cbColDef,
    SQLSMALLINT        ibScale,
    SQLPOINTER         rgbValue,
    SQLLEN             cbValueMax,
    SQLLEN 		      *pcbValue)
    {
        sds+="SQLBindParameter\n";
        wprintf(L"SQLBindParameter called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLBrowseConnect(
    SQLHDBC            hdbc,
    SQLCHAR 		  *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR 		  *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT       *pcbConnStrOut)
    {
        sds+="SQLBrowseConnect\n";
       wprintf(L"SQLBrowseConnect called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLBrowseConnectA(
    SQLHDBC            hdbc,
    SQLCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut)
    {
        sds+="SQLBrowseConnectA\n";
       wprintf(L"SQLBrowseConnectA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLBrowseConnectW(
    SQLHDBC            hdbc,
    SQLWCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLWCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut)
    {
        sds+="SQLBrowseConnectW\n";
        wprintf(L"SQLBrowseConnectW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColAttributeA(
	SQLHSTMT		hstmt,
	SQLSMALLINT		iCol,
	SQLSMALLINT		iField,
	SQLPOINTER		pCharAttr,
	SQLSMALLINT		cbCharAttrMax,	
	SQLSMALLINT  	        *pcbCharAttr,
	SQLLEN              	*pNumAttr)
    {
        sds+="SQLColAttributeA\n";
        wprintf(L"SQLColAttributeA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColAttributeW(
	SQLHSTMT		hstmt,
	SQLUSMALLINT	iCol,
	SQLUSMALLINT	iField,
	SQLPOINTER		pCharAttr,
	SQLSMALLINT		cbCharAttrMax,	
	SQLSMALLINT  	*pcbCharAttr,
	SQLLEN		*pNumAttr)
    {
        sds+="SQLColAttributeW\n";
         wprintf(L"SQLColAttributeW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColAttributes(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLUSMALLINT       fDescType,
    SQLPOINTER         rgbDesc,
    SQLSMALLINT        cbDescMax,
    SQLSMALLINT 	  *pcbDesc,
    SQLLEN 		      *pfDesc)
    {
        sds+="SQLColAttributes\n";
         wprintf(L"SQLColAttributes called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColAttributesA(
    SQLHSTMT        hstmt,
    SQLUSMALLINT    icol,
    SQLUSMALLINT    fDescType,
    SQLPOINTER      rgbDesc,
    SQLSMALLINT     cbDescMax,
    SQLSMALLINT    	*pcbDesc,
    SQLLEN     		*pfDesc)
    {
        sds+="SQLColAttributesA\n";
         wprintf(L"SQLColAttributesA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColAttributesW(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLUSMALLINT       fDescType,
    SQLPOINTER         rgbDesc,
    SQLSMALLINT        cbDescMax,
    SQLSMALLINT        *pcbDesc,
    SQLLEN             *pfDesc)
    {
        sds+="SQLColAttributesW\n";
         wprintf(L"SQLColAttributesW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColumnPrivileges(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR 		  *szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLColumnPrivileges\n";
        wprintf(L"SQLColumnPrivileges called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColumnPrivilegesA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLColumnPrivilegesA\n";
         wprintf(L"SQLColumnPrivilegesA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColumnPrivilegesW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLWCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLColumnPrivilegesW\n";
        wprintf(L"SQLColumnPrivilegesW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColumnsA(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        	*szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        	*szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR        	*szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLColumnsA\n";
        wprintf(L"SQLColumnsA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLColumnsW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLWCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLColumnsW\n";
         wprintf(L"SQLColumnsW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLConnectA(
    SQLHDBC         hdbc,
    SQLCHAR         *szDSN,
    SQLSMALLINT     cbDSN,
    SQLCHAR         *szUID,
    SQLSMALLINT     cbUID,
    SQLCHAR         *szAuthStr,
    SQLSMALLINT     cbAuthStr)
    {
        sds+="SQLConnectA\n";
        wprintf(L"SQLConnectA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLConnectW(
        SQLHDBC hdbc,
        SQLWCHAR *szDSN,
        SQLSMALLINT cbDSN,
        SQLWCHAR *szUID,
        SQLSMALLINT cbUID,
        SQLWCHAR *szAuthStr,
        SQLSMALLINT cbAuthStr)
    {
        sds+="SQLConnectW\n";
        wprintf(L"SQLConnectW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLCopyDesc(SQLHDESC SourceDescHandle,
                                        SQLHDESC TargetDescHandle)
    {
        sds+="SQLCopyDesc\n";
         wprintf(L"SQLCopyDesc called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDataSources(SQLHENV EnvironmentHandle,
                                           SQLUSMALLINT Direction, SQLCHAR *ServerName,
                                           SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1,
                                           SQLCHAR *Description, SQLSMALLINT BufferLength2,
                                           SQLSMALLINT *NameLength2)
    {
        sds+="SQLDataSources\n";
         wprintf(L"SQLDataSources called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDataSourcesA(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR        *szDSN,
    SQLSMALLINT        cbDSNMax,
    SQLSMALLINT    *pcbDSN,
    SQLCHAR        *szDescription,
    SQLSMALLINT        cbDescriptionMax,
    SQLSMALLINT    *pcbDescription)
    {
        sds+="SQLDataSourcesA\n";
         wprintf(L"SQLDataSourcesA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDataSourcesW(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLWCHAR        *szDSN,
    SQLSMALLINT        cbDSNMax,
    SQLSMALLINT    *pcbDSN,
    SQLWCHAR        *szDescription,
    SQLSMALLINT        cbDescriptionMax,
    SQLSMALLINT    *pcbDescription)
    {
        sds+="SQLDataSourcesW\n";
        wprintf(L"SQLDataSourcesW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDescribeColA(
    SQLHSTMT        hstmt,
    SQLUSMALLINT    icol,
    SQLCHAR         *szColName,
    SQLSMALLINT     cbColNameMax,
    SQLSMALLINT    	*pcbColName,
    SQLSMALLINT    	*pfSqlType,
    SQLULEN    		*pcbColDef,
    SQLSMALLINT    	*pibScale,
    SQLSMALLINT    	*pfNullable)
    {
        sds+="SQLDescribeColA\n";
        wprintf(L"SQLDescribeColA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDescribeColW(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLWCHAR        *szColName,
    SQLSMALLINT        cbColNameMax,
    SQLSMALLINT    *pcbColName,
    SQLSMALLINT    *pfSqlType,
    SQLULEN       *pcbColDef,
    SQLSMALLINT    *pibScale,
    SQLSMALLINT    *pfNullable)
    {
        sds+="SQLDescribeColW\n";
         wprintf(L"SQLDescribeColW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDescribeParam(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       ipar,
    SQLSMALLINT 	  *pfSqlType,
    SQLULEN 	      *pcbParamDef,
    SQLSMALLINT 	  *pibScale,
    SQLSMALLINT 	  *pfNullable)
    {
        sds+="SQLDescribeParam\n";
         wprintf(L"SQLDescribeParam called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDriverConnectA(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion)
    {
        sds+="SQLDriverConnectA\n";
         wprintf(L"SQLDriverConnectA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDriverConnectW(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLWCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLWCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion)
    {
        sds+="SQLDriverConnectW\n";
         wprintf(L"SQLDriverConnectW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDrivers(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR 		  *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT 	  *pcbDriverDesc,
    SQLCHAR 		  *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT 	  *pcbDrvrAttr)
    {
        sds+="SQLDrivers\n";
        wprintf(L"SQLDrivers called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDriversA(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR        *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT    *pcbDriverDesc,
    SQLCHAR        *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT    *pcbDrvrAttr)
    {
        sds+="SQLDriversA\n";
         wprintf(L"SQLDriversA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLDriversW(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLWCHAR        *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT    *pcbDriverDesc,
    SQLWCHAR        *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT    *pcbDrvrAttr)
    {
        sds+="SQLDriversW\n";
       wprintf(L"SQLDriversW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLErrorA(
    SQLHENV            henv,
    SQLHDBC            hdbc,
    SQLHSTMT           hstmt,
    SQLCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        sds+="SQLErrorA\n";
        wprintf(L"SQLErrorA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLErrorW(
    SQLHENV            henv,
    SQLHDBC            hdbc,
    SQLHSTMT           hstmt,
    SQLWCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLWCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        sds+="SQLErrorW\n";
         wprintf(L"SQLErrorW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLExecDirectA(
        SQLHSTMT hstmt,
        SQLCHAR *szSqlStr,
        SQLINTEGER cbSqlStr)
    {
        sds+="SQLExecDirectA\n";
        wprintf(L"SQLExecDirectA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLExecDirectW(
        SQLHSTMT hstmt,
        SQLWCHAR *szSqlStr,
        SQLINTEGER cbSqlStr)
    {
        sds+="SQLExecDirectW\n";
         wprintf(L"SQLExecDirectW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLExtendedFetch(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fFetchType,
    SQLLEN             irow,
    SQLULEN 	  	   *pcrow,
    SQLUSMALLINT 	   *rgfRowStatus)
    {
        sds+="SQLExtendedFetch\n";
        wprintf(L"SQLExtendedFetch called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLFetchScroll(SQLHSTMT StatementHandle,SQLSMALLINT FetchOrientation, SQLLEN FetchOffset)
    {
        sds+="SQLFetchScroll\n";
        wprintf(L"SQLFetchScroll called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLForeignKeys(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szPkCatalogName,
    SQLSMALLINT        cbPkCatalogName,
    SQLCHAR 		  *szPkSchemaName,
    SQLSMALLINT        cbPkSchemaName,
    SQLCHAR 		  *szPkTableName,
    SQLSMALLINT        cbPkTableName,
    SQLCHAR 		  *szFkCatalogName,
    SQLSMALLINT        cbFkCatalogName,
    SQLCHAR 		  *szFkSchemaName,
    SQLSMALLINT        cbFkSchemaName,
    SQLCHAR 		  *szFkTableName,
    SQLSMALLINT        cbFkTableName)
    {
        sds+="SQLForeignKeys\n";
        wprintf(L"SQLForeignKeys called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLForeignKeysA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szPkCatalogName,
    SQLSMALLINT        cbPkCatalogName,
    SQLCHAR        *szPkSchemaName,
    SQLSMALLINT        cbPkSchemaName,
    SQLCHAR        *szPkTableName,
    SQLSMALLINT        cbPkTableName,
    SQLCHAR        *szFkCatalogName,
    SQLSMALLINT        cbFkCatalogName,
    SQLCHAR        *szFkSchemaName,
    SQLSMALLINT        cbFkSchemaName,
    SQLCHAR        *szFkTableName,
    SQLSMALLINT        cbFkTableName)
    {
        sds+="SQLForeignKeysA\n";
         wprintf(L"SQLForeignKeysA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLForeignKeysW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szPkCatalogName,
    SQLSMALLINT        cbPkCatalogName,
    SQLWCHAR        *szPkSchemaName,
    SQLSMALLINT        cbPkSchemaName,
    SQLWCHAR        *szPkTableName,
    SQLSMALLINT        cbPkTableName,
    SQLWCHAR        *szFkCatalogName,
    SQLSMALLINT        cbFkCatalogName,
    SQLWCHAR        *szFkSchemaName,
    SQLSMALLINT        cbFkSchemaName,
    SQLWCHAR        *szFkTableName,
    SQLSMALLINT        cbFkTableName)
    {
        sds+="SQLForeignKeysW\n";
        wprintf(L"SQLForeignKeysW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLGetConnectAttr(SQLHDBC ConnectionHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER BufferLength, SQLINTEGER *StringLength)
    {
        sds+="SQLGetConnectAttr\n";
        wprintf(L"SQLGetConnectAttr called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetConnectAttrA(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        sds+="SQLGetConnectAttrA\n";
        wprintf(L"SQLGetConnectAttrA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetConnectAttrW(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        sds+="SQLGetConnectAttrW\n";
       wprintf(L"SQLGetConnectAttrW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetConnectOptionA(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam)
    {
        sds+="SQLGetConnectOptionA\n";
         wprintf(L"SQLGetConnectOptionA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetConnectOptionW(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam)
    {
        sds+="SQLGetConnectOptionW\n";
         wprintf(L"SQLGetConnectOptionW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLGetCursorName(SQLHSTMT StatementHandle,SQLCHAR *CursorName, SQLSMALLINT BufferLength,SQLSMALLINT *NameLength)
    {
        sds+="SQLGetCursorName\n";
         wprintf(L"SQLGetCursorName called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetCursorNameA(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szCursor,
    SQLSMALLINT        cbCursorMax,
    SQLSMALLINT    *pcbCursor)
    {
        sds+="SQLGetCursorNameA\n";
        wprintf(L"SQLGetCursorNameA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetCursorNameW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCursor,
    SQLSMALLINT        cbCursorMax,
    SQLSMALLINT    *pcbCursor)
    {
        sds+="SQLGetCursorNameW\n";
         wprintf(L"SQLGetCursorNameW called\n");
        return NULL;
    }
    SQLRETURN SQL_API SQLGetDescField(SQLHDESC DescriptorHandle,SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,SQLPOINTER Value, SQLINTEGER BufferLength,SQLINTEGER *StringLength)
    {
        sds+="SQLGetDescField\n";
         wprintf(L"SQLGetDescField called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDescFieldA(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        iField,
    SQLPOINTER         rgbValue,
    SQLINTEGER		   cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        sds+="SQLGetDescFieldA\n";
        wprintf(L"SQLGetDescFieldA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDescFieldW(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        iField,
    SQLPOINTER         rgbValue,
    SQLINTEGER		   cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        sds+="SQLGetDescFieldW\n";
        wprintf(L"SQLGetDescFieldW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDescRec(SQLHDESC DescriptorHandle,
                                          SQLSMALLINT RecNumber, SQLCHAR *Name,
                                          SQLSMALLINT BufferLength, SQLSMALLINT *StringLength,
                                          SQLSMALLINT *Type, SQLSMALLINT *SubType,
                                          SQLLEN *Length, SQLSMALLINT *Precision,
                                          SQLSMALLINT *Scale, SQLSMALLINT *Nullable)
    {
        sds+="SQLGetDescRec\n";
        wprintf(L"SQLGetDescRec called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDescRecA(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLCHAR        *szName,
    SQLSMALLINT        cbNameMax,
    SQLSMALLINT    *pcbName,
    SQLSMALLINT    *pfType,
    SQLSMALLINT    *pfSubType,
    SQLLEN     *pLength,
    SQLSMALLINT    *pPrecision, 
    SQLSMALLINT    *pScale,
    SQLSMALLINT    *pNullable)
    {
        sds+="SQLGetDescRecA\n";
         wprintf(L"SQLGetDescRecA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDescRecW(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLWCHAR        *szName,
    SQLSMALLINT        cbNameMax,
    SQLSMALLINT    *pcbName,
    SQLSMALLINT    *pfType,
    SQLSMALLINT    *pfSubType,
    SQLLEN         *pLength,
    SQLSMALLINT    *pPrecision, 
    SQLSMALLINT    *pScale,
    SQLSMALLINT    *pNullable)
    {
        sds+="SQLGetDescRecW\n";
         wprintf(L"SQLGetDescRecW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDiagField(SQLSMALLINT HandleType, SQLHANDLE Handle,
                                            SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
                                            SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
                                            SQLSMALLINT *StringLength)
    {
        sds+="SQLGetDiagField\n";
         wprintf(L"SQLGetDiagField called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDiagFieldA(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        fDiagField,
    SQLPOINTER         rgbDiagInfo,
    SQLSMALLINT        cbDiagInfoMax,
    SQLSMALLINT    *pcbDiagInfo)
    {
        sds+="SQLGetDiagFieldA\n";
         wprintf(L"SQLGetDiagFieldA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDiagFieldW(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        fDiagField,
    SQLPOINTER         rgbDiagInfo,
    SQLSMALLINT        cbDiagInfoMax,
    SQLSMALLINT    *pcbDiagInfo)
    {
        sds+="SQLGetDiagFieldW\n";
         wprintf(L"SQLGetDiagFieldW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDiagRecA(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        sds+="SQLGetDiagRecA\n";
         wprintf(L"SQLGetDiagRecA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetDiagRecW(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLWCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLWCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        sds+="SQLGetDiagRecW\n";
        wprintf(L"SQLGetDiagRecW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLGetEnvAttr(SQLHENV EnvironmentHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER BufferLength, SQLINTEGER *StringLength)
    {
        sds+="SQLGetEnvAttr\n";
        wprintf(L"SQLGetEnvAttr called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLGetInfo(SQLHDBC ConnectionHandle,SQLUSMALLINT InfoType, SQLPOINTER InfoValue,SQLSMALLINT BufferLength, SQLSMALLINT *StringLength)
    {
        sds+="SQLGetInfo\n";
         wprintf(L"SQLGetInfo called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetInfoA(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fInfoType,
    SQLPOINTER         rgbInfoValue,
    SQLSMALLINT        cbInfoValueMax,
    SQLSMALLINT*       pcbInfoValue)
    {
        sds+="SQLGetInfoA\n";
         wprintf(L"SQLGetInfoA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetInfoW(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fInfoType,
    SQLPOINTER         rgbInfoValue,
    SQLSMALLINT        cbInfoValueMax,
    SQLSMALLINT    *pcbInfoValue)
    {
        sds+="SQLGetInfoW\n";
         wprintf(L"SQLGetInfoW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLGetStmtAttr(SQLHSTMT StatementHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER BufferLength, SQLINTEGER *StringLength)
    {
        sds+="SQLGetStmtAttr\n";
         wprintf(L"SQLGetStmtAttr called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetStmtAttrA(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        sds+="SQLGetStmtAttrA\n";
        wprintf(L"SQLGetStmtAttrA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLGetStmtAttrW(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        sds+="SQLGetStmtAttrW\n";
         wprintf(L"SQLGetStmtAttrW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLGetStmtOption(SQLHSTMT StatementHandle,SQLUSMALLINT Option, SQLPOINTER Value)
    {
        sds+="SQLGetStmtOption\n";
         wprintf(L"SQLGetStmtOption called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLGetTypeInfo(SQLHSTMT StatementHandle,SQLSMALLINT DataType)
    {
        sds+="SQLGetTypeInfo\n";
         wprintf(L"SQLGetTypeInfo called\n");
        return NULL;
    }
    SQLRETURN SQL_API 	SQLGetTypeInfoA(
	SQLHSTMT			StatementHandle,
	SQLSMALLINT			DataTyoe)
    {
        sds+="SQLGetTypeInfoA\n";
        wprintf(L"SQLGetTypeInfoA called\n");
        return NULL;
    }
    SQLRETURN SQL_API 	SQLGetTypeInfoW(
	SQLHSTMT			StatementHandle,
	SQLSMALLINT			DataType)
    {
        sds+="SQLGetTypeInfoW\n";
        wprintf(L"SQLGetTypeInfoW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLNativeSql(
    SQLHDBC            hdbc,
    SQLCHAR 		  *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLCHAR 		  *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER 		  *pcbSqlStr)
    {
        sds+="SQLNativeSql\n";
         wprintf(L"SQLNativeSql called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLNativeSqlA(
    SQLHDBC            hdbc,
    SQLCHAR        *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER     *pcbSqlStr)
    {
        sds+="SQLNativeSqlA\n";
         wprintf(L"SQLNativeSqlA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLNativeSqlW(
    SQLHDBC            hdbc,
    SQLWCHAR        *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLWCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER     *pcbSqlStr)
    {
        sds+="SQLNativeSqlW\n";
         wprintf(L"SQLNativeSqlW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLNumParams(
    SQLHSTMT           hstmt,
    SQLSMALLINT 	  *pcpar)
    {
        sds+="SQLNumParams\n";
         wprintf(L"SQLNumParams called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLParamData(SQLHSTMT StatementHandle,SQLPOINTER *Value)
    {
        sds+="SQLParamData\n";
         wprintf(L"SQLParamData called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLParamOptions(
    SQLHSTMT           hstmt,
    SQLULEN        	   crow,
    SQLULEN 	  	   *pirow)
    {
        sds+="SQLParamOptions\n";
         wprintf(L"SQLParamOptions called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLPrepareA(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szSqlStr,
    SQLINTEGER         cbSqlStr)
    {
        sds+="SQLPrepareA\n";
         wprintf(L"SQLPrepareA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLPrepareW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStr)
    {
        sds+="SQLPrepareW\n";
         wprintf(L"SQLPrepareW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLPrimaryKeys(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName)
    {
        sds+="SQLPrimaryKeys\n";
        wprintf(L"SQLPrimaryKeys called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLPrimaryKeysA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        sds+="SQLPrimaryKeysA\n";
        wprintf(L"SQLPrimaryKeysA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLPrimaryKeysW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        sds+="SQLPrimaryKeysW\n";
         wprintf(L"SQLPrimaryKeysW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLProcedureColumns(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szProcName,
    SQLSMALLINT        cbProcName,
    SQLCHAR 		  *szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLProcedureColumns\n";
        wprintf(L"SQLProcedureColumns called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLProcedureColumnsA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szProcName,
    SQLSMALLINT        cbProcName,
    SQLCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLProcedureColumnsA\n";
        wprintf(L"SQLProcedureColumnsA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLProcedureColumnsW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szProcName,
    SQLSMALLINT        cbProcName,
    SQLWCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName)
    {
        sds+="SQLProcedureColumnsW\n";
         wprintf(L"SQLProcedureColumnsW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLProcedures(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szProcName,
    SQLSMALLINT        cbProcName)
    {
        sds+="SQLProcedures\n";
        wprintf(L"SQLProcedures called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLProceduresA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szProcName,
    SQLSMALLINT        cbProcName)
    {
        sds+="SQLProceduresA\n";
         wprintf(L"SQLProceduresA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLProceduresW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szProcName,
    SQLSMALLINT        cbProcName)
    {
        sds+="SQLProceduresW\n";
         wprintf(L"SQLProceduresW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLPutData(SQLHSTMT StatementHandle,SQLPOINTER Data, SQLLEN StrLen_or_Ind)
    {
        sds+="SQLPutData\n";
         wprintf(L"SQLPutData called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetConnectAttrA(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValue)
    {
        sds+="SQLSetConnectAttrA\n";
        wprintf(L"SQLSetConnectAttrA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetConnectAttrW(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValue)
    {
        sds+="SQLSetConnectAttrW\n";
         wprintf(L"SQLSetConnectAttrW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetConnectOptionA(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam)
    {
        sds+="SQLSetConnectOptionA\n";
         wprintf(L"SQLSetConnectOptionA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetConnectOptionW(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam)
    {
        sds+="SQLSetConnectOptionW\n";
         wprintf(L"SQLSetConnectOptionW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLSetCursorName(SQLHSTMT StatementHandle,SQLCHAR *CursorName, SQLSMALLINT NameLength)
    {
        sds+="SQLSetCursorName\n";
         wprintf(L"SQLSetCursorName called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetCursorNameA(
    SQLHSTMT           hstmt,
    SQLCHAR           *szCursor,
    SQLSMALLINT        cbCursor)
    {
        sds+="SQLSetCursorNameA\n";
         wprintf(L"SQLSetCursorNameA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetCursorNameW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCursor,
    SQLSMALLINT        cbCursor)
    {
        sds+="SQLSetCursorNameW\n";
        wprintf(L"SQLSetCursorNameW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLSetDescField(SQLHDESC DescriptorHandle,SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,SQLPOINTER Value, SQLINTEGER BufferLength)
    {
        sds+="SQLSetDescField\n";
         wprintf(L"SQLSetDescField called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLSetDescFieldW(SQLHDESC DescriptorHandle,SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,SQLPOINTER Value, SQLINTEGER BufferLength)
    {
        sds+="SQLSetDescFieldW\n";
         wprintf(L"SQLSetDescFieldW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetDescRec(SQLHDESC DescriptorHandle,
                                          SQLSMALLINT RecNumber, SQLSMALLINT Type,
                                          SQLSMALLINT SubType, SQLLEN Length,
                                          SQLSMALLINT Precision, SQLSMALLINT Scale,
                                          SQLPOINTER Data, SQLLEN *StringLength,
                                          SQLLEN *Indicator)
    {
        sds+="SQLSetDescRec\n";
        wprintf(L"SQLSetDescRec called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetParam(SQLHSTMT StatementHandle,
                                        SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                                        SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
                                        SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
                                        SQLLEN *StrLen_or_Ind)
    {
        sds+="SQLSetParam\n";
         wprintf(L"SQLSetParam called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetPos(
    SQLHSTMT           hstmt,
    SQLSETPOSIROW      irow,
    SQLUSMALLINT       fOption,
    SQLUSMALLINT       fLock)
    {
        sds+="SQLSetPos\n";
        wprintf(L"SQLSetPos called\n");
        return NULL;
    }
    /*      Deprecated functions from prior versions of ODBC */
    SQLRETURN SQL_API  SQLSetScrollOptions(    /*      Use SQLSetStmtOptions */
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fConcurrency,
    SQLLEN             crowKeyset,
    SQLUSMALLINT       crowRowset)
    {
        sds+="SQLSetScrollOptions\n";
        wprintf(L"SQLSetScrollOptions called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLSetStmtAttr(SQLHSTMT StatementHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER StringLength)
    {
        sds+="SQLSetStmtAttr\n";
         wprintf(L"SQLSetStmtAttr called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSetStmtAttrW(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax)
    {
        sds+="SQLSetStmtAttrW\n";
         wprintf(L"SQLSetStmtAttrW called\n");
        return NULL;
    }
    SQLRETURN SQL_API   SQLSetStmtOption(SQLHSTMT StatementHandle,SQLUSMALLINT Option, SQLULEN Value)
    {
        sds+="SQLSetStmtOption\n";
        wprintf(L"SQLSetStmtOption called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSpecialColumns(SQLHSTMT StatementHandle,
                                              SQLUSMALLINT IdentifierType, SQLCHAR *CatalogName,
                                              SQLSMALLINT NameLength1, SQLCHAR *SchemaName,
                                              SQLSMALLINT NameLength2, SQLCHAR *TableName,
                                              SQLSMALLINT NameLength3, SQLUSMALLINT Scope,
                                              SQLUSMALLINT Nullable)
    {
        sds+="SQLSpecialColumns\n";
         wprintf(L"SQLSpecialColumns called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSpecialColumnsA(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fColType,
    SQLCHAR        	*szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        	*szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        	*szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fScope,
    SQLUSMALLINT       fNullable)
    {
        sds+="SQLSpecialColumnsA\n";
         wprintf(L"SQLSpecialColumnsA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLSpecialColumnsW(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fColType,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fScope,
    SQLUSMALLINT       fNullable)
    {
        sds+="SQLSpecialColumnsW\n";
        wprintf(L"SQLSpecialColumnsW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLStatistics(SQLHSTMT StatementHandle,
                                          SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                                          SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
                                          SQLCHAR *TableName, SQLSMALLINT NameLength3,
                                          SQLUSMALLINT Unique, SQLUSMALLINT Reserved)
    {
        sds+="SQLStatistics\n";
        wprintf(L"SQLStatistics called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLStatisticsA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fUnique,
    SQLUSMALLINT       fAccuracy)
    {
        sds+="SQLStatisticsA\n";
         wprintf(L"SQLStatisticsA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLStatisticsW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fUnique,
    SQLUSMALLINT       fAccuracy)
    {
        sds+="SQLStatisticsW\n";
         wprintf(L"SQLStatisticsW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLTablePrivileges(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName)
    {
        sds+="SQLTablePrivileges\n";
         wprintf(L"SQLTablePrivileges called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLTablePrivilegesA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        sds+="SQLTablePrivilegesA\n";
        wprintf(L"SQLTablePrivilegesA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLTablePrivilegesW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        sds+="SQLTablePrivilegesW\n";
        wprintf(L"SQLTablePrivilegesW called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLTablesA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR        *szTableType,
    SQLSMALLINT        cbTableType)
    {
        sds+="SQLTablesA\n";
         wprintf(L"SQLTablesA called\n");
        return NULL;
    }
    SQLRETURN SQL_API  SQLTablesW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLWCHAR        *szTableType,
    SQLSMALLINT        cbTableType)
    {
        sds+="SQLTablesW\n";
         wprintf(L"SQLTablesW called\n");
        return NULL;
    }
    // lost
    SQLRETURN SQL_API SQLCancelHandle(  
      SQLSMALLINT  HandleType,  
      SQLHANDLE    Handle)
      {
          sds+="SQLCancelHandle\n";
          wprintf(L"SQLCancelHandle called\n");
        return NULL;
      }
      SQLRETURN SQL_API SQLCompleteAsync(  
      SQLSMALLINT HandleType,  
      SQLHANDLE   Handle,  
      RETCODE *   AsyncRetCodePtr)
      {
          sds+="SQLCompleteAsync\n";
           wprintf(L"SQLCompleteAsync called\n");
        return NULL;
      }
      SQLRETURN SQL_API  SQLAllocHandleStd(SQLSMALLINT fHandleType, SQLHANDLE hInput, SQLHANDLE * phOutput)
      {
          using namespace std;
          sds += "SQLAllocHandleStd\n";
          ofstream myfile( GetProgramDir()+"\\hello.txt", ios::trunc);
          if (myfile.is_open())
          {
              myfile << sds;
              myfile << endl;
              myfile.close();
          }
          wprintf(L"SQLAllocHandleStd called\n");
          return NULL;
      }
      void CloseODBCPerfData()
      {
          sds += "CloseODBCPerfData\n";
          wprintf(L"CloseODBCPerfData called\n");
      }
      void CollectODBCPerfData()
      {
          sds += "CollectODBCPerfData\n";
          wprintf(L"CollectODBCPerfData called\n");
      }
      void CursorLibLockDbc()
      {
          sds += "CursorLibLockDbc\n";
          wprintf(L"CursorLibLockDbc called\n");
      }
      void CursorLibLockDesc()
      {
          sds += "CursorLibLockDesc\n";
          wprintf(L"CursorLibLockDbc called\n");
      }
      void CursorLibLockStmt()
      {
          sds += "CursorLibLockStmt\n";
          wprintf(L"CursorLibLockDbc called\n");
      }
      void CursorLibTransact()
      {
          sds += "CursorLibTransact\n";
          wprintf(L"CursorLibTransact called\n");
      }
      void DllBidEntryPoint()
      {
          sds += "DllBidEntryPoint\n";
          wprintf(L"DllBidEntryPoint called\n");
      }
      void GetODBCSharedData()
      {
          sds += "GetODBCSharedData\n";
          wprintf(L"GetODBCSharedData called\n");
      }
      void LockHandle()
      {
          sds += "LockHandle\n";
          wprintf(L"LockHandle called\n");
      }
      DWORD SQL_API ODBCGetTryWaitValue()
      {
          sds += "ODBCGetTryWaitValue\n";
          wprintf(L"ODBCGetTryWaitValue called\n");
          return NULL;
      }
      void ODBCInternalConnectW()
      {
          sds += "ODBCInternalConnectW\n";
          wprintf(L"ODBCInternalConnectW called\n");
      }
      void ODBCQualifyFileDSNW()
      {
          sds += "ODBCQualifyFileDSNW\n";
          wprintf(L"ODBCQualifyFileDSNW called\n");
      }
      void ODBCSetTryWaitValue()
      {
          sds += "ODBCSetTryWaitValue\n";
          wprintf(L"ODBCSetTryWaitValue called\n");
      }
      void OpenODBCPerfData()
      {
          sds += "OpenODBCPerfData\n";
          wprintf(L"OpenODBCPerfData called\n");
      }
      void PostComponentError()
      {
          sds += "PostComponentError\n";
          wprintf(L"PostComponentError called\n");
      }
      void PostODBCComponentError()
      {
          sds += "PostODBCComponentError\n";
          wprintf(L"PostODBCComponentError called\n");
      }
      void PostODBCError()
      {
          sds += "PostODBCError\n";
          wprintf(L"PostODBCError called\n");
      }
      void SQLGetConnectOption()
      {
          sds += "SQLGetConnectOption\n";
          wprintf(L"SQLGetConnectOption called\n");
      }
      void SQLSetDescFieldA()
      {
          sds += "SQLSetDescFieldA\n";
          wprintf(L"SQLSetDescFieldA called\n");
      }
      void SQLSetStmtAttrA()
      {
          sds += "SQLSetStmtAttrA\n";
          wprintf(L"SQLSetStmtAttrA called\n");
      }
      void SearchStatusCode()
      {
          sds += "SearchStatusCode\n";
          wprintf(L"SearchStatusCode called\n");
      }
      void VFreeErrors()
      {
          sds += "VFreeErrors\n";
          wprintf(L"VFreeErrors called\n");
      }
      void VRetrieveDriverErrorsRowCol()
      {
          sds += "VRetrieveDriverErrorsRowCol\n";
          wprintf(L"VRetrieveDriverErrorsRowCol called\n");
      }
      void ValidateErrorQueue()
      {
          sds += "ValidateErrorQueue\n";
          wprintf(L"ValidateErrorQueue called\n");
      }
      void g_hHeapMalloc()
      {
          sds += "g_hHeapMalloc\n";
          wprintf(L"g_hHeapMalloc called\n");
      }

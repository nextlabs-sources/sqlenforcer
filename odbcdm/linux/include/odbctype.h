#ifndef ODBC_TYPE_H
#define ODBC_TYPE_H
#include <sql.h>
#include <sqlext.h>

typedef SQLRETURN(SQL_API *SQLGetDiagRecFun)(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber, SQLCHAR *Sqlstate,  SQLINTEGER *NativeError, SQLCHAR *MessageText,  SQLSMALLINT BufferLength, SQLSMALLINT *TextLength);
typedef SQLRETURN(SQL_API *SQLAllocHandleFun)(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle);
typedef SQLRETURN(SQL_API *SQLSetEnvAttrFun)(SQLHENV EnvironmentHandle, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER StringLength);
typedef SQLRETURN(SQL_API *SQLConnectFun)(SQLHDBC ConnectionHandle,  SQLCHAR *ServerName, SQLSMALLINT NameLength1, SQLCHAR *UserName, SQLSMALLINT NameLength2, SQLCHAR *Authentication, SQLSMALLINT NameLength3);
typedef SQLRETURN(SQL_API *SQLDriverConnectFun)(SQLHDBC hdbc,SQLHWND hwnd,SQLCHAR *szConnStrIn, SQLSMALLINT cbConnStrIn,SQLCHAR           *szConnStrOut, SQLSMALLINT        cbConnStrOutMax,SQLSMALLINT 	  *pcbConnStrOut, SQLUSMALLINT       fDriverCompletion);
typedef SQLRETURN(SQL_API *SQLExecDirectFun)(SQLHSTMT StatementHandle,  SQLCHAR *StatementText, SQLINTEGER TextLength);
typedef SQLRETURN(SQL_API *SQLNumResultColsFun)(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount);
typedef SQLRETURN(SQL_API *SQLRowCountFun)(SQLHSTMT StatementHandle,  SQLLEN *RowCount);
typedef SQLRETURN(SQL_API *SQLCloseCursorFun)(SQLHSTMT StatementHandle);
typedef SQLRETURN(SQL_API *SQLFreeStmtFun)(SQLHSTMT StatementHandle, SQLUSMALLINT Option);
typedef SQLRETURN(SQL_API *SQLFreeHandleFun)(SQLSMALLINT HandleType, SQLHANDLE Handle);
typedef SQLRETURN(SQL_API *SQLFreeEnvFun)(SQLHENV EnvironmentHandle);
typedef SQLRETURN(SQL_API *SQLFreeConnectFun)(SQLHDBC ConnectionHandle);
typedef SQLRETURN(SQL_API *SQLDisconnectFun)(SQLHDBC ConnectionHandle);
typedef SQLRETURN(SQL_API *SQLGetFunctionsFun)(SQLHDBC ConnectionHandle, SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported);
typedef SQLRETURN(SQL_API *SQLColumnsFun)(SQLHSTMT StatementHandle,SQLCHAR *CatalogName, SQLSMALLINT NameLength1,SQLCHAR *SchemaName, SQLSMALLINT NameLength2,SQLCHAR *TableName, SQLSMALLINT NameLength3,SQLCHAR *ColumnName, SQLSMALLINT NameLength4);
typedef SQLRETURN(SQL_API *SQLFetchFun)(SQLHSTMT StatementHandle);
typedef SQLRETURN(SQL_API *SQLDescribeColFun)(SQLHSTMT StatementHandle,SQLUSMALLINT ColumnNumber, SQLCHAR *ColumnName,  SQLSMALLINT BufferLength, SQLSMALLINT *NameLength,  SQLSMALLINT *DataType, SQLULEN *ColumnSize, SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable);
typedef SQLRETURN(SQL_API *SQLAllocStmtFun)(SQLHDBC ConnectionHandle,SQLHSTMT *StatementHandle);
typedef SQLRETURN(SQL_API *SQLSetConnectOptionFun)(SQLHDBC ConnectionHandle,SQLUSMALLINT Option, SQLULEN Value);
typedef SQLRETURN(SQL_API *SQLColAttributeFun)(SQLHSTMT StatementHandle,SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength, SQLSMALLINT *StringLength, SQLLEN *NumericAttribute );
typedef SQLRETURN(SQL_API *SQLPrepareFun)(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength);
typedef SQLRETURN(SQL_API *SQLErrorFun)(SQLHENV EnvironmentHandle,SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,SQLCHAR *Sqlstate, SQLINTEGER *NativeError,SQLCHAR *MessageText, SQLSMALLINT BufferLength,SQLSMALLINT *TextLength);
typedef SQLRETURN(SQL_API *SQLSetConnectAttrFun)(SQLHDBC ConnectionHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER StringLength);
typedef SQLRETURN(SQL_API *SQLAllocEnvFun)(SQLHENV *EnvironmentHandle);
typedef SQLRETURN(SQL_API *SQLTransactFun)(SQLHENV EnvironmentHandle,SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType);
typedef SQLRETURN(SQL_API *SQLExecuteFun)(SQLHSTMT StatementHandle);
typedef SQLRETURN(SQL_API *SQLAllocConnectFun)(SQLHENV EnvironmentHandle, SQLHDBC *ConnectionHandle);
typedef SQLRETURN(SQL_API *SQLEndTranFun)(SQLSMALLINT HandleType, SQLHANDLE Handle,SQLSMALLINT CompletionType);
typedef SQLRETURN(SQL_API *SQLGetDataFun)(SQLHSTMT StatementHandle,SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,SQLPOINTER TargetValue, SQLLEN BufferLength,SQLLEN *StrLen_or_Ind);
typedef SQLRETURN(SQL_API *SQLTablesFun)(SQLHSTMT StatementHandle,SQLCHAR *CatalogName, SQLSMALLINT NameLength1,SQLCHAR *SchemaName, SQLSMALLINT NameLength2,SQLCHAR *TableName, SQLSMALLINT NameLength3,SQLCHAR *TableType, SQLSMALLINT NameLength4);
typedef SQLRETURN(SQL_API *SQLMoreResultsFun)(SQLHSTMT hstmt); 
typedef SQLRETURN(SQL_API *SQLBulkOperationsFun)(
    SQLHSTMT            StatementHandle,
    SQLSMALLINT         Operation);
typedef SQLRETURN(SQL_API *SQLCancelFun)(SQLHSTMT StatementHandle);
typedef SQLRETURN(SQL_API *SQLBindColFun)(SQLHSTMT StatementHandle,
           SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
           SQLPOINTER TargetValue, 
           SQLLEN BufferLength,SQLLEN *StrLen_or_Ind);
typedef SQLRETURN(SQL_API *SQLBindParamFun)(SQLHSTMT StatementHandle,
                                    SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                                    SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
                                    SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
                                    SQLLEN *StrLen_or_Ind);
typedef SQLRETURN(SQL_API *SQLBindParameterFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       ipar,
    SQLSMALLINT        fParamType,
    SQLSMALLINT        fCType,
    SQLSMALLINT        fSqlType,
    SQLULEN            cbColDef,
    SQLSMALLINT        ibScale,
    SQLPOINTER         rgbValue,
    SQLLEN             cbValueMax,
    SQLLEN 		      *pcbValue);  

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
typedef SQLRETURN(SQL_API *SQLColAttributeAFun)(
	SQLHSTMT		hstmt,
	SQLSMALLINT		iCol,
	SQLSMALLINT		iField,
	SQLPOINTER		pCharAttr,
	SQLSMALLINT		cbCharAttrMax,	
	SQLSMALLINT  	        *pcbCharAttr,
	SQLLEN              	*pNumAttr);	 
typedef SQLRETURN(SQL_API *SQLColAttributeWFun)(
	SQLHSTMT		hstmt,
	SQLUSMALLINT	iCol,
	SQLUSMALLINT	iField,
	SQLPOINTER		pCharAttr,
	SQLSMALLINT		cbCharAttrMax,	
	SQLSMALLINT  	*pcbCharAttr,
	SQLLEN		*pNumAttr);	  
typedef SQLRETURN(SQL_API *SQLColAttributesFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLUSMALLINT       fDescType,
    SQLPOINTER         rgbDesc,
    SQLSMALLINT        cbDescMax,
    SQLSMALLINT 	  *pcbDesc,
    SQLLEN 		      *pfDesc); 
typedef SQLRETURN(SQL_API *SQLColAttributesAFun)(
    SQLHSTMT        hstmt,
    SQLUSMALLINT    icol,
    SQLUSMALLINT    fDescType,
    SQLPOINTER      rgbDesc,
    SQLSMALLINT     cbDescMax,
    SQLSMALLINT    	*pcbDesc,
    SQLLEN     		*pfDesc);   
typedef SQLRETURN(SQL_API *SQLColAttributesWFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLUSMALLINT       fDescType,
    SQLPOINTER         rgbDesc,
    SQLSMALLINT        cbDescMax,
    SQLSMALLINT        *pcbDesc,
    SQLLEN             *pfDesc);    
typedef SQLRETURN(SQL_API *SQLColumnPrivilegesFun)(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR 		  *szColumnName,
    SQLSMALLINT        cbColumnName);   
typedef SQLRETURN(SQL_API *SQLColumnPrivilegesAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName);  
typedef SQLRETURN(SQL_API *SQLColumnPrivilegesWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLWCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName);    
typedef SQLRETURN(SQL_API *SQLColumnsAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        	*szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        	*szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR        	*szColumnName,
    SQLSMALLINT        cbColumnName); 
typedef SQLRETURN(SQL_API *SQLColumnsWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLWCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName);  
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
typedef SQLRETURN(SQL_API *SQLCopyDescFun)(SQLHDESC SourceDescHandle,
                                   SQLHDESC TargetDescHandle);
typedef SQLRETURN(SQL_API *SQLDataSourcesFun)(SQLHENV EnvironmentHandle,
                                      SQLUSMALLINT Direction, SQLCHAR *ServerName,
                                      SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1,
                                      SQLCHAR *Description, SQLSMALLINT BufferLength2,
                                      SQLSMALLINT *NameLength2);
typedef SQLRETURN(SQL_API *SQLDataSourcesAFun)(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR        *szDSN,
    SQLSMALLINT        cbDSNMax,
    SQLSMALLINT    *pcbDSN,
    SQLCHAR        *szDescription,
    SQLSMALLINT        cbDescriptionMax,
    SQLSMALLINT    *pcbDescription);
typedef SQLRETURN(SQL_API *SQLDataSourcesWFun)(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLWCHAR        *szDSN,
    SQLSMALLINT        cbDSNMax,
    SQLSMALLINT    *pcbDSN,
    SQLWCHAR        *szDescription,
    SQLSMALLINT        cbDescriptionMax,
    SQLSMALLINT    *pcbDescription);
typedef SQLRETURN(SQL_API *SQLDescribeColAFun)(
    SQLHSTMT        hstmt,
    SQLUSMALLINT    icol,
    SQLCHAR         *szColName,
    SQLSMALLINT     cbColNameMax,
    SQLSMALLINT    	*pcbColName,
    SQLSMALLINT    	*pfSqlType,
    SQLULEN    		*pcbColDef,
    SQLSMALLINT    	*pibScale,
    SQLSMALLINT    	*pfNullable);
typedef SQLRETURN(SQL_API *SQLDescribeColWFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLWCHAR        *szColName,
    SQLSMALLINT        cbColNameMax,
    SQLSMALLINT    *pcbColName,
    SQLSMALLINT    *pfSqlType,
    SQLULEN       *pcbColDef,
    SQLSMALLINT    *pibScale,
    SQLSMALLINT    *pfNullable);
typedef SQLRETURN(SQL_API *SQLDescribeParamFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       ipar,
    SQLSMALLINT 	  *pfSqlType,
    SQLULEN 	      *pcbParamDef,
    SQLSMALLINT 	  *pibScale,
    SQLSMALLINT 	  *pfNullable);
typedef SQLRETURN(SQL_API *SQLDriverConnectAFun)(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion);
typedef SQLRETURN(SQL_API *SQLDriverConnectWFun)(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLWCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLWCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion);
typedef SQLRETURN(SQL_API *SQLDriversFun)(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR 		  *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT 	  *pcbDriverDesc,
    SQLCHAR 		  *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT 	  *pcbDrvrAttr);
typedef SQLRETURN(SQL_API *SQLDriversAFun)(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR        *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT    *pcbDriverDesc,
    SQLCHAR        *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT    *pcbDrvrAttr);
typedef SQLRETURN(SQL_API *SQLDriversWFun)(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLWCHAR        *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT    *pcbDriverDesc,
    SQLWCHAR        *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT    *pcbDrvrAttr);
typedef SQLRETURN(SQL_API *SQLErrorAFun)(
    SQLHENV            henv,
    SQLHDBC            hdbc,
    SQLHSTMT           hstmt,
    SQLCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg);
typedef SQLRETURN(SQL_API *SQLErrorWFun)(
    SQLHENV            henv,
    SQLHDBC            hdbc,
    SQLHSTMT           hstmt,
    SQLWCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLWCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg);
typedef SQLRETURN(SQL_API *SQLExecDirectAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR           *szSqlStr,
    SQLINTEGER         cbSqlStr);
typedef SQLRETURN(SQL_API *SQLExecDirectWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStr);
typedef SQLRETURN(SQL_API *SQLExtendedFetchFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fFetchType,
    SQLLEN             irow,
    SQLULEN 	  	   *pcrow,
    SQLUSMALLINT 	   *rgfRowStatus);
typedef SQLRETURN(SQL_API *SQLFetchScrollFun)(SQLHSTMT StatementHandle,
                                      SQLSMALLINT FetchOrientation, SQLLEN FetchOffset);
typedef SQLRETURN(SQL_API *SQLForeignKeysFun)(
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
    SQLSMALLINT        cbFkTableName);
typedef SQLRETURN(SQL_API *SQLForeignKeysAFun)(
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
    SQLSMALLINT        cbFkTableName);
typedef SQLRETURN(SQL_API *SQLForeignKeysWFun)(
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
    SQLSMALLINT        cbFkTableName);
typedef SQLRETURN(SQL_API *SQLGetConnectAttrFun)(SQLHDBC ConnectionHandle,
                                         SQLINTEGER Attribute, SQLPOINTER Value,
                                         SQLINTEGER BufferLength, SQLINTEGER *StringLength);
typedef SQLRETURN(SQL_API *SQLGetConnectAttrAFun)(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue);
typedef SQLRETURN(SQL_API *SQLGetConnectAttrWFun)(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue);
typedef SQLRETURN(SQL_API *SQLGetConnectOptionAFun)(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam);
typedef SQLRETURN(SQL_API *SQLGetConnectOptionWFun)(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam);
typedef SQLRETURN(SQL_API *SQLGetCursorNameFun)(SQLHSTMT StatementHandle,
                                        SQLCHAR *CursorName, SQLSMALLINT BufferLength,
                                        SQLSMALLINT *NameLength);
typedef SQLRETURN(SQL_API *SQLGetCursorNameAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szCursor,
    SQLSMALLINT        cbCursorMax,
    SQLSMALLINT    *pcbCursor);
typedef SQLRETURN(SQL_API *SQLGetCursorNameWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCursor,
    SQLSMALLINT        cbCursorMax,
    SQLSMALLINT    *pcbCursor);
typedef SQLRETURN(*SQLGetDescFieldFun)(SQLHDESC DescriptorHandle,
                                SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
                                SQLPOINTER Value, SQLINTEGER BufferLength,
                                SQLINTEGER *StringLength);
typedef SQLRETURN(SQL_API *SQLGetDescFieldAFun)(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        iField,
    SQLPOINTER         rgbValue,
    SQLINTEGER		   cbValueMax,
    SQLINTEGER     *pcbValue);
typedef SQLRETURN(SQL_API *SQLGetDescFieldWFun)(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        iField,
    SQLPOINTER         rgbValue,
    SQLINTEGER		   cbValueMax,
    SQLINTEGER     *pcbValue);
typedef SQLRETURN(SQL_API *SQLGetDescRecFun)(SQLHDESC DescriptorHandle,
                                     SQLSMALLINT RecNumber, SQLCHAR *Name,
                                     SQLSMALLINT BufferLength, SQLSMALLINT *StringLength,
                                     SQLSMALLINT *Type, SQLSMALLINT *SubType,
                                     SQLLEN *Length, SQLSMALLINT *Precision,
                                     SQLSMALLINT *Scale, SQLSMALLINT *Nullable);
typedef SQLRETURN(SQL_API *SQLGetDescRecAFun)(
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
    SQLSMALLINT    *pNullable);
typedef SQLRETURN(SQL_API *SQLGetDescRecWFun)(
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
    SQLSMALLINT    *pNullable);
typedef SQLRETURN(SQL_API *SQLGetDiagFieldFun)(SQLSMALLINT HandleType, SQLHANDLE Handle,
                                       SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
                                       SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
                                       SQLSMALLINT *StringLength);
typedef SQLRETURN(SQL_API *SQLGetDiagFieldAFun)(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        fDiagField,
    SQLPOINTER         rgbDiagInfo,
    SQLSMALLINT        cbDiagInfoMax,
    SQLSMALLINT    *pcbDiagInfo);
typedef SQLRETURN(SQL_API *SQLGetDiagFieldWFun)(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        fDiagField,
    SQLPOINTER         rgbDiagInfo,
    SQLSMALLINT        cbDiagInfoMax,
    SQLSMALLINT    *pcbDiagInfo);
typedef SQLRETURN(SQL_API *SQLGetDiagRecAFun)(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg);
typedef SQLRETURN(SQL_API *SQLGetDiagRecWFun)(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLWCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLWCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg);
typedef SQLRETURN(SQL_API *SQLGetEnvAttrFun)(SQLHENV EnvironmentHandle,
                                     SQLINTEGER Attribute, SQLPOINTER Value,
                                     SQLINTEGER BufferLength, SQLINTEGER *StringLength);
typedef SQLRETURN(SQL_API *SQLGetInfoFun)(SQLHDBC ConnectionHandle,
                                  SQLUSMALLINT InfoType, SQLPOINTER InfoValue,
                                  SQLSMALLINT BufferLength, SQLSMALLINT *StringLength);
typedef SQLRETURN(SQL_API *SQLGetInfoAFun)(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fInfoType,
    SQLPOINTER         rgbInfoValue,
    SQLSMALLINT        cbInfoValueMax,
    SQLSMALLINT*       pcbInfoValue);
typedef SQLRETURN(SQL_API *SQLGetInfoWFun)(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fInfoType,
    SQLPOINTER         rgbInfoValue,
    SQLSMALLINT        cbInfoValueMax,
    SQLSMALLINT    *pcbInfoValue);
typedef SQLRETURN(SQL_API *SQLGetStmtAttrFun)(SQLHSTMT StatementHandle,
                                      SQLINTEGER Attribute, SQLPOINTER Value,
                                      SQLINTEGER BufferLength, SQLINTEGER *StringLength);
typedef SQLRETURN(SQL_API *SQLGetStmtAttrAFun)(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue);
typedef SQLRETURN(SQL_API *SQLGetStmtAttrWFun)(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue);
typedef SQLRETURN(SQL_API *SQLGetStmtOptionFun)(SQLHSTMT StatementHandle,
                                        SQLUSMALLINT Option, SQLPOINTER Value);
typedef SQLRETURN(SQL_API *SQLGetStmtOptionAFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam);
typedef SQLRETURN(SQL_API *SQLGetTypeInfoFun)(SQLHSTMT StatementHandle,
                                      SQLSMALLINT DataType);
typedef SQLRETURN(SQL_API	*SQLGetTypeInfoAFun)(
	SQLHSTMT			StatementHandle,
	SQLSMALLINT			DataTyoe);
typedef SQLRETURN(SQL_API	*SQLGetTypeInfoWFun)(
	SQLHSTMT			StatementHandle,
	SQLSMALLINT			DataType);
typedef SQLRETURN(SQL_API *SQLNativeSqlFun)(
    SQLHDBC            hdbc,
    SQLCHAR 		  *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLCHAR 		  *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER 		  *pcbSqlStr);
typedef SQLRETURN(SQL_API *SQLNativeSqlAFun)(
    SQLHDBC            hdbc,
    SQLCHAR        *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER     *pcbSqlStr);
typedef SQLRETURN(SQL_API *SQLNativeSqlWFun)(
    SQLHDBC            hdbc,
    SQLWCHAR        *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLWCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER     *pcbSqlStr);
typedef SQLRETURN(SQL_API *SQLNumParamsFun)(
    SQLHSTMT           hstmt,
    SQLSMALLINT 	  *pcpar);
typedef SQLRETURN(SQL_API *SQLParamDataFun)(SQLHSTMT StatementHandle,
                                    SQLPOINTER *Value);
typedef SQLRETURN(SQL_API *SQLParamOptionsFun)(
    SQLHSTMT           hstmt,
    SQLULEN        	   crow,
    SQLULEN 	  	   *pirow);
typedef SQLRETURN(SQL_API *SQLPrepareAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szSqlStr,
    SQLINTEGER         cbSqlStr);
typedef SQLRETURN(SQL_API *SQLPrepareWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStr);
typedef SQLRETURN(SQL_API *SQLPrimaryKeysFun)(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName);
typedef SQLRETURN(SQL_API *SQLPrimaryKeysAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName);
typedef SQLRETURN(SQL_API *SQLPrimaryKeysWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName);
typedef SQLRETURN(SQL_API *SQLProcedureColumnsFun)(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szProcName,
    SQLSMALLINT        cbProcName,
    SQLCHAR 		  *szColumnName,
    SQLSMALLINT        cbColumnName);
typedef SQLRETURN(SQL_API *SQLProcedureColumnsAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szProcName,
    SQLSMALLINT        cbProcName,
    SQLCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName);
typedef SQLRETURN(SQL_API *SQLProcedureColumnsWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szProcName,
    SQLSMALLINT        cbProcName,
    SQLWCHAR        *szColumnName,
    SQLSMALLINT        cbColumnName);
typedef SQLRETURN(SQL_API *SQLProceduresFun)(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szProcName,
    SQLSMALLINT        cbProcName);
typedef SQLRETURN(SQL_API *SQLProceduresAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szProcName,
    SQLSMALLINT        cbProcName);
typedef SQLRETURN(SQL_API *SQLProceduresWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szProcName,
    SQLSMALLINT        cbProcName);
typedef SQLRETURN(SQL_API *SQLPutDataFun)(SQLHSTMT StatementHandle,
                                  SQLPOINTER Data, SQLLEN StrLen_or_Ind);
typedef SQLRETURN(SQL_API *SQLSetConnectAttrAFun)(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValue);
typedef SQLRETURN(SQL_API *SQLSetConnectAttrWFun)(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValue);
typedef SQLRETURN(SQL_API *SQLSetConnectOptionAFun)(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam);
typedef SQLRETURN(SQL_API *SQLSetConnectOptionWFun)(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam);
typedef SQLRETURN(SQL_API *SQLSetCursorNameFun)(SQLHSTMT StatementHandle,
                                        SQLCHAR *CursorName, SQLSMALLINT NameLength);
typedef SQLRETURN(SQL_API *SQLSetCursorNameAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR           *szCursor,
    SQLSMALLINT        cbCursor);
typedef SQLRETURN(SQL_API *SQLSetCursorNameWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCursor,
    SQLSMALLINT        cbCursor);
typedef SQLRETURN(SQL_API *SQLSetDescFieldFun)(SQLHDESC DescriptorHandle,
                                       SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
                                       SQLPOINTER Value, SQLINTEGER BufferLength);
typedef SQLRETURN(SQL_API *SQLSetDescFieldWFun)(SQLHDESC DescriptorHandle,
           						   SQLSMALLINT RecNumber, 
								   SQLSMALLINT FieldIdentifier,
           						   SQLPOINTER Value, 
								   SQLINTEGER BufferLength);
typedef SQLRETURN(SQL_API *SQLSetDescRecFun)(SQLHDESC DescriptorHandle,
                                     SQLSMALLINT RecNumber, SQLSMALLINT Type,
                                     SQLSMALLINT SubType, SQLLEN Length,
                                     SQLSMALLINT Precision, SQLSMALLINT Scale,
                                     SQLPOINTER Data, SQLLEN *StringLength,
                                     SQLLEN *Indicator);
typedef SQLRETURN(SQL_API *SQLSetParamFun)(SQLHSTMT StatementHandle,
                                   SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                                   SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
                                   SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
                                   SQLLEN *StrLen_or_Ind);
typedef SQLRETURN(SQL_API *SQLSetPosFun)(
    SQLHSTMT           hstmt,
    SQLSETPOSIROW      irow,
    SQLUSMALLINT       fOption,
    SQLUSMALLINT       fLock);
/*      Deprecated functions from prior versions of ODBC */
typedef SQLRETURN(SQL_API *SQLSetScrollOptionsFun)(    /*      Use SQLSetStmtOptions */
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fConcurrency,
    SQLLEN             crowKeyset,
    SQLUSMALLINT       crowRowset);
typedef SQLRETURN(SQL_API *SQLSetStmtAttrFun)(SQLHSTMT StatementHandle,
                                      SQLINTEGER Attribute, SQLPOINTER Value,
                                      SQLINTEGER StringLength);
typedef SQLRETURN(SQL_API *SQLSetStmtAttrWFun)(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax);
typedef SQLRETURN(SQL_API *SQLSetStmtOptionFun)(SQLHSTMT StatementHandle,
                                        SQLUSMALLINT Option, SQLULEN Value);
typedef SQLRETURN(SQL_API *SQLSetStmtOptionAFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam);
typedef SQLRETURN(SQL_API *SQLSpecialColumnsFun)(SQLHSTMT StatementHandle,
                                         SQLUSMALLINT IdentifierType, SQLCHAR *CatalogName,
                                         SQLSMALLINT NameLength1, SQLCHAR *SchemaName,
                                         SQLSMALLINT NameLength2, SQLCHAR *TableName,
                                         SQLSMALLINT NameLength3, SQLUSMALLINT Scope,
                                         SQLUSMALLINT Nullable);
typedef SQLRETURN(SQL_API *SQLSpecialColumnsAFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fColType,
    SQLCHAR        	*szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        	*szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        	*szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fScope,
    SQLUSMALLINT       fNullable);
typedef SQLRETURN(SQL_API *SQLSpecialColumnsWFun)(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fColType,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fScope,
    SQLUSMALLINT       fNullable);
typedef SQLRETURN(SQL_API *SQLStatisticsFun)(SQLHSTMT StatementHandle,
                                     SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                                     SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
                                     SQLCHAR *TableName, SQLSMALLINT NameLength3,
                                     SQLUSMALLINT Unique, SQLUSMALLINT Reserved);
typedef SQLRETURN(SQL_API *SQLStatisticsAFun)(
    SQLHSTMT           hstmt,

    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fUnique,
    SQLUSMALLINT       fAccuracy);
typedef SQLRETURN(SQL_API *SQLStatisticsWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLUSMALLINT       fUnique,
    SQLUSMALLINT       fAccuracy);
typedef SQLRETURN(SQL_API *SQLTablePrivilegesFun)(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName);
typedef SQLRETURN(SQL_API *SQLTablePrivilegesAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName);
typedef SQLRETURN(SQL_API *SQLTablePrivilegesWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName);
typedef SQLRETURN(SQL_API *SQLTablesAFun)(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLCHAR        *szTableType,
    SQLSMALLINT        cbTableType);
typedef SQLRETURN(SQL_API *SQLTablesWFun)(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName,
    SQLWCHAR        *szTableType,
    SQLSMALLINT        cbTableType);

                                
#endif 

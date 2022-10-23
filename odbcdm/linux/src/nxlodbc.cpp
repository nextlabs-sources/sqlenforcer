#include "nxlodbc.h"
#include "odbcproxy.h"
#include <sql.h>
#include <sqlext.h>
#include "enforcerwrapper.h"
#include "sqlexception.h"

#define EXPORT_API  __attribute__((visibility("default")))
#define EXPORT_SQLAPI SQL_API __attribute__((visibility("default")))
#define ODBCINST COdbcProxy::Instance()
class EnforcerData
{
	typedef void *NxlHandler;

  private:
	std::map<NxlHandler, unsigned long> enforcerContext;
	std::map<SQLHANDLE, SQLHANDLE> handlerdict;

  public:
	static EnforcerData &Instance()
	{
		static EnforcerData enforcerData;
		return enforcerData;
	};
	void enforcerContextInsert(NxlHandler dataKey, unsigned long dataValue)
	{
		enforcerContext.insert(std::pair<NxlHandler, unsigned long>(dataKey, dataValue));
	}
	int enforcerContextRemove(NxlHandler dataKey)
	{
		return enforcerContext.erase(dataKey);
	}
	bool enforcerContextFind(NxlHandler dataKey, unsigned long &keyValue)
	{
		std::map<NxlHandler, unsigned long>::iterator iter;
		iter = enforcerContext.find(dataKey);
		if (iter != enforcerContext.end())
		{
			keyValue = iter->second;
			return true;
		}
		else
		{
			return false;
		}
	}
	void handlerdictInsert(SQLHANDLE dataKey, SQLHANDLE dataValue)
	{
		handlerdict.insert(std::pair<SQLHANDLE, SQLHANDLE>(dataKey, dataValue));
	}
	int handlerdictRemove(SQLHANDLE dataKey)
	{
		return handlerdict.erase(dataKey);
	}
	bool handlerdictFind(SQLHANDLE dataKey, SQLHANDLE &keyValue)
	{
		std::map<SQLHANDLE, SQLHANDLE>::iterator iter;
		iter = handlerdict.find(dataKey);
		if (iter != handlerdict.end())
		{
			keyValue = iter->second;
			return true;
		}
		else
		{
			return false;
		}
	}
};
bool queryMap(std::map<std::string, std::string> data,std::string key,std::string& value)
{
  std::map<std::string, std::string>::iterator iter; 
  iter = data.find(key);
  if(iter != data.end()) 
  {
    value = iter->second;
    return true;
  }
  else
  {
	  return false;
  }
}
size_t size(const char* source){return strlen(source);}
size_t size(const wchar_t* source){return wcslen(source);}
template<typename T>
bool parseConnectingStr(const T* src, std::map<std::string, std::string>& data)
{
    int i = 0;
    std::string key = "";
    std::string value = "";
    int tks = 0;
	size_t srcLength = size(src);
    while (i < srcLength)
    {
        if (src[i] == ';' || 0 == i)
        {
            // eat a key
            if (src[i] == ';')
            {
                ++i;
                if (i >= srcLength) break;
            }
			while(i < srcLength && src[i] == ' ')
			{
				++i;
			}
			if (i >= srcLength) break;
            int pos1 = i;
            while (i < srcLength && (src[i] != '='))
                ++i;
            key = std::string(src + pos1, src + i);
			transform(key.begin(), key.end(), key.begin(), ::tolower); 
            tks++;
        }
        else if (src[i] == '=')
        {
            // eat a value
            ++i;
            if (i >= srcLength) break;
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
extern "C" 
{
    SQLRETURN EXPORT_SQLAPI SQLGetDiagRec(SQLSMALLINT HandleType, SQLHANDLE Handle,
                                          SQLSMALLINT RecNumber, SQLCHAR *Sqlstate,
                                          SQLINTEGER *NativeError, SQLCHAR *MessageText,
                                          SQLSMALLINT BufferLength, SQLSMALLINT *TextLength)
    {
        return ODBCINST->SQLGetDiagRec(HandleType, Handle, RecNumber, Sqlstate, NativeError, MessageText,
                                       BufferLength, TextLength);
    }

    SQLRETURN EXPORT_SQLAPI SQLAllocHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle)
    {
        SQLRETURN result = ODBCINST->SQLAllocHandle(HandleType, InputHandle, OutputHandle);
        if (HandleType == SQL_HANDLE_STMT)
        {
            EnforcerData::Instance().handlerdictInsert(*OutputHandle, InputHandle);
        }
        return result;
     }

     SQLRETURN EXPORT_SQLAPI SQLSetEnvAttr(SQLHENV EnvironmentHandle,
                                           SQLINTEGER Attribute, SQLPOINTER Value,
                                           SQLINTEGER StringLength)
     {
         return ODBCINST->SQLSetEnvAttr(EnvironmentHandle, Attribute, Value, StringLength);
     }

     SQLRETURN EXPORT_SQLAPI SQLConnect(SQLHDBC ConnectionHandle,
                                        SQLCHAR *ServerName, SQLSMALLINT NameLength1,
                                        SQLCHAR *UserName, SQLSMALLINT NameLength2,
                                        SQLCHAR *Authentication, SQLSMALLINT NameLength3)
     {
         printf("nxlodbc: SQLConnect:%s\n", ServerName);
         SqlException exc;
         unsigned long enforcerContext = Enforcer::Instance()->SQLEnforcerNewContext((const char *)UserName, (const char *)Authentication, &exc);
         EnforcerData::Instance().enforcerContextInsert(ConnectionHandle, enforcerContext);
         return ODBCINST->SQLConnect(ConnectionHandle, ServerName, NameLength1, UserName, NameLength2, Authentication, NameLength3);
     }

     SQLRETURN EXPORT_SQLAPI SQLExecDirect(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
     {
         printf("nxlodbc: SQLExecDirect:%s\n", StatementText);
         SQLHDBC serverhdbc;
         unsigned long enforcerContext;
         std::string strNewSql;
         Enforcer::Instance()->SQLEnforcerWriteLogA(4, "Enter SQLExecDirect");
         if (EnforcerData::Instance().handlerdictFind(StatementHandle, serverhdbc))
         {
             wprintf(L"SQLExecDirect handlerdictFind\n");
             if (EnforcerData::Instance().enforcerContextFind(serverhdbc, enforcerContext))
             {
                 wprintf(L"SQLExecDirect enforcerContextFind\n");
                 SqlException exc;
                 strNewSql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, (char *)StatementText, &exc);
             }
             else
             {
                 strNewSql = (char *)StatementText;
             }
         }
         else
         {
             strNewSql = (char *)StatementText;
         }
         wprintf(L"SQLExecDirect strNewSql:%s\n", strNewSql);
         return ODBCINST->SQLExecDirect(StatementHandle, (SQLCHAR *)strNewSql.c_str(), strNewSql.length());
     }

     SQLRETURN EXPORT_SQLAPI SQLNumResultCols(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount)
     {
         return ODBCINST->SQLNumResultCols(StatementHandle, ColumnCount);
     }

     SQLRETURN EXPORT_SQLAPI SQLRowCount(SQLHSTMT StatementHandle, SQLLEN *RowCount)
     {
         return ODBCINST->SQLRowCount(StatementHandle, RowCount);
     }

     SQLRETURN EXPORT_SQLAPI SQLCloseCursor(SQLHSTMT StatementHandle)
     {
         return ODBCINST->SQLCloseCursor(StatementHandle);
     }

     SQLRETURN EXPORT_SQLAPI SQLFreeStmt(SQLHSTMT StatementHandle, SQLUSMALLINT Option)
     {
         return ODBCINST->SQLFreeStmt(StatementHandle, Option);
     }

    SQLRETURN EXPORT_SQLAPI SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
    {
         return ODBCINST->SQLFreeHandle(HandleType, Handle);
    }

    SQLRETURN  EXPORT_SQLAPI SQLDisconnect(SQLHDBC ConnectionHandle)
    {
        return ODBCINST->SQLDisconnect(ConnectionHandle);
    }

     SQLRETURN  EXPORT_SQLAPI SQLGetFunctions(SQLHDBC ConnectionHandle,  SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported)
     {
         return ODBCINST->SQLGetFunctions(ConnectionHandle, FunctionId, Supported);
     }

     SQLRETURN  EXPORT_SQLAPI SQLColumns(SQLHSTMT StatementHandle,
                                  SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                                  SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
                                  SQLCHAR *TableName, SQLSMALLINT NameLength3,
                                  SQLCHAR *ColumnName, SQLSMALLINT NameLength4)
    {
        return ODBCINST->SQLColumns(StatementHandle, CatalogName, NameLength1, SchemaName, NameLength2, TableName, NameLength3,
        ColumnName, NameLength4);
    }

    SQLRETURN  EXPORT_SQLAPI SQLFetch(SQLHSTMT StatementHandle)
    {
        return ODBCINST->SQLFetch(StatementHandle);
    }

    SQLRETURN  EXPORT_SQLAPI SQLFreeEnv(SQLHENV EnvironmentHandle)
    {
        return ODBCINST->SQLFreeEnv(EnvironmentHandle);
    }

    SQLRETURN EXPORT_SQLAPI SQLDriverConnect(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLCHAR 		  *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR           *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT 	  *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion)
    {
        std::map<std::string, std::string> data{};
	if (parseConnectingStr((char*)szConnStrIn, data))
	{
		std::string uid;
		std::string pwd;
		queryMap(data, "uid", uid);
		queryMap(data, "pwd", pwd);
        SqlException exc;
		unsigned long enforcerContext = Enforcer::Instance()->SQLEnforcerNewContext(uid.c_str(), pwd.c_str(),&exc);
		EnforcerData::Instance().enforcerContextInsert(hdbc, enforcerContext);
	}
        return ODBCINST->SQLDriverConnect(hdbc, hwnd, szConnStrIn, cbConnStrIn, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion);
    }

     SQLRETURN  EXPORT_SQLAPI SQLFreeConnect(SQLHDBC ConnectionHandle)
     {
         return ODBCINST->SQLFreeConnect(ConnectionHandle);
     }

     SQLRETURN  EXPORT_SQLAPI SQLDescribeCol(SQLHSTMT StatementHandle,
                                      SQLUSMALLINT ColumnNumber, SQLCHAR *ColumnName,
                                      SQLSMALLINT BufferLength, SQLSMALLINT *NameLength,
                                      SQLSMALLINT *DataType, SQLULEN *ColumnSize,
                                      SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable)
     {
         return ODBCINST->SQLDescribeCol(StatementHandle, ColumnNumber, ColumnName, BufferLength, NameLength, DataType, ColumnSize, DecimalDigits, Nullable);
     }

     SQLRETURN  EXPORT_SQLAPI SQLAllocStmt(SQLHDBC ConnectionHandle, SQLHSTMT *StatementHandle)  
     {
         return ODBCINST->SQLAllocStmt(ConnectionHandle, StatementHandle);
     } 

    SQLRETURN  EXPORT_SQLAPI SQLSetConnectOption(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLULEN Value)
    {
        return ODBCINST->SQLSetConnectOption(ConnectionHandle, Option, Value);
    }

    SQLRETURN EXPORT_SQLAPI SQLColAttribute(SQLHSTMT StatementHandle,SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength, SQLSMALLINT *StringLength, SQLLEN *NumericAttribute )
    {
        return ODBCINST->SQLColAttribute(StatementHandle, ColumnNumber, FieldIdentifier,
        CharacterAttribute, BufferLength, StringLength, NumericAttribute );
    }

     SQLRETURN EXPORT_SQLAPI SQLPrepare(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength)
     {
         printf("nxlodbc SQLPrepare:%s\n", StatementText);
         return ODBCINST->SQLPrepare(StatementHandle, StatementText, TextLength);
     }

     SQLRETURN EXPORT_SQLAPI SQLError(SQLHENV EnvironmentHandle,SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,SQLCHAR *Sqlstate, SQLINTEGER *NativeError,SQLCHAR *MessageText, SQLSMALLINT BufferLength,SQLSMALLINT *TextLength)
     {
         return ODBCINST->SQLError(EnvironmentHandle, ConnectionHandle, StatementHandle,
         Sqlstate, NativeError, MessageText, BufferLength, TextLength);
     }

     SQLRETURN EXPORT_SQLAPI SQLSetConnectAttr(SQLHDBC ConnectionHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER StringLength)
     {
         return ODBCINST->SQLSetConnectAttr(ConnectionHandle, Attribute, Value, StringLength);
     }

     SQLRETURN EXPORT_SQLAPI SQLAllocEnv(SQLHENV *EnvironmentHandle)
     {
         return ODBCINST->SQLAllocEnv(EnvironmentHandle);
     }

    SQLRETURN EXPORT_SQLAPI SQLTransact(SQLHENV EnvironmentHandle,SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType)
    {
        return ODBCINST->SQLTransact(EnvironmentHandle, ConnectionHandle, CompletionType);
    }

    SQLRETURN EXPORT_SQLAPI SQLExecute(SQLHSTMT StatementHandle)
    {
        return ODBCINST->SQLExecute(StatementHandle);
    }
    SQLRETURN EXPORT_SQLAPI SQLAllocConnect(SQLHENV EnvironmentHandle, SQLHDBC *ConnectionHandle)
    {
        return ODBCINST->SQLAllocConnect(EnvironmentHandle, ConnectionHandle);
    }

    SQLRETURN EXPORT_SQLAPI SQLEndTran(SQLSMALLINT HandleType, SQLHANDLE Handle,SQLSMALLINT CompletionType)
    {
        return ODBCINST->SQLEndTran(HandleType, Handle, CompletionType);
    }

    SQLRETURN EXPORT_SQLAPI SQLGetData(SQLHSTMT StatementHandle,SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,SQLPOINTER TargetValue, SQLLEN BufferLength,SQLLEN *StrLen_or_Ind)
    {
        return ODBCINST->SQLGetData(StatementHandle, ColumnNumber, TargetType, TargetValue, BufferLength, 
        StrLen_or_Ind);
    }

     SQLRETURN EXPORT_SQLAPI SQLTables(SQLHSTMT StatementHandle,SQLCHAR *CatalogName, SQLSMALLINT NameLength1,SQLCHAR *SchemaName, SQLSMALLINT NameLength2,SQLCHAR *TableName, SQLSMALLINT NameLength3,SQLCHAR *TableType, SQLSMALLINT NameLength4)
     {
         return ODBCINST->SQLTables(StatementHandle, CatalogName, NameLength1,
         SchemaName, NameLength2, TableName, NameLength3,
         TableType, NameLength4);
     }

     SQLRETURN EXPORT_SQLAPI SQLMoreResults(SQLHSTMT hstmt)
     {
         return ODBCINST->SQLMoreResults(hstmt);
     }
     SQLRETURN   EXPORT_SQLAPI SQLBulkOperations(
    SQLHSTMT            StatementHandle,
    SQLSMALLINT         Operation)
    {
        return ODBCINST->SQLBulkOperations(StatementHandle,Operation);
    }
    SQLRETURN  EXPORT_SQLAPI SQLCancel(SQLHSTMT StatementHandle)
    {
        return ODBCINST->SQLCancel(StatementHandle);
    }
    SQLRETURN  EXPORT_SQLAPI SQLBindCol(SQLHSTMT StatementHandle,
           SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
           SQLPOINTER TargetValue, 
           SQLLEN BufferLength,SQLLEN *StrLen_or_Ind)
           {
               return ODBCINST->SQLBindCol(StatementHandle,ColumnNumber,TargetType,TargetValue,BufferLength,StrLen_or_Ind);
           }
    SQLRETURN  EXPORT_SQLAPI SQLBindParam(SQLHSTMT StatementHandle,
                                    SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                                    SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
                                    SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
                                    SQLLEN *StrLen_or_Ind)
                                    {
                                        return ODBCINST->SQLBindParam(StatementHandle,ParameterNumber,ValueType,ParameterType,LengthPrecision,ParameterScale,ParameterValue,StrLen_or_Ind);
                                    }
    SQLRETURN EXPORT_SQLAPI SQLBindParameter(
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
        return ODBCINST->SQLBindParameter(hstmt,ipar,fParamType,fCType,fSqlType,cbColDef,ibScale,rgbValue,cbValueMax,pcbValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLBrowseConnect(
    SQLHDBC            hdbc,
    SQLCHAR 		  *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR 		  *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT       *pcbConnStrOut)
    {
        return ODBCINST->SQLBrowseConnect(hdbc,szConnStrIn,cbConnStrIn,szConnStrOut,cbConnStrOutMax,pcbConnStrOut);
    }
    SQLRETURN EXPORT_SQLAPI SQLBrowseConnectA(
    SQLHDBC            hdbc,
    SQLCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut)
    {
        return ODBCINST->SQLBrowseConnectA(hdbc,szConnStrIn,cbConnStrIn,szConnStrOut,cbConnStrOutMax,pcbConnStrOut);
    }
    SQLRETURN EXPORT_SQLAPI SQLBrowseConnectW(
    SQLHDBC            hdbc,
    SQLWCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLWCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut)
    {
        return ODBCINST->SQLBrowseConnectW(hdbc,szConnStrIn,cbConnStrIn,szConnStrOut,cbConnStrOutMax,pcbConnStrOut);
    }
    SQLRETURN EXPORT_SQLAPI SQLColAttributeA(
	SQLHSTMT		hstmt,
	SQLSMALLINT		iCol,
	SQLSMALLINT		iField,
	SQLPOINTER		pCharAttr,
	SQLSMALLINT		cbCharAttrMax,	
	SQLSMALLINT  	        *pcbCharAttr,
	SQLLEN              	*pNumAttr)
    {
        return ODBCINST->SQLColAttributeA(hstmt,iCol,iField,pCharAttr,cbCharAttrMax,pcbCharAttr,pNumAttr);
    }
    SQLRETURN EXPORT_SQLAPI SQLColAttributeW(
	SQLHSTMT		hstmt,
	SQLUSMALLINT	iCol,
	SQLUSMALLINT	iField,
	SQLPOINTER		pCharAttr,
	SQLSMALLINT		cbCharAttrMax,	
	SQLSMALLINT  	*pcbCharAttr,
	SQLLEN		*pNumAttr)
    {
        return ODBCINST->SQLColAttributeW(hstmt,iCol,iField,pCharAttr,cbCharAttrMax,pcbCharAttr,pNumAttr);
    }
    SQLRETURN EXPORT_SQLAPI SQLColAttributes(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLUSMALLINT       fDescType,
    SQLPOINTER         rgbDesc,
    SQLSMALLINT        cbDescMax,
    SQLSMALLINT 	  *pcbDesc,
    SQLLEN 		      *pfDesc)
    {
        return ODBCINST->SQLColAttributes(hstmt,icol,fDescType,rgbDesc,cbDescMax,pcbDesc,pfDesc);
    }
    SQLRETURN EXPORT_SQLAPI SQLColAttributesA(
    SQLHSTMT        hstmt,
    SQLUSMALLINT    icol,
    SQLUSMALLINT    fDescType,
    SQLPOINTER      rgbDesc,
    SQLSMALLINT     cbDescMax,
    SQLSMALLINT    	*pcbDesc,
    SQLLEN     		*pfDesc)
    {
        return ODBCINST->SQLColAttributesA(hstmt,icol,fDescType,rgbDesc,cbDescMax,pcbDesc,pfDesc);
    }
    SQLRETURN EXPORT_SQLAPI SQLColAttributesW(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLUSMALLINT       fDescType,
    SQLPOINTER         rgbDesc,
    SQLSMALLINT        cbDescMax,
    SQLSMALLINT        *pcbDesc,
    SQLLEN             *pfDesc)
    {
        return ODBCINST->SQLColAttributesW(hstmt,icol,fDescType,rgbDesc,cbDescMax,pcbDesc,pfDesc);
    }
    SQLRETURN EXPORT_SQLAPI SQLColumnPrivileges(
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
        return ODBCINST->SQLColumnPrivileges(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLColumnPrivilegesA(
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
        return ODBCINST->SQLColumnPrivilegesA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLColumnPrivilegesW(
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
        return ODBCINST->SQLColumnPrivilegesW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLColumnsA(
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
        return ODBCINST->SQLColumnsA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLColumnsW(
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
        return ODBCINST->SQLColumnsW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLConnectA(
    SQLHDBC         hdbc,
    SQLCHAR         *szDSN,
    SQLSMALLINT     cbDSN,
    SQLCHAR         *szUID,
    SQLSMALLINT     cbUID,
    SQLCHAR         *szAuthStr,
    SQLSMALLINT     cbAuthStr)
    {
        SqlException exc;
        unsigned long enforcerContext = Enforcer::Instance()->SQLEnforcerNewContext((const char*)szUID,(const char*)szAuthStr, &exc);
	    EnforcerData::Instance().enforcerContextInsert(hdbc,enforcerContext);
        return ODBCINST->SQLConnectA(hdbc,szDSN,cbDSN,szUID,cbUID,szAuthStr,cbAuthStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLConnectW(
        SQLHDBC hdbc,
        SQLWCHAR *szDSN,
        SQLSMALLINT cbDSN,
        SQLWCHAR *szUID,
        SQLSMALLINT cbUID,
        SQLWCHAR *szAuthStr,
        SQLSMALLINT cbAuthStr)
    {
        char uid[256];
        char pwd[256];
        sprintf_s(uid, "%ws", szUID);
        sprintf_s(pwd, "%ws", szAuthStr);
        SqlException exc;
        unsigned long enforcerContext = Enforcer::Instance()->SQLEnforcerNewContext(uid, pwd, &exc);
        EnforcerData::Instance().enforcerContextInsert(ConnectionHandle, enforcerContext);
        return ODBCINST->SQLConnectW(hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr);
    }
    SQLRETURN  EXPORT_SQLAPI SQLCopyDesc(SQLHDESC SourceDescHandle,
                                   SQLHDESC TargetDescHandle)
                                   {
                                       return ODBCINST->SQLCopyDesc(SourceDescHandle,TargetDescHandle);
                                   }
    SQLRETURN  EXPORT_SQLAPI SQLDataSources(SQLHENV EnvironmentHandle,
                                      SQLUSMALLINT Direction, SQLCHAR *ServerName,
                                      SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1,
                                      SQLCHAR *Description, SQLSMALLINT BufferLength2,
                                      SQLSMALLINT *NameLength2)
                                      {
                                          return ODBCINST->SQLDataSources(EnvironmentHandle,Direction,ServerName,BufferLength1,NameLength1,Description,BufferLength2,NameLength2);
                                      }
    SQLRETURN EXPORT_SQLAPI SQLDataSourcesA(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR        *szDSN,
    SQLSMALLINT        cbDSNMax,
    SQLSMALLINT    *pcbDSN,
    SQLCHAR        *szDescription,
    SQLSMALLINT        cbDescriptionMax,
    SQLSMALLINT    *pcbDescription)
    {
        return ODBCINST->SQLDataSourcesA(henv,fDirection,szDSN,cbDSNMax,pcbDSN,szDescription,cbDescriptionMax,pcbDescription);
    }
    SQLRETURN EXPORT_SQLAPI SQLDataSourcesW(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLWCHAR        *szDSN,
    SQLSMALLINT        cbDSNMax,
    SQLSMALLINT    *pcbDSN,
    SQLWCHAR        *szDescription,
    SQLSMALLINT        cbDescriptionMax,
    SQLSMALLINT    *pcbDescription)
    {
        return ODBCINST->SQLDataSourcesW(henv,fDirection,szDSN,cbDSNMax,pcbDSN,szDescription,cbDescriptionMax,pcbDescription);
    }
    SQLRETURN EXPORT_SQLAPI SQLDescribeColA(
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
        return ODBCINST->SQLDescribeColA(hstmt,icol,szColName,cbColNameMax,pcbColName,pfSqlType,pcbColDef,pibScale,pfNullable);
    }
    SQLRETURN EXPORT_SQLAPI SQLDescribeColW(
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
        return ODBCINST->SQLDescribeColW(hstmt,icol,szColName,cbColNameMax,pcbColName,pfSqlType,pcbColDef,pibScale,pfNullable);
    }
    SQLRETURN EXPORT_SQLAPI SQLDescribeParam(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       ipar,
    SQLSMALLINT 	  *pfSqlType,
    SQLULEN 	      *pcbParamDef,
    SQLSMALLINT 	  *pibScale,
    SQLSMALLINT 	  *pfNullable)
    {
        return ODBCINST->SQLDescribeParam(hstmt,ipar,pfSqlType,pcbParamDef,pibScale,pfNullable);
    }
    SQLRETURN EXPORT_SQLAPI SQLDriverConnectA(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion)
    {
        std::map<std::string, std::string> data{};
	if (parseConnectingStr((char*)szConnStrIn, data))
	{
		std::string uid;
		std::string pwd;
		queryMap(data, "uid", uid);
		queryMap(data, "pwd", pwd);
        SqlException exc;
		unsigned long enforcerContext = Enforcer::Instance()->SQLEnforcerNewContext(uid.c_str(), pwd.c_str(), &exc);
		EnforcerData::Instance().enforcerContextInsert(hdbc, enforcerContext);
	}
        return ODBCINST->SQLDriverConnectA(hdbc,hwnd,szConnStrIn,cbConnStrIn,szConnStrOut,cbConnStrOutMax,pcbConnStrOut,fDriverCompletion);
    }
    SQLRETURN EXPORT_SQLAPI SQLDriverConnectW(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    SQLWCHAR        *szConnStrIn,
    SQLSMALLINT        cbConnStrIn,
    SQLWCHAR        *szConnStrOut,
    SQLSMALLINT        cbConnStrOutMax,
    SQLSMALLINT    *pcbConnStrOut,
    SQLUSMALLINT       fDriverCompletion)
    {
        std::map<std::string, std::string> data{};
	if (parseConnectingStr(szConnStrIn, data))
	{
		std::string uid;
		std::string pwd;
		queryMap(data, "uid", uid);
		queryMap(data, "pwd", pwd);
        SqlException exc;
		unsigned long enforcerContext = Enforcer::Instance()->SQLEnforcerNewContext(uid.c_str(), pwd.c_str(), &exc);
		EnforcerData::Instance().enforcerContextInsert(hdbc, enforcerContext);
	}
        return ODBCINST->SQLDriverConnectW(hdbc,hwnd,szConnStrIn,cbConnStrIn,szConnStrOut,cbConnStrOutMax,pcbConnStrOut,fDriverCompletion);
    }
    SQLRETURN EXPORT_SQLAPI SQLDrivers(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR 		  *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT 	  *pcbDriverDesc,
    SQLCHAR 		  *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT 	  *pcbDrvrAttr)
    {
        return ODBCINST->SQLDrivers(henv,fDirection,szDriverDesc,cbDriverDescMax,pcbDriverDesc,szDriverAttributes,cbDrvrAttrMax,pcbDrvrAttr);
    }
    SQLRETURN EXPORT_SQLAPI SQLDriversA(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLCHAR        *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT    *pcbDriverDesc,
    SQLCHAR        *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT    *pcbDrvrAttr)
    {
        return ODBCINST->SQLDriversA(henv,fDirection,szDriverDesc,cbDriverDescMax,pcbDriverDesc,szDriverAttributes,cbDrvrAttrMax,pcbDrvrAttr);
    }
    SQLRETURN EXPORT_SQLAPI SQLDriversW(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    SQLWCHAR        *szDriverDesc,
    SQLSMALLINT        cbDriverDescMax,
    SQLSMALLINT    *pcbDriverDesc,
    SQLWCHAR        *szDriverAttributes,
    SQLSMALLINT        cbDrvrAttrMax,
    SQLSMALLINT    *pcbDrvrAttr)
    {
        return ODBCINST->SQLDriversW(henv,fDirection,szDriverDesc,cbDriverDescMax,pcbDriverDesc,szDriverAttributes,cbDrvrAttrMax,pcbDrvrAttr);
    }
    SQLRETURN EXPORT_SQLAPI SQLErrorA(
    SQLHENV            henv,
    SQLHDBC            hdbc,
    SQLHSTMT           hstmt,
    SQLCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        return ODBCINST->SQLErrorA(henv,hdbc,hstmt,szSqlState,pfNativeError,szErrorMsg,cbErrorMsgMax,pcbErrorMsg);
    }
    SQLRETURN EXPORT_SQLAPI SQLErrorW(
    SQLHENV            henv,
    SQLHDBC            hdbc,
    SQLHSTMT           hstmt,
    SQLWCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLWCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        return ODBCINST->SQLErrorW(henv,hdbc,hstmt,szSqlState,pfNativeError,szErrorMsg,cbErrorMsgMax,pcbErrorMsg);
    }
    SQLRETURN EXPORT_SQLAPI SQLExecDirectA(
        SQLHSTMT hstmt,
        SQLCHAR *szSqlStr,
        SQLINTEGER cbSqlStr)
    {
        SQLHDBC serverhdbc;
        unsigned long enforcerContext;
        std::string strNewSql;
        Enforcer::Instance()->SQLEnforcerWriteLogA(4, "Enter SQLExecDirectA");
        if (EnforcerData::Instance().handlerdictFind(hstmt, serverhdbc))
        {
            wprintf(L"SQLExecDirectA handlerdictFind\n");
            if (EnforcerData::Instance().enforcerContextFind(serverhdbc, enforcerContext))
            {
                wprintf(L"SQLExecDirectA enforcerContextFind\n");
                SqlException exc;
                strNewSql = Enforcer::Instance()->SQLEnforcerEvaluationSQLA(enforcerContext, (char *)szSqlStr, &exc);
            }
            else
            {
                strNewSql = (char *)szSqlStr;
            }
        }
        else
        {
            strNewSql = (char *)szSqlStr;
        }
        wprintf(L"SQLExecDirectA strNewSql:%s\n", strNewSql);
        return ODBCINST->SQLExecDirectA(hstmt, (SQLCHAR *)strNewSql.c_str(), cbSqlStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLExecDirectW(
        SQLHSTMT hstmt,
        SQLWCHAR *szSqlStr,
        SQLINTEGER cbSqlStr)
    {
        SQLHDBC serverhdbc;
        unsigned long enforcerContext;
        std::wstring strNewSql;
        Enforcer::Instance()->SQLEnforcerWriteLogA(4, "Enter SQLExecDirectW");
        if (EnforcerData::Instance().handlerdictFind(hstmt, serverhdbc))
        {
            wprintf(L"SQLExecDirectW handlerdictFind\n");
            if (EnforcerData::Instance().enforcerContextFind(serverhdbc, enforcerContext))
            {
                wprintf(L"SQLExecDirectW enforcerContextFind\n");
                SqlException exc;
                //bool bBlock = false;
                strNewSql = Enforcer::Instance()->SQLEnforcerEvaluationSQLW(enforcerContext, szSqlStr, &exc);
            }
            else
            {
                strNewSql = szSqlStr;
            }
        }
        else
        {
            strNewSql = szSqlStr;
        }
        wprintf(L"SQLExecDirectW strNewSql:%s\n", strNewSql.c_str());
        return ODBCINST->SQLExecDirectW(hstmt, (SQLWCHAR *)strNewSql.c_str(), cbSqlStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLExtendedFetch(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fFetchType,
    SQLLEN             irow,
    SQLULEN 	  	   *pcrow,
    SQLUSMALLINT 	   *rgfRowStatus)
    {
        return ODBCINST->SQLExtendedFetch(hstmt,fFetchType,irow,pcrow,rgfRowStatus);
    }
    SQLRETURN  EXPORT_SQLAPI SQLFetchScroll(SQLHSTMT StatementHandle,SQLSMALLINT FetchOrientation, SQLLEN FetchOffset)
    {
        return ODBCINST->SQLFetchScroll(StatementHandle,FetchOrientation,FetchOffset);
    }
    SQLRETURN EXPORT_SQLAPI SQLForeignKeys(
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
        return ODBCINST->SQLForeignKeys(hstmt,szPkCatalogName,cbPkCatalogName,szPkSchemaName,cbPkSchemaName,szPkTableName,cbPkTableName,szFkCatalogName,cbFkCatalogName,szFkSchemaName,cbFkSchemaName,szFkTableName,cbFkTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLForeignKeysA(
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
        return ODBCINST->SQLForeignKeysA(hstmt,szPkCatalogName,cbPkCatalogName,szPkSchemaName,cbPkSchemaName,szPkTableName,cbPkTableName,szFkCatalogName,cbFkCatalogName,szFkSchemaName,cbFkSchemaName,szFkTableName,cbFkTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLForeignKeysW(
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
        return ODBCINST->SQLForeignKeysW(hstmt,szPkCatalogName,cbPkCatalogName,szPkSchemaName,cbPkSchemaName,szPkTableName,cbPkTableName,szFkCatalogName,cbFkCatalogName,szFkSchemaName,cbFkSchemaName,szFkTableName,cbFkTableName);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetConnectAttr(SQLHDBC ConnectionHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER BufferLength, SQLINTEGER *StringLength)
    {
        return ODBCINST->SQLGetConnectAttr(ConnectionHandle,Attribute,Value,BufferLength,StringLength);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetConnectAttrA(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        return ODBCINST->SQLGetConnectAttrA(hdbc,fAttribute,rgbValue,cbValueMax,pcbValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetConnectAttrW(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        return ODBCINST->SQLGetConnectAttrW(hdbc,fAttribute,rgbValue,cbValueMax,pcbValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetConnectOptionA(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam)
    {
        return ODBCINST->SQLGetConnectOptionA(hdbc,fOption,pvParam);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetConnectOptionW(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam)
    {
        return ODBCINST->SQLGetConnectOptionW(hdbc,fOption,pvParam);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetCursorName(SQLHSTMT StatementHandle,SQLCHAR *CursorName, SQLSMALLINT BufferLength,SQLSMALLINT *NameLength)
    {
        return ODBCINST->SQLGetCursorName(StatementHandle,CursorName,BufferLength,NameLength);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetCursorNameA(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szCursor,
    SQLSMALLINT        cbCursorMax,
    SQLSMALLINT    *pcbCursor)
    {
        return ODBCINST->SQLGetCursorNameA(hstmt,szCursor,cbCursorMax,pcbCursor);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetCursorNameW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCursor,
    SQLSMALLINT        cbCursorMax,
    SQLSMALLINT    *pcbCursor)
    {
        return ODBCINST->SQLGetCursorNameW(hstmt,szCursor,cbCursorMax,pcbCursor);
    }
    SQLRETURN EXPORT_API SQLGetDescField(SQLHDESC DescriptorHandle,SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,SQLPOINTER Value, SQLINTEGER BufferLength,SQLINTEGER *StringLength)
    {
        return ODBCINST->SQLGetDescField(DescriptorHandle,RecNumber,FieldIdentifier,Value,BufferLength,StringLength);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetDescFieldA(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        iField,
    SQLPOINTER         rgbValue,
    SQLINTEGER		   cbValueMax,
    SQLINTEGER     *pcbValue)
    {
       return ODBCINST->SQLGetDescFieldA(hdesc,iRecord,iField,rgbValue,cbValueMax,pcbValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetDescFieldW(
    SQLHDESC           hdesc,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        iField,
    SQLPOINTER         rgbValue,
    SQLINTEGER		   cbValueMax,
    SQLINTEGER     *pcbValue)
    {
       return ODBCINST->SQLGetDescFieldW(hdesc,iRecord,iField,rgbValue,cbValueMax,pcbValue);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetDescRec(SQLHDESC DescriptorHandle,
                                     SQLSMALLINT RecNumber, SQLCHAR *Name,
                                     SQLSMALLINT BufferLength, SQLSMALLINT *StringLength,
                                     SQLSMALLINT *Type, SQLSMALLINT *SubType,
                                     SQLLEN *Length, SQLSMALLINT *Precision,
                                     SQLSMALLINT *Scale, SQLSMALLINT *Nullable)
                                     {
                                         return ODBCINST->SQLGetDescRec(DescriptorHandle,RecNumber,Name,BufferLength,StringLength,Type,SubType,Length,Precision,Scale,Nullable);
                                     }
    SQLRETURN EXPORT_SQLAPI SQLGetDescRecA(
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
        return ODBCINST->SQLGetDescRecA(hdesc,iRecord,szName,cbNameMax,pcbName,pfType,pfSubType,pLength,pPrecision,pScale,pNullable);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetDescRecW(
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
        return ODBCINST->SQLGetDescRecW(hdesc,iRecord,szName,cbNameMax,pcbName,pfType,pfSubType,pLength,pPrecision,pScale,pNullable);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetDiagField(SQLSMALLINT HandleType, SQLHANDLE Handle,
                                       SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
                                       SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
                                       SQLSMALLINT *StringLength)
                                       {
                                           return ODBCINST->SQLGetDiagField(HandleType,Handle,RecNumber,DiagIdentifier,DiagInfo,BufferLength,StringLength);
                                       }
    SQLRETURN EXPORT_SQLAPI SQLGetDiagFieldA(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        fDiagField,
    SQLPOINTER         rgbDiagInfo,
    SQLSMALLINT        cbDiagInfoMax,
    SQLSMALLINT    *pcbDiagInfo)
    {
        return ODBCINST->SQLGetDiagFieldA(fHandleType,handle,iRecord,fDiagField,rgbDiagInfo,cbDiagInfoMax,pcbDiagInfo);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetDiagFieldW(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLSMALLINT        fDiagField,
    SQLPOINTER         rgbDiagInfo,
    SQLSMALLINT        cbDiagInfoMax,
    SQLSMALLINT    *pcbDiagInfo)
    {
        return ODBCINST->SQLGetDiagFieldW(fHandleType,handle,iRecord,fDiagField,rgbDiagInfo,cbDiagInfoMax,pcbDiagInfo);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetDiagRecA(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        return ODBCINST->SQLGetDiagRecA(fHandleType,handle,iRecord,szSqlState,pfNativeError,szErrorMsg,cbErrorMsgMax,pcbErrorMsg);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetDiagRecW(
    SQLSMALLINT        fHandleType,
    SQLHANDLE          handle,
    SQLSMALLINT        iRecord,
    SQLWCHAR        *szSqlState,
    SQLINTEGER     *pfNativeError,
    SQLWCHAR        *szErrorMsg,
    SQLSMALLINT        cbErrorMsgMax,
    SQLSMALLINT    *pcbErrorMsg)
    {
        return ODBCINST->SQLGetDiagRecW(fHandleType,handle,iRecord,szSqlState,pfNativeError,szErrorMsg,cbErrorMsgMax,pcbErrorMsg);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetEnvAttr(SQLHENV EnvironmentHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER BufferLength, SQLINTEGER *StringLength)
    {
        return ODBCINST->SQLGetEnvAttr(EnvironmentHandle,Attribute,Value,BufferLength,StringLength);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetInfo(SQLHDBC ConnectionHandle,SQLUSMALLINT InfoType, SQLPOINTER InfoValue,SQLSMALLINT BufferLength, SQLSMALLINT *StringLength)
    {
        return ODBCINST->SQLGetInfo(ConnectionHandle,InfoType,InfoValue,BufferLength,StringLength);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetInfoA(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fInfoType,
    SQLPOINTER         rgbInfoValue,
    SQLSMALLINT        cbInfoValueMax,
    SQLSMALLINT*       pcbInfoValue)
    {
        return ODBCINST->SQLGetInfoA(hdbc,fInfoType,rgbInfoValue,cbInfoValueMax,pcbInfoValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetInfoW(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fInfoType,
    SQLPOINTER         rgbInfoValue,
    SQLSMALLINT        cbInfoValueMax,
    SQLSMALLINT    *pcbInfoValue)
    {
        return ODBCINST->SQLGetInfoW(hdbc,fInfoType,rgbInfoValue,cbInfoValueMax,pcbInfoValue);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetStmtAttr(SQLHSTMT StatementHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER BufferLength, SQLINTEGER *StringLength)
    {
        return ODBCINST->SQLGetStmtAttr(StatementHandle,Attribute,Value,BufferLength,StringLength);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetStmtAttrA(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        return ODBCINST->SQLGetStmtAttrA(hstmt,fAttribute,rgbValue,cbValueMax,pcbValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetStmtAttrW(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax,
    SQLINTEGER     *pcbValue)
    {
        return ODBCINST->SQLGetStmtAttrW(hstmt,fAttribute,rgbValue,cbValueMax,pcbValue);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetStmtOption(SQLHSTMT StatementHandle,SQLUSMALLINT Option, SQLPOINTER Value)
    {
        return ODBCINST->SQLGetStmtOption(StatementHandle,Option,Value);
    }
    SQLRETURN EXPORT_SQLAPI SQLGetStmtOptionA(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fOption,
    SQLPOINTER         pvParam)
    {
       return ODBCINST->SQLGetStmtOptionA(hstmt,fOption,pvParam);
    }
    SQLRETURN  EXPORT_SQLAPI SQLGetTypeInfo(SQLHSTMT StatementHandle,SQLSMALLINT DataType)
    {
        return ODBCINST->SQLGetTypeInfo(StatementHandle,DataType);
    }
    SQLRETURN EXPORT_SQLAPI	SQLGetTypeInfoA(
	SQLHSTMT			StatementHandle,
	SQLSMALLINT			DataTyoe)
    {
       return ODBCINST->SQLGetTypeInfoA(StatementHandle,DataTyoe);
    }
    SQLRETURN EXPORT_SQLAPI	SQLGetTypeInfoW(
	SQLHSTMT			StatementHandle,
	SQLSMALLINT			DataType)
    {
       return ODBCINST->SQLGetTypeInfoW(StatementHandle,DataType);
    }
    SQLRETURN EXPORT_SQLAPI SQLNativeSql(
    SQLHDBC            hdbc,
    SQLCHAR 		  *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLCHAR 		  *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER 		  *pcbSqlStr)
    {
        return ODBCINST->SQLNativeSql(hdbc,szSqlStrIn,cbSqlStrIn,szSqlStr,cbSqlStrMax,pcbSqlStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLNativeSqlA(
    SQLHDBC            hdbc,
    SQLCHAR        *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER     *pcbSqlStr)
    {
        return ODBCINST->SQLNativeSqlA(hdbc,szSqlStrIn,cbSqlStrIn,szSqlStr,cbSqlStrMax,pcbSqlStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLNativeSqlW(
    SQLHDBC            hdbc,
    SQLWCHAR        *szSqlStrIn,
    SQLINTEGER         cbSqlStrIn,
    SQLWCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStrMax,
    SQLINTEGER     *pcbSqlStr)
    {
        return ODBCINST->SQLNativeSqlW(hdbc,szSqlStrIn,cbSqlStrIn,szSqlStr,cbSqlStrMax,pcbSqlStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLNumParams(
    SQLHSTMT           hstmt,
    SQLSMALLINT 	  *pcpar)
    {
        return ODBCINST->SQLNumParams(hstmt,pcpar);
    }
    SQLRETURN  EXPORT_SQLAPI SQLParamData(SQLHSTMT StatementHandle,SQLPOINTER *Value)
    {
        return ODBCINST->SQLParamData(StatementHandle,Value);
    }
    SQLRETURN EXPORT_SQLAPI SQLParamOptions(
    SQLHSTMT           hstmt,
    SQLULEN        	   crow,
    SQLULEN 	  	   *pirow)
    {
        return ODBCINST->SQLParamOptions(hstmt,crow,pirow);
    }
    SQLRETURN EXPORT_SQLAPI SQLPrepareA(
    SQLHSTMT           hstmt,
    SQLCHAR        	*szSqlStr,
    SQLINTEGER         cbSqlStr)
    {
        return ODBCINST->SQLPrepareA(hstmt,szSqlStr,cbSqlStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLPrepareW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szSqlStr,
    SQLINTEGER         cbSqlStr)
    {
        return ODBCINST->SQLPrepareW(hstmt,szSqlStr,cbSqlStr);
    }
    SQLRETURN EXPORT_SQLAPI SQLPrimaryKeys(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName)
    {
        return ODBCINST->SQLPrimaryKeys(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLPrimaryKeysA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        return ODBCINST->SQLPrimaryKeysA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLPrimaryKeysW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        return ODBCINST->SQLPrimaryKeysW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLProcedureColumns(
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
        return ODBCINST->SQLProcedureColumns(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szProcName,cbProcName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLProcedureColumnsA(
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
        return ODBCINST->SQLProcedureColumnsA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szProcName,cbProcName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLProcedureColumnsW(
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
        return ODBCINST->SQLProcedureColumnsW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szProcName,cbProcName,szColumnName,cbColumnName);
    }
    SQLRETURN EXPORT_SQLAPI SQLProcedures(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szProcName,
    SQLSMALLINT        cbProcName)
    {
        return ODBCINST->SQLProcedures(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szProcName,cbProcName);
    }
    SQLRETURN EXPORT_SQLAPI SQLProceduresA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szProcName,
    SQLSMALLINT        cbProcName)
    {
        return ODBCINST->SQLProceduresA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szProcName,cbProcName);
    }
    SQLRETURN EXPORT_SQLAPI SQLProceduresW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szProcName,
    SQLSMALLINT        cbProcName)
    {
        return ODBCINST->SQLProceduresW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szProcName,cbProcName);
    }
    SQLRETURN  EXPORT_SQLAPI SQLPutData(SQLHSTMT StatementHandle,SQLPOINTER Data, SQLLEN StrLen_or_Ind)
    {
        return ODBCINST->SQLPutData(StatementHandle,Data,StrLen_or_Ind);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetConnectAttrA(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValue)
    {
       return ODBCINST->SQLSetConnectAttrA(hdbc,fAttribute,rgbValue,cbValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetConnectAttrW(
    SQLHDBC            hdbc,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValue)
    {
        return ODBCINST->SQLSetConnectAttrW(hdbc,fAttribute,rgbValue,cbValue);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetConnectOptionA(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam)
    {
        return ODBCINST->SQLSetConnectOptionA(hdbc,fOption,vParam);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetConnectOptionW(
    SQLHDBC            hdbc,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam)
    {
        return ODBCINST->SQLSetConnectOptionW(hdbc,fOption,vParam);
    }
    SQLRETURN  EXPORT_SQLAPI SQLSetCursorName(SQLHSTMT StatementHandle,SQLCHAR *CursorName, SQLSMALLINT NameLength)
    {
        return ODBCINST->SQLSetCursorName(StatementHandle,CursorName,NameLength);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetCursorNameA(
    SQLHSTMT           hstmt,
    SQLCHAR           *szCursor,
    SQLSMALLINT        cbCursor)
    {
        return ODBCINST->SQLSetCursorNameA(hstmt,szCursor,cbCursor);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetCursorNameW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCursor,
    SQLSMALLINT        cbCursor)
    {
        return ODBCINST->SQLSetCursorNameW(hstmt,szCursor,cbCursor);
    }
    SQLRETURN  EXPORT_SQLAPI SQLSetDescField(SQLHDESC DescriptorHandle,SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,SQLPOINTER Value, SQLINTEGER BufferLength)
    {
        return ODBCINST->SQLSetDescField(DescriptorHandle,RecNumber,FieldIdentifier,Value,BufferLength);
    }
    SQLRETURN  EXPORT_SQLAPI SQLSetDescFieldW(SQLHDESC DescriptorHandle,SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,SQLPOINTER Value, SQLINTEGER BufferLength)
    {
        return ODBCINST->SQLSetDescFieldW(DescriptorHandle,RecNumber,FieldIdentifier,Value,BufferLength);
    }
    SQLRETURN  EXPORT_SQLAPI SQLSetDescRec(SQLHDESC DescriptorHandle,
                                     SQLSMALLINT RecNumber, SQLSMALLINT Type,
                                     SQLSMALLINT SubType, SQLLEN Length,
                                     SQLSMALLINT Precision, SQLSMALLINT Scale,
                                     SQLPOINTER Data, SQLLEN *StringLength,
                                     SQLLEN *Indicator)
                                     {
                                         return ODBCINST->SQLSetDescRec(DescriptorHandle,RecNumber,Type,SubType,Length,Precision,Scale,Data,StringLength,Indicator);
                                     }
    SQLRETURN  EXPORT_SQLAPI SQLSetParam(SQLHSTMT StatementHandle,
                                   SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType,
                                   SQLSMALLINT ParameterType, SQLULEN LengthPrecision,
                                   SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue,
                                   SQLLEN *StrLen_or_Ind)
                                   {
                                       return ODBCINST->SQLSetParam(StatementHandle,ParameterNumber,ValueType,ParameterType,LengthPrecision,ParameterScale,ParameterValue,StrLen_or_Ind);
                                   }
    SQLRETURN EXPORT_SQLAPI SQLSetPos(
    SQLHSTMT           hstmt,
    SQLSETPOSIROW      irow,
    SQLUSMALLINT       fOption,
    SQLUSMALLINT       fLock)
    {
        return ODBCINST->SQLSetPos(hstmt,irow,fOption,fLock);
    }
    /*      Deprecated functions from prior versions of ODBC */
    SQLRETURN EXPORT_SQLAPI SQLSetScrollOptions(    /*      Use SQLSetStmtOptions */
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fConcurrency,
    SQLLEN             crowKeyset,
    SQLUSMALLINT       crowRowset)
    {
        return ODBCINST->SQLSetScrollOptions(hstmt,fConcurrency,crowKeyset,crowRowset);
    }
    SQLRETURN  EXPORT_SQLAPI SQLSetStmtAttr(SQLHSTMT StatementHandle,SQLINTEGER Attribute, SQLPOINTER Value,SQLINTEGER StringLength)
    {
        return ODBCINST->SQLSetStmtAttr(StatementHandle,Attribute,Value,StringLength);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetStmtAttrW(
    SQLHSTMT           hstmt,
    SQLINTEGER         fAttribute,
    SQLPOINTER         rgbValue,
    SQLINTEGER         cbValueMax)
    {
        return ODBCINST->SQLSetStmtAttrW(hstmt,fAttribute,rgbValue,cbValueMax);
    }
    SQLRETURN  EXPORT_SQLAPI SQLSetStmtOption(SQLHSTMT StatementHandle,SQLUSMALLINT Option, SQLULEN Value)
    {
        return ODBCINST->SQLSetStmtOption(StatementHandle,Option,Value);
    }
    SQLRETURN EXPORT_SQLAPI SQLSetStmtOptionA(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fOption,
    SQLULEN            vParam)
    {
        return ODBCINST->SQLSetStmtOptionA(hstmt,fOption,vParam);
    }
    SQLRETURN  EXPORT_SQLAPI SQLSpecialColumns(SQLHSTMT StatementHandle,
                                         SQLUSMALLINT IdentifierType, SQLCHAR *CatalogName,
                                         SQLSMALLINT NameLength1, SQLCHAR *SchemaName,
                                         SQLSMALLINT NameLength2, SQLCHAR *TableName,
                                         SQLSMALLINT NameLength3, SQLUSMALLINT Scope,
                                         SQLUSMALLINT Nullable)
                                         {
                                             return ODBCINST->SQLSpecialColumns(StatementHandle,IdentifierType,CatalogName,NameLength1,SchemaName,NameLength2,TableName,NameLength3,Scope,Nullable);
                                         }
    SQLRETURN EXPORT_SQLAPI SQLSpecialColumnsA(
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
        return ODBCINST->SQLSpecialColumnsA(hstmt,fColType,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,fScope,fNullable);
    }
    SQLRETURN EXPORT_SQLAPI SQLSpecialColumnsW(
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
        return ODBCINST->SQLSpecialColumnsW(hstmt,fColType,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,fScope,fNullable);
    }
    SQLRETURN  EXPORT_SQLAPI SQLStatistics(SQLHSTMT StatementHandle,
                                     SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
                                     SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
                                     SQLCHAR *TableName, SQLSMALLINT NameLength3,
                                     SQLUSMALLINT Unique, SQLUSMALLINT Reserved)
                                     {
                                         return ODBCINST->SQLStatistics(StatementHandle,CatalogName,NameLength1,SchemaName,NameLength2,TableName,NameLength3,Unique,Reserved);
                                     }
    SQLRETURN EXPORT_SQLAPI SQLStatisticsA(
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
        return ODBCINST->SQLStatisticsA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,fUnique,fAccuracy);
    }
    SQLRETURN EXPORT_SQLAPI SQLStatisticsW(
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
        return ODBCINST->SQLStatisticsW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,fUnique,fAccuracy);
    }
    SQLRETURN EXPORT_SQLAPI SQLTablePrivileges(
    SQLHSTMT           hstmt,
    SQLCHAR 		  *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR 		  *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR 		  *szTableName,
    SQLSMALLINT        cbTableName)
    {
        return ODBCINST->SQLTablePrivileges(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLTablePrivilegesA(
    SQLHSTMT           hstmt,
    SQLCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        return ODBCINST->SQLTablePrivilegesA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLTablePrivilegesW(
    SQLHSTMT           hstmt,
    SQLWCHAR        *szCatalogName,
    SQLSMALLINT        cbCatalogName,
    SQLWCHAR        *szSchemaName,
    SQLSMALLINT        cbSchemaName,
    SQLWCHAR        *szTableName,
    SQLSMALLINT        cbTableName)
    {
        return ODBCINST->SQLTablePrivilegesW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName);
    }
    SQLRETURN EXPORT_SQLAPI SQLTablesA(
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
        return ODBCINST->SQLTablesA(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,szTableType,cbTableType);
    }
    SQLRETURN EXPORT_SQLAPI SQLTablesW(
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
        return ODBCINST->SQLTablesW(hstmt,szCatalogName,cbCatalogName,szSchemaName,cbSchemaName,szTableName,cbTableName,szTableType,cbTableType);
    }
 
                                      
                                 
                                     
                                
                                        
                                       
                                      
} 
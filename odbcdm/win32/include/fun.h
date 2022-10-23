#ifndef FUN_H_20190315
#define FUN_H_20190315

#include <map>
#include "commfun.h"
#include "EMDBType.h"

typedef struct STR_ODBC_COL_BINDING {
	SQLSMALLINT         cDisplaySize;           /* size to display  */
	char               *szBuffer;             /* display buffer   */
	SQLLEN              indPtr = 0;                 /* size or null     */
	BOOL                fChar;                  /* character col?   */
	struct STR_ODBC_COL_BINDING  *sNext;                 /* linked list      */
} ODBC_COL_BINDING;

struct SqlException; 
bool InitEnforceContext(SQLHDBC hdbc, SqlException * exc);
bool parseConnectingStr(const char *src, std::map<std::string, std::string> &data);

bool  QueryODBCSessionInfo(HDBC hdbc, EMDB_DB_TYPE dbType, std::string& strUser, std::string& strSchema, std::string& strServer, std::string& strDbName, SqlException * exc);
void AllocateBindings(HSTMT    hStmt,
	SQLSMALLINT   cCols,
	ODBC_COL_BINDING       **ppBinding,
	SQLSMALLINT   *pDisplay);


#endif 
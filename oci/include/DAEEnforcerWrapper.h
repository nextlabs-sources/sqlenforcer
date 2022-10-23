#pragma once

#include <string>

/*

*/
typedef void* EMDBResultHandle;
typedef void* EMDBUserCtxHandle;

 enum EMDBReturn { EMDB_SUCCESS, EMDB_ERROR /* todo */, EMDB_INVALID_HANDLE };

 enum EMDBResultCode { EMDB_BLOCK_THIS_TEXT, EMDB_USE_NEW_TEXT, EMDB_DENY_EXECUTE };

typedef EMDBReturn (*EMDBInitFunc)(const char *module_name);

typedef EMDBReturn (*EMDBNewUserCtxFunc)(const char *server_name, const char *database_name, const char *schema_name, const char *dbtype, EMDBUserCtxHandle *output_user_ctx);

typedef EMDBReturn(*EMDBFreeUserCtxFunc)(EMDBUserCtxHandle user_ctx);

typedef EMDBReturn(*EMDBSetUserCtxPropertyFunc)(EMDBUserCtxHandle user_ctx, const char *key, const char *value);

typedef EMDBReturn(*EMDBClearUserCtxPropertyFunc)(EMDBUserCtxHandle user_ctx);

typedef EMDBReturn(*EMDBEvalSqlFunc)(const char *sql, EMDBUserCtxHandle user_ctx, EMDBResultHandle result);

typedef EMDBReturn(*EMDBNewResultFunc)(EMDBResultHandle *output_result);

typedef EMDBReturn(*EMDBFreeResultFunc)(EMDBResultHandle result);

typedef EMDBReturn(*EMDBResultGetCodeFunc)(EMDBResultHandle result, EMDBResultCode *output_code);

typedef EMDBReturn(*EMDBResultGetDetailFunc)(EMDBResultHandle result, const char **output_detail);

typedef int  (*SQLEnforcerWriteLogWithTagAFunc)(int level, const char* tag, const char* msg);


enum EMDataType{
    EMDATA_STRING,
    EMDATA_NUMBER,
    EMDATA_DATE,
    EMDATA_TIME,
    EMDATA_TIMESTAMP,
    EMDATA_STRING2,
    EMDATA_TIMESTAMP_TZ_ORA,
    EMDATA_YMINTERVAL,
    EMDATA_DSINTERVAL,
    EMDATA_NONSUPPORT

};
struct Metadata {
    std::string _col;
    EMDataType _type;
};
#include <vector>
#include <functional>
typedef std::vector<Metadata> MetadataVec;
typedef std::function<bool (const std::string &,MetadataVec & )> QueryMetadataFunc;

typedef EMDBReturn (*EMDBQueryMetadata_cb_Func)(EMDBUserCtxHandle user_ctx, QueryMetadataFunc func);

#include <map>
class  Enforcer
{
   public:
   static Enforcer* Instance(){
       static Enforcer* pEnforcer = new Enforcer();
       return pEnforcer;
   }

   bool LoadEnforcer(std::string path);
   bool IsLoaded() { return _bload; }

   //
public:
    EMDBInitFunc EMDBInit = NULL;
    EMDBNewUserCtxFunc EMDBNewUserCtx = NULL;
    EMDBFreeUserCtxFunc EMDBFreeUserCtx = NULL;
    EMDBSetUserCtxPropertyFunc EMDBSetUserCtxProperty = NULL;
    EMDBClearUserCtxPropertyFunc EMDBClearUserCtxProperty = NULL;
    EMDBEvalSqlFunc EMDBEvalSql = NULL;
    EMDBNewResultFunc EMDBNewResult = NULL;
    EMDBFreeResultFunc EMDBFreeResult = NULL;
    EMDBResultGetCodeFunc EMDBResultGetCode = NULL;
    EMDBResultGetDetailFunc EMDBResultGetDetail = NULL;
    EMDBQueryMetadata_cb_Func EMDBQueryMetadata_cb = NULL;
    SQLEnforcerWriteLogWithTagAFunc EMDBWriteLog = NULL;
private:
    bool _bload = false;
protected:
    Enforcer();
    Enforcer(const Enforcer&){};

};
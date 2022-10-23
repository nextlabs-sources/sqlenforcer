#include <commfun.h>
#include "DAEEnforcerWrapper.h"


#ifdef _WIN32
#include <windows.h>
#else

#endif

//#define GET_Enforcer_PROC(funname) funname=(funname##Fun)::GetProcAddress((HMODULE)hEnforcer, #funname);

Enforcer::Enforcer()
{
}


bool Enforcer::LoadEnforcer(std::string path)
{
// #ifdef _WIN64
// 	std::string EnforcerPath = "C:\\Program Files\\NextLabs\\DAEForWindows\\Common\\bin64\\sqlenforcer.dll";//TODO
// #else
// 	std::string EnforcerPath = "C:\\Program Files\\NextLabs\\DAEForWindows\\Common\\bin32\\sqlenforcer.dll";//TODO
// #endif
    
    //printf("load enforcer from:%s\n", EnforcerPath.c_str() );   /* here we can not call theLog */
    void* hEnforcer = CommonFun::LoadShareLibrary(path.c_str());
    if(hEnforcer==NULL)
    {
        //printf(LOAD_MODULE_FAILED, EnforcerPath.c_str(), CommonFun::ShareLibraryError().c_str());
		_bload = false;
        return false;
    }

	EMDBInit = (EMDBInitFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBInit");
	EMDBNewUserCtx = (EMDBNewUserCtxFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBNewUserCtx");
	EMDBFreeUserCtx = (EMDBFreeUserCtxFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBFreeUserCtx");
	EMDBSetUserCtxProperty = (EMDBSetUserCtxPropertyFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBSetUserCtxProperty");
	EMDBClearUserCtxProperty = (EMDBClearUserCtxPropertyFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBClearUserCtxProperty");
	EMDBEvalSql = (EMDBEvalSqlFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBEvalSql");
	EMDBNewResult = (EMDBNewResultFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBNewResult");
	EMDBFreeResult = (EMDBFreeResultFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBFreeResult");
	EMDBResultGetCode = (EMDBResultGetCodeFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBResultGetCode");
	EMDBResultGetDetail = (EMDBResultGetDetailFunc)CommonFun::GetProcAddress(hEnforcer, "EMDBResultGetDetail");
    EMDBQueryMetadata_cb = (EMDBQueryMetadata_cb_Func)CommonFun::GetProcAddress(hEnforcer, "EMDBQueryMetadata_cb");
	EMDBWriteLog = (SQLEnforcerWriteLogWithTagAFunc)CommonFun::GetProcAddress(hEnforcer, "SQLEnforcerWriteLogWithTagA");
	


	_bload = EMDBInit != NULL &&
		EMDBNewUserCtx != NULL &&
		EMDBFreeUserCtx != NULL &&
		EMDBSetUserCtxProperty != NULL &&
		EMDBClearUserCtxProperty != NULL &&
		EMDBEvalSql != NULL &&
		EMDBNewResult != NULL &&
		EMDBFreeResult != NULL &&
		EMDBResultGetCode != NULL &&
		EMDBResultGetDetail != NULL &&
		EMDBWriteLog;
	return _bload;
}
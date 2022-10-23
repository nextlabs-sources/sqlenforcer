 #include "policymgrwrapper.h"
 #include "commfun.h"
 #include "EMDBConfig.h"
 #include "DAELog.h"

 #ifdef WIN32
 #include <windows.h>
 #else
 #include <dlfcn.h>
 #endif

 bool CCPolicyMgrWrapper::LoadPolicyMgr()
 {
     const std::string strInstallPath = EMDBConfig::GetInstance().get_global_install_path();
#ifdef WIN32
#ifdef _WIN64
     //std::string strPath = strInstallPath + "\\Common\\bin64\\DAECCPolicyMgr.dll";
     std::string strPath = "DAECCPolicyMgr.dll"; 
#else
     std::string strPath = strInstallPath + "\\Common\\bin32\\DAECCPolicyMgr.dll";
#endif
#else
     std::string strPath = strInstallPath + "/Common/bin64/libdaeccpolicymgr.so";
#endif
     //load library
     void* hModule = CommonFun::LoadShareLibrary(strPath.c_str());
     if (hModule==NULL) {
         #ifdef WIN32
         theLog->WriteLog(log_fatal, "load DAECCPolicyMgr.dll failed, dwlasterror=0x%x", GetLastError() );
         #else
         const char * err = dlerror();
         theLog->WriteLog(log_fatal, "load libDAECCPolicyMgr.so failed, dlerror=%s", err!=NULL ? err : "NULL" );
         #endif 
         return false;
     }
     //get function address
     PolicyInit = (PolicyInit_Func)CommonFun::GetProcAddress(hModule, "PolicyInit");
     GetTablePolicyinfo = (GetTablePolicyinfo_Func)CommonFun::GetProcAddress(hModule, "GetTablePolicyinfo");
     Exit = (Exit_Func)CommonFun::GetProcAddress(hModule, "Exit");
     UpdateSyncInterval = (UpdateSyncInterval_Func)CommonFun::GetProcAddress(hModule, "UpdateSyncInterval"); 
     IsNeedEnforcer = (IsNeedEnforcer_Func)CommonFun::GetProcAddress(hModule, "IsNeedEnforcer");
     BindUpdateNotification = (BindUpdateNotification_Func)CommonFun::GetProcAddress(hModule, "BindUpdateNotification");

     m_bWell = (PolicyInit != NULL) &&
               (GetTablePolicyinfo != NULL) &&
               (Exit != NULL) &&
               (UpdateSyncInterval != NULL) &&
               (IsNeedEnforcer != NULL) &&
               (BindUpdateNotification != NULL);
     return m_bWell;
 }
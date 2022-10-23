#include "DAEOciWrapper.h"
#include "DAELog.h"
#include <commfun.h>
#ifdef _WIN32
#else
#include <dlfcn.h>
#include "funchook.h"
#include <stdio.h>
#endif

OCIHandleAlloc_Func DAEOCIMgrApi::OCIHandleAlloc = nullptr;
OCIHandleFree_Func DAEOCIMgrApi::OCIHandleFree = nullptr;//= (OCIHandleFree_Func)CommonFun::GetProcAddress(hd, "OCIHandleFree");
OCIStmtPrepare_Func DAEOCIMgrApi::OCIStmtPrepare = nullptr;//= (OCIStmtPrepare_Func)CommonFun::GetProcAddress(hd, "OCIStmtPrepare");
OCIStmtPrepare2_Func DAEOCIMgrApi::OCIStmtPrepare2 = nullptr;//= (OCIStmtPrepare2_Func)CommonFun::GetProcAddress(hd, "OCIStmtPrepare2");
OCIStmtExecute_Func DAEOCIMgrApi::OCIStmtExecute = nullptr;//= (OCIStmtExecute_Func)CommonFun::GetProcAddress(hd, "OCIStmtExecute");
OCIServerAttach_Func DAEOCIMgrApi::OCIServerAttach = nullptr;//= (OCIServerAttach_Func)CommonFun::GetProcAddress(hd, "OCIServerAttach");
OCIAttrSet_Func DAEOCIMgrApi::OCIAttrSet = nullptr;//= (OCIAttrSet_Func)CommonFun::GetProcAddress(hd, "OCIAttrSet");

OCIBindByName_Func DAEOCIMgrApi::OCIBindByName = nullptr;//= (OCIBindByName_Func)CommonFun::GetProcAddress(hd, "OCIBindByName");
OCIBindByName2_Func DAEOCIMgrApi::OCIBindByName2 = nullptr;//= (OCIBindByName2_Func)CommonFun::GetProcAddress(hd, "OCIBindByName2");
OCIBindByPos_Func DAEOCIMgrApi::OCIBindByPos = nullptr;//=(OCIBindByPos_Func)CommonFun::GetProcAddress(hd, "OCIBindByPos");
OCIBindByPos2_Func DAEOCIMgrApi::OCIBindByPos2 = nullptr;//= (OCIBindByPos2_Func)CommonFun::GetProcAddress(hd, "OCIBindByPos2");
OCIDefineByPos_Func DAEOCIMgrApi::OCIDefineByPos = nullptr;//= (OCIDefineByPos_Func)CommonFun::GetProcAddress(hd, "OCIDefineByPos");

OCIStmtFetch_Func DAEOCIMgrApi::OCIStmtFetch = nullptr;//= (OCIStmtFetch_Func)CommonFun::GetProcAddress(hd, "OCIStmtFetch");
OCIStmtFetch2_Func DAEOCIMgrApi::OCIStmtFetch2 = nullptr;//= (OCIStmtFetch2_Func)CommonFun::GetProcAddress(hd, "OCIStmtFetch2");
OCIAttrGet_Func DAEOCIMgrApi::OCIAttrGet = nullptr;//= (OCIAttrGet_Func)CommonFun::GetProcAddress(hd, "OCIAttrGet");

OCISessionBegin_Func DAEOCIMgrApi::OCISessionBegin= nullptr;


OCIErrorGet_Func DAEOCIMgrApi::OCIErrorGet=nullptr;
OCIParamGet_Func DAEOCIMgrApi::OCIParamGet = nullptr;

OCIInitialize_Func DAEOCIMgrApi::OCIInitialize = nullptr;
OCIEnvCreate_Func DAEOCIMgrApi::OCIEnvCreate= nullptr;
OCIEnvNlsCreate_Func DAEOCIMgrApi::OCIEnvNlsCreate = nullptr;

OCIServerDetach_Func DAEOCIMgrApi::OCIServerDetach = nullptr;
OCISessionEnd_Func DAEOCIMgrApi::OCISessionEnd = nullptr;

DAEOCIMgrApi::DAEOCIMgrApi() {
    if(!m_bInit){
        m_bInit = InitApi();
    }
}




bool DAEOCIMgrApi::InitApi() {
#ifdef _WIN32
    auto hd = CommonFun::LoadShareLibrary("oci_ms.dll");;
    if(nullptr == hd){
        Log::WLog(log_error,"::LoadLibraryA oci_ms.dll failed!");
        return false;
    }

#else
    auto hd = dlopen("libclntsh.so", RTLD_NOW|RTLD_GLOBAL);
    //
    if(nullptr == hd){
        return false;
    }
#endif

    OCIEnvCreate = (OCIEnvCreate_Func)CommonFun::GetProcAddress(hd, "OCIEnvCreate");
    OCIInitialize = (OCIInitialize_Func)CommonFun::GetProcAddress(hd, "OCIInitialize");
//    OCIEnvInit = (OCIEnvInit_Func)CommonFun::GetProcAddress(hd, "OCIEnvInit");
    OCIEnvNlsCreate = (OCIEnvNlsCreate_Func)CommonFun::GetProcAddress(hd, "OCIEnvNlsCreate");
//    OCIFEnvCreate = (OCIFEnvCreate_Func)CommonFun::GetProcAddress(hd, "OCIFEnvCreate");

    OCIHandleAlloc = (OCIHandleAlloc_Func)CommonFun::GetProcAddress(hd, "OCIHandleAlloc");
    
    OCIHandleFree = (OCIHandleFree_Func)CommonFun::GetProcAddress(hd, "OCIHandleFree");
    OCIStmtPrepare = (OCIStmtPrepare_Func)CommonFun::GetProcAddress(hd, "OCIStmtPrepare");
    OCIStmtPrepare2 = (OCIStmtPrepare2_Func)CommonFun::GetProcAddress(hd, "OCIStmtPrepare2");
    OCIStmtExecute = (OCIStmtExecute_Func)CommonFun::GetProcAddress(hd, "OCIStmtExecute");
    OCIServerAttach = (OCIServerAttach_Func)CommonFun::GetProcAddress(hd, "OCIServerAttach");
    OCIAttrSet = (OCIAttrSet_Func)CommonFun::GetProcAddress(hd, "OCIAttrSet");

   OCIBindByName = (OCIBindByName_Func)CommonFun::GetProcAddress(hd, "OCIBindByName");
   OCIBindByName2 = (OCIBindByName2_Func)CommonFun::GetProcAddress(hd, "OCIBindByName2");
   OCIBindByPos =(OCIBindByPos_Func)CommonFun::GetProcAddress(hd, "OCIBindByPos");
   OCIBindByPos2 = (OCIBindByPos2_Func)CommonFun::GetProcAddress(hd, "OCIBindByPos2");
   OCIDefineByPos = (OCIDefineByPos_Func)CommonFun::GetProcAddress(hd, "OCIDefineByPos");

   OCIStmtFetch = (OCIStmtFetch_Func)CommonFun::GetProcAddress(hd, "OCIStmtFetch");
   OCIStmtFetch2 = (OCIStmtFetch2_Func)CommonFun::GetProcAddress(hd, "OCIStmtFetch2");
   OCIAttrGet = (OCIAttrGet_Func)CommonFun::GetProcAddress(hd, "OCIAttrGet");

    OCISessionBegin = (OCISessionBegin_Func)CommonFun::GetProcAddress(hd, "OCISessionBegin");

    OCIErrorGet = (OCIErrorGet_Func)CommonFun::GetProcAddress(hd, "OCIErrorGet");

    OCIParamGet = (OCIParamGet_Func)CommonFun::GetProcAddress(hd, "OCIParamGet");

    OCIServerDetach = (OCIServerDetach_Func)CommonFun::GetProcAddress(hd, "OCIServerDetach");
    OCISessionEnd = (OCISessionEnd_Func)CommonFun::GetProcAddress(hd, "OCISessionEnd");

#ifdef _WIN32
#else
    //hook
    funchook_t *funchook = funchook_create();

    int rv = 0;
//    rv = funchook_prepare(funchook, (void **)&OCIInitialize, (void *)OCIInitialize_new);
//    if (0 != rv)
//    {
//        return false;
//    }

//    rv = funchook_prepare(funchook, (void **)&OCIEnvInit, (void *)OCIEnvInit_new);
//    if (0 != rv)
//    {
//        return false;
//    }
    rv = funchook_prepare(funchook, (void **)&OCIEnvCreate, (void *)OCIEnvCreate_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIEnvNlsCreate, (void *)OCIEnvNlsCreate_new);
    if (0 != rv)
    {
        return false;
    }
    //rv = funchook_prepare(funchook, (void **)&OCIFEnvCreate, (void *)OCIFEnvCreate_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIHandleAlloc, (void *)OCIHandleAlloc_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIHandleFree, (void *)OCIHandleFree_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIStmtPrepare, (void *)OCIStmtPrepare_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIStmtPrepare2, (void *)OCIStmtPrepare2_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIStmtExecute, (void *)OCIStmtExecute_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIServerAttach, (void *)OCIServerAttach_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCIAttrSet, (void *)OCIAttrSet_new);
    if (0 != rv)
    {
        return false;
    }
    rv = funchook_prepare(funchook, (void **)&OCISessionBegin, (void *)OCISessionBegin_new);
    if (0 != rv)
    {
        return false;
    }
//    rv = funchook_prepare(funchook, (void **)&OCIBindByName, (void *)OCIBindByName_new);
//    if (0 != rv)
//    {
//        return false;
//    }
//    rv = funchook_prepare(funchook, (void **)&OCIBindByName2, (void *)OCIBindByName2_new);
//    if (0 != rv)
//    {
//        return false;
//    }
//    rv = funchook_prepare(funchook, (void **)&OCIBindByPos, (void *)OCIBindByPos_new);
//    if (0 != rv)
//    {
//        return false;
//    }
//    rv = funchook_prepare(funchook, (void **)&OCIBindByPos2, (void *)OCIBindByPos2_new);
//    if (0 != rv)
//    {
//        return false;
//    }
//    rv = funchook_prepare(funchook, (void **)&OCIDefineByPos, (void *)OCIDefineByPos_new);
//    if (0 != rv)
//    {
//        return false;
//    }
//    rv = funchook_prepare(funchook, (void **)&OCIStmtFetch, (void *)OCIStmtFetch_new);
//    if (0 != rv)
//    {
//        return false;
//    }
//    rv = funchook_prepare(funchook, (void **)&OCIStmtFetch2, (void *)OCIStmtFetch2_new);
//    if (0 != rv)
//    {
//        return false;
//    }
//    rv = funchook_prepare(funchook, (void **)&OCIAttrGet, (void *)OCIAttrGet_new);
//    if (0 != rv)
//    {
//        return false;
//    }
    rv = funchook_install(funchook, 0);
    if (rv != 0)
    {
        return false;
    }
    printf("----funchook_install succeed!----\n");
#endif
    return OCIHandleAlloc != NULL;
}

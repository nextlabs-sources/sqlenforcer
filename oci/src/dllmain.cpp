// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <stdio.h>
#include <string>
//#include "commfun.h"
const std::string OCI_MS ="OCI_MS.DLL";
#include "DAEOciWrapper.h"


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{ 
		DisableThreadLibraryCalls(hinstDLL);

		::OutputDebugStringA("-- begin");
		std::string path_ocims;
		char sz[256]={0};
		::GetModuleFileNameA(hinstDLL,sz,256);
		std::string path_oci(sz);
		int ipos = path_oci.rfind("OCI.DLL");
		if(std::string::npos != ipos){
			path_ocims =path_oci.substr(0, ipos);
		} 
		path_ocims += OCI_MS;
		::OutputDebugStringA(path_ocims.c_str());
		auto hODBCMgr = ::LoadLibraryA(path_ocims.c_str());
		if(nullptr == hODBCMgr){
			::OutputDebugStringA("-- load oci_ms failed!");
		}
		DAEOCIMgrApi::Instance();

		::OutputDebugStringA("-- end");
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		
	}
	return TRUE;
}

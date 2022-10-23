#pragma once

#ifdef _WIN64
#ifdef _DEBUG
#pragma comment(lib,"lib\\json_vc71_libmtd.lib")
#else //
#pragma comment(lib,"lib\\json_vc71_libmt.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib,"lib\\x86\\json_vc71_libmtd.lib")
#else //
#pragma comment(lib,"lib\\x86\\json_vc71_libmt.lib")
#endif
#endif



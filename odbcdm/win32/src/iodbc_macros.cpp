#include "iodbc_macros.h"
#include <mutex>
#include <assert.h>

std::mutex g_odbc_mutex;
//static int g_odbc_mutex_lock_cnt = 0;
// static CRITICAL_SECTION M;
// void INIT_ODBC_LOCK() {
// 	//InitializeCriticalSection(&M);
// }

void odbc_lock() {
	g_odbc_mutex.lock();
	//assert(0 == g_odbc_mutex_lock_cnt);
	//g_odbc_mutex_lock_cnt++;
	//EnterCriticalSection(&M);
}

void odbc_unlock() {
	//assert(1 == g_odbc_mutex_lock_cnt);
	// g_odbc_mutex_lock_cnt--;
	 g_odbc_mutex.unlock();
	//LeaveCriticalSection(&M);
}
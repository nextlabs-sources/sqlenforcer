//
// Created by jeff on 2019/9/3.
//

//redirect some API

#include "ODBCMgrApi.h"
//
//#if defined(__cplusplus)
//extern  "C" {
//#endif
//
//int uodbc_open_stats(void **rh, unsigned int mode);
//#define UODBC_STATS_READ 0x1
//#define UODBC_STATS_WRITE 0x2
//int uodbc_close_stats(void *rh);
//int uodbc_get_stats(void *h, pid_t request_pid,
//                    uodbc_stats_retentry *s, int n_stats);
//char *uodbc_stats_error(char *buf, size_t buflen);
//
//#if defined(__cplusplus)
//}
//#endif
//#include <stdio.h>


bool SQL_API ODBCSetTryWaitValue ( DWORD dwValue )
{
    return 0;
}

#ifdef __cplusplus
DWORD SQL_API ODBCGetTryWaitValue ( )
#else
DWORD SQL_API ODBCGetTryWaitValue ( void )
#endif
{
    return 0;
}








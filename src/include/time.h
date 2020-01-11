#ifndef __TIME_H__
#define __TIME_H__

#include <stddef.h>
#include <lvlibc/time-abi.h>

#ifdef __cplusplus
extern "C" {
#endif

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

#ifdef __cplusplus
}
#endif

#endif

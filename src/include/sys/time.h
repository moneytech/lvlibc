#ifndef __SYS__TIME_H__
#define __SYS__TIME_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct timeval {
    time_t tv_sec;
    suseconds_t tv_usec;
};

struct itimerval {
    struct timeval it_interval;
    struct timeval it_value;
};

#ifdef __cplusplus
}
#endif

#endif

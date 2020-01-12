#ifndef __FCNTL_H__
#define __FCNTL_H__

#include <sys/types.h>
#include <lvlibc/fcntl-abi.h>

#ifdef __cplusplus
extern "C" {
#endif

int fcntl(int, int, ...);
int open(const char *, int, ...);
int creat(const char *, mode_t);

#ifdef __cplusplus
}
#endif

#endif

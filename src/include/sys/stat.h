#ifndef __SYS__STAT_H__
#define __SYS__STAT_H__

#include <sys/types.h>
#include <lvlibc/stat-abi.h>

#ifdef __cplusplus
extern "C" {
#endif

int chmod(const char *, mode_t);
int fchmod(int, mode_t);
int fstat(int, struct stat *);
int lstat(const char *restrict, struct stat *restrict);
int mkdir(const char *, mode_t);
int mkfifo(const char *, mode_t);
int mknod(const char *, mode_t, dev_t);
int stat(const char *restrict, struct stat *restrict);
mode_t umask(mode_t);

#ifdef __cplusplus
}
#endif

#endif

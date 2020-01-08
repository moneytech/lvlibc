#ifndef __LVLIBC__SYSDEPS_H__
#define __LVLIBC__SYSDEPS_H__

#include <stddef.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

int __sys_open(const char *path, int flags);
ssize_t __sys_read(int fd, void *buf, size_t count);

#ifdef __cplusplus
}
#endif

#endif

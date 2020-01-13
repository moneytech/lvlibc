#ifndef __UNISTD_H__
#define __UNISTD_H__

#include <stddef.h>
#include <sys/types.h>
#include <lvlibc/unistd-abi.h>

#define _POSIX_VERSION (200809L)

#ifdef __cplusplus
extern "C" {
#endif

pid_t getpid(void);

pid_t fork(void);
int execv(const char *path, char *const argv[]);
int execvp(const char *path, char *const argv[]);
int execve(const char *path, char *const argv[], char *const envp[]);

int access(const char *path, int amode);

#ifdef __cplusplus
}
#endif

#endif

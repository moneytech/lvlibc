#ifndef __UNISTD_H__
#define __UNISTD_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

pid_t fork(void);
int execv(const char *path, char *const argv[]);
int execvp(const char *path, char *const argv[]);
int execve(const char *path, char *const argv[], char *const envp[]);

#ifdef __cplusplus
}
#endif

#endif

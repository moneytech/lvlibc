#ifndef __SYS__WAIT_H__
#define __SYS__WAIT_H__

#include <signal.h>
#include <sys/types.h>
#include <lvlibc/wait-abi.h>

#ifdef __cplusplus
extern "C" {
#endif

pid_t wait(int *);
pid_t waitpid(pid_t, int *, int);

#ifdef __cplusplus
}
#endif

#endif

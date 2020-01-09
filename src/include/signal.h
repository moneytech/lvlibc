#ifndef __SIGNAL_H__
#define __SIGNAL_H__

#include <sys/types.h>
#include <lvlibc/signal-abi.h>

#ifdef __cplusplus
extern "C" {
#endif

union sigval {
    int sival_int;
    void *sival_ptr;
};

struct sigevent {
    int sigev_notify;
    int sigev_signo;
    union sigval sigev_value;
    void (*sigev_notify_function)(union sigval);
    pthread_attr_t *sigev_notify_attributes;
};

int sigaction(int, const struct sigaction *, struct sigaction *);
void (*signal(int, void (*)(int)))(int);

#ifdef __cplusplus
}
#endif

#endif

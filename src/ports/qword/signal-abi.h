#ifndef __LVLIBC__SIGNAL_ABI_H__
#define __LVLIBC__SIGNAL_ABI_H__

#define SA_NOCLDSTOP (1 << 0)
#define SA_ONSTACK   (1 << 1)
#define SA_RESETHAND (1 << 2)
#define SA_RESTART   (1 << 3)
#define SA_SIGINFO   (1 << 4)
#define SA_NOCLDWAIT (1 << 5)
#define SA_NODEFER   (1 << 6)

#define SIG_ERR  (void (*)(int))(-1)
#define SIG_DFL  (void (*)(int))(-2)
#define SIG_IGN  (void (*)(int))(-3)
#define SIG_HOLD (void (*)(int))(-4)

#define SIGABRT    1
#define SIGFPE     2
#define SIGILL     3
#define SIGINT     4
#define SIGSEGV    5
#define SIGTERM    6
#define SIGPROF    7
#define SIGALRM    8
#define SIGBUS     9
#define SIGCHLD   10
#define SIGCONT   11
#define SIGHUP    12
#define SIGKILL   13
#define SIGPIPE   14
#define SIGQUIT   15
#define SIGSTOP   16
#define SIGTSTP   17
#define SIGTTIN   18
#define SIGTTOU   19
#define SIGUSR1   20
#define SIGUSR2   21
#define SIGSYS    22
#define SIGTRAP   23
#define SIGURG    24
#define SIGVTALRM 25
#define SIGXCPU   26
#define SIGXFSZ   27
#define SIGWINCH  28

#ifdef __cplusplus
extern "C" {
#endif

typedef long sigset_t;

struct sigaction {
	void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
	void (*sa_sigaction)(int, void *, void *);
};

#ifdef __cplusplus
}
#endif

#endif

#ifndef __LVLIBC__WAIT_ABI_H__
#define __LVLIBC__WAIT_ABI_H__

#define WCONTINUED 1
#define WNOHANG 2
#define WUNTRACED 4
#define WEXITED 8
#define WNOWAIT 16
#define WSTOPPED 32

#define WEXITSTATUS(x) ((x) & 0x000000ff)
#define WIFCONTINUED(x) ((x) & 0x00000100)
#define WIFEXITED(x) ((x) & 0x00000200)
#define WIFSIGNALED(x) ((x) & 0x00000400)
#define WIFSTOPPED(x) ((x) & 0x00000800)
#define WSTOPSIG(x) (((x) & 0x00ff0000) >> 16)
#define WTERMSIG(x) (((x) & 0xff000000) >> 24)

#endif

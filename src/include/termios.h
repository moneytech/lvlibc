#ifndef __TERMIOS_H__
#define __TERMIOS_H__

#include <sys/types.h>
#include <lvlibc/termios-abi.h>

#ifdef __cplusplus
extern "C" {
#endif

speed_t cfgetispeed(const struct termios *);
speed_t cfgetospeed(const struct termios *);
int     cfsetispeed(struct termios *, speed_t);
int     cfsetospeed(struct termios *, speed_t);
int     tcdrain(int);
int     tcflow(int, int);
int     tcflush(int, int);
int     tcgetattr(int, struct termios *);
pid_t   tcgetsid(int);
int     tcsendbreak(int, int);
int     tcsetattr(int, int, struct termios *);

#ifdef __cplusplus
}
#endif

#endif

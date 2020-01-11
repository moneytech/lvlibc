#ifndef __SETJMP_H__
#define __SETJMP_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t jmp_buf[8];

int setjmp(jmp_buf state);
void longjmp(jmp_buf state, int ret);

#ifdef __cplusplus
}
#endif

#endif

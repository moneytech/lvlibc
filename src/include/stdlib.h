#ifndef __STDLIB_H__
#define __STDLIB_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *malloc(size_t size);
void free(void *ptr);
void abort(void);
int atexit(void (*func)(void));
int atoi(const char *str);
char *getenv(const char *var);

#ifdef __cplusplus
}
#endif

#endif

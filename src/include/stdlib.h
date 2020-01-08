#ifndef __STDLIB_H__
#define __STDLIB_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *malloc(size_t size);
void free(void *ptr);
void abort(void);

#ifdef __cplusplus
}
#endif

#endif

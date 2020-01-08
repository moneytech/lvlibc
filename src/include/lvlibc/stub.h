#ifndef __LVLIBC__STUB_H__
#define __LVLIBC__STUB_H__

#include <assert.h>

#define FUNCTION_STUB() do { \
    assert(!"Function " stringify(__func__) " is a stub"); \
} while (0)

#endif

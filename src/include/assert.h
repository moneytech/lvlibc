#ifndef __ASSERT_H__
#define __ASSERT_H__

// FIXME: don't include this
#include <lvlibc/sysdeps.h>

#define stringify(a) str(a)
#define str(a) #a

// TODO: assert needs to print debug info, this is just a stub
#ifdef NDEBUG
    #define assert(expr) ((void)0)
#else
    #define assert(expr) do { \
        if (!(expr)) { \
            char str0[] = "Assertion failed at line "; \
            char str1[] = stringify(__LINE__); \
            char str2[] = " of file "; \
            char str3[] = stringify(__FILE__); \
            __sys_write(2, str0, sizeof(str0)); \
            __sys_write(2, str1, sizeof(str1)); \
            __sys_write(2, str2, sizeof(str2)); \
            __sys_write(2, str3, sizeof(str3)); \
            __sys_write(2, "\n", 1); \
            __sys_exit(1); \
        } \
    } while (0)
#endif

#endif

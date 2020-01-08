#include <stdlib.h>
#include <lvlibc/sysdeps.h>
#include <lvlibc/stub.h>

int atexit(void (*func)(void)) { FUNCTION_STUB(); }

void exit(int status) {
    __sys_exit(status);
}

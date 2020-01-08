#include <lvlibc/sysdeps.h>
#include <stdarg.h>

void __sys_exit(int error_code) {
    asm volatile (
        "syscall"
        :
        : "a"(12), "D"(error_code)
    );
}

ssize_t __sys_read(int fd, void *buf, size_t count) {
    ssize_t ret;
    int _errno;
    asm volatile (
        "syscall"
        : "=a"(ret), "=d"(_errno)
        : "a"(3), "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11"
    );
    return ret;
}

ssize_t __sys_write(int fd, const void *buf, size_t count) {
    ssize_t ret;
    int _errno;
    asm volatile (
        "syscall"
        : "=a"(ret), "=d"(_errno)
        : "a"(4), "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11"
    );
    return ret;
}

int __sys_open(const char *path, int flags, ...) {
    int ret;
    int mode;
    int _errno;
    va_list l;
    va_start(l, flags);
    mode = va_arg(l, int);
    va_end(l);
    asm volatile (
        "syscall"
        : "=a"(ret), "=d"(_errno)
        : "a"(1), "D"(path), "S"(flags), "d"(mode)
        : "rcx", "r11"
    );
    return ret;
}

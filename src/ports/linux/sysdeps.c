#include <lvlibc/sysdeps.h>
#include <stdarg.h>

void __sys_exit(int error_code) {
    asm volatile (
        "syscall"
        :
        : "a"(60), "D"(error_code)
    );
}

ssize_t __sys_read(int fd, void *buf, size_t count) {
    ssize_t ret;
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(0), "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11"
    );
    return ret;
}

ssize_t __sys_write(int fd, const void *buf, size_t count) {
    ssize_t ret;
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(1), "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11"
    );
    return ret;
}

int __sys_open(const char *path, int flags, ...) {
    int ret;
    int mode;
    va_list l;
    va_start(l, flags);
    mode = va_arg(l, int);
    va_end(l);
    asm volatile (
        "syscall"
        : "=a"(ret)
        : "a"(2), "D"(path), "S"(flags), "d"(mode)
        : "rcx", "r11"
    );
    return ret;
}

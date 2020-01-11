#include <stdio.h>

#include <lvlibc/sysdeps.h>

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>

#define FMT_PUT(dst, len, c) {\
                if(!(len) && check_bounds) goto end;\
                *(dst)++ = (c);\
                len--;\
                ret++;\
            }

static const char *digits_upper = "0123456789ABCDEF";
static const char *digits_lower = "0123456789abcdef";

static char *num_fmt(char *buf, size_t buf_len, uint64_t i, int base, int padding, char pad_with, int handle_signed, int upper, int len, char plus_char) {
    int neg = (int64_t)i < 0 && handle_signed;

    if (neg)
        i = (uint64_t)(-((int64_t)i));

    char *ptr = buf + buf_len - 1;
    *ptr = '\0';

    const char *digits = upper ? digits_upper : digits_lower;

    do {
        *--ptr = digits[i % base];
        if (padding)
            padding--;
        if (len > 0)
            len--;
        buf_len--;
    } while ((i /= base) != 0 && (len == -1 || len) && buf_len);

    while (padding && buf_len) {
        *--ptr = pad_with;
        padding--;
        buf_len--;
    }

    if (!buf_len)
        return ptr;

    if (neg)
        *--ptr = '-';

    if (!neg && plus_char)
        *--ptr = plus_char;

    return ptr;
}

#define NUM_BUF_LEN 48

static int internal_format_string(int check_bounds, char *buf, size_t len, const char *fmt, va_list arg) {
    int ret = 0;
    uint64_t i;
    char *s;
    char num_buf[NUM_BUF_LEN];

    while(*fmt && (len || !check_bounds)) {
        if (*fmt != '%') {
            *buf++ = *fmt;
            fmt++;
            continue;
        }

        fmt++;
        int padding = 0;
        char pad_with = ' ';
        int wide = 0, upper = 0;
        char plus_char = 0;
        int alternative = 0;
        int precision = 0;

        if (*fmt == '0') {
            pad_with = '0';
            fmt++;
        } else if (*fmt == '#') {
            alternative = 1;
            fmt++;
        } else if (*fmt == ' ') {
            plus_char = ' ';
            fmt++;
        } else if (*fmt == '+') {
            plus_char = '+';
            fmt++;
        } else if (*fmt == '-') {
            // TODO: left align with padding
            fmt++;
        }

        if (*fmt == '*') {
            padding = va_arg(arg, int);
            fmt++;
        } else while (isdigit(*fmt)) {
            padding *= 10;
            padding += *fmt++ - '0';
        }

        // next character is the precision
        if (*fmt == '.') {
            fmt++;
            if (*fmt == '*') {
                precision = va_arg(arg, int);
                fmt++;
            } else while (isdigit(*fmt)) {
                precision *= 10;
                precision += *fmt++ - '0';
            }
        } else {
            precision = -1;
        }

        while (*fmt == 'l') {
            wide = 1;
            fmt++;
        }

        while (*fmt == 'h') {
            // XXX: handle narrower types in a special way?
            fmt++;
        }

        upper = *fmt == 'X' || *fmt == 'P';

        switch (*fmt) {
            case 'c': {
                i = va_arg(arg, int);
                FMT_PUT(buf, len, i);
                break;
            }

            case 'i':
            case 'd': {
                if (wide)
                    i = va_arg(arg, long int);
                else
                    i = va_arg(arg, int);

                char *c = num_fmt(num_buf, NUM_BUF_LEN, i, 10, padding, pad_with, 1, 0, -1, plus_char);
                while (*c) {
                    FMT_PUT(buf, len, *c);
                    c++;
                }
                break;
            }

            case 'u': {
                if (wide)
                    i = va_arg(arg, long int);
                else
                    i = va_arg(arg, int) & 0xFFFFFFFFul;

                char *c = num_fmt(num_buf, NUM_BUF_LEN, i, 10, padding, pad_with, 0, 0, -1, plus_char);
                while (*c) {
                    FMT_PUT(buf, len, *c);
                    c++;
                }
                break;
            }

            case 'o': {
                if (wide)
                    i = va_arg(arg, long int);
                else
                    i = va_arg(arg, int);

                char *c = num_fmt(num_buf, NUM_BUF_LEN, i, 8, padding, pad_with, 0, 0, -1, plus_char);

                if (alternative)
                    FMT_PUT(buf, len, '0');

                while (*c) {
                    FMT_PUT(buf, len, *c);
                    c++;
                }
                break;
            }

            case 'X':
            case 'x': {
                if (wide)
                    i = va_arg(arg, long int);
                else
                    i = va_arg(arg, int);

                char *c = num_fmt(num_buf, NUM_BUF_LEN, i, 16, padding, pad_with, 0, upper, wide ? 16 : 8, plus_char);

                if (alternative) {
                    FMT_PUT(buf, len, '0');
                    FMT_PUT(buf, len, upper ? 'X' : 'x');
                }

                while (*c) {
                    FMT_PUT(buf, len, *c);
                    c++;
                }
                break;
            }

            case 'P':
            case 'p': {
                i = (uintptr_t)(va_arg(arg, void *));

                char *c = num_fmt(num_buf, NUM_BUF_LEN, i, 16, padding, pad_with, 0, upper, sizeof(uintptr_t) / 4, plus_char);
                while (*c) {
                    FMT_PUT(buf, len, *c);
                    c++;
                }
                break;
            }

            case 's': {
                s = va_arg(arg, char *);
                while (*s && precision) {
                    FMT_PUT(buf, len, *s);
                    s++;
                    if (precision > 0)
                        precision--;
                }
                break;
            }

            case '%': {
                FMT_PUT(buf, len, '%');
                break;
            }
        }

        fmt++;
    }

end:
    if (len)
        *buf++ = '\0';

    return ret;
}

int vsnprintf(char *buf, size_t len, const char *fmt, va_list arg) {
    return internal_format_string(1, buf, len, fmt, arg);
}

int vsprintf(char *buf, const char *fmt, va_list arg) {
    return internal_format_string(0, buf, 0, fmt, arg);
}

int snprintf(char *buf, size_t len, const char *fmt, ...) {
    va_list va;

    va_start(va, fmt);
    int ret = vsnprintf(buf, len, fmt, va);
    va_end(va);

    return ret;
}

int sprintf(char *buf, const char *fmt, ...) {
    va_list va;

    va_start(va, fmt);
    int ret = vsprintf(buf, fmt, va);
    va_end(va);

    return ret;
}

// TODO: maybe figure out a better way than a stack buffer

#define TMP_BUFFER_SIZE 512

int vfprintf(FILE *stream, const char *fmt, va_list arg) {
    char buf[TMP_BUFFER_SIZE];
    int ret = vsnprintf(buf, TMP_BUFFER_SIZE, fmt, arg);
    fwrite(buf, 1, ret, stream);
    return ret;
}

int __vdprintf(int fd, const char *fmt, va_list arg) {
    char buf[TMP_BUFFER_SIZE];
    int ret = vsnprintf(buf, TMP_BUFFER_SIZE, fmt, arg);
    __sys_write(fd, buf, ret);
    return ret;
}

int fprintf(FILE *stream, const char *fmt, ...) {
    va_list va;

    va_start(va, fmt);
    int ret = vfprintf(stream, fmt, va);
    va_end(va);

    return ret;
}

int __dprintf(int fd, const char *fmt, ...) {
    va_list va;

    va_start(va, fmt);
    int ret = __vdprintf(fd, fmt, va);
    va_end(va);

    return ret;
}

int vprintf(const char *fmt, va_list arg) {
    return vfprintf(stdout, fmt, arg);
}

int printf(const char *fmt, ...) {
    va_list va;

    va_start(va, fmt);
    int ret = vprintf(fmt, va);
    va_end(va);

    return ret;
}

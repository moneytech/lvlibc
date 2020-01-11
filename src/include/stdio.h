#ifndef __STDIO_H__
#define __STDIO_H__

#include <stddef.h>
#include <stdarg.h>
#include <lvlibc/stdio-abi.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __FILE FILE;
extern FILE *stdin, *stdout, *stderr;

int fflush(FILE *stream);
FILE *fopen(const char *path, const char *mode);
int fclose(FILE *stream);
size_t fread(void *buf, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *buf, size_t size, size_t nmemb, FILE *stream);
int fseek(FILE *stream, long int offset, int whence);
long int ftell(FILE *stream);
void setbuf(FILE *stream, char *buffer);

int vsnprintf(char *buf, size_t len, const char *fmt, va_list arg);
int vsprintf(char *buf, const char *fmt, va_list arg);
int snprintf(char *buf, size_t len, const char *fmt, ...);
int sprintf(char *buf, const char *fmt, ...);

int vfprintf(FILE *stream, const char *fmt, va_list arg);
int fprintf(FILE *stream, const char *fmt, ...);
int vprintf(const char *fmt, va_list arg);
int printf(const char *fmt, ...);

int __vdprintf(int fd, const char *fmt, va_list arg);
int __dprintf(int fd, const char *fmt, ...);

#if _POSIX_C_SOURCE >= 200809 || defined(__GLIBC__)
#  define vdprintf __vdprintf
#  define dprintf __dprintf
#endif

#ifdef __cplusplus
}
#endif

#endif

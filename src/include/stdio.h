#ifndef __STDIO_H__
#define __STDIO_H__

#include <stddef.h>
#include <stdarg.h>
#include <lvlibc/stdio-abi.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __FILE FILE;
extern FILE *stdin, *stdout, *stderr;

int fflush(FILE *stream);
int fprintf(FILE *stream, const char *fmt, ...);
int vfprintf(FILE *stream, const char *fmt, va_list arg);
FILE *fopen(const char *path, const char *mode);
int fclose(FILE *stream);
size_t fread(void *buf, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *buf, size_t size, size_t nmemb, FILE *stream);
int fseek(FILE *stream, long int offset, int whence);
long int ftell(FILE *stream);
void setbuf(FILE *stream, char *buffer);

#ifdef __cplusplus
}
#endif

#endif

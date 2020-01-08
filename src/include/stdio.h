#ifndef __STDIO_H__
#define __STDIO_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __FILE FILE;
extern FILE *stdin, *stdout, *stderr;

int fflush(FILE *stream);
int fprintf(FILE *stream, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif

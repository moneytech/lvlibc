#include <stddef.h>

#include <string.h>

void* memchr(const void* str, int c, size_t n) {
    char* a = (char*)str;

    for (size_t i = 0; i < n; i++) {
        if (a[i] == c) {
            return a + i;
        }
    }

    return NULL;
}

int memcmp(const void* str1, const void* str2, size_t n) {
    const char* a = str1;
    const char* b = str2;

    for (size_t i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            return -1;
        } else if (a[i] > b[i]) {
            return 1;
        }
    }

    return 0;
}

void* memcpy(void* dest, const void* src, size_t n) {
    char*       a = dest;
    const char* b  = src;

    for (size_t i = 0; i < n; i++) {
        a[i] = b[i];
    }

    return dest;
}

void* memmove(void* dest, const void* src, size_t n) {
    char*       a = dest;
    const char* b  = src;

    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            a[i] = b[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            a[i - 1] = b[i - 1];
        }
    }

    return dest;
}

void* memset(void* str, int c, size_t n) {
    char* a = (char*)str;

    for (size_t i = 0; i < n; i++) {
        a[i] = c;
    }

    return str;
}

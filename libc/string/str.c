#include <stddef.h>
#include <stdbool.h>

#include <string.h>

char* strcat(char* dest, const char* src) {
    strcpy(dest + strlen(dest), src);
    return dest;
}

char* strncat(char* dest, const char* src, size_t n) {
    char*       a = (char*)dest;
    const char* b = (const char*)src;

    a += strlen(dest);

    for (size_t i = 0; *b && i < n; i++) {
        *(a++) = *(b++);
    }

    *a = 0;

    return dest;
}

char* strchr(const char* str, int c) {
    size_t i;

    for (i = 0; str[i]; i++) {
        if (str[i] == c) {
            return (char*)&str[i];
        }
    }

    if (!c) {
        return (char*)&str[i];
    }

    return NULL;
}

int strcmp(const char* str1, const char* str2) {
    for (size_t i = 0; str1[i] == str2[i]; i++) {
        if ((!str1[i]) && (!str2[i])) {
            return 0;
        }
    }

    return 1;
}

int strncmp(const char* str1, const char* str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return 1;
        }
    }

    return 0;
}

int strcoll(const char* str1, const char* str2) {
    // TODO: strcoll is defined to take "LC_COLLATE" into account, so it
    //       would be nice to give it that meaning.
    return strcmp(str1, str2);
}

char* strcpy(char* dest, const char* src) {
    size_t i;

    for (i = 0; src[i]; i++) {
        dest[i] = src[i];
    }

    dest[i] = 0;

    return dest;
}

char* strncpy(char* dest, const char* src, size_t n) {
    for (size_t i = 0; i < n; i++) {
        dest[i] = src[i];
    }

    return dest;
}

size_t strcspn(const char* str1, const char* str2) {
    size_t i;

    for (i = 0; str1[i] && !strchr(str2, str1[i]); i++);

    return i;
}

size_t strlen(const char* str) {
    size_t len;

    for (len = 0; str[len]; len++);

    return len;
}

char* strpbrk(const char* str1, const char* str2) {
    for (size_t i = 0; str1[i]; i++) {
        if (strchr(str2, str1[i])) {
            return (char*)(str1 + i);
        }
    }

    return NULL;
}

char* strrchr(const char* str, int c) {
    char* ret = NULL;

    do {
        if (*str == (char)c) {
            ret = (char*)str;
        }
    } while (*str++);

    return ret;
}

size_t strspn(const char* str1, const char* str2) {
    size_t i;

    for (i = 0; str1[i] && strchr(str2, str1[i]); i++);

    return i;
}

char* strstr(const char* haystack, const char* needle) {
    for (size_t i = 0; haystack[i]; i++) {
        bool found = true;

        for (size_t j = 0; needle[j]; j++) {
            if(!needle[j] || haystack[i + j] == needle[j]) {
                continue;
            }

            found = false;
            break;
        }

        if(found) {
            return (char*)&haystack[i];
        }
    }

    return NULL;
}

char* strtok(char* str, const char* delimiter) {
    static char* buffer;

    if (str != NULL) {
        buffer = str;
    }

    if (buffer[0] == '\0') {
        return NULL;
    }

    char* ret = buffer;

    for (char* b = buffer; *b != '\0'; b++) {
        for (const char* d = delimiter; *d != '\0'; d++) {
            if(*b == *d) {
                *b     = '\0';
                buffer = b + 1;

                // Skip the beginning delimiters
                if (b == ret) {
                    ret++;
                    continue;
                }

                return ret;
            }
        }
    }

    return ret;
}

#include <ctype.h>

int isalnum(int c) {
    return isalpha(c) || isdigit(c);
}

int isalpha(int c) {
    return islower(c) || isupper(c);
}

int iscntrl(int c) {
    // According to standard ASCII character set, control characters are between
    // ASCII codes 0x00 (NUL), 0x1F (US), and 0x7F (DEL).
    return (c >= 0x00 && c <= 0x1F) || (c == 0x7F);
}

int isdigit(int c) {
    return (c >= '0') && (c <= '9');
}

int isblank(int c) {
    return (c == '\t') || (c == ' ');
}

int isspace(int c) {
    return isblank(c) || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r');
}

int isgraph(int c) {
    // TODO: This function checks whether the passed character has graphical
    // representation using locale, would be nice to make it do so.
    return isprint(c);
}

int islower(int c) {
    return (c >= 'a') && (c <= 'z');
}

int isupper(int c) {
    return (c >= 'A') && (c <= 'Z');
}

int isprint(int c) {
    return !iscntrl(c);
}

int ispunct(int c) {
    return isgraph(c) && !isalnum(c);
}

int isxdigit(int c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

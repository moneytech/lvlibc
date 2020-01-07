#include <ctype.h>

int tolower(int c) {
    return isupper(c) ? c - ('A' - 'a') : c;
}

int toupper(int c) {
    return islower(c) ? c - ('a' - 'A') : c;
}

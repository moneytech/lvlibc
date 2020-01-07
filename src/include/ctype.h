#pragma once

// Case related functions (case.c).
int tolower(int c);
int toupper(int c);

// Character related functions (char.c).
int isalnum(int c);
int isalpha(int c);
int iscntrl(int c);
int isdigit(int c);
int isblank(int c);
int isspace(int c);
int isgraph(int c);
int islower(int c);
int isupper(int c);
int isprint(int c);
int ispunct(int c);
int isxdigit(int c);

// GLibc extensions (glibc.c).
int isascii(int c);

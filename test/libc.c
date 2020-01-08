#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

void testCType(void);
void testString(void);
void testPrintf(void);

int main(int argc, char** argv) {
    testCType();
    testString();
    testPrintf();
}

void testCType(void) {
    assert(isalnum('d'));
    assert(isalnum('Y'));
    assert(!isalnum('$'));
    assert(!isalnum('%'));

    assert(isalpha('R'));
    assert(!isalpha('4'));

    assert(iscntrl('\f'));
    assert(!iscntrl(' '));

    assert(isdigit('0'));
    assert(!isdigit('F'));

    assert(isblank('\t'));
    assert(!isblank('\n'));

    assert(isspace(' '));
    assert(isspace('\f'));
    assert(!isspace('e'));

    assert(isgraph('a'));
    assert(!isgraph('\r'));

    assert(islower('a'));
    assert(!islower('$'));

    assert(isupper('A'));
    assert(!isupper('&'));

    assert(isprint('&'));
    assert(!isprint('\r'));

    assert(ispunct('\\'));
    assert(!ispunct('a'));

    assert(isxdigit('F'));
    assert(!isxdigit('G'));

    assert(isascii('g'));
    assert(!isascii(1241215124));

    assert(tolower('D') == 'd');
    assert(tolower('$') == '$');
    assert(toupper('d') == 'D');
    assert(toupper('D') == 'D');
}

void testString(void) {
    const char str[] = "This is a cruel example of our modern's day society";
    const char ch    = 'f';

    assert(!strcmp(memchr(str, ch, strlen(str)), "f our modern's day society"));
}

void testPrintf(void) {
    char buf[64];

    snprintf(buf, 64, "%0*d", 3, 8);
    assert(!strcmp(buf, "008"));

    snprintf(buf, 64, "%+d", 8);
    assert(!strcmp(buf, "+8"));

    snprintf(buf, 64, "% d", 8);
    assert(!strcmp(buf, " 8"));

    snprintf(buf, 64, "%+d", -8);
    assert(!strcmp(buf, "-8"));

    snprintf(buf, 64, "% d", -8);
    assert(!strcmp(buf, "-8"));

    snprintf(buf, 64, "%.*s", 5, "hello world");
    assert(!strcmp(buf, "hello"));

    snprintf(buf, 64, "%.7s", "testing 123");
    assert(!strcmp(buf, "testing"));

    snprintf(buf, 64, "%#x", 0xdead);
    assert(!strcmp(buf, "0xdead"));

    snprintf(buf, 64, "%#X", 0xdead);
    assert(!strcmp(buf, "0XDEAD"));

    snprintf(buf, 64, "%#o", 0755);
    assert(!strcmp(buf, "0755"));

    snprintf(buf, 64, "%ld", 841522231760502511);
    assert(!strcmp(buf, "841522231760502511"));

    snprintf(buf, 64, "%u", 841522231760502511);
    assert(!strcmp(buf, "3735928559"));

    snprintf(buf, 64, "%hd", 74);
    assert(!strcmp(buf, "74"));

    sprintf(buf, "%d", 42920563);
    assert(!strcmp(buf, "42920563"));
}

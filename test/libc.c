#include <ctype.h>
#include <string.h>
#include <assert.h>

void testCType(void);
void testString(void);

int main(int argc, char** argv) {
    testCType();
    testString();
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

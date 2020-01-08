#include <stdlib.h>
#include <assert.h>

int main();

void _start(void) {
    // TODO: this is a stub.
    int ret = main();
    exit(ret);
}

void __stack_chk_fail(void) {
    assert(!"Stack overflow detected");
}

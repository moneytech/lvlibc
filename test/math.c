#include <math.h>
#include <assert.h>

int main(int argc, char** argv) {
    assert(isnan(0.1) == 0);
    assert(fmod(2, 2) == 0);

    assert(sin(M_PI / 6) - 0.5 <= 0.0001);
    assert(cos(-5 * M_PI / 4) - (-0.70710678119) <= 0.0001);
}

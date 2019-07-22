# LVLibc, the Lavender Libc

![forthebadge](https://forthebadge.com/images/badges/contains-cat-gifs.svg)

LVLibc is the C library of the Lavender OS project, even though its portable to
other systems.

The whole design has as main principles code correctness, and the extensive
use of static linking, instead of dynamic one, even though the latter can be
used tricking the build process quite easily

## Documentation

+ [Authors](AUTHORS.md)
+ [License of the libc](LICENSE.md)

## Building the source code

Make sure you have installed:

* `git` (only if you are using it to download the source)
* `make`
* `gcc`, `clang`, or another C compiler, the latest the better.

With all of that covered, just clone the [source] with `git` if you dont
have it already with:

```bash
git clone https://github.com/lavenderos/lvlibc.git
cd lvlibc
```

And next lets build and install the source with:

```bash
./configure     # Configure the prefix can be changed with --prefix=<prefix>
make            # Build and link into the final executables
make test       # Test against some examples
make install    # Install into prefix,
```

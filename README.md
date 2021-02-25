# `errnoname` - The `errno` Name Library

`errnoname` is a C library that lets us get the
symbolic name for each `errno` integer value.


# Usage

## API

The library has a single function:

```c
char const * errnoname(int)
```

Pass an `errno` value in, get back a pointer to
a null-terminated string containing the name.

If the `errno` value does not match a known name, a null pointer
is returned. (This intentionally includes `errno` value `0`.)

This function is always thread-safe and reentrant.

This function never sets `errno`.

## Example

Here is a "hello world" with error handling:

```c
#include <errno.h> /* errno */
#include <stdio.h> /* EOF, fflush, fprintf, fputs, stderr, stdout */
#include <stdlib.h> /* EXIT_FAILURE, EXIT_SUCCESS */

#include "errnoname.h" /* errnoname */

int main(int argc, char * * argv)
{
    char const * error_name;

    /* `fputs` and `fflush` return `EOF` for all errors: */
    if(fputs("Hello world\n", stdout) != EOF
    && fflush(stdout) != EOF)
    {
        return EXIT_SUCCESS;   
    }

    /* since `fputs` or `fflush` failed, `errno` should be */
    /* the error from the underlying `write` on most systems: */
    error_name = errnoname(errno);

    /* check if null, which means this `errno` value is unknown: */
    if(!error_name)
    {
        fprintf(stderr, "unknown error number: %d\n", errno);
    }
    else
    {
        fprintf(stderr, "error: %s\n", error_name);
    }
    return EXIT_FAILURE;
}
```

## C Name Collisions

The `errnoname.h` header will only ever define identifiers
whose first nine characters are `errnoname` or `ERRNONAME`.

So names like `errno_name`, `errnoName`, `ErrnoName`, or
`ERRNO_NAME` will always remain available for you to use.

## Building

Just compile and link `errnoname.c` as normal.

## Optimization

If `errnoname.c` is compiled with the `ERRNONAME_SAFE_TO_USE_ARRAY`
preprocessor macro defined, it will use a C array of `errno` names
indexed by `errno` values instead of a `switch` statement.

Note that modern compilers can already automatically convert
the switch to an array lookup when optimizations are turned
up high enough if it is safe and more efficient to do so.


# Contributing

The best way to help this library is making sure that
we have the best coverage of `errno` names possible:

* Check if the `for-maintainers/gather-errno-names.sh`
  script has the most complete and up-to-date sources
  of information for `errno` names - maybe you know a
  better way to get the latest ones for some system,
  and maybe we are missing a source we should include.

* Check if the `for-maintainers/errno-list.txt` file
  is missing any `errno` names that you know about.

* Check if the `for-maintainers/generate-c.sh` script
  file handles all `errno` names that alias the same
  errno value on any system.

You can also help by sharing your use-cases, what features
you want, and design suggestions - the `errnoname`
function is a good minimal foundation, but there might be
other features or performance optimizations worth doing.

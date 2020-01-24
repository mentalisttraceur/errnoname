# `errnoname` - The `errno` Name Library

Finally, a way to get the symbolic name of `errno`!

`errnoname` is

1. A C library that provides a way to get the symbolic
   name string for each `errno` integer value.

2. A list of `errno` names in use on many operating systems.

3. A handful of simple scripts for gathering that list of
   `errno` names and generating the library code from it.


# Usage

## API

The library has a single function:

```c
char const * errnoname(int)
```

Pass an `errno` value in, get back a pointer to
a null-terminated string containing the name.

If the `errno` value does not match a known name, a null pointer is
returned. (This includes `errno` value `0` on all modern systems.)

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

You can ignore all the other files in here -
they are not needed to use the library.

## Optimization

The *default* implementation in `errnoname.c` might not always produce
the most efficient code, because it is instead optimized to be:

1.  Simple - trivial for a human to mentally verify as robustly correct,
    with minimal room for edge cases to slip past human thinking.

2.  Portable - code as portable as possible, no unportable assumptions
    (except perhaps to guide optimizations without changing
    correctness or introducing pathological worst-case behavior).

3.  Optimizer-friendly - code optimized for optimization eventually
    performs as well or better than code optimized for performance.

4.  Safe - well-defined and well-bounded worst-case runspace and runtime
    even with pathological `errno` values (such as `-1` or `INT_MAX`).

However, if you need better execution speed or code size, and
you understand the downsides relative to the above four points,
`errnoname.c` provides an option you can enable at compile-time:

*   If `ERRNONAME_SAFE_TO_USE_ARRAY` is defined, `errnoname.c`
    will trust that it is safe to do the name lookups by using
    an array of `errno` names indexed by `errno` values.

    Note that modern compilers can already do this automatically
    in common cases when optimizations are turned up high enough.

# Contributing

The best way to help this library is making sure that
we have the best coverage of `errno` names possible:

* Check if the `gather-errno-names.sh` script has the
  most complete and up-to-date sources of information
  for `errno` names - maybe you know of a better way
  to get the latest ones for some system.

* Check if the errno list file is missing any of the
  `errno` names that exist on the systems you use.

* Check if all `errno` names that might be equivalent
  on some systems are handled in the generate script.

You can also help by sharing your use-cases, what features you want,
and design suggestions - the `errnoname` function is a good minimal
foundation, but there might be other features or performance
optimizations worth doing.

And finally, this can be more than a C library -
let's expand it to every language that needs it!

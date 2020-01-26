#!/bin/sh -
# Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

skip_1_if_same_as_2()
{
    # Given the arguments 'EWOULDBLOCK' and 'EAGAIN', turns lines like
    #     #ifdef EWOULDBLOCK
    # into lines like
    #     #if defined(EWOULDBLOCK) && (!defined(EAGAIN) || EWOULDBLOCK != EAGAIN)

    sed "s/ifdef $1/if defined($1) \&\& (!defined($2) || $1 != $2)/"
}

only_up_to()
{
    # Only print stdin up to the line that matches the first argument

    sed "/$1/,$ d"
}

only_after()
{
    # Only print stdin after the line that matches the first argument

    sed "1,/$1/ d"
}

format_as_array_entries()
{
    # Turns lines like
    #     EAGAIN
    # into lines like
    #     #ifdef EAGAIN
    #         [EAGAIN] = "EAGAIN",
    #     #endif

    sed 's/^.*$/    #ifdef &\n        [&] = "&",\n    #endif/'
}

format_as_switch_entries()
{
    # Turns lines like
    #     EAGAIN
    # into lines like
    #     #ifdef EAGAIN
    #         case EAGAIN: return "EAGAIN";
    #     #endif

    sed 's/^.*$/    #ifdef &\n        case &: return "&";\n    #endif/'
}

# errno list comes in on stdin, errnoname.c comes out on stdout

# spooling it all into memory is easiest way to use it twice
errno_list=`cat`

cat errnoname.c.template \
| only_up_to '{{ array_entries }}'

printf '%s\n' "$errno_list" \
| format_as_array_entries \
| skip_1_if_same_as_2 EWOULDBLOCK EAGAIN \
| skip_1_if_same_as_2 EOPNOTSUPP ENOTSUP \
| skip_1_if_same_as_2 EDEADLOCK EDEADLK \
| skip_1_if_same_as_2 ECANCELLED ECANCELED

cat errnoname.c.template \
| only_after '{{ array_entries }}' \
| only_up_to '{{ switch_entries }}'

printf '%s\n' "$errno_list" \
| format_as_switch_entries \
| skip_1_if_same_as_2 EWOULDBLOCK EAGAIN \
| skip_1_if_same_as_2 EOPNOTSUPP ENOTSUP \
| skip_1_if_same_as_2 EDEADLOCK EDEADLK \
| skip_1_if_same_as_2 ECANCELLED ECANCELED

cat errnoname.c.template \
| only_after '{{ switch_entries }}'

#!/bin/sh -
# Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com>
# Copyright 2021 Alejandro Colomar <alx.manpages@gmail.com>
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

wrap_in_ifdef_blocks()
{
    # Turns lines like
    #     EAGAIN
    # into lines like
    #         #ifdef EAGAIN
    #     EAGAIN
    #         #endif

    sed 's/^.*$/    #ifdef &\n&\n    #endif/'
}

skip_1_if_same_as_2()
{
    # Given the arguments "EWOULDBLOCK"
    # and "EAGAIN", turns lines like
    #     EWOULDBLOCK
    # into lines like
    #             #if !defined(EAGAIN) || EWOULDBLOCK != EAGAIN
    #     EWOULDBLOCK
    #             #endif

    sed "/#/! s/$1/        #if !defined($2) || $1 != $2\n$1\n        #endif/"
}

format_as_array_designated_initializers()
{
    # Turns lines like
    #     EAGAIN
    # into lines like
    #             [EAGAIN] = "EAGAIN",

    sed '/#/! s/^.*$/        [&] = "&",/'
}

format_as_switch_cases()
{
    # Turns lines like
    #     EAGAIN
    # into lines like
    #             case EAGAIN: return "EAGAIN";

    sed '/#/! s/^.*$/        case &: return "&";/'
}

# errno list comes in on stdin, errnoname_{array,switch}.c.inc come out
tmpfile=tmp;	#`mktemp -t errnoname.XXXXX`;

cat \
| wrap_in_ifdef_blocks \
| skip_1_if_same_as_2 EWOULDBLOCK EAGAIN \
| skip_1_if_same_as_2 EOPNOTSUPP ENOTSUP \
| skip_1_if_same_as_2 EDEADLOCK EDEADLK \
| skip_1_if_same_as_2 ECANCELLED ECANCELED \
> ${tmpfile};

< ${tmpfile} \
format_as_array_designated_initializers \
> errnoname_array.c.inc;

< ${tmpfile} \
format_as_switch_cases \
> errnoname_switch.c.inc;

rm ${tmpfile};

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
    sed "s/#   ifdef $1/#   if defined($1) \&\& (!defined($2) || $1 != $2)/"
}

# errno list comes in on stdin, errnoname.c comes out on stdout

# spooling it all into memory is easiest way to use it twice
errno_list=`cat`

sed '/{{ array_entries }}/,$ d' errnoname.c.template

printf '%s\n' "$errno_list" \
| sed 's/^.*$/#   ifdef &\n        [&] = "&",\n#   endif/' \
| skip_1_if_same_as_2 EWOULDBLOCK EAGAIN \
| skip_1_if_same_as_2 EOPNOTSUPP ENOTSUP \
| skip_1_if_same_as_2 EDEADLOCK EDEADLK \
| skip_1_if_same_as_2 ECANCELLED ECANCELED

sed '1,/{{ array_entries }}/ d; /{{ switch_entries }}/,$ d' \
    errnoname.c.template

printf '%s\n' "$errno_list" \
| sed 's/^.*$/#   ifdef &\n        case &: return "&";\n#   endif/' \
| skip_1_if_same_as_2 EWOULDBLOCK EAGAIN \
| skip_1_if_same_as_2 EOPNOTSUPP ENOTSUP \
| skip_1_if_same_as_2 EDEADLOCK EDEADLK \
| skip_1_if_same_as_2 ECANCELLED ECANCELED

sed '1,/{{ switch_entries }}/ d' errnoname.c.template

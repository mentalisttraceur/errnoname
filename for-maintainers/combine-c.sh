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

main()
{
    directory=${1?'first argument must be a folder containing the .c parts'}
    template=$directory/errnoname.c

    # The combined errnoname.c is printed on stdout:

    cat "$template" \
    | only_lines_before '#include "errnoname-array-elements.c.inc"'

    cat "${directory}"/errnoname-array-elements.c.inc

    cat "$template" \
    | only_lines_after '#include "errnoname-array-elements.c.inc"' \
    | only_lines_before '#include "errnoname-switch-cases.c.inc"'

    cat "${directory}"/errnoname-switch-cases.c.inc

    cat "$template" \
    | only_lines_after '#include "errnoname-switch-cases.c.inc"'
}

only_lines_before()
{
    # Only prints the lines before the line
    # that matches the first argument.

    sed "/$1/,$ d"
}

only_lines_after()
{
    # Only prints the lines after the line
    # that matches the first argument.

    sed "1,/$1/ d"
}

main "$@"

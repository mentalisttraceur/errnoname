#!/bin/sh -
# SPDX-License-Identifier: 0BSD
# Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com>

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

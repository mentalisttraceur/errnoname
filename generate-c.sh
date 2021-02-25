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
    list=${1?'first argument must be the errno-list.txt file'}
    template=${2?'second argument must be the errnoname.c.template file'}

    cat "$template" \
    | only_lines_before '{{ array_entries }}'

    cat "$list" \
    | wrap_in_preprocessor_checks \
    | format_as_array_designated_initializers

    cat "$template" \
    | only_lines_after '{{ array_entries }}' \
    | only_lines_before '{{ switch_entries }}'

    cat "$list" \
    | wrap_in_preprocessor_checks \
    | format_as_switch_cases

    cat "$template" \
    | only_lines_after '{{ switch_entries }}'
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

wrap_in_preprocessor_checks()
{
    wrap_in_ifdef_blocks \
    | handle_possible_alias EAGAIN EWOULDBLOCK \
    | handle_possible_alias ENOTSUP EOPNOTSUPP \
    | handle_possible_alias EDEADLK EDEADLOCK \
    | handle_possible_alias ECANCELED ECANCELLED \
    | handle_possible_alias ECONNREFUSED EREFUSED \
    | handle_possible_alias EDESTADDRREQ EDESTADDREQ \
    | handle_possible_alias EINPROGRESS EINPROG
}

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

handle_possible_alias()
{
    # Given the arguments "EAGAIN" and "EWOULDBLOCK", turns lines like
    #     EWOULDBLOCK
    # into lines like
    #             #if !defined(EAGAIN) || EWOULDBLOCK != EAGAIN
    #     EWOULDBLOCK
    #             #endif

    sed "/#/! s/^$2$/        #if !defined($1) || $2 != $1\n$2\n        #endif/"
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

main "$@"

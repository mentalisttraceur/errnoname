#!/bin/sh -
# SPDX-License-Identifier: 0BSD
# Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com>

main()
{
    directory=${1?'first argument must be the output directory'}

    # Read the errno list from stdin:
    list=`cat`

    printf '%s\n' "$list" \
    | wrap_in_preprocessor_checks \
    | format_as_array_designated_initializers \
    > "${directory}"/errnoname-array-elements.c.inc

    printf '%s\n' "$list" \
    | wrap_in_preprocessor_checks \
    | format_as_switch_cases \
    > "${directory}"/errnoname-switch-cases.c.inc
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

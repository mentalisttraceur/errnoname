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

get()
{
    curl --silent --show-error -- "$@"
    # Alternative for users who don't have curl:
    #wget --quiet --output-document - -- "$@"
}

github()
{
    get https://raw.githubusercontent.com/"$1"
}

extract_c()
{
    sed 's/\t/ /g' | grep '#define E' | cut -d' ' -f2
}

linux()
{
    github torvalds/linux/master/include/uapi/asm-generic/errno-base.h \
    | extract_c &
    github torvalds/linux/master/include/uapi/asm-generic/errno.h \
    | extract_c
}

darwin()  # MacOS, iOS, etc.
{
    github apple/darwin-xnu/master/bsd/sys/errno.h | extract_c | grep -v ELAST
}

freebsd()
{
    github freebsd/freebsd/master/sys/sys/errno.h | extract_c | grep -v ELAST
}

netbsd()
{
    github NetBSD/src/trunk/sys/sys/errno.h | extract_c | grep -v ELAST
}

openbsd()
{
    github openbsd/src/master/sys/sys/errno.h | extract_c | grep -v ELAST
}

dragonflybsd()
{
    github DragonFlyBSD/DragonFlyBSD/master/sys/sys/errno.h \
    | extract_c | grep -v ELAST
}

illumos()
{
    github illumos/illumos-gate/master/usr/src/boot/sys/sys/errno.h \
    | extract_c | grep -v ELAST
}

opensolaris()
{
    github nxmirrors/onnv/master/usr/src/uts/common/sys/errno.h | extract_c
}

cygwin()
{
    github cygwin/cygwin/master/newlib/libc/include/sys/errno.h | extract_c
}

aix()
{
    # IBM does not seem to provide any URL to any AIX errno
    # list, but Go will probably stay up to date with it:

    github golang/go/master/src/syscall/zerrors_aix_ppc64.go \
    | grep 'Errno' | awk '{ print $1 }'
}

zos()
{
    # IBM does not seem to provide a stable URL to the latest
    # z/OS errno list, so we have to find and extract it:

    errno_documentation=`
        get https://www.ibm.com/it-infrastructure/z/zos \
        | grep 'Find z/OS documentation' | cut -d\" -f6 \
        | sed 's|/en/homepage.html$|.bpxbd00/errnoh.htm?view=embed|'
    ` &&
    get "$errno_documentation" \
    | grep '<td class="nrule">E[^ ]*<' | cut -d\> -f2 | cut -d\< -f1
}

solaris()
{
    # Oracle does not seem to provide a stable URL to the latest
    # Solaris errno list, so we have to find and extract it:

    latest_solaris_documentation=`
        get https://docs.oracle.com/en/operating-systems/solaris.html \
        | grep 'Information Library' | head -n1 | cut -d\" -f2
    ` &&
    errno_documentation=`
        get https://docs.oracle.com/"$latest_solaris_documentation" \
        | grep 'System Calls' | cut -d\" -f4 \
        | sed 's/^http:/https:/; s|/index.html$|/intro-2.html|'
    ` &&
    get "$errno_documentation" \
    | grep '<dt>[0-9]* E' | cut -d\> -f2 | cut -d\< -f1 | cut -d' ' -f2 \
    | sed 's/EMGSIZE/EMSGSIZE/'  # fix documentation typo
}

hpux()
{
    # HP does not seem to provide any URL to any HP-UX
    # errno list, so we resort to a public manpage mirror:

    get https://nixdoc.net/man-pages/HP-UX/man2/errno.2.html \
    | grep '\[E.*\]' | cut -d\] -f1 | cut -d\[ -f2
}

_historical()
{
    # `errno` names should be manually added here if:
    #
    # 1. they do not show up in any downloaded current `errno` lists,
    #    **and**
    # 2. they come from old systems that no longer get new releases.
    #
    # this seems like the cleanest way to support old systems.

    printf '%s\n' \
        EAIO \
        EALIGN \
        EBADVER \
        ECANCELLED \
        ECKPT \
        ECONFIG \
        EDIRTY \
        EDUPPKG \
        EFAIL \
        EFSCORRUPTED \
        EINIT \
        EINPROG \
        EMTIMERS \
        ENFSREMOTE \
        ENOLOAD \
        ENOMATCH \
        ENOREG \
        ENOUNLD \
        ENOUNREG \
        EOPCOMPLETE \
        EPATHREMOTE \
        EPOWERF \
        ERELOC \
        ERELOCATED \
        EREMDEV \
        EREMOTERELEASE \
        EVERSION \
        EWRONGFS
}

{
    aix &
    cygwin &
    darwin &
    dragonflybsd &
    freebsd &
    hpux &
    illumos &
    linux &
    netbsd &
    openbsd &
    opensolaris &
    solaris &
    zos &
    _historical &
} | sort -u

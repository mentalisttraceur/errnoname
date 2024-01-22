#!/bin/sh -
# SPDX-License-Identifier: 0BSD
# Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com>

get()
{
    curl --location --silent --show-error -- "$@"
    # Alternative for users who don't have curl:
    #wget --quiet --output-document - -- "$@"
}

github()
{
    get https://raw.githubusercontent.com/"$1"
}

extract_c()
{
    sed 's/\t/ /g; s/  */ /g; s/^ //; s/# define/#define/' \
    | grep '#define E' | cut -d' ' -f2
}

linux()
{
    github torvalds/linux/master/arch/alpha/include/uapi/asm/errno.h \
    | extract_c &
    github torvalds/linux/master/arch/mips/include/uapi/asm/errno.h \
    | extract_c &
    github torvalds/linux/master/arch/parisc/include/uapi/asm/errno.h \
    | extract_c &
    github torvalds/linux/master/arch/powerpc/include/uapi/asm/errno.h \
    | extract_c &
    github torvalds/linux/master/arch/sparc/include/uapi/asm/errno.h \
    | extract_c &
    github torvalds/linux/master/include/linux/errno.h | extract_c &
    github torvalds/linux/master/include/uapi/asm-generic/errno-base.h \
    | extract_c &
    github torvalds/linux/master/include/uapi/asm-generic/errno.h \
    | extract_c

    # Retry-based AIO was removed on 2013-05-08 in
    # commit 41003a7bcfed1255032e1e7c7b487e505b22e298:
    printf '%s\n' EIOCBRETRY
}

darwin()  # MacOS, iOS, etc.
{
    github apple/darwin-xnu/main/bsd/sys/errno.h | extract_c | grep -v ELAST
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
    github kofemann/opensolaris/master/usr/src/uts/common/sys/errno.h | extract_c
}

cygwin()
{
    github cygwin/cygwin/master/newlib/libc/include/sys/errno.h | extract_c
}

minix()
{
    github Stichting-MINIX-Research-Foundation/minix/master/sys/sys/errno.h \
    | extract_c | grep -v ELAST

    # Alleged in https://www.mail-archive.com/bug-gnulib@gnu.org/msg39118.html
    printf '%s\n' EBADIOCTL
}

haiku()
{
    github haiku/haiku/master/headers/os/support/Errors.h | extract_c &
    github haiku/haiku/master/headers/build/os/support/Errors.h | extract_c
}

hurd()
{
    # GNU's glibc seems like the most canonical source on how
    # the error codes in GNU's Hurd translate to errno names:

    get 'https://sourceware.org/git/?p=glibc.git;a=blob_plain;f=sysdeps/mach/hurd/bits/errno.h;hb=HEAD' \
    | extract_c
}

redox()
{
    get 'https://gitlab.redox-os.org/redox-os/relibc/-/raw/master/src/header/errno/mod.rs' \
    | grep 'pub const E' | cut -d' ' -f3 | cut -d: -f1
}

zos()
{
    latest_zos_documentation='https://www.ibm.com/docs/en/zos/latest?topic='
    get "$latest_zos_documentation"'codes-return-errnos' \
    | grep 'nrule.*>E[^ ]*<' | cut -d\> -f2 | cut -d\< -f1 &
    get "$latest_zos_documentation"'calls-sockets-return-codes-errnos' \
    | grep 'ncol.*>E[^ ]*<' | cut -d\> -f2 | cut -d\< -f1
}

aix()
{
    # IBM does not seem to provide any URL to any AIX errno
    # list, but Go will probably stay up to date with it:

    github golang/go/master/src/syscall/zerrors_aix_ppc64.go \
    | grep 'Errno' | awk '{ print $1 }'
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
        | grep 'System Calls' | cut -d\" -f2 \
        | sed 's/^http:/https:/; s|/index.html$|/intro-2.html|'
    ` &&
    get "$errno_documentation" \
    | grep '<dt>[1-9][0-9]* E' | cut -d\> -f2 | cut -d\< -f1 | cut -d' ' -f2
}

qnx()
{
    # BlackBerry does not seem to provide a stable URL to the latest
    # QNX errno list, so we have to find and extract it:

    qnx_documentation='https://www.qnx.com/developers/docs'
    errno_documentation=`
        get "$qnx_documentation/" \
        | grep "$qnx_documentation/[1-9][0-9]*\.[0-9][0-9]*/#" \
        | head -n1 \
        | sed 's/.*href="//; s/".*//' \
        | sed 's|#.*|com.qnx.doc.neutrino.lib_ref/topic/e/errno.html|'
    ` &&
    get "$errno_documentation" \
    | grep 'keyword const">E' | sed 's/.*>E/E/; s/<.*//' \
    | grep -v EOK

    # Removed from the documentation as of QNX 8.0,
    # but present in 7.1 and maybe earlier:
    printf '%s\n' ENOREMOTE
}

tru64()
{
    # HP does not seem to provide any URL to any Tru64 UNIX
    # errno list, so we use a mirror of OSF/1 v1.0 source:

    github calmsacibis995/osf1-10-src/master/usr/opt/OSC200/src/kernel/sys/errno.h \
    | extract_c | grep -v ESUCCESS
}

unixware()
{
    # Xinuos does not seem to provide a stable URL to the latest
    # UnixWare errno list, but newer releases seem unlikely:

    get 'https://uw714doc.xinuos.com/en/man/html.2/Intro.2.html' \
    | grep '<BR>[1-9][0-9]* *<B>E' | cut -d\> -f4 | cut -d\< -f1
}

openserver()
{
    # OpenServer 5 was the last unique release (6 is
    # based on UnixWare and 10 is based on FreeBSD):

    get 'https://osr507doc.xinuos.com/en/man/html.S/Intro.S.html' \
    | grep -A1 '</TD><TD>' | grep '^E[^ ]*$'
}

hpux()
{
    # HP does not seem to provide any URL to any HP-UX errno list, so we
    # try to make the most complete combination of dumps found online:

    get 'https://m.cafe.daum.net/realhpux/4qAH/13?svc=cafeapi' \
    | sed 's/<BR>/\n/g; s/&nbsp;/ /g' \
    | grep '#define E' | sed 's/.*#define E/E/' | cut -d' ' -f1

    github calmsacibis995/hpux-910-src/master/source_product/9.10/sys.A.B9.10/h/_errno.h \
    | extract_c | grep -v ESUCCESS
    github calmsacibis995/hpux-910-src/master/source_product/9.10/sys.A.B9.10/h/errno.h \
    | extract_c

    # EPOWERF shows up on https://www.ioplex.com/~miallen/errcmp.html
    # and a couple HP community support discussion threads:
    printf '%s\n' EPOWERF
}

irix()
{
    # SGI no longer exists and IRIX is discontinued so we
    # use a GitHub mirror of the source (newest I found):
    github JohnDTX/irix-3.x-src/main/sys/h/errno.h | extract_c &

    # These four errno show up on the public manpage mirror
    # https://nixdoc.net/man-pages/IRIX/man2/intro.2.html
    printf '%s\n' ECKPT
    printf '%s\n' EFSCORRUPTED
    printf '%s\n' ENFSREMOTE
    printf '%s\n' EWRONGFS

    # Alleged in https://www.mail-archive.com/bug-gnulib@gnu.org/msg39118.html
    printf '%s\n' EBADFILT
    printf '%s\n' EBADRSPEC
    printf '%s\n' EBADTSPEC
    printf '%s\n' EBDHDL
    printf '%s\n' EBUFSIZE
}

ultrix()
{
    # DEC no longer exists and ULTRIX is discontinued so we
    # use a GitHub mirror of the source:

    github calmsacibis995/ultrix42-src/master/sys/h/errno.h | extract_c
}

execute_with_prefixed_errors()
{
    command=$1
    case $command in [!a-zA-Z_]* | ?*[!a-zA-Z0-9]*)
        printf '%s\n' "bad subcommand: $command" 1>&2
        return 1
    esac
    { "$command" 2>&1 1>&3 | sed "s/^/$command: /" 1>&2; } 3>&1
}

all()
{
    for source in \
        aix \
        cygwin \
        darwin \
        dragonflybsd \
        freebsd \
        haiku \
        hurd \
        hpux \
        illumos \
        irix \
        linux \
        minix \
        netbsd \
        openbsd \
        openserver \
        opensolaris \
        qnx \
        redox \
        solaris \
        tru64 \
        ultrix \
        unixware \
        zos
    do
        execute_with_prefixed_errors "$source" &
    done
}

for argument
do execute_with_prefixed_errors "$argument" &
done | LC_ALL=C sort -u

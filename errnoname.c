/*****************************************************************************\
 * Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
\*****************************************************************************/

#ifndef ERRNONAME_C
#define ERRNONAME_C

#include <errno.h>

char const * errnoname(int errno_)
{
#ifdef ERRNONAME_SAFE_TO_USE_ARRAY
    static char const * const names[] =
    {
        [0] = 0,
    #ifdef E2BIG
        [E2BIG] = "E2BIG",
    #endif
    #ifdef EACCES
        [EACCES] = "EACCES",
    #endif
    #ifdef EADDRINUSE
        [EADDRINUSE] = "EADDRINUSE",
    #endif
    #ifdef EADDRNOTAVAIL
        [EADDRNOTAVAIL] = "EADDRNOTAVAIL",
    #endif
    #ifdef EADI
        [EADI] = "EADI",
    #endif
    #ifdef EADV
        [EADV] = "EADV",
    #endif
    #ifdef EAFNOSUPPORT
        [EAFNOSUPPORT] = "EAFNOSUPPORT",
    #endif
    #ifdef EAGAIN
        [EAGAIN] = "EAGAIN",
    #endif
    #ifdef EAIO
        [EAIO] = "EAIO",
    #endif
    #ifdef EALIGN
        [EALIGN] = "EALIGN",
    #endif
    #ifdef EALREADY
        [EALREADY] = "EALREADY",
    #endif
    #ifdef EASYNC
        [EASYNC] = "EASYNC",
    #endif
    #ifdef EAUTH
        [EAUTH] = "EAUTH",
    #endif
    #ifdef EBADARCH
        [EBADARCH] = "EBADARCH",
    #endif
    #ifdef EBADCOOKIE
        [EBADCOOKIE] = "EBADCOOKIE",
    #endif
    #ifdef EBADE
        [EBADE] = "EBADE",
    #endif
    #ifdef EBADEXEC
        [EBADEXEC] = "EBADEXEC",
    #endif
    #ifdef EBADF
        [EBADF] = "EBADF",
    #endif
    #ifdef EBADFD
        [EBADFD] = "EBADFD",
    #endif
    #ifdef EBADHANDLE
        [EBADHANDLE] = "EBADHANDLE",
    #endif
    #ifdef EBADMACHO
        [EBADMACHO] = "EBADMACHO",
    #endif
    #ifdef EBADMSG
        [EBADMSG] = "EBADMSG",
    #endif
    #ifdef EBADR
        [EBADR] = "EBADR",
    #endif
    #ifdef EBADRPC
        [EBADRPC] = "EBADRPC",
    #endif
    #ifdef EBADRQC
        [EBADRQC] = "EBADRQC",
    #endif
    #ifdef EBADSLT
        [EBADSLT] = "EBADSLT",
    #endif
    #ifdef EBADTYPE
        [EBADTYPE] = "EBADTYPE",
    #endif
    #ifdef EBADVER
        [EBADVER] = "EBADVER",
    #endif
    #ifdef EBFONT
        [EBFONT] = "EBFONT",
    #endif
    #ifdef EBUSY
        [EBUSY] = "EBUSY",
    #endif
    #ifdef ECANCELED
        [ECANCELED] = "ECANCELED",
    #endif
    #ifdef ECANCELLED
        #if !defined(ECANCELED) || ECANCELLED != ECANCELED
        [ECANCELLED] = "ECANCELLED",
        #endif
    #endif
    #ifdef ECAPMODE
        [ECAPMODE] = "ECAPMODE",
    #endif
    #ifdef ECASECLASH
        [ECASECLASH] = "ECASECLASH",
    #endif
    #ifdef ECHILD
        [ECHILD] = "ECHILD",
    #endif
    #ifdef ECHRNG
        [ECHRNG] = "ECHRNG",
    #endif
    #ifdef ECICS
        [ECICS] = "ECICS",
    #endif
    #ifdef ECKPT
        [ECKPT] = "ECKPT",
    #endif
    #ifdef ECKSUM
        [ECKSUM] = "ECKSUM",
    #endif
    #ifdef ECLONEME
        [ECLONEME] = "ECLONEME",
    #endif
    #ifdef ECOMM
        [ECOMM] = "ECOMM",
    #endif
    #ifdef ECONFIG
        [ECONFIG] = "ECONFIG",
    #endif
    #ifdef ECONNABORTED
        [ECONNABORTED] = "ECONNABORTED",
    #endif
    #ifdef ECONNREFUSED
        [ECONNREFUSED] = "ECONNREFUSED",
    #endif
    #ifdef ECONNRESET
        [ECONNRESET] = "ECONNRESET",
    #endif
    #ifdef ECORRUPT
        [ECORRUPT] = "ECORRUPT",
    #endif
    #ifdef ECVCERORR
        [ECVCERORR] = "ECVCERORR",
    #endif
    #ifdef ECVPERORR
        [ECVPERORR] = "ECVPERORR",
    #endif
    #ifdef EDATALESS
        [EDATALESS] = "EDATALESS",
    #endif
    #ifdef EDEADLK
        [EDEADLK] = "EDEADLK",
    #endif
    #ifdef EDEADLOCK
        #if !defined(EDEADLK) || EDEADLOCK != EDEADLK
        [EDEADLOCK] = "EDEADLOCK",
        #endif
    #endif
    #ifdef EDESTADDREQ
        #if !defined(EDESTADDRREQ) || EDESTADDREQ != EDESTADDRREQ
        [EDESTADDREQ] = "EDESTADDREQ",
        #endif
    #endif
    #ifdef EDESTADDRREQ
        [EDESTADDRREQ] = "EDESTADDRREQ",
    #endif
    #ifdef EDEVERR
        [EDEVERR] = "EDEVERR",
    #endif
    #ifdef EDIRIOCTL
        [EDIRIOCTL] = "EDIRIOCTL",
    #endif
    #ifdef EDIRTY
        [EDIRTY] = "EDIRTY",
    #endif
    #ifdef EDIST
        [EDIST] = "EDIST",
    #endif
    #ifdef EDOM
        [EDOM] = "EDOM",
    #endif
    #ifdef EDOOFUS
        [EDOOFUS] = "EDOOFUS",
    #endif
    #ifdef EDOTDOT
        [EDOTDOT] = "EDOTDOT",
    #endif
    #ifdef EDQUOT
        [EDQUOT] = "EDQUOT",
    #endif
    #ifdef EDUPFD
        [EDUPFD] = "EDUPFD",
    #endif
    #ifdef EDUPPKG
        [EDUPPKG] = "EDUPPKG",
    #endif
    #ifdef EEXIST
        [EEXIST] = "EEXIST",
    #endif
    #ifdef EFAIL
        [EFAIL] = "EFAIL",
    #endif
    #ifdef EFAULT
        [EFAULT] = "EFAULT",
    #endif
    #ifdef EFBIG
        [EFBIG] = "EFBIG",
    #endif
    #ifdef EFORMAT
        [EFORMAT] = "EFORMAT",
    #endif
    #ifdef EFPOS
        [EFPOS] = "EFPOS",
    #endif
    #ifdef EFRAGS
        [EFRAGS] = "EFRAGS",
    #endif
    #ifdef EFSCORRUPTED
        [EFSCORRUPTED] = "EFSCORRUPTED",
    #endif
    #ifdef EFTYPE
        [EFTYPE] = "EFTYPE",
    #endif
    #ifdef EHOSTDOWN
        [EHOSTDOWN] = "EHOSTDOWN",
    #endif
    #ifdef EHOSTUNREACH
        [EHOSTUNREACH] = "EHOSTUNREACH",
    #endif
    #ifdef EHWPOISON
        [EHWPOISON] = "EHWPOISON",
    #endif
    #ifdef EIBMBADCALL
        [EIBMBADCALL] = "EIBMBADCALL",
    #endif
    #ifdef EIBMBADPARM
        [EIBMBADPARM] = "EIBMBADPARM",
    #endif
    #ifdef EIBMCANCELLED
        [EIBMCANCELLED] = "EIBMCANCELLED",
    #endif
    #ifdef EIBMCONFLICT
        [EIBMCONFLICT] = "EIBMCONFLICT",
    #endif
    #ifdef EIBMIUCVERR
        [EIBMIUCVERR] = "EIBMIUCVERR",
    #endif
    #ifdef EIBMSOCKINUSE
        [EIBMSOCKINUSE] = "EIBMSOCKINUSE",
    #endif
    #ifdef EIBMSOCKOUTOFRANGE
        [EIBMSOCKOUTOFRANGE] = "EIBMSOCKOUTOFRANGE",
    #endif
    #ifdef EIDRM
        [EIDRM] = "EIDRM",
    #endif
    #ifdef EILSEQ
        [EILSEQ] = "EILSEQ",
    #endif
    #ifdef EINIT
        [EINIT] = "EINIT",
    #endif
    #ifdef EINPROG
        #if !defined(EINPROGRESS) || EINPROG != EINPROGRESS
        [EINPROG] = "EINPROG",
        #endif
    #endif
    #ifdef EINPROGRESS
        [EINPROGRESS] = "EINPROGRESS",
    #endif
    #ifdef EINTEGRITY
        [EINTEGRITY] = "EINTEGRITY",
    #endif
    #ifdef EINTR
        [EINTR] = "EINTR",
    #endif
    #ifdef EINTRNODATA
        [EINTRNODATA] = "EINTRNODATA",
    #endif
    #ifdef EINVAL
        [EINVAL] = "EINVAL",
    #endif
    #ifdef EIO
        [EIO] = "EIO",
    #endif
    #ifdef EIOCBQUEUED
        [EIOCBQUEUED] = "EIOCBQUEUED",
    #endif
    #ifdef EIPSEC
        [EIPSEC] = "EIPSEC",
    #endif
    #ifdef EISCONN
        [EISCONN] = "EISCONN",
    #endif
    #ifdef EISDIR
        [EISDIR] = "EISDIR",
    #endif
    #ifdef EISNAM
        [EISNAM] = "EISNAM",
    #endif
    #ifdef EJUKEBOX
        [EJUKEBOX] = "EJUKEBOX",
    #endif
    #ifdef EJUSTRETURN
        [EJUSTRETURN] = "EJUSTRETURN",
    #endif
    #ifdef EKEEPLOOKING
        [EKEEPLOOKING] = "EKEEPLOOKING",
    #endif
    #ifdef EKEYEXPIRED
        [EKEYEXPIRED] = "EKEYEXPIRED",
    #endif
    #ifdef EKEYREJECTED
        [EKEYREJECTED] = "EKEYREJECTED",
    #endif
    #ifdef EKEYREVOKED
        [EKEYREVOKED] = "EKEYREVOKED",
    #endif
    #ifdef EL2HLT
        [EL2HLT] = "EL2HLT",
    #endif
    #ifdef EL2NSYNC
        [EL2NSYNC] = "EL2NSYNC",
    #endif
    #ifdef EL3HLT
        [EL3HLT] = "EL3HLT",
    #endif
    #ifdef EL3RST
        [EL3RST] = "EL3RST",
    #endif
    #ifdef ELBIN
        [ELBIN] = "ELBIN",
    #endif
    #ifdef ELEMSGERR
        [ELEMSGERR] = "ELEMSGERR",
    #endif
    #ifdef ELEMULTITHREAD
        [ELEMULTITHREAD] = "ELEMULTITHREAD",
    #endif
    #ifdef ELEMULTITHREADFORK
        [ELEMULTITHREADFORK] = "ELEMULTITHREADFORK",
    #endif
    #ifdef ELENOFORK
        [ELENOFORK] = "ELENOFORK",
    #endif
    #ifdef ELIBACC
        [ELIBACC] = "ELIBACC",
    #endif
    #ifdef ELIBBAD
        [ELIBBAD] = "ELIBBAD",
    #endif
    #ifdef ELIBEXEC
        [ELIBEXEC] = "ELIBEXEC",
    #endif
    #ifdef ELIBMAX
        [ELIBMAX] = "ELIBMAX",
    #endif
    #ifdef ELIBSCN
        [ELIBSCN] = "ELIBSCN",
    #endif
    #ifdef ELNRNG
        [ELNRNG] = "ELNRNG",
    #endif
    #ifdef ELOCKUNMAPPED
        [ELOCKUNMAPPED] = "ELOCKUNMAPPED",
    #endif
    #ifdef ELOOP
        [ELOOP] = "ELOOP",
    #endif
    #ifdef EMEDIA
        [EMEDIA] = "EMEDIA",
    #endif
    #ifdef EMEDIUMTYPE
        [EMEDIUMTYPE] = "EMEDIUMTYPE",
    #endif
    #ifdef EMFILE
        [EMFILE] = "EMFILE",
    #endif
    #ifdef EMLINK
        [EMLINK] = "EMLINK",
    #endif
    #ifdef EMOUNTEXIT
        [EMOUNTEXIT] = "EMOUNTEXIT",
    #endif
    #ifdef EMOVEFD
        [EMOVEFD] = "EMOVEFD",
    #endif
    #ifdef EMSGSIZE
        [EMSGSIZE] = "EMSGSIZE",
    #endif
    #ifdef EMTIMERS
        [EMTIMERS] = "EMTIMERS",
    #endif
    #ifdef EMULTIHOP
        [EMULTIHOP] = "EMULTIHOP",
    #endif
    #ifdef EMVSBADCHAR
        [EMVSBADCHAR] = "EMVSBADCHAR",
    #endif
    #ifdef EMVSCATLG
        [EMVSCATLG] = "EMVSCATLG",
    #endif
    #ifdef EMVSCPLERROR
        [EMVSCPLERROR] = "EMVSCPLERROR",
    #endif
    #ifdef EMVSCVAF
        [EMVSCVAF] = "EMVSCVAF",
    #endif
    #ifdef EMVSDYNALC
        [EMVSDYNALC] = "EMVSDYNALC",
    #endif
    #ifdef EMVSERR
        [EMVSERR] = "EMVSERR",
    #endif
    #ifdef EMVSEXPIRE
        [EMVSEXPIRE] = "EMVSEXPIRE",
    #endif
    #ifdef EMVSINITIAL
        [EMVSINITIAL] = "EMVSINITIAL",
    #endif
    #ifdef EMVSNORTL
        [EMVSNORTL] = "EMVSNORTL",
    #endif
    #ifdef EMVSNOTXP
        [EMVSNOTXP] = "EMVSNOTXP",
    #endif
    #ifdef EMVSPARM
        [EMVSPARM] = "EMVSPARM",
    #endif
    #ifdef EMVSPASSWORD
        [EMVSPASSWORD] = "EMVSPASSWORD",
    #endif
    #ifdef EMVSPATHOPTS
        [EMVSPATHOPTS] = "EMVSPATHOPTS",
    #endif
    #ifdef EMVSPFSFILE
        [EMVSPFSFILE] = "EMVSPFSFILE",
    #endif
    #ifdef EMVSPFSPERM
        [EMVSPFSPERM] = "EMVSPFSPERM",
    #endif
    #ifdef EMVSSAF2ERR
        [EMVSSAF2ERR] = "EMVSSAF2ERR",
    #endif
    #ifdef EMVSSAFEXTRERR
        [EMVSSAFEXTRERR] = "EMVSSAFEXTRERR",
    #endif
    #ifdef EMVSTODNOTSET
        [EMVSTODNOTSET] = "EMVSTODNOTSET",
    #endif
    #ifdef ENAMETOOLONG
        [ENAMETOOLONG] = "ENAMETOOLONG",
    #endif
    #ifdef ENAVAIL
        [ENAVAIL] = "ENAVAIL",
    #endif
    #ifdef ENEEDAUTH
        [ENEEDAUTH] = "ENEEDAUTH",
    #endif
    #ifdef ENETDOWN
        [ENETDOWN] = "ENETDOWN",
    #endif
    #ifdef ENETRESET
        [ENETRESET] = "ENETRESET",
    #endif
    #ifdef ENETUNREACH
        [ENETUNREACH] = "ENETUNREACH",
    #endif
    #ifdef ENFILE
        [ENFILE] = "ENFILE",
    #endif
    #ifdef ENFSREMOTE
        [ENFSREMOTE] = "ENFSREMOTE",
    #endif
    #ifdef ENMFILE
        [ENMFILE] = "ENMFILE",
    #endif
    #ifdef ENOANO
        [ENOANO] = "ENOANO",
    #endif
    #ifdef ENOATTR
        [ENOATTR] = "ENOATTR",
    #endif
    #ifdef ENOBUFS
        [ENOBUFS] = "ENOBUFS",
    #endif
    #ifdef ENOCONNECT
        [ENOCONNECT] = "ENOCONNECT",
    #endif
    #ifdef ENOCSI
        [ENOCSI] = "ENOCSI",
    #endif
    #ifdef ENODATA
        [ENODATA] = "ENODATA",
    #endif
    #ifdef ENODEV
        [ENODEV] = "ENODEV",
    #endif
    #ifdef ENOENT
        [ENOENT] = "ENOENT",
    #endif
    #ifdef ENOEXEC
        [ENOEXEC] = "ENOEXEC",
    #endif
    #ifdef ENOIOCTL
        [ENOIOCTL] = "ENOIOCTL",
    #endif
    #ifdef ENOIOCTLCMD
        [ENOIOCTLCMD] = "ENOIOCTLCMD",
    #endif
    #ifdef ENOKEY
        [ENOKEY] = "ENOKEY",
    #endif
    #ifdef ENOLCK
        [ENOLCK] = "ENOLCK",
    #endif
    #ifdef ENOLINK
        [ENOLINK] = "ENOLINK",
    #endif
    #ifdef ENOLOAD
        [ENOLOAD] = "ENOLOAD",
    #endif
    #ifdef ENOMATCH
        [ENOMATCH] = "ENOMATCH",
    #endif
    #ifdef ENOMEDIUM
        [ENOMEDIUM] = "ENOMEDIUM",
    #endif
    #ifdef ENOMEM
        [ENOMEM] = "ENOMEM",
    #endif
    #ifdef ENOMSG
        [ENOMSG] = "ENOMSG",
    #endif
    #ifdef ENONET
        [ENONET] = "ENONET",
    #endif
    #ifdef ENOPARAM
        [ENOPARAM] = "ENOPARAM",
    #endif
    #ifdef ENOPKG
        [ENOPKG] = "ENOPKG",
    #endif
    #ifdef ENOPOLICY
        [ENOPOLICY] = "ENOPOLICY",
    #endif
    #ifdef ENOPROTOOPT
        [ENOPROTOOPT] = "ENOPROTOOPT",
    #endif
    #ifdef ENOREG
        [ENOREG] = "ENOREG",
    #endif
    #ifdef ENOREUSE
        [ENOREUSE] = "ENOREUSE",
    #endif
    #ifdef ENOSHARE
        [ENOSHARE] = "ENOSHARE",
    #endif
    #ifdef ENOSPC
        [ENOSPC] = "ENOSPC",
    #endif
    #ifdef ENOSR
        [ENOSR] = "ENOSR",
    #endif
    #ifdef ENOSTR
        [ENOSTR] = "ENOSTR",
    #endif
    #ifdef ENOSYM
        [ENOSYM] = "ENOSYM",
    #endif
    #ifdef ENOSYS
        [ENOSYS] = "ENOSYS",
    #endif
    #ifdef ENOTACTIVE
        [ENOTACTIVE] = "ENOTACTIVE",
    #endif
    #ifdef ENOTBLK
        [ENOTBLK] = "ENOTBLK",
    #endif
    #ifdef ENOTCAPABLE
        [ENOTCAPABLE] = "ENOTCAPABLE",
    #endif
    #ifdef ENOTCONN
        [ENOTCONN] = "ENOTCONN",
    #endif
    #ifdef ENOTDIR
        [ENOTDIR] = "ENOTDIR",
    #endif
    #ifdef ENOTEMPTY
        [ENOTEMPTY] = "ENOTEMPTY",
    #endif
    #ifdef ENOTNAM
        [ENOTNAM] = "ENOTNAM",
    #endif
    #ifdef ENOTREADY
        [ENOTREADY] = "ENOTREADY",
    #endif
    #ifdef ENOTRECOVERABLE
        [ENOTRECOVERABLE] = "ENOTRECOVERABLE",
    #endif
    #ifdef ENOTRUST
        [ENOTRUST] = "ENOTRUST",
    #endif
    #ifdef ENOTSOCK
        [ENOTSOCK] = "ENOTSOCK",
    #endif
    #ifdef ENOTSUP
        [ENOTSUP] = "ENOTSUP",
    #endif
    #ifdef ENOTSUPP
        [ENOTSUPP] = "ENOTSUPP",
    #endif
    #ifdef ENOTSYNC
        [ENOTSYNC] = "ENOTSYNC",
    #endif
    #ifdef ENOTTY
        [ENOTTY] = "ENOTTY",
    #endif
    #ifdef ENOTUNIQ
        [ENOTUNIQ] = "ENOTUNIQ",
    #endif
    #ifdef ENOUNLD
        [ENOUNLD] = "ENOUNLD",
    #endif
    #ifdef ENOUNREG
        [ENOUNREG] = "ENOUNREG",
    #endif
    #ifdef ENXIO
        [ENXIO] = "ENXIO",
    #endif
    #ifdef EOFFLOADboxDOWN
        [EOFFLOADboxDOWN] = "EOFFLOADboxDOWN",
    #endif
    #ifdef EOFFLOADboxERROR
        [EOFFLOADboxERROR] = "EOFFLOADboxERROR",
    #endif
    #ifdef EOFFLOADboxRESTART
        [EOFFLOADboxRESTART] = "EOFFLOADboxRESTART",
    #endif
    #ifdef EOPCOMPLETE
        [EOPCOMPLETE] = "EOPCOMPLETE",
    #endif
    #ifdef EOPENSTALE
        [EOPENSTALE] = "EOPENSTALE",
    #endif
    #ifdef EOPNOTSUPP
        #if !defined(ENOTSUP) || EOPNOTSUPP != ENOTSUP
        [EOPNOTSUPP] = "EOPNOTSUPP",
        #endif
    #endif
    #ifdef EOVERFLOW
        [EOVERFLOW] = "EOVERFLOW",
    #endif
    #ifdef EOWNERDEAD
        [EOWNERDEAD] = "EOWNERDEAD",
    #endif
    #ifdef EPASSTHROUGH
        [EPASSTHROUGH] = "EPASSTHROUGH",
    #endif
    #ifdef EPATHREMOTE
        [EPATHREMOTE] = "EPATHREMOTE",
    #endif
    #ifdef EPERM
        [EPERM] = "EPERM",
    #endif
    #ifdef EPFNOSUPPORT
        [EPFNOSUPPORT] = "EPFNOSUPPORT",
    #endif
    #ifdef EPIPE
        [EPIPE] = "EPIPE",
    #endif
    #ifdef EPOWERF
        [EPOWERF] = "EPOWERF",
    #endif
    #ifdef EPROBE_DEFER
        [EPROBE_DEFER] = "EPROBE_DEFER",
    #endif
    #ifdef EPROCLIM
        [EPROCLIM] = "EPROCLIM",
    #endif
    #ifdef EPROCUNAVAIL
        [EPROCUNAVAIL] = "EPROCUNAVAIL",
    #endif
    #ifdef EPROGMISMATCH
        [EPROGMISMATCH] = "EPROGMISMATCH",
    #endif
    #ifdef EPROGUNAVAIL
        [EPROGUNAVAIL] = "EPROGUNAVAIL",
    #endif
    #ifdef EPROTO
        [EPROTO] = "EPROTO",
    #endif
    #ifdef EPROTONOSUPPORT
        [EPROTONOSUPPORT] = "EPROTONOSUPPORT",
    #endif
    #ifdef EPROTOTYPE
        [EPROTOTYPE] = "EPROTOTYPE",
    #endif
    #ifdef EPWROFF
        [EPWROFF] = "EPWROFF",
    #endif
    #ifdef EQFULL
        [EQFULL] = "EQFULL",
    #endif
    #ifdef EQSUSPENDED
        [EQSUSPENDED] = "EQSUSPENDED",
    #endif
    #ifdef ERANGE
        [ERANGE] = "ERANGE",
    #endif
    #ifdef ERECALLCONFLICT
        [ERECALLCONFLICT] = "ERECALLCONFLICT",
    #endif
    #ifdef ERECYCLE
        [ERECYCLE] = "ERECYCLE",
    #endif
    #ifdef EREDRIVEOPEN
        [EREDRIVEOPEN] = "EREDRIVEOPEN",
    #endif
    #ifdef EREFUSED
        #if !defined(ECONNREFUSED) || EREFUSED != ECONNREFUSED
        [EREFUSED] = "EREFUSED",
        #endif
    #endif
    #ifdef ERELOC
        [ERELOC] = "ERELOC",
    #endif
    #ifdef ERELOCATED
        [ERELOCATED] = "ERELOCATED",
    #endif
    #ifdef ERELOOKUP
        [ERELOOKUP] = "ERELOOKUP",
    #endif
    #ifdef EREMCHG
        [EREMCHG] = "EREMCHG",
    #endif
    #ifdef EREMDEV
        [EREMDEV] = "EREMDEV",
    #endif
    #ifdef EREMOTE
        [EREMOTE] = "EREMOTE",
    #endif
    #ifdef EREMOTEIO
        [EREMOTEIO] = "EREMOTEIO",
    #endif
    #ifdef EREMOTERELEASE
        [EREMOTERELEASE] = "EREMOTERELEASE",
    #endif
    #ifdef ERESTART
        [ERESTART] = "ERESTART",
    #endif
    #ifdef ERESTARTNOHAND
        [ERESTARTNOHAND] = "ERESTARTNOHAND",
    #endif
    #ifdef ERESTARTNOINTR
        [ERESTARTNOINTR] = "ERESTARTNOINTR",
    #endif
    #ifdef ERESTARTSYS
        [ERESTARTSYS] = "ERESTARTSYS",
    #endif
    #ifdef ERESTART_RESTARTBLOCK
        [ERESTART_RESTARTBLOCK] = "ERESTART_RESTARTBLOCK",
    #endif
    #ifdef ERFKILL
        [ERFKILL] = "ERFKILL",
    #endif
    #ifdef EROFS
        [EROFS] = "EROFS",
    #endif
    #ifdef ERPCMISMATCH
        [ERPCMISMATCH] = "ERPCMISMATCH",
    #endif
    #ifdef ERREMOTE
        [ERREMOTE] = "ERREMOTE",
    #endif
    #ifdef ESAD
        [ESAD] = "ESAD",
    #endif
    #ifdef ESERVERFAULT
        [ESERVERFAULT] = "ESERVERFAULT",
    #endif
    #ifdef ESHLIBVERS
        [ESHLIBVERS] = "ESHLIBVERS",
    #endif
    #ifdef ESHUTDOWN
        [ESHUTDOWN] = "ESHUTDOWN",
    #endif
    #ifdef ESIGPARM
        [ESIGPARM] = "ESIGPARM",
    #endif
    #ifdef ESOCKTNOSUPPORT
        [ESOCKTNOSUPPORT] = "ESOCKTNOSUPPORT",
    #endif
    #ifdef ESOFT
        [ESOFT] = "ESOFT",
    #endif
    #ifdef ESPIPE
        [ESPIPE] = "ESPIPE",
    #endif
    #ifdef ESRCH
        [ESRCH] = "ESRCH",
    #endif
    #ifdef ESRMNT
        [ESRMNT] = "ESRMNT",
    #endif
    #ifdef ESTALE
        [ESTALE] = "ESTALE",
    #endif
    #ifdef ESTRPIPE
        [ESTRPIPE] = "ESTRPIPE",
    #endif
    #ifdef ESYSERROR
        [ESYSERROR] = "ESYSERROR",
    #endif
    #ifdef ETIME
        [ETIME] = "ETIME",
    #endif
    #ifdef ETIMEDOUT
        [ETIMEDOUT] = "ETIMEDOUT",
    #endif
    #ifdef ETOOMANYREFS
        [ETOOMANYREFS] = "ETOOMANYREFS",
    #endif
    #ifdef ETOOSMALL
        [ETOOSMALL] = "ETOOSMALL",
    #endif
    #ifdef ETXTBSY
        [ETXTBSY] = "ETXTBSY",
    #endif
    #ifdef EUCLEAN
        [EUCLEAN] = "EUCLEAN",
    #endif
    #ifdef EUNATCH
        [EUNATCH] = "EUNATCH",
    #endif
    #ifdef EUSERS
        [EUSERS] = "EUSERS",
    #endif
    #ifdef EVERSION
        [EVERSION] = "EVERSION",
    #endif
    #ifdef EWOULDBLOCK
        #if !defined(EAGAIN) || EWOULDBLOCK != EAGAIN
        [EWOULDBLOCK] = "EWOULDBLOCK",
        #endif
    #endif
    #ifdef EWRONGFS
        [EWRONGFS] = "EWRONGFS",
    #endif
    #ifdef EWRPROTECT
        [EWRPROTECT] = "EWRPROTECT",
    #endif
    #ifdef EXDEV
        [EXDEV] = "EXDEV",
    #endif
    #ifdef EXFULL
        [EXFULL] = "EXFULL",
    #endif
    };
    if(errno_ >= 0 && errno_ < (sizeof(names) / sizeof(*names)))
    {
        return names[errno_];
    }
    return 0;
#else /* ERRNONAME_SAFE_TO_USE_ARRAY */
    switch(errno_)
    {
        case 0: return 0;
    #ifdef E2BIG
        case E2BIG: return "E2BIG";
    #endif
    #ifdef EACCES
        case EACCES: return "EACCES";
    #endif
    #ifdef EADDRINUSE
        case EADDRINUSE: return "EADDRINUSE";
    #endif
    #ifdef EADDRNOTAVAIL
        case EADDRNOTAVAIL: return "EADDRNOTAVAIL";
    #endif
    #ifdef EADI
        case EADI: return "EADI";
    #endif
    #ifdef EADV
        case EADV: return "EADV";
    #endif
    #ifdef EAFNOSUPPORT
        case EAFNOSUPPORT: return "EAFNOSUPPORT";
    #endif
    #ifdef EAGAIN
        case EAGAIN: return "EAGAIN";
    #endif
    #ifdef EAIO
        case EAIO: return "EAIO";
    #endif
    #ifdef EALIGN
        case EALIGN: return "EALIGN";
    #endif
    #ifdef EALREADY
        case EALREADY: return "EALREADY";
    #endif
    #ifdef EASYNC
        case EASYNC: return "EASYNC";
    #endif
    #ifdef EAUTH
        case EAUTH: return "EAUTH";
    #endif
    #ifdef EBADARCH
        case EBADARCH: return "EBADARCH";
    #endif
    #ifdef EBADCOOKIE
        case EBADCOOKIE: return "EBADCOOKIE";
    #endif
    #ifdef EBADE
        case EBADE: return "EBADE";
    #endif
    #ifdef EBADEXEC
        case EBADEXEC: return "EBADEXEC";
    #endif
    #ifdef EBADF
        case EBADF: return "EBADF";
    #endif
    #ifdef EBADFD
        case EBADFD: return "EBADFD";
    #endif
    #ifdef EBADHANDLE
        case EBADHANDLE: return "EBADHANDLE";
    #endif
    #ifdef EBADMACHO
        case EBADMACHO: return "EBADMACHO";
    #endif
    #ifdef EBADMSG
        case EBADMSG: return "EBADMSG";
    #endif
    #ifdef EBADR
        case EBADR: return "EBADR";
    #endif
    #ifdef EBADRPC
        case EBADRPC: return "EBADRPC";
    #endif
    #ifdef EBADRQC
        case EBADRQC: return "EBADRQC";
    #endif
    #ifdef EBADSLT
        case EBADSLT: return "EBADSLT";
    #endif
    #ifdef EBADTYPE
        case EBADTYPE: return "EBADTYPE";
    #endif
    #ifdef EBADVER
        case EBADVER: return "EBADVER";
    #endif
    #ifdef EBFONT
        case EBFONT: return "EBFONT";
    #endif
    #ifdef EBUSY
        case EBUSY: return "EBUSY";
    #endif
    #ifdef ECANCELED
        case ECANCELED: return "ECANCELED";
    #endif
    #ifdef ECANCELLED
        #if !defined(ECANCELED) || ECANCELLED != ECANCELED
        case ECANCELLED: return "ECANCELLED";
        #endif
    #endif
    #ifdef ECAPMODE
        case ECAPMODE: return "ECAPMODE";
    #endif
    #ifdef ECASECLASH
        case ECASECLASH: return "ECASECLASH";
    #endif
    #ifdef ECHILD
        case ECHILD: return "ECHILD";
    #endif
    #ifdef ECHRNG
        case ECHRNG: return "ECHRNG";
    #endif
    #ifdef ECICS
        case ECICS: return "ECICS";
    #endif
    #ifdef ECKPT
        case ECKPT: return "ECKPT";
    #endif
    #ifdef ECKSUM
        case ECKSUM: return "ECKSUM";
    #endif
    #ifdef ECLONEME
        case ECLONEME: return "ECLONEME";
    #endif
    #ifdef ECOMM
        case ECOMM: return "ECOMM";
    #endif
    #ifdef ECONFIG
        case ECONFIG: return "ECONFIG";
    #endif
    #ifdef ECONNABORTED
        case ECONNABORTED: return "ECONNABORTED";
    #endif
    #ifdef ECONNREFUSED
        case ECONNREFUSED: return "ECONNREFUSED";
    #endif
    #ifdef ECONNRESET
        case ECONNRESET: return "ECONNRESET";
    #endif
    #ifdef ECORRUPT
        case ECORRUPT: return "ECORRUPT";
    #endif
    #ifdef ECVCERORR
        case ECVCERORR: return "ECVCERORR";
    #endif
    #ifdef ECVPERORR
        case ECVPERORR: return "ECVPERORR";
    #endif
    #ifdef EDATALESS
        case EDATALESS: return "EDATALESS";
    #endif
    #ifdef EDEADLK
        case EDEADLK: return "EDEADLK";
    #endif
    #ifdef EDEADLOCK
        #if !defined(EDEADLK) || EDEADLOCK != EDEADLK
        case EDEADLOCK: return "EDEADLOCK";
        #endif
    #endif
    #ifdef EDESTADDREQ
        #if !defined(EDESTADDRREQ) || EDESTADDREQ != EDESTADDRREQ
        case EDESTADDREQ: return "EDESTADDREQ";
        #endif
    #endif
    #ifdef EDESTADDRREQ
        case EDESTADDRREQ: return "EDESTADDRREQ";
    #endif
    #ifdef EDEVERR
        case EDEVERR: return "EDEVERR";
    #endif
    #ifdef EDIRIOCTL
        case EDIRIOCTL: return "EDIRIOCTL";
    #endif
    #ifdef EDIRTY
        case EDIRTY: return "EDIRTY";
    #endif
    #ifdef EDIST
        case EDIST: return "EDIST";
    #endif
    #ifdef EDOM
        case EDOM: return "EDOM";
    #endif
    #ifdef EDOOFUS
        case EDOOFUS: return "EDOOFUS";
    #endif
    #ifdef EDOTDOT
        case EDOTDOT: return "EDOTDOT";
    #endif
    #ifdef EDQUOT
        case EDQUOT: return "EDQUOT";
    #endif
    #ifdef EDUPFD
        case EDUPFD: return "EDUPFD";
    #endif
    #ifdef EDUPPKG
        case EDUPPKG: return "EDUPPKG";
    #endif
    #ifdef EEXIST
        case EEXIST: return "EEXIST";
    #endif
    #ifdef EFAIL
        case EFAIL: return "EFAIL";
    #endif
    #ifdef EFAULT
        case EFAULT: return "EFAULT";
    #endif
    #ifdef EFBIG
        case EFBIG: return "EFBIG";
    #endif
    #ifdef EFORMAT
        case EFORMAT: return "EFORMAT";
    #endif
    #ifdef EFPOS
        case EFPOS: return "EFPOS";
    #endif
    #ifdef EFRAGS
        case EFRAGS: return "EFRAGS";
    #endif
    #ifdef EFSCORRUPTED
        case EFSCORRUPTED: return "EFSCORRUPTED";
    #endif
    #ifdef EFTYPE
        case EFTYPE: return "EFTYPE";
    #endif
    #ifdef EHOSTDOWN
        case EHOSTDOWN: return "EHOSTDOWN";
    #endif
    #ifdef EHOSTUNREACH
        case EHOSTUNREACH: return "EHOSTUNREACH";
    #endif
    #ifdef EHWPOISON
        case EHWPOISON: return "EHWPOISON";
    #endif
    #ifdef EIBMBADCALL
        case EIBMBADCALL: return "EIBMBADCALL";
    #endif
    #ifdef EIBMBADPARM
        case EIBMBADPARM: return "EIBMBADPARM";
    #endif
    #ifdef EIBMCANCELLED
        case EIBMCANCELLED: return "EIBMCANCELLED";
    #endif
    #ifdef EIBMCONFLICT
        case EIBMCONFLICT: return "EIBMCONFLICT";
    #endif
    #ifdef EIBMIUCVERR
        case EIBMIUCVERR: return "EIBMIUCVERR";
    #endif
    #ifdef EIBMSOCKINUSE
        case EIBMSOCKINUSE: return "EIBMSOCKINUSE";
    #endif
    #ifdef EIBMSOCKOUTOFRANGE
        case EIBMSOCKOUTOFRANGE: return "EIBMSOCKOUTOFRANGE";
    #endif
    #ifdef EIDRM
        case EIDRM: return "EIDRM";
    #endif
    #ifdef EILSEQ
        case EILSEQ: return "EILSEQ";
    #endif
    #ifdef EINIT
        case EINIT: return "EINIT";
    #endif
    #ifdef EINPROG
        #if !defined(EINPROGRESS) || EINPROG != EINPROGRESS
        case EINPROG: return "EINPROG";
        #endif
    #endif
    #ifdef EINPROGRESS
        case EINPROGRESS: return "EINPROGRESS";
    #endif
    #ifdef EINTEGRITY
        case EINTEGRITY: return "EINTEGRITY";
    #endif
    #ifdef EINTR
        case EINTR: return "EINTR";
    #endif
    #ifdef EINTRNODATA
        case EINTRNODATA: return "EINTRNODATA";
    #endif
    #ifdef EINVAL
        case EINVAL: return "EINVAL";
    #endif
    #ifdef EIO
        case EIO: return "EIO";
    #endif
    #ifdef EIOCBQUEUED
        case EIOCBQUEUED: return "EIOCBQUEUED";
    #endif
    #ifdef EIPSEC
        case EIPSEC: return "EIPSEC";
    #endif
    #ifdef EISCONN
        case EISCONN: return "EISCONN";
    #endif
    #ifdef EISDIR
        case EISDIR: return "EISDIR";
    #endif
    #ifdef EISNAM
        case EISNAM: return "EISNAM";
    #endif
    #ifdef EJUKEBOX
        case EJUKEBOX: return "EJUKEBOX";
    #endif
    #ifdef EJUSTRETURN
        case EJUSTRETURN: return "EJUSTRETURN";
    #endif
    #ifdef EKEEPLOOKING
        case EKEEPLOOKING: return "EKEEPLOOKING";
    #endif
    #ifdef EKEYEXPIRED
        case EKEYEXPIRED: return "EKEYEXPIRED";
    #endif
    #ifdef EKEYREJECTED
        case EKEYREJECTED: return "EKEYREJECTED";
    #endif
    #ifdef EKEYREVOKED
        case EKEYREVOKED: return "EKEYREVOKED";
    #endif
    #ifdef EL2HLT
        case EL2HLT: return "EL2HLT";
    #endif
    #ifdef EL2NSYNC
        case EL2NSYNC: return "EL2NSYNC";
    #endif
    #ifdef EL3HLT
        case EL3HLT: return "EL3HLT";
    #endif
    #ifdef EL3RST
        case EL3RST: return "EL3RST";
    #endif
    #ifdef ELBIN
        case ELBIN: return "ELBIN";
    #endif
    #ifdef ELEMSGERR
        case ELEMSGERR: return "ELEMSGERR";
    #endif
    #ifdef ELEMULTITHREAD
        case ELEMULTITHREAD: return "ELEMULTITHREAD";
    #endif
    #ifdef ELEMULTITHREADFORK
        case ELEMULTITHREADFORK: return "ELEMULTITHREADFORK";
    #endif
    #ifdef ELENOFORK
        case ELENOFORK: return "ELENOFORK";
    #endif
    #ifdef ELIBACC
        case ELIBACC: return "ELIBACC";
    #endif
    #ifdef ELIBBAD
        case ELIBBAD: return "ELIBBAD";
    #endif
    #ifdef ELIBEXEC
        case ELIBEXEC: return "ELIBEXEC";
    #endif
    #ifdef ELIBMAX
        case ELIBMAX: return "ELIBMAX";
    #endif
    #ifdef ELIBSCN
        case ELIBSCN: return "ELIBSCN";
    #endif
    #ifdef ELNRNG
        case ELNRNG: return "ELNRNG";
    #endif
    #ifdef ELOCKUNMAPPED
        case ELOCKUNMAPPED: return "ELOCKUNMAPPED";
    #endif
    #ifdef ELOOP
        case ELOOP: return "ELOOP";
    #endif
    #ifdef EMEDIA
        case EMEDIA: return "EMEDIA";
    #endif
    #ifdef EMEDIUMTYPE
        case EMEDIUMTYPE: return "EMEDIUMTYPE";
    #endif
    #ifdef EMFILE
        case EMFILE: return "EMFILE";
    #endif
    #ifdef EMLINK
        case EMLINK: return "EMLINK";
    #endif
    #ifdef EMOUNTEXIT
        case EMOUNTEXIT: return "EMOUNTEXIT";
    #endif
    #ifdef EMOVEFD
        case EMOVEFD: return "EMOVEFD";
    #endif
    #ifdef EMSGSIZE
        case EMSGSIZE: return "EMSGSIZE";
    #endif
    #ifdef EMTIMERS
        case EMTIMERS: return "EMTIMERS";
    #endif
    #ifdef EMULTIHOP
        case EMULTIHOP: return "EMULTIHOP";
    #endif
    #ifdef EMVSBADCHAR
        case EMVSBADCHAR: return "EMVSBADCHAR";
    #endif
    #ifdef EMVSCATLG
        case EMVSCATLG: return "EMVSCATLG";
    #endif
    #ifdef EMVSCPLERROR
        case EMVSCPLERROR: return "EMVSCPLERROR";
    #endif
    #ifdef EMVSCVAF
        case EMVSCVAF: return "EMVSCVAF";
    #endif
    #ifdef EMVSDYNALC
        case EMVSDYNALC: return "EMVSDYNALC";
    #endif
    #ifdef EMVSERR
        case EMVSERR: return "EMVSERR";
    #endif
    #ifdef EMVSEXPIRE
        case EMVSEXPIRE: return "EMVSEXPIRE";
    #endif
    #ifdef EMVSINITIAL
        case EMVSINITIAL: return "EMVSINITIAL";
    #endif
    #ifdef EMVSNORTL
        case EMVSNORTL: return "EMVSNORTL";
    #endif
    #ifdef EMVSNOTXP
        case EMVSNOTXP: return "EMVSNOTXP";
    #endif
    #ifdef EMVSPARM
        case EMVSPARM: return "EMVSPARM";
    #endif
    #ifdef EMVSPASSWORD
        case EMVSPASSWORD: return "EMVSPASSWORD";
    #endif
    #ifdef EMVSPATHOPTS
        case EMVSPATHOPTS: return "EMVSPATHOPTS";
    #endif
    #ifdef EMVSPFSFILE
        case EMVSPFSFILE: return "EMVSPFSFILE";
    #endif
    #ifdef EMVSPFSPERM
        case EMVSPFSPERM: return "EMVSPFSPERM";
    #endif
    #ifdef EMVSSAF2ERR
        case EMVSSAF2ERR: return "EMVSSAF2ERR";
    #endif
    #ifdef EMVSSAFEXTRERR
        case EMVSSAFEXTRERR: return "EMVSSAFEXTRERR";
    #endif
    #ifdef EMVSTODNOTSET
        case EMVSTODNOTSET: return "EMVSTODNOTSET";
    #endif
    #ifdef ENAMETOOLONG
        case ENAMETOOLONG: return "ENAMETOOLONG";
    #endif
    #ifdef ENAVAIL
        case ENAVAIL: return "ENAVAIL";
    #endif
    #ifdef ENEEDAUTH
        case ENEEDAUTH: return "ENEEDAUTH";
    #endif
    #ifdef ENETDOWN
        case ENETDOWN: return "ENETDOWN";
    #endif
    #ifdef ENETRESET
        case ENETRESET: return "ENETRESET";
    #endif
    #ifdef ENETUNREACH
        case ENETUNREACH: return "ENETUNREACH";
    #endif
    #ifdef ENFILE
        case ENFILE: return "ENFILE";
    #endif
    #ifdef ENFSREMOTE
        case ENFSREMOTE: return "ENFSREMOTE";
    #endif
    #ifdef ENMFILE
        case ENMFILE: return "ENMFILE";
    #endif
    #ifdef ENOANO
        case ENOANO: return "ENOANO";
    #endif
    #ifdef ENOATTR
        case ENOATTR: return "ENOATTR";
    #endif
    #ifdef ENOBUFS
        case ENOBUFS: return "ENOBUFS";
    #endif
    #ifdef ENOCONNECT
        case ENOCONNECT: return "ENOCONNECT";
    #endif
    #ifdef ENOCSI
        case ENOCSI: return "ENOCSI";
    #endif
    #ifdef ENODATA
        case ENODATA: return "ENODATA";
    #endif
    #ifdef ENODEV
        case ENODEV: return "ENODEV";
    #endif
    #ifdef ENOENT
        case ENOENT: return "ENOENT";
    #endif
    #ifdef ENOEXEC
        case ENOEXEC: return "ENOEXEC";
    #endif
    #ifdef ENOIOCTL
        case ENOIOCTL: return "ENOIOCTL";
    #endif
    #ifdef ENOIOCTLCMD
        case ENOIOCTLCMD: return "ENOIOCTLCMD";
    #endif
    #ifdef ENOKEY
        case ENOKEY: return "ENOKEY";
    #endif
    #ifdef ENOLCK
        case ENOLCK: return "ENOLCK";
    #endif
    #ifdef ENOLINK
        case ENOLINK: return "ENOLINK";
    #endif
    #ifdef ENOLOAD
        case ENOLOAD: return "ENOLOAD";
    #endif
    #ifdef ENOMATCH
        case ENOMATCH: return "ENOMATCH";
    #endif
    #ifdef ENOMEDIUM
        case ENOMEDIUM: return "ENOMEDIUM";
    #endif
    #ifdef ENOMEM
        case ENOMEM: return "ENOMEM";
    #endif
    #ifdef ENOMSG
        case ENOMSG: return "ENOMSG";
    #endif
    #ifdef ENONET
        case ENONET: return "ENONET";
    #endif
    #ifdef ENOPARAM
        case ENOPARAM: return "ENOPARAM";
    #endif
    #ifdef ENOPKG
        case ENOPKG: return "ENOPKG";
    #endif
    #ifdef ENOPOLICY
        case ENOPOLICY: return "ENOPOLICY";
    #endif
    #ifdef ENOPROTOOPT
        case ENOPROTOOPT: return "ENOPROTOOPT";
    #endif
    #ifdef ENOREG
        case ENOREG: return "ENOREG";
    #endif
    #ifdef ENOREUSE
        case ENOREUSE: return "ENOREUSE";
    #endif
    #ifdef ENOSHARE
        case ENOSHARE: return "ENOSHARE";
    #endif
    #ifdef ENOSPC
        case ENOSPC: return "ENOSPC";
    #endif
    #ifdef ENOSR
        case ENOSR: return "ENOSR";
    #endif
    #ifdef ENOSTR
        case ENOSTR: return "ENOSTR";
    #endif
    #ifdef ENOSYM
        case ENOSYM: return "ENOSYM";
    #endif
    #ifdef ENOSYS
        case ENOSYS: return "ENOSYS";
    #endif
    #ifdef ENOTACTIVE
        case ENOTACTIVE: return "ENOTACTIVE";
    #endif
    #ifdef ENOTBLK
        case ENOTBLK: return "ENOTBLK";
    #endif
    #ifdef ENOTCAPABLE
        case ENOTCAPABLE: return "ENOTCAPABLE";
    #endif
    #ifdef ENOTCONN
        case ENOTCONN: return "ENOTCONN";
    #endif
    #ifdef ENOTDIR
        case ENOTDIR: return "ENOTDIR";
    #endif
    #ifdef ENOTEMPTY
        case ENOTEMPTY: return "ENOTEMPTY";
    #endif
    #ifdef ENOTNAM
        case ENOTNAM: return "ENOTNAM";
    #endif
    #ifdef ENOTREADY
        case ENOTREADY: return "ENOTREADY";
    #endif
    #ifdef ENOTRECOVERABLE
        case ENOTRECOVERABLE: return "ENOTRECOVERABLE";
    #endif
    #ifdef ENOTRUST
        case ENOTRUST: return "ENOTRUST";
    #endif
    #ifdef ENOTSOCK
        case ENOTSOCK: return "ENOTSOCK";
    #endif
    #ifdef ENOTSUP
        case ENOTSUP: return "ENOTSUP";
    #endif
    #ifdef ENOTSUPP
        case ENOTSUPP: return "ENOTSUPP";
    #endif
    #ifdef ENOTSYNC
        case ENOTSYNC: return "ENOTSYNC";
    #endif
    #ifdef ENOTTY
        case ENOTTY: return "ENOTTY";
    #endif
    #ifdef ENOTUNIQ
        case ENOTUNIQ: return "ENOTUNIQ";
    #endif
    #ifdef ENOUNLD
        case ENOUNLD: return "ENOUNLD";
    #endif
    #ifdef ENOUNREG
        case ENOUNREG: return "ENOUNREG";
    #endif
    #ifdef ENXIO
        case ENXIO: return "ENXIO";
    #endif
    #ifdef EOFFLOADboxDOWN
        case EOFFLOADboxDOWN: return "EOFFLOADboxDOWN";
    #endif
    #ifdef EOFFLOADboxERROR
        case EOFFLOADboxERROR: return "EOFFLOADboxERROR";
    #endif
    #ifdef EOFFLOADboxRESTART
        case EOFFLOADboxRESTART: return "EOFFLOADboxRESTART";
    #endif
    #ifdef EOPCOMPLETE
        case EOPCOMPLETE: return "EOPCOMPLETE";
    #endif
    #ifdef EOPENSTALE
        case EOPENSTALE: return "EOPENSTALE";
    #endif
    #ifdef EOPNOTSUPP
        #if !defined(ENOTSUP) || EOPNOTSUPP != ENOTSUP
        case EOPNOTSUPP: return "EOPNOTSUPP";
        #endif
    #endif
    #ifdef EOVERFLOW
        case EOVERFLOW: return "EOVERFLOW";
    #endif
    #ifdef EOWNERDEAD
        case EOWNERDEAD: return "EOWNERDEAD";
    #endif
    #ifdef EPASSTHROUGH
        case EPASSTHROUGH: return "EPASSTHROUGH";
    #endif
    #ifdef EPATHREMOTE
        case EPATHREMOTE: return "EPATHREMOTE";
    #endif
    #ifdef EPERM
        case EPERM: return "EPERM";
    #endif
    #ifdef EPFNOSUPPORT
        case EPFNOSUPPORT: return "EPFNOSUPPORT";
    #endif
    #ifdef EPIPE
        case EPIPE: return "EPIPE";
    #endif
    #ifdef EPOWERF
        case EPOWERF: return "EPOWERF";
    #endif
    #ifdef EPROBE_DEFER
        case EPROBE_DEFER: return "EPROBE_DEFER";
    #endif
    #ifdef EPROCLIM
        case EPROCLIM: return "EPROCLIM";
    #endif
    #ifdef EPROCUNAVAIL
        case EPROCUNAVAIL: return "EPROCUNAVAIL";
    #endif
    #ifdef EPROGMISMATCH
        case EPROGMISMATCH: return "EPROGMISMATCH";
    #endif
    #ifdef EPROGUNAVAIL
        case EPROGUNAVAIL: return "EPROGUNAVAIL";
    #endif
    #ifdef EPROTO
        case EPROTO: return "EPROTO";
    #endif
    #ifdef EPROTONOSUPPORT
        case EPROTONOSUPPORT: return "EPROTONOSUPPORT";
    #endif
    #ifdef EPROTOTYPE
        case EPROTOTYPE: return "EPROTOTYPE";
    #endif
    #ifdef EPWROFF
        case EPWROFF: return "EPWROFF";
    #endif
    #ifdef EQFULL
        case EQFULL: return "EQFULL";
    #endif
    #ifdef EQSUSPENDED
        case EQSUSPENDED: return "EQSUSPENDED";
    #endif
    #ifdef ERANGE
        case ERANGE: return "ERANGE";
    #endif
    #ifdef ERECALLCONFLICT
        case ERECALLCONFLICT: return "ERECALLCONFLICT";
    #endif
    #ifdef ERECYCLE
        case ERECYCLE: return "ERECYCLE";
    #endif
    #ifdef EREDRIVEOPEN
        case EREDRIVEOPEN: return "EREDRIVEOPEN";
    #endif
    #ifdef EREFUSED
        #if !defined(ECONNREFUSED) || EREFUSED != ECONNREFUSED
        case EREFUSED: return "EREFUSED";
        #endif
    #endif
    #ifdef ERELOC
        case ERELOC: return "ERELOC";
    #endif
    #ifdef ERELOCATED
        case ERELOCATED: return "ERELOCATED";
    #endif
    #ifdef ERELOOKUP
        case ERELOOKUP: return "ERELOOKUP";
    #endif
    #ifdef EREMCHG
        case EREMCHG: return "EREMCHG";
    #endif
    #ifdef EREMDEV
        case EREMDEV: return "EREMDEV";
    #endif
    #ifdef EREMOTE
        case EREMOTE: return "EREMOTE";
    #endif
    #ifdef EREMOTEIO
        case EREMOTEIO: return "EREMOTEIO";
    #endif
    #ifdef EREMOTERELEASE
        case EREMOTERELEASE: return "EREMOTERELEASE";
    #endif
    #ifdef ERESTART
        case ERESTART: return "ERESTART";
    #endif
    #ifdef ERESTARTNOHAND
        case ERESTARTNOHAND: return "ERESTARTNOHAND";
    #endif
    #ifdef ERESTARTNOINTR
        case ERESTARTNOINTR: return "ERESTARTNOINTR";
    #endif
    #ifdef ERESTARTSYS
        case ERESTARTSYS: return "ERESTARTSYS";
    #endif
    #ifdef ERESTART_RESTARTBLOCK
        case ERESTART_RESTARTBLOCK: return "ERESTART_RESTARTBLOCK";
    #endif
    #ifdef ERFKILL
        case ERFKILL: return "ERFKILL";
    #endif
    #ifdef EROFS
        case EROFS: return "EROFS";
    #endif
    #ifdef ERPCMISMATCH
        case ERPCMISMATCH: return "ERPCMISMATCH";
    #endif
    #ifdef ERREMOTE
        case ERREMOTE: return "ERREMOTE";
    #endif
    #ifdef ESAD
        case ESAD: return "ESAD";
    #endif
    #ifdef ESERVERFAULT
        case ESERVERFAULT: return "ESERVERFAULT";
    #endif
    #ifdef ESHLIBVERS
        case ESHLIBVERS: return "ESHLIBVERS";
    #endif
    #ifdef ESHUTDOWN
        case ESHUTDOWN: return "ESHUTDOWN";
    #endif
    #ifdef ESIGPARM
        case ESIGPARM: return "ESIGPARM";
    #endif
    #ifdef ESOCKTNOSUPPORT
        case ESOCKTNOSUPPORT: return "ESOCKTNOSUPPORT";
    #endif
    #ifdef ESOFT
        case ESOFT: return "ESOFT";
    #endif
    #ifdef ESPIPE
        case ESPIPE: return "ESPIPE";
    #endif
    #ifdef ESRCH
        case ESRCH: return "ESRCH";
    #endif
    #ifdef ESRMNT
        case ESRMNT: return "ESRMNT";
    #endif
    #ifdef ESTALE
        case ESTALE: return "ESTALE";
    #endif
    #ifdef ESTRPIPE
        case ESTRPIPE: return "ESTRPIPE";
    #endif
    #ifdef ESYSERROR
        case ESYSERROR: return "ESYSERROR";
    #endif
    #ifdef ETIME
        case ETIME: return "ETIME";
    #endif
    #ifdef ETIMEDOUT
        case ETIMEDOUT: return "ETIMEDOUT";
    #endif
    #ifdef ETOOMANYREFS
        case ETOOMANYREFS: return "ETOOMANYREFS";
    #endif
    #ifdef ETOOSMALL
        case ETOOSMALL: return "ETOOSMALL";
    #endif
    #ifdef ETXTBSY
        case ETXTBSY: return "ETXTBSY";
    #endif
    #ifdef EUCLEAN
        case EUCLEAN: return "EUCLEAN";
    #endif
    #ifdef EUNATCH
        case EUNATCH: return "EUNATCH";
    #endif
    #ifdef EUSERS
        case EUSERS: return "EUSERS";
    #endif
    #ifdef EVERSION
        case EVERSION: return "EVERSION";
    #endif
    #ifdef EWOULDBLOCK
        #if !defined(EAGAIN) || EWOULDBLOCK != EAGAIN
        case EWOULDBLOCK: return "EWOULDBLOCK";
        #endif
    #endif
    #ifdef EWRONGFS
        case EWRONGFS: return "EWRONGFS";
    #endif
    #ifdef EWRPROTECT
        case EWRPROTECT: return "EWRPROTECT";
    #endif
    #ifdef EXDEV
        case EXDEV: return "EXDEV";
    #endif
    #ifdef EXFULL
        case EXFULL: return "EXFULL";
    #endif
    }
    return 0;
#endif /* ERRNONAME_SAFE_TO_USE_ARRAY */
}

#endif /* ERRNONAME_C */

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
    #if defined(ECANCELLED) && (!defined(ECANCELED) || ECANCELLED != ECANCELED)
        [ECANCELLED] = "ECANCELLED",
    #endif
    #ifdef ECAPMODE
        [ECAPMODE] = "ECAPMODE",
    #endif
    #ifdef ECHILD
        [ECHILD] = "ECHILD",
    #endif
    #ifdef ECHRNG
        [ECHRNG] = "ECHRNG",
    #endif
    #ifdef ECKPT
        [ECKPT] = "ECKPT",
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
    #ifdef EDEADLK
        [EDEADLK] = "EDEADLK",
    #endif
    #if defined(EDEADLOCK) && (!defined(EDEADLK) || EDEADLOCK != EDEADLK)
        [EDEADLOCK] = "EDEADLOCK",
    #endif
    #ifdef EDESTADDREQ
        [EDESTADDREQ] = "EDESTADDREQ",
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
        [EINPROG] = "EINPROG",
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
    #ifdef EINVAL
        [EINVAL] = "EINVAL",
    #endif
    #ifdef EIO
        [EIO] = "EIO",
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
    #ifdef EOPCOMPLETE
        [EOPCOMPLETE] = "EOPCOMPLETE",
    #endif
    #if defined(EOPNOTSUPP) && (!defined(ENOTSUP) || EOPNOTSUPP != ENOTSUP)
        [EOPNOTSUPP] = "EOPNOTSUPP",
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
    #ifdef ERECYCLE
        [ERECYCLE] = "ERECYCLE",
    #endif
    #ifdef EREDRIVEOPEN
        [EREDRIVEOPEN] = "EREDRIVEOPEN",
    #endif
    #ifdef EREFUSED
        [EREFUSED] = "EREFUSED",
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
    #ifdef ERFKILL
        [ERFKILL] = "ERFKILL",
    #endif
    #ifdef EROFS
        [EROFS] = "EROFS",
    #endif
    #ifdef ERPCMISMATCH
        [ERPCMISMATCH] = "ERPCMISMATCH",
    #endif
    #ifdef ESAD
        [ESAD] = "ESAD",
    #endif
    #ifdef ESHLIBVERS
        [ESHLIBVERS] = "ESHLIBVERS",
    #endif
    #ifdef ESHUTDOWN
        [ESHUTDOWN] = "ESHUTDOWN",
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
    #ifdef ESTART
        [ESTART] = "ESTART",
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
    #if defined(EWOULDBLOCK) && (!defined(EAGAIN) || EWOULDBLOCK != EAGAIN)
        [EWOULDBLOCK] = "EWOULDBLOCK",
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
    #if defined(ECANCELLED) && (!defined(ECANCELED) || ECANCELLED != ECANCELED)
        case ECANCELLED: return "ECANCELLED";
    #endif
    #ifdef ECAPMODE
        case ECAPMODE: return "ECAPMODE";
    #endif
    #ifdef ECHILD
        case ECHILD: return "ECHILD";
    #endif
    #ifdef ECHRNG
        case ECHRNG: return "ECHRNG";
    #endif
    #ifdef ECKPT
        case ECKPT: return "ECKPT";
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
    #ifdef EDEADLK
        case EDEADLK: return "EDEADLK";
    #endif
    #if defined(EDEADLOCK) && (!defined(EDEADLK) || EDEADLOCK != EDEADLK)
        case EDEADLOCK: return "EDEADLOCK";
    #endif
    #ifdef EDESTADDREQ
        case EDESTADDREQ: return "EDESTADDREQ";
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
        case EINPROG: return "EINPROG";
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
    #ifdef EINVAL
        case EINVAL: return "EINVAL";
    #endif
    #ifdef EIO
        case EIO: return "EIO";
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
    #ifdef EOPCOMPLETE
        case EOPCOMPLETE: return "EOPCOMPLETE";
    #endif
    #if defined(EOPNOTSUPP) && (!defined(ENOTSUP) || EOPNOTSUPP != ENOTSUP)
        case EOPNOTSUPP: return "EOPNOTSUPP";
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
    #ifdef ERECYCLE
        case ERECYCLE: return "ERECYCLE";
    #endif
    #ifdef EREDRIVEOPEN
        case EREDRIVEOPEN: return "EREDRIVEOPEN";
    #endif
    #ifdef EREFUSED
        case EREFUSED: return "EREFUSED";
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
    #ifdef ERFKILL
        case ERFKILL: return "ERFKILL";
    #endif
    #ifdef EROFS
        case EROFS: return "EROFS";
    #endif
    #ifdef ERPCMISMATCH
        case ERPCMISMATCH: return "ERPCMISMATCH";
    #endif
    #ifdef ESAD
        case ESAD: return "ESAD";
    #endif
    #ifdef ESHLIBVERS
        case ESHLIBVERS: return "ESHLIBVERS";
    #endif
    #ifdef ESHUTDOWN
        case ESHUTDOWN: return "ESHUTDOWN";
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
    #ifdef ESTART
        case ESTART: return "ESTART";
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
    #if defined(EWOULDBLOCK) && (!defined(EAGAIN) || EWOULDBLOCK != EAGAIN)
        case EWOULDBLOCK: return "EWOULDBLOCK";
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

/* SPDX-License-Identifier: 0BSD */
/* Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com> */

#ifndef ERRNONAME_H
#define ERRNONAME_H

#ifndef ERRNONAME_STATIC_INCLUDE
#define ERRNONAME_STATIC_INCLUDE STATIC_INCLUDE
#endif

#if ERRNONAME_STATIC_INCLUDE
#include "errnoname.c"
#else
char const * errnoname(int);
#endif

#endif /* ERRNONAME_H */

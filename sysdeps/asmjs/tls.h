/* Definition for thread-local data handling.
   Copyright (C) 2002-2016 Free Software Foundation, Inc.
   Copyright (C) 2016 Pip Cet <pipcet@gmail.com>

   This file is NOT part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* An architecture-specific version of this file has to defined a
   number of symbols:

     TLS_TCB_AT_TP  or  TLS_DTV_AT_TP

     The presence of one of these symbols signals which variant of
     the TLS ABI is used.  There are in the moment two variants
     available:

     * the thread pointer points to a thread control block

     * the thread pointer points to the dynamic thread vector


     TLS_TCB_SIZE

     This is the size of the thread control block structure.  How
     this is actually defined depends on the ABI.  The thread control
     block could be internal descriptor of the thread library or
     just a data structure which allows finding the DTV.

     TLS_INIT_TCB_SIZE

     Similarly, but this value is only used at startup and in the
     dynamic linker itself.  There are no threads in use at that time.


     TLS_TCB_ALIGN

     Alignment requirements for the TCB structure.

     TLS_INIT_TCB_ALIGN

     Similarly, but for the structure used at startup time.


     INSTALL_DTV(tcb, init_dtv)

     This macro must install the given initial DTV into the thread control
     block TCB.  The normal runtime functionality must then be able to
     use the value.


     TLS_INIT_TP(tcb)

     This macro must initialize the thread pointer to enable normal TLS
     operation.  The parameter is a pointer to the thread control block.
     ld.so calls this macro once.


     THREAD_DTV()

     This macro returns the address of the DTV of the current thread.
     This normally is done using the thread register which points
     to the dtv or the TCB (from which the DTV can found).
  */

#ifndef _TLS_H
#define _TLS_H 1

#include <stdio.h>

#define TLS_DTV_AT_TP 0
#define TLS_TCB_AT_TP 1

#define TLS_TCB_SIZE 64
#define TLS_INIT_TCB_SIZE 64
#define TLS_TCB_ALIGN 16
#define TLS_INIT_TCB_ALIGN 16

#define TLS_PRE_TCB_SIZE 64 /* XXX what's this? */

#ifndef __DTV_T__
#define __DTV_T__
typedef struct {
  long counter;
  struct {
    void *val;
    char *to_free;
    int is_static;
  } pointer;
} dtv_t;
#endif

/* Return dtv of given thread descriptor.  */
# define GET_DTV(tcbp) \
  (*(dtv_t **) (tcbp))

#define THREAD_GSCOPE_SET_FLAG() do { } while(0) // XXX
#define THREAD_GSCOPE_RESET_FLAG() do { } while(0) // XXX
#define THREAD_GSCOPE_WAIT() do { } while(0) // XXX

#define THREAD_SELF                                                     \
  ({                                                                    \
    struct pthread *__self;                                             \
    asm("%O0 = tp;" : "=r" (__self));                                   \
    if(0) fprintf(stderr, "THREAD_SELF from %p\n", __builtin_return_address(0)); \
    ((void **)__self)[1];                                                  \
  })

#define THREAD_DTV()                                                    \
  ({                                                                    \
    struct pthread *__self;                                             \
    asm("%O0 = tp;" : "=r" (__self));                                   \
    if(0) fprintf(stderr, "THREAD_DTV() from %p\n", __builtin_return_address(0)); \
    *(dtv_t **)__self;                                                  \
  })

#define TLS_INIT_TP(tcbp)                       \
  ({                                            \
    asm volatile("tp = %O0;" : : "r" (tcbp));                           \
    if(0) fprintf(stderr, "TLS_INIT_TP() from %p\n", __builtin_return_address(0)); \
    NULL;                                       \
  })

#define INSTALL_DTV(tcb, init_dtv)              \
  ({                                            \
    *(void **)(tcb) = init_dtv; \
    if(0) fprintf(stderr, "INSTALL_DTV() from %p\n", __builtin_return_address(0)); \
    NULL;                                       \
  })

#endif

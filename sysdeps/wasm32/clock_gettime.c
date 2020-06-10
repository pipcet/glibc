/* Get the current value of a clock.
   Copyright (C) 2015-2016 Free Software Foundation, Inc.
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

#include <time.h>
#include <errno.h>
#include "thinthin.h"

int
__clock_gettime (clockid_t clock_id, struct timespec *tp);
libc_hidden_proto (__clock_gettime)

/* Get current value of CLOCK and store it in TP.  */
int
__clock_gettime (clockid_t clock_id, struct timespec *tp)
{
  return __THINTHIN_SYSCALL (clock_gettime, clock_id, tp);
}
libc_hidden_def (__clock_gettime)
weak_alias (__clock_gettime, clock_gettime)

int
__clock_gettime64 (clockid_t clock_id, struct __timespec64 *tp);
libc_hidden_proto (__clock_gettime64)

/* Get current value of CLOCK and store it in TP.  */
int
__clock_gettime64 (clockid_t clock_id, struct __timespec64 *tp)
{
  return __THINTHIN_SYSCALL (clock_gettime, clock_id, (void *)tp);
}
libc_hidden_def (__clock_gettime64)
weak_alias (__clock_gettime64, clock_gettime64)

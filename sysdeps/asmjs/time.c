/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
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

#include <errno.h>
#include <time.h>
#include <sys/time.h>

#include "asmjs.h"

extern int __thinthin_gettimeofday(struct timeval *tv, void *tz)
  __attribute__((stackcall));

/* XXX with the default includes, gettimeofday->time->gettimeofday
 * loops endlessly */
/* Return the time now, and store it in *TIMER if not NULL.  */
time_t
time (time_t *timer)
{
  struct timeval tv;
  __thinthin_gettimeofday(&tv, NULL);

  *timer = tv.tv_sec;

  return tv.tv_sec;
}
libc_hidden_def (time)

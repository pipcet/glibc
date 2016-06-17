/* Copyright (C) 2011-2016 Free Software Foundation, Inc.
   Copyright (C) 2016 Pip Cet <pipcet@gmail.com>
   This file is NOT part of the GNU C Library.
   Based on code which was:
   Contributed by Chris Metcalf <cmetcalf@tilera.com>, 2011.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>
#include <poll.h>
#include <unistd.h>

#include "thinthin.h"

/* Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.  */

int
__poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
  struct timespec tmo;
  struct timespec *tmo_p = NULL;

  if (timeout >= 0)
    {
      tmo.tv_sec = timeout/1000;
      tmo.tv_nsec = 1000000 * (timeout%1000);
      tmo_p = &tmo;
    }
  int ret = __THINTHIN_SYSCALL(ppoll, fds, nfds, tmo_p, NULL);

  if (ret < 0)
    {
      __set_errno (-ret);

      ret = -1;
    }

  return ret;
}

libc_hidden_def (__poll)

weak_alias (__poll, poll)
weak_alias (__poll, __libc_poll)

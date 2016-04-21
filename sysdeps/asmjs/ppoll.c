/* Copyright (C) 2011-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
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

extern int __thinthin_ppoll(struct pollfd *fds, nfds_t nfds,
                            const struct timespec *, const sigset_t *)
  __attribute__((stackcall));

int
__ppoll(struct pollfd *fds, nfds_t nfds,
        const struct timespec *ts, const sigset_t *sigmask)
{
  int ret = __thinthin_ppoll(fds, nfds, ts, sigmask);

  if (ret < 0)
    {
      __set_errno (-ret);

      ret = -1;
    }

  return ret;
}

libc_hidden_def (__ppoll)

weak_alias (__ppoll, ppoll)
weak_alias (__ppoll, __libc_ppoll)

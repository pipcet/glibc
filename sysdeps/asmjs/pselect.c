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
#include <sys/poll.h>
#include <sys/select.h>
#include <errno.h>
#include <unistd.h>


extern int __thinthin_ppoll(struct pollfd *fds, nfds_t nfds,
                            const struct timespec *, const sigset_t *)
  __attribute__((stackcall));

/* Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.  */

int
__pselect(int maxfds, fd_set *readfds,
          fd_set *writefds, fd_set *exceptfds,
          const struct timespec *timeout,
          const sigset_t *sigmask)
{
  struct pollfd pfd[maxfds];
  int nfds = 0;

  for (int fd = 0; fd < maxfds; fd++) {
    if ((readfds && FD_ISSET (fd, readfds)) ||
        (writefds && FD_ISSET (fd, writefds)) ||
        (exceptfds && FD_ISSET (fd, exceptfds))) {
      pfd[nfds].fd = fd;
      pfd[nfds].events = 0;
      pfd[nfds].revents = 0;

      if (readfds && FD_ISSET (fd, readfds))
        pfd[nfds].events |= POLLIN;
      if (writefds && FD_ISSET (fd, writefds))
        pfd[nfds].events |= POLLOUT;

      nfds++;
    }
  }

  if (readfds)
    FD_ZERO (readfds);
  if (writefds)
    FD_ZERO (writefds);
  if (exceptfds)
    FD_ZERO (exceptfds);

  for (int fdi = 0; fdi < nfds; fdi++)
    {
      int fd = pfd[fdi].fd;
      short revents = pfd[fdi].revents;
      if (revents)
        {
          if (readfds && (revents & POLLIN))
            FD_SET (fd, readfds);
          if (writefds && (revents & POLLOUT))
            FD_SET (fd, writefds);
          if (exceptfds && (revents & (POLLERR|POLLHUP|POLLNVAL)))
            FD_SET (fd, exceptfds);
        }
    }

  int result;

  result = __thinthin_ppoll(pfd, nfds, timeout, sigmask);

  if (result < 0)
    {
      __set_errno(-result);

      result = -1;
    }

  return result;
}
libc_hidden_def (__pselect)

weak_alias (__pselect, pselect)
weak_alias (__pselect, __libc_pselect)

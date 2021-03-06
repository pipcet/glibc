/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
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
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>

#include "thinthin.h"

/* Perform file control operations on FD.  */
int
__libc_fcntl (int fd, int cmd, ...)
{
  if (fd < 0)
    {
      __set_errno (EBADF);
      return -1;
    }

  switch (cmd)
    {
    case F_GETFL:
    case F_GETFD:
      return __THINTHIN_SYSCALL (fcntl_v, fd, cmd);
    case F_SETFD:
    case F_DUPFD:
    case F_DUPFD_CLOEXEC:
      {
        va_list arg;
        int i;
        va_start (arg, cmd);
        i = va_arg (arg, int);
        va_end (arg);
        return __THINTHIN_SYSCALL (fcntl_i, fd, cmd, i);
      }
    case F_GETLK:
    case F_SETLK:
    case F_SETLKW:
      {
        va_list arg;
        void *p;
        va_start (arg, cmd);
        p = va_arg (arg, void *);
        va_end (arg);
        return __THINTHIN_SYSCALL (fcntl_p, fd, cmd, p);
      }
    default:
      fprintf(stderr, "unknown fcntl %08x\n", cmd);
      __set_errno (ENOSYS);
      return -1;
    }
}
libc_hidden_def (__libc_fcntl)
weak_alias (__libc_fcntl, __fcntl)
libc_hidden_weak (__fcntl)
weak_alias (__libc_fcntl, fcntl)

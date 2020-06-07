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
#include <stdarg.h>
#include <sys/ioctl.h>

#include "thinthin.h"

/* Perform the I/O control operation specified by REQUEST on FD.
   The actual type and use of ARG and the return value depend on REQUEST.  */
int
__ioctl (int fd, unsigned long int request, ...)
{
  switch (request)
    {
    case FIONREAD:
      {
        va_list arg;
        void *ptr;
        va_start (arg, request);
        ptr = va_arg (arg, void *);
        va_end (arg);
        return __THINTHIN_SYSCALL(ioctl_p, fd, request, ptr);
        break;
      }
    default:
      __set_errno (ENOSYS);
      return -1;
    }
}

weak_alias (__ioctl, ioctl)

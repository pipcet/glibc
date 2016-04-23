/* Open a file by name.
   Copyright (C) 2015-2016 Free Software Foundation, Inc.
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

#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>

#include "asmjs.h"

extern int __thinthin_openat (int fd, const char *file, int oflag, int mode)
  __attribute__((stackcall));

/* Open FILE with access OFLAG.  If OFLAG includes O_CREAT,
   a third argument is the file protection.  */
int
__libc_openat (int fd, const char *file, int oflag, ...)
{
  mode_t mode = 0;
  int ret;

  errno = 0;

  if (oflag & O_CREAT)
    {
      va_list arg;
      va_start (arg, oflag);
      mode = va_arg (arg, mode_t);
      va_end (arg);
      ret = __thinthin_openat(fd, file, oflag, mode);
    }
  else
    {
      ret = __thinthin_openat(fd, file, oflag, 0);
    }

  if (ret < 0)
    {
      __set_errno (-ret);
      return -1;
    }

  return ret;
}
libc_hidden_def (__libc_openat)
weak_alias (__libc_openat, __openat)
libc_hidden_weak (__openat)
weak_alias (__libc_openat, openat)

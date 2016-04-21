/* Read directory entries from a file descriptor.
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

#include <dirent.h>
#include <stdio.h>
#include <errno.h>

/* this probably breaks with the new varargs CC */
extern ssize_t __thinthin_getdents(int, char *, size_t)
  __attribute__((stackcall));

ssize_t
internal_function
__getdents (int fd, char *buf, size_t nbytes)
{
  ssize_t ret = __thinthin_getdents(fd, buf, nbytes);

  if (ret < 0)
    {
      __set_errno(-ret);
      return -1;
    }

  return ret;
}

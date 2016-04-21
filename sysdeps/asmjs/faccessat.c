/* Check file access permission.
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

#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#include "asmjs.h"

extern int __thinthin_faccessat(int, const char *, int, int)
  __attribute__((stackcall));

/* Test for access to FILE.  */
int
__faccessat (int fd, const char *file, int type, int flag)
{
  int ret = __thinthin_faccessat(fd, file, type, flag);

  if (ret < 0)
    {
      __set_errno(-ret);
      return -1;
    }

  return ret;
}
weak_alias (__faccessat, faccessat)

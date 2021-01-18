/* Get stat information from a file name.
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

/* Avoid the declaration so the compiler doesn't complain about the alias
   with a different type signature.  It doesn't know that 'struct stat'
   and 'struct stat64' are ABI-compatible.  */
#define __xstat64 __xstat64_avoid
#include <sys/stat.h>
#undef  __xstat64

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <fcntl.h>

#include "thinthin.h"

/* Get file information about FILE in BUF.  */
int
__xstat (int vers, const char *file, struct stat *buf)
{
  return __THINTHIN_SYSCALL (newfstatat, AT_FDCWD, file, buf, 0);
}
weak_alias (__xstat, xstat)

strong_alias (__xstat, __xstat64)
hidden_ver (__xstat, __xstat64)

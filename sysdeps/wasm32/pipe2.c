/* Copyright (C) 2011-2016 Free Software Foundation, Inc.
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

#include <errno.h>
#include <unistd.h>
#include <stddef.h>

#include "thinthin.h"

/* Create a one-way communication channel (__pipe).
   If successful, two file descriptors are stored in PIPEDES;
   bytes written on PIPEDES[1] can be read from PIPEDES[0].
   Returns 0 if successful, -1 if not.  */
int
pipe2 (int __pipedes[2], int flags)
{
  return __THINTHIN_SYSCALL(pipe2, __pipedes, flags);
}

int
__pipe2 (int __pipedes[2], int flags)
{
  return __THINTHIN_SYSCALL(pipe2, __pipedes, flags);
}

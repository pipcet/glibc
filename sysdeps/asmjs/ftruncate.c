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
#include <sys/types.h>
#include <unistd.h>

extern int __ftruncate64(int, off64_t);

/* Truncate the file referenced by FD to LENGTH bytes.  */
int
__ftruncate (int fd, off_t length)
{
  return __ftruncate64(fd, length);
}

weak_alias (__ftruncate, ftruncate)

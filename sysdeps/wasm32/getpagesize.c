/* Copyright (C) 1993-2016 Free Software Foundation, Inc.
   Copyright (C) 2016 Pip Cet <pipcet@gmail.com>
   This file is NOT part of the GNU C Library.
   Contributed by Brendan Kehoe (brendan@cygnus.com).

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

/* Return the system page size.  There's no such thing for
 * WebAssembly, but GCC uses this function to get a good chunk size
 * for its allocator, so return what x86 uses.  (WebAssembly does use
 * 64 KiB pages for some internal purposes, but we don't want to
 * expose that).  */
int
__getpagesize (void)
{
  return 4096;
}
libc_hidden_def (__getpagesize)
weak_alias (__getpagesize, getpagesize)

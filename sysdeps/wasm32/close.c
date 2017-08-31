/* Close a file descriptor.
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
#include <errno.h>

#include "thinthin.h"

/* Close the file descriptor FD.  */
int
__close (int fd)
{
  return __THINTHIN_SYSCALL(close, fd);
}
libc_hidden_def (__close)
strong_alias (__close, __libc_close)
weak_alias (__close, close)
strong_alias (__close, __close_nocancel)
libc_hidden_def (__close_nocancel)
int
__close_nostatus (int fd)
{
  return __THINTHIN_SYSCALL_NOSTATUS(close, fd);
}
libc_hidden_def (__close_nostatus)
strong_alias (__close_nostatus, __close_nocancel_nostatus)
libc_hidden_def (__close_nocancel_nostatus)

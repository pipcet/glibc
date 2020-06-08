/* lseek -- Move the file position of a file descriptor.
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

/* Seek to OFFSET on FD, starting from WHENCE.  */
off_t
__lseek (int fd, off_t offset, int whence)
{
  return __THINTHIN_SYSCALL(lseek, fd, offset, whence);
}
libc_hidden_def (__lseek)
weak_alias (__lseek, lseek)

libc_hidden_proto (__lseek64)
/* Seek to OFFSET on FD, starting from WHENCE.  */
off64_t
__lseek64 (int fd, off64_t offset, int whence)
{
  return __THINTHIN_SYSCALL(lseek, fd, offset, whence);
}
libc_hidden_def (__lseek64)
weak_alias (__lseek64, lseek64)

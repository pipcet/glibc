/* Copyright (C) 2015-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

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

#include <sys/socket.h>
#include <sysdep-cancel.h>
#include <socketcall.h>
#include <shlib-compat.h>

ssize_t
__libc_sendmsg (int fd, const struct msghdr *msg, int flags)
{
  /* POSIX specifies that both msghdr::msg_iovlen and msghdr::msg_controllen
     to be int and socklen_t respectively.  However Linux defines it as
     both size_t.  So for 64-bit it requires some adjustments by copying to
     temporary header and zeroing the pad fields.  */
#if __WORDSIZE == 64
  struct msghdr hdr;
  if (msg != NULL)
    {
      hdr = *msg;
      hdr.__glibc_reserved1 = 0;
      hdr.__glibc_reserved2 = 0;
      msg = &hdr;
    }
#endif

#ifdef __ASSUME_SENDMSG_SYSCALL
  return SYSCALL_CANCEL (sendmsg, fd, msg, flags);
#else
  return SOCKETCALL_CANCEL (sendmsg, fd, msg, flags);
#endif
}
weak_alias (__libc_sendmsg, __sendmsg)
versioned_symbol (libc, __libc_sendmsg, sendmsg, GLIBC_2_24);

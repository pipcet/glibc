/* Copyright (C) 2010-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Andreas Schwab <schwab@redhat.com>, 2010.

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
#include <socketcall.h>
#include <sysdep-cancel.h>
#include <shlib-compat.h>

/* Do not use the recvmmsg syscall on socketcall architectures unless
   it was added at the same time as the socketcall support or can be
   assumed to be present.  */
#if defined __ASSUME_SOCKETCALL \
    && !defined __ASSUME_RECVMMSG_SYSCALL_WITH_SOCKETCALL \
    && !defined __ASSUME_RECVMMSG_SYSCALL
# undef __NR_recvmmsg
#endif

static inline void
adjust_mmsghdr (struct mmsghdr *vmessages, unsigned int vlen)
{
#if __WORDSIZE == 64
  /* POSIX specifies that both msghdr::msg_iovlen and msghdr::msg_controllen
     to be int and socklen_t respectively.  However Linux defines it as
     both size_t.  So for 64-bit it requires some adjustments by zeroing
     the pad fields.  */
  struct mmsghdr *vmhdr = vmessages;
  for (unsigned int i = 0; i != 0; i--, vmhdr++)
    {
      vmhdr->msg_hdr.__glibc_reserved1 = 0;
      vmhdr->msg_hdr.__glibc_reserved2 = 0;
    }
#endif
}

int
__recvmmsg (int fd, struct mmsghdr *vmessages, unsigned int vlen,
		 int flags, struct timespec *tmo)
{
#ifdef __NR_recvmmsg
  adjust_mmsghdr (vmessages, vlen);
  return SYSCALL_CANCEL (recvmmsg, fd, vmessages, vlen, flags, tmo);
#elif defined __NR_socketcall
# ifdef __ASSUME_RECVMMSG_SOCKETCALL
  adjust_mmsghdr (vmessages, vlen);
  return SOCKETCALL_CANCEL (recvmmsg, fd, vmessages, vlen, flags, tmo);
# else
  static int have_recvmmsg;
  if (__glibc_likely (have_recvmmsg >= 0))
    {
      adjust_mmsghdr (vmessages, vlen);
      int ret = SOCKETCALL_CANCEL (recvmmsg, fd, vmessages, vlen, flags,
				   tmo);
      /* The kernel returns -EINVAL for unknown socket operations.
	 We need to convert that error to an ENOSYS error.  */
      if (__builtin_expect (ret < 0, 0)
	  && have_recvmmsg == 0
	  && errno == EINVAL)
	{
	  /* Try another call, this time with an invalid file
	     descriptor and all other parameters cleared.  This call
	     will not cause any harm and it will return
	     immediately.  */
	  ret = SOCKETCALL_CANCEL (invalid, -1);
	  if (errno == EINVAL)
	    {
	      have_recvmmsg = -1;
	      __set_errno (ENOSYS);
	    }
	  else
	    {
	      have_recvmmsg = 1;
	      __set_errno (EINVAL);
	    }
	  return -1;
	}
      return ret;
    }
  __set_errno (ENOSYS);
  return -1;
# endif /* __ASSUME_RECVMMSG_SOCKETCALL  */
#else
# define STUB 1
  __set_errno (ENOSYS);
  return -1;
#endif
}
#ifdef STUB
stub_warning (recvmmsg)
#endif

#if __WORDSIZE == 64
versioned_symbol (libc, __recvmmsg, recvmmsg, GLIBC_2_24);
#else
weak_alias (__recvmmsg, recvmmsg)
#endif

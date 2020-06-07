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
#include <signal.h>
#include <zeropage.h>

static struct sigaction __sigactions[NSIG];

static int
__sigaction_sigfpe (int sig, const struct sigaction *act,
                    struct sigaction *oact)
{
  if (act)
    __threadpage->sigfpe = (long long)(long)act->sa_handler;

  return 0;
}

static int
__sigaction_sigsegv (int sig, const struct sigaction *act,
                     struct sigaction *oact)
{
  if (act)
    __threadpage->sigsegv = (long long)(long)act->sa_handler;

  return 0;
}

/* If ACT is not NULL, change the action for SIG to *ACT.
   If OACT is not NULL, put the old action for SIG in *OACT.  */
int
__sigaction (int sig, const struct sigaction *act, struct sigaction *oact)
{
  if (sig <= 0 || sig >= NSIG)
    {
      __set_errno (EINVAL);
      return -1;
    }

  if (oact)
    *oact = __sigactions[sig];

  if (act) {
    __sigactions[sig] = *act;

    if (sig == SIGFPE)
      __sigaction_sigfpe (sig, act, oact);
    if (sig == SIGSEGV)
      __sigaction_sigsegv (sig, act, oact);
  }

  return 0;
}
libc_hidden_def (__sigaction)

weak_alias (__sigaction, sigaction)

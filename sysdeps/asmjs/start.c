/* Entry-point for programs.
   Copyright (C) 2015-2016 Free Software Foundation, Inc.
   Copyright (C) 2016 Pip Cet <pipcet@gmail.com>
   This file is NOT part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   In addition to the permissions in the GNU Lesser General Public
   License, the Free Software Foundation gives you unlimited
   permission to link the compiled version of this file with other
   programs, and to distribute those programs without any restriction
   coming from the use of this file. (The GNU Lesser General Public
   License restrictions do apply in other respects; for example, they
   cover modification of the file, and distribution when not linked
   into another program.)

   Note that people who make modified versions of this file are not
   obligated to grant this special exception for their modified
   versions; it is their choice whether to do so. The GNU Lesser
   General Public License gives permission to release a modified
   version without this exception; this exception also makes it
   possible to release a modified version which carries forward this
   exception.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <stdint.h>
#include <link.h>

/* The application defines this, of course.  */
extern int main (int argc, char **argv, char **envp);

/* These are defined in libc.  */
extern int __libc_csu_init (int argc, char **argv, char **envp);
extern void __libc_csu_fini (void);
extern int __libc_start_main (int (*main) (int, char **, char **),
                              int argc, char **argv, //ElfW(auxv_t) *auxv,
                              int (*init) (int, char **, char **),
                              void (*fini) (void),
                              void (*rtld_fini) (void),
                              void *stack_end);

void
_start (int argc, char **argv) __attribute__((stackcall));

void __attribute__((stackcall))
_start (int argc, char **argv)
{
  /* The generic code actually assumes that envp follows argv.  */

  __libc_start_main (&main,
		     argc,
		     argv,
		     //NULL,
		     &__libc_csu_init, &__libc_csu_fini,
		     NULL,
		     __builtin_frame_address (0));

  /* That should not return.  Make sure we crash if it did.  */
  while (1)
    __builtin_trap ();
}

/* Startup support for ELF initializers/finalizers in the main executable.
   Copyright (C) 2002-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

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
   <https://www.gnu.org/licenses/>.  */

#include <stddef.h>
#include <elf-initfini.h>

#include <unistd.h>

/* These magic symbols are provided by the linker.  */
extern void (*__preinit_array_start []) (int, char **, char **)
  attribute_hidden;
extern void (*__preinit_array_end []) (int, char **, char **)
  attribute_hidden;
extern void (*__init_array_start []) (int, char **, char **)
  attribute_hidden;
extern void (*__init_array_end []) (int, char **, char **)
  attribute_hidden;
extern void (*__fini_array_start []) (void) attribute_hidden;
extern void (*__fini_array_end []) (void) attribute_hidden;

#if defined(__ASMJS__) || defined(__WASM32__)
#define MULTIFILE
#endif
#ifdef MULTIFILE
struct multifile_header {
  unsigned long long data_start;
  unsigned long long terminator;
  unsigned long long preinit_array_start;
  unsigned long long preinit_array_end;
  unsigned long long init_array_start;
  unsigned long long init_array_end;
  unsigned long long fini_array_start;
  unsigned long long fini_array_end;
};

#include <thinthin.h>

void
__libc_csu_init_multifile_header (struct multifile_header *mfh,
				  int argc, char **argv, char **envp)
{
  if (mfh->terminator)
    {
      __libc_csu_init_multifile_header ((struct multifile_header *)(long)mfh->terminator, argc, argv, envp);
    }

  void (**array_start)(int, char **, char **) = (void (**)(int, char **, char **))(long)mfh->init_array_start;
  void (**array_end)(int, char **, char **) = (void (**)(int, char **, char **))(long)mfh->init_array_end;
  while (array_start < array_end)
    {
      (**array_start)(argc, argv, envp);
      array_start++;
    }
}

void
__libc_csu_preinit_multifile_header (struct multifile_header *mfh,
				     int argc, char **argv, char **envp)
{
  if (mfh->terminator)
    {
      __libc_csu_preinit_multifile_header ((struct multifile_header *)(long)mfh->terminator, argc, argv, envp);
    }

  void (**array_start)(int, char **, char **) = (void (**)(int, char **, char **))(long)mfh->preinit_array_start;
  void (**array_end)(int, char **, char **) = (void (**)(int, char **, char **))(long)mfh->preinit_array_end;
  while (array_start < array_end)
    {
      (**array_start)(argc, argv, envp);
      array_start++;
    }
}

void
__libc_csu_init_multifile (int argc, char **argv, char **envp)
{
  struct multifile_header *mfh = (struct multifile_header *)16384;

  mfh = (struct multifile_header *)16384;
  __libc_csu_preinit_multifile_header(mfh, argc, argv, envp);
  __libc_csu_init_multifile_header(mfh, argc, argv, envp);
}

void
__libc_csu_fini_multifile (void)
{
  return;
  struct multifile_header *mfh = (struct multifile_header *)16384;
  while (mfh)
    {
      void (**array_start)(void) = (void (**)(void))(long)mfh->fini_array_start;
      void (**array_end)(void) = (void (**)(void))(long)mfh->fini_array_end;
      while (array_start < array_end)
	{
	  array_end--;
	  (**array_end)();
	}
      mfh = (struct multifile_header *)(long)mfh->terminator;
    }
}
#endif

#if ELF_INITFINI
/* These function symbols are provided for the .init/.fini section entry
   points automagically by the linker.  */
extern void _init (void);
extern void _fini (void);
#endif


/* These functions are passed to __libc_start_main by the startup code.
   These get statically linked into each program.  For dynamically linked
   programs, this module will come from libc_nonshared.a and differs from
   the libc.a module in that it doesn't call the preinit array.  */


void
__libc_csu_init (int argc, char **argv, char **envp)
{
  /* For dynamically linked executables the preinit array is executed by
     the dynamic linker (before initializing any shared object).  */

#ifdef MULTIFILE
  __libc_csu_init_multifile (argc, argv, envp);
#endif
}

/* This function should not be used anymore.  We run the executable's
   destructor now just like any other.  We cannot remove the function,
   though.  */
void
__libc_csu_fini (void)
{
#ifndef LIBC_NONSHARED
#ifdef MULTIFILE
  __libc_csu_fini_multifile ();
#endif

  size_t i = __fini_array_end - __fini_array_start;
  while (i-- > 0)
    (*__fini_array_start [i]) ();

# if ELF_INITFINI
  _fini ();
# endif
#endif
}

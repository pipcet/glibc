/* Load a shared object at run time.
   Copyright (C) 1995-2021 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */

#include <dlfcn.h>
#include <libintl.h>
#include <stddef.h>
#include <unistd.h>
#include <ldsodefs.h>
#include <errno.h>
#include <stdlib.h>
#include <thinthin.h>

void *
__dlopen (const char *file, int mode DL_CALLER_DECL)
{
  struct thinthin_libinfo libinfo;
  int error = __thinthin_open_dynamic(file, NULL, &libinfo);
  if (error < 0)
    {
      errno = -error;
      return NULL;
    }
  void *mem = malloc (libinfo.data_end - libinfo.data);
  if (mem == NULL)
    {
      errno = ENOMEM;
      return NULL;
    }
  int error2 = __thinthin_load_dynamic(libinfo.modid, mem);
  if (error2 < 0)
    {
      errno = -error2;
      return NULL;
    }
  return (void *)(long)error;
}

# ifdef SHARED
#  include <shlib-compat.h>
strong_alias (__dlopen, dlopen)
# endif
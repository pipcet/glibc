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
#include <thinthin.h>

void *
__dlvsym (void *handle, const char *symbol, const char *version
	  DL_CALLER_DECL)
{
  void *ret = NULL;
  int error = __thinthin_dynamic_symbol (&ret, (long)handle, symbol, version);
  if (error)
    {
      errno = -error;
      return NULL;
    }
  return ret;
}

# ifdef SHARED
#  include <shlib-compat.h>
strong_alias (__dlvsym, dlvsym)
# endif
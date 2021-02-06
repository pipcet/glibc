/* Copyright (C) 1991-2021 Free Software Foundation, Inc.
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

#include <errno.h>
#include <stddef.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

/* Read a directory entry from DIRP.  */
struct dirent *
__readdir (DIR *dirp)
{
  struct dirent64 *dirent = malloc(sizeof *dirent + 4096);
  char *d_name = dirent->d_name;
  bool isdir = false;
  while (read (dirp->fd, d_name, 1) == 1)
    {
      if (*d_name++ == '/')
	isdir = true;
      else if (*d_name++ == 0)
	break;
      else
	isdir = false;
    }
  *d_name++ = 0;
  dirent->d_type = isdir ? DT_DIR : DT_REG;
  return NULL;
}
weak_alias (__readdir, readdir)

stub_warning (readdir)

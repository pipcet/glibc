/* Environment handling for dynamic loader.
   Copyright (C) 1995-2016 Free Software Foundation, Inc.
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

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ldsodefs.h>

/* In ld.so __environ is not exported.  */
extern char **__environ attribute_hidden;

int
unsetenv (const char *name)
{
  char **ep;

  ep = __environ;
  while (*ep != NULL)
    {
      size_t cnt = 0;

      while ((*ep)[cnt] == name[cnt] && name[cnt] != '\0')
	++cnt;

      if (name[cnt] == '\0' && (*ep)[cnt] == '=')
	{
	  /* Found it.  Remove this pointer by moving later ones to
	     the front.  */
	  char **dp = ep;

	  do
	    dp[0] = dp[1];
	  while (*dp++);
	  /* Continue the loop in case NAME appears again.  */
	}
      else
	++ep;
    }

  return 0;
}

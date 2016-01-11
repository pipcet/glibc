/* The tunable framework.  See the README to know how to use the tunable in
   a glibc module.

   Copyright (C) 2016 Free Software Foundation, Inc.
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

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/mman.h>
#include <libc-internal.h>

extern char **__environ;

#define TUNABLES_INTERNAL 1
#include "tunables.h"

#define GLIBC_TUNABLES "GLIBC_TUNABLES"

/* We avoid calling into the C library as much as we can, especially functions
   that we know could use tunables in future for some reason or the other.  For
   example, we call mmap directly instead of malloc because malloc uses
   tunables.  Similarly, the string functions may use tunables in future to
   select optimal routines and we want to make sure we stay out of the way and
   not invoke their initializers before the tunable list has been
   initialized.  */

static void
t_memcpy (char *dest, const char *src, size_t len)
{
  for (size_t i = 0; i < len; i++)
    dest[i] = src[i];
}

static int
t_strcmp (const char *a, const char *b)
{
  size_t i = 0;

  for (i = 0; *a != '\0' && *b != '\0'; i++, a++, b++)
    if (*a != *b)
      return *a - *b;

  return *a - *b;
}

static char *
t_strdup (const char *in)
{
  size_t len = 0;

  while (in[len] != '\0')
    len++;

  /* Allocate enough number of pages.  Given the number of tunables this should
     not exceed a single page but we err on the conservative side and try to
     allocate space as needed.  */
  size_t alloclen = ALIGN_UP (len + 1, __getpagesize ());

  char *out = __mmap (NULL, alloclen, PROT_READ | PROT_WRITE,
		      MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);

  if (__glibc_unlikely (out == MAP_FAILED))
    return NULL;
  else
    {
      t_memcpy (out, in, len);
      return out;
    }
}

static bool
get_next_env (char ***envp, char **name, size_t *namelen, char **val)
{
  char **ev = *envp;

  while (ev != NULL && *ev != '\0')
    {
      char *envline = *ev;
      int len = 0;

      while (envline[len] != '\0' && envline[len] != '=')
	len++;

      /* Just the name and no value, go to the next one.  */
      if (envline[len] == '\0')
	continue;

      *name = envline;
      *namelen = len;
      *val = &envline[len + 1];
      *envp = ++ev;

      return true;
    }

  return false;
}

/* Initialize tunables from the GLIBC_TUNABLES environment variable.  The
   variable is set as colon separated name=value pairs.  This routine may be
   called from the constructor of either libpthread.so or lic.so.  Constructor
   calls for libraries are protected by the dl_load_lock, so this routine won't
   be called concurrently from diferent threads.  */
void
__tunables_init (char **envp)
{
  static bool initialized = false;

  if (__glibc_likely (initialized))
    return;

  char **evp = envp;
  char *p = NULL;

  char *envname;
  size_t envnamelen;
  char *envval;

  while (get_next_env (&evp, &envname, &envnamelen, &envval))
    {
      char *name = alloca (envnamelen + 1);

      t_memcpy (name, envname, envnamelen);
      name[envnamelen] = '\0';

      if (!t_strcmp (name, GLIBC_TUNABLES))
	{
	  p = t_strdup (envval);
	  break;
	}
    }

  if (p == NULL || *p == '\0')
    goto out;

  while (true)
    {
      char *name = p;
      size_t len = 0;

      /* First, find where the name ends.  */
      while (p[len] != '=' && p[len] != '\0')
	len++;

      /* If we reach the end of the string before getting a valid name-value
	 pair, bail out.  */
      if (p[len] == '\0')
	goto out;

      p[len] = '\0';
      p += len + 1;

      char *value = p;
      len = 0;

      while (p[len] != ':' && p[len] != '\0')
	len++;

      char end = p[len];
      p[len] = '\0';

      /* Add the tunable if it exists.  */
      for (size_t i = 0; i < sizeof (tunable_list) / sizeof (tunable_t); i++)
	{
	  if (t_strcmp (name, tunable_list[i].name) == 0)
	    {
	      tunable_list[i].val = value;
	      break;
	    }
	}

      if (end == ':')
	p += len + 1;
      else
	goto out;
    }
out:
  initialized = true;
}
libc_hidden_def (__tunables_init)

/* Initialize all tunables using its legacy environment variable values whose
   names are passed in ENVVARS.  */
void
__compat_tunables_init_envvars (struct compat_tunable_env *envvars, int count)
{
  /* Traverse through the environment to find environment variables we may need
     to set.  */
  char **envp = __environ;
  char *envname = NULL;
  char *envval = NULL;
  size_t len = 0;

  while (get_next_env (&envp, &envname, &len, &envval))
    {
      int init_count = 0;
      for (int i = 0; i < count; i++)
	{
	  tunable_id_t t = envvars[i].id;
	  tunable_t *cur = &tunable_list[t];

	  /* Skip over tunables that have already been initialized.  */
	  if (cur->initialized)
	    {
	      init_count++;
	      continue;
	    }

	  const char *name = envvars[i].env;
	  char *ename = alloca (len + 1);

	  t_memcpy (ename, envname, len);
	  ename[len] = '\0';

	  /* We have a match.  Initialize and move on to the next line.  */
	  if (t_strcmp (ename, name) == 0)
	    {
	      cur->val = envval;
	      cur->set (cur->val);
	      cur->initialized = true;
	      break;
	    }
	}

      /* All of the tunable envvars have been initialized.  */
      if (count == init_count)
	break;
    }
}
libc_hidden_def (__compat_tunables_init_envvars)

/* Initialize a tunable and set its value.  */
void
__tunable_register (tunable_id_t id, tunable_setter_t set_func)
{
  tunable_t *cur = &tunable_list[id];

  cur->set = set_func;
  if (cur->val != NULL)
    {
      set_func (cur->val);
      cur->initialized = true;
    }
}
libc_hidden_def (__tunable_register)

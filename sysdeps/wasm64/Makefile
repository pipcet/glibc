# Copyright (C) 1992-2016 Free Software Foundation, Inc.
# Copyright (C) 2016 Pip Cet <pipcet@gmail.com>
# This file is NOT part of the GNU C Library.

# The GNU C Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.

# The GNU C Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with the GNU C Library; if not, see
# <http://www.gnu.org/licenses/>.

ifeq ($(subdir),string)
CFLAGS-wordcopy.c += -Wno-uninitialized
endif

ifeq ($(subdir),elf)
ifeq (yes:yes,$(build-shared):$(unwind-find-fde))
# This is needed to support g++ v2 and v3.
sysdep_routines += framestate unwind-pe
shared-only-routines += framestate unwind-pe
endif
endif

ifeq ($(subdir),csu)
sysdep_routines += start
endif

ifeq ($(subdir),misc)
sysdep_routines += thinthin errno-location
endif

ifeq ($(subdir),io)
sysdep_headers += bits/fcntl-linux.h
endif

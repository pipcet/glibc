# Makefile for support library, used only at build and test time
# Copyright (C) 2016-2017 Free Software Foundation, Inc.
# This file is part of the GNU C Library.

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

subdir := support

include ../Makeconfig

extra-libs := libsupport
extra-libs-others = $(extra-libs)
extra-libs-noinstall := $(extra-libs)

libsupport-routines = \
  check \
  check_addrinfo \
  check_dns_packet \
  check_hostent \
  check_netent \
  ignore_stderr \
  oom_error \
  set_fortify_handler \
  support-xstat \
  support_become_root \
  support_can_chroot \
  support_capture_subprocess \
  support_capture_subprocess_check \
  support_chroot \
  support_enter_network_namespace \
  support_format_address_family \
  support_format_addrinfo \
  support_format_dns_packet \
  support_format_herrno \
  support_format_hostent \
  support_format_netent \
  support_isolate_in_subprocess \
  support_record_failure \
  support_run_diff \
  support_shared_allocate \
  support_write_file_string \
  support_test_main \
  support_test_verify_impl \
  temp_file \
  write_message \
  xaccept \
  xaccept4 \
  xasprintf \
  xbind \
  xcalloc \
  xchroot \
  xclose \
  xconnect \
  xdup2 \
  xfclose \
  xfopen \
  xfork \
  xgetsockname \
  xlisten \
  xmalloc \
  xmemstream \
  xmkdir \
  xmmap \
  xmprotect \
  xmunmap \
  xopen \
  xpipe \
  xpoll \
  xrealloc \
  xrecvfrom \
  xsendto \
  xsetsockopt \
  xsocket \
  xstrdup \
  xwaitpid \
  xwrite \

libsupport-static-only-routines := $(libsupport-routines)
# Only build one variant of the library.
libsupport-inhibit-o := .os
ifeq ($(build-shared),yes)
libsupport-inhibit-o += .o
endif

tests = \
  README-testing \
  tst-support-namespace \
  tst-support_capture_subprocess \
  tst-support_format_dns_packet \
  tst-support_record_failure \

ifeq ($(run-built-tests),yes)
tests-special = \
  $(objpfx)tst-support_record_failure-2.out

$(objpfx)tst-support_record_failure-2.out: tst-support_record_failure-2.sh \
  $(objpfx)tst-support_record_failure
	$(SHELL) $< $(common-objpfx) '$(test-program-prefix-before-env)' \
	  '$(run-program-env)' '$(test-program-prefix-after-env)' \
	  > $@; \
	$(evaluate-test)
endif

$(objpfx)tst-support_format_dns_packet: $(common-objpfx)resolv/libresolv.so

include ../Rules

/* Machine-dependent ELF dynamic relocation inline functions.  Stub version.
   Copyright (C) 1995-2016 Free Software Foundation, Inc.
   Copyright (C) 2016 Pip Cet <pipcet@gmail.com>
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

#ifndef dl_machine_h
#define dl_machine_h

#define ELF_MACHINE_NAME "asmjs"

#include <string.h>
#include <link.h>


/* Return nonzero iff ELF header is compatible with the running host.  */
extern inline
__attribute__((always_inline))
int
elf_machine_matches_host (const Elf32_Ehdr *ehdr)
{
  switch (ehdr->e_machine)
    {
    default:
      return 0;
    }

  return 0;
}

/* Return the link-time address of _DYNAMIC.  */
extern inline Elf32_Addr
elf_machine_dynamic (void)
{
  return 0xdeadbeef; // XXX
}


/* Return the run-time load address of the shared object.  */
extern inline Elf32_Addr
elf_machine_load_address (void)
{
  return 0xdeadbeef; // XXX 
}

/* Fixup a PLT entry to bounce directly to the function at VALUE.  */

extern inline Elf32_Addr
elf_machine_fixup_plt (struct link_map *map, lookup_t t,
		       const Elf32_Rela *reloc,
		       Elf32_Addr *reloc_addr, Elf32_Addr value)
{
  return *reloc_addr = value;
}

/* Perform the relocation specified by RELOC and SYM (which is fully resolved).
   LOADADDR is the load address of the object; INFO is an array indexed
   by DT_* of the .dynamic section info.  */

extern inline void
__attribute__ ((always_inline))
elf_machine_rel (Elf32_Addr loadaddr, Elf32_Dyn *info[DT_NUM],
		 const Elf32_Rel *reloc, const Elf32_Sym *sym,
		 Elf32_Addr (*resolve) (const Elf32_Sym **ref,
					Elf32_Addr reloc_addr,
					int noplt))
{
  switch (ELF32_R_TYPE (reloc->r_info))
    {
    default:
      for(;;);
      break;
    }
}


extern inline Elf32_Addr
__attribute__ ((always_inline))
elf_machine_rela (struct link_map *map, const Elf32_Rela *reloc,
                  const Elf32_Sym *sym, const struct r_found_version *version,
                  void *const reloc_addr_arg, int skip_ifunc)
{
  while (1);

  return 0xdeadbeef;
}


/* Set up the loaded object described by L so its unrelocated PLT
   entries will jump to the on-demand fixup code in dl-runtime.c.  */

extern inline int
__attribute__ ((always_inline))
elf_machine_runtime_setup (struct link_map *l,
                           int lazy,
                           int consider_profile)
{
  extern void _dl_runtime_resolve (Elf32_Word);

  if (lazy)
    {
      /* The GOT entries for functions in the PLT have not yet been filled
         in.  Their initial contents will arrange when called to push an
         offset into the .rel.plt section, push _GLOBAL_OFFSET_TABLE_[1],
         and then jump to _GLOBAL_OFFSET_TABLE[2].  */
      Elf32_Addr *got = (Elf32_Addr *) D_PTR (l, l_info[DT_PLTGOT]);
      got[1] = (Elf32_Addr) l;	/* Identify this shared object.  */

      /* This function will get called to fix up the GOT entry indicated by
         the offset on the stack, and then jump to the resolved address.  */
      got[2] = (Elf32_Addr) &_dl_runtime_resolve;
    }

  return lazy;
}


/* Initial entry point code for the dynamic linker.
   The C function `_dl_start' is the real entry point;
   its return value is the user program's entry point.  */

#define RTLD_START #error need some startup code

#define ELF_MACHINE_NO_REL 1
#define ELF_MACHINE_NO_RELA 1

#define R_ASMJS_HEX16R4 3
#define ELF_MACHINE_JMP_SLOT R_ASMJS_HEX16R4

#define elf_machine_type_class(type)                            \
  (R_ASMJS_HEX16R4)

#define elf_machine_plt_value(l,reloc,value) 0xdeadbeef
#endif

#ifdef RESOLVE_MAP
auto inline void __attribute__((always_inline))
elf_machine_lazy_rel (struct link_map *map,
                      ElfW(Addr) l_addr, const ElfW(Rel) *reloc,
                      int skip_ifunc)
{
}

auto inline void __attribute__((always_inline))
elf_machine_rela_relative (ElfW(Addr) l_addr, const ElfW(Rela) *reloc,
			   void *const reloc_addr)
{
}
#endif

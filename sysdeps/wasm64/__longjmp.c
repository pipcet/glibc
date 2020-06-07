#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>


void __longjmp(__jmp_buf env, int retval)
{
  fprintf(stderr, "longjmp %lx %lx %lx\n", (long)env->__pc,
          (long)env->__fp, (long)env->__sp);

  asm volatile(".flush\n\t"
               "%S2\n\t"
               "%0\n\t"
               "i64.const 8\n\t"
               "i64.add\n\t"
               "i32.wrap_i64\n\t"
               "call[1] $i64_load\n\t"
               "%R2\n\t"
               "i64.const 16\n\t"
               "%2\n\t"
               "i64.add\n\t"
               "i32.wrap_i64\n\t"
               "%0\n\t"
               "i32.wrap_i64\n\t"
               "call[1] $i64_load\n\t"
               "call[2] $i64_store\n\t"
               "i64.const 32\n\t"
               "%2\n\t"
               "i64.add\n\t"
               "i32.wrap_i64\n\t"
               "%0\n\t"
               "i64.const 16\n\t"
               "i64.add\n\t"
               "i32.wrap_i64\n\t"
               "call[1] $i64_load\n\t"
               "i64.const 16\n\t"
               "i64.add\n\t"
               "call[2] $i64_store\n\t"
               "i32.const $rv\n\t"
               "%1\n\t"
               "call[2] $i64_store\n\t"
               "%2\n\t"
               "i64.const 3\n\t"
               "i64.or\n\t"
               "return[1]"
/*  asm volatile("foreign_abort(-1|0, HEAP32[r0>>2]|0, HEAP32[r0+4>>2]|0, HEAP32[r0+8>>2]|0, r0|0);\n\t"
               "foreign_abort(-1|0, HEAP32[HEAP32[r0+4>>2]>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+4>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+8>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+12>>2]|0);\n\t"
               ".flush\n\t"
               "foreign_abort(-1|0, 0, 0, 0, 0);\n\t"
               "foreign_abort(-1|0, HEAP32[r0>>2]|0, HEAP32[r0+4>>2]|0, HEAP32[r0+8>>2]|0, r0|0);\n\t"
               "foreign_abort(-1|0, HEAP32[HEAP32[r0+4>>2]>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+4>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+8>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+12>>2]|0);\n\t"
               "%O2 = HEAP32[%O0+4>>2]|0;\n\t"
               "HEAP32[%O2+8>>2] = HEAP32[%O0>>2]<<4;\n\t"
               "HEAP32[%O2+16>>2] = (HEAP32[%O0+8>>2]|0) + 16|0;\n\t"
               "rv = %O1;\n\t"
               "return %O2|3;\n\t" */
               : : "r" (env), "r" (retval), "r" (0));
  while (1) {}
}

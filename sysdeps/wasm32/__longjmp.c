#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>

struct __stackframe {
  long x0;  /*  0 */
  long x1;  /*  4 */
  long pc0; /*  8 */
  long x15; /* 12 */
  long dpc; /* 16 */
  long x3;  /* 20 */
  long x4;  /* 24 */
  long x5;  /* 28 */
  long sp;  /* 32 */
};

void __longjmp(__jmp_buf env, int retval)
{
  asm volatile(".flush\n\t");

  struct __stackframe *sf = (struct __stackframe *)env->__fp;

  sf->pc0 = (long)env->__pc0;
  sf->dpc = (long)env->__rpc;
  sf->sp = (long)env->__sp;

  asm volatile("i32.const 8288\n\t"
               "%1\n\t"
               "i32.store a=2 0\n\t"
               "%0\n\t"
               "i32.const 3\n\t"
               "i32.or\n\t"
               "return"
               : : "r" (env->__fp), "r" (retval));
  while (1) {}
}

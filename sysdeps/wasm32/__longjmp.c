#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>

struct __stackframe {
  long x0;
  long x1;
  long pc0;
  long x15;
  long dpc;
  long x3;
  long x4;
  long x5;
  long sp;
};

void __longjmp(__jmp_buf env, int retval)
{
  long *stack = (long *)&stack;

  asm volatile(".flush\n\t");

  struct __stackframe *sf = (struct __stackframe *)env->__fp;

  sf->pc0 = (long)env->__pc0;
  sf->dpc = (long)env->__rpc;
  sf->sp = (long)env->__sp;

  stack = (long *)&stack;

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

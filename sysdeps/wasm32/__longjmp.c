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
  fprintf(stderr, "longjmp %lx %lx %lx %lx\n", (long)env->__pc0,
          (long)env->__rpc,
          (long)env->__fp, (long)env->__sp);

  long *stack = (long *)&stack;
  int i;

  asm volatile(".flush\n\t");

  for (i=0; i < 127; i++) {
    fprintf(stderr, "%03d %p %lx\n", i, stack, *stack);
    stack++;
  }

  struct __stackframe *sf = (struct __stackframe *)env->__fp;

  sf->pc0 = (long)env->__pc0;
  sf->dpc = (long)env->__rpc;
  sf->sp = (long)env->__sp;

  stack = (long *)&stack;

  for (i=0; i < 127; i++) {
    fprintf(stderr, "%03d %p %lx\n", i, stack, *stack);
    stack++;
  }

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

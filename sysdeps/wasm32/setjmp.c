#include <setjmp.h>
#include <stdio.h>

int __sigsetjmp_fp (struct __jmp_buf_tag env[1], int __savemask,
                    void *__fp)
{
  void *pc0 = NULL;
  void *rpc = NULL;
  void *sp = NULL;

  long *stack = (long *)&stack;
  int i;

  asm volatile(".flush");
  fprintf(stderr, "%p\n", __fp);
  for (i = 0; i < 100; i++) {
    fprintf(stderr, "%03d %p %lx\n", i, stack, *stack);
    stack++;
  }

  asm volatile("%S0\n\t.flush\n\t%1\n\ti32.const 8\n\ti32.add\n\ti32.load a=2 0\n\t%R0" : "=r" (pc0) : "r" (__fp));
  asm volatile("%S0\n\tget_local $rpc\n\t%R0" : "=r" (rpc));
  asm volatile("%S0\n\tget_local $fp\n\ti32.const %/\n\ti32.add\n\t%R0"
               : "=r" (sp));

  env->__jmpbuf->__pc0 = rpc;
  env->__jmpbuf->__rpc = rpc;
  env->__jmpbuf->__fp = __fp;
  env->__jmpbuf->__sp = sp;

  return 0;
}

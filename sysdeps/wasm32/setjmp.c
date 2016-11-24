#include <setjmp.h>
#include <stdio.h>

int __sigsetjmp_fp (struct __jmp_buf_tag env[1], int __savemask,
                    void *__fp)
{
  void *rpc = NULL;
  void *sp = NULL;

  asm volatile("%S0\n\tget_local $rpc\n\t%R0" : "=r" (rpc));
  asm volatile("%S0\n\tget_local $fp\n\ti64.const %/\n\ti64.add\n\t%R0"
               : "=r" (sp));

  env->__jmpbuf->__pc = rpc;
  env->__jmpbuf->__fp = __fp;
  env->__jmpbuf->__sp = sp;

  return 0;
}

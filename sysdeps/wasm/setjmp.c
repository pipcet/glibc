#include <setjmp.h>
#include <stdio.h>

int __sigsetjmp_fp (struct __jmp_buf_tag env[1], int __savemask,
                    void *__fp)
{
  void *rpc = NULL;
  void *sp = NULL;

/*   asm volatile("%O0 = rpc|0;" : "=r" (rpc));
  asm volatile("%O0 = fp+%/|0;" : "=r" (sp)); */

  env->__jmpbuf->__pc = rpc;
  env->__jmpbuf->__fp = __fp;
  env->__jmpbuf->__sp = sp;

  return 0;
}

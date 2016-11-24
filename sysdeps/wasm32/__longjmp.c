#include <unistd.h>
#include <setjmp.h>
#include <stdio.h>


void __longjmp(__jmp_buf env, int retval)
{
  fprintf(stderr, "longjmp %lx %lx %lx\n", (long)env->__pc,
          (long)env->__fp, (long)env->__sp);

  while (1) {}
}

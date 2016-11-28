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

int __sigsetjmp (jmp_buf env, int savemask)
{
  /* TODO get rid of this .flush. */
  asm volatile(".flush");

  fprintf(stderr, "env %p\n", env);

  void *x;

  asm volatile("%S0\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "%R0\n\t"
               : "=r" (x));


  fprintf(stderr, "x0 %p\n", x);

  x = (void *)*(void **)x;
  x = (void *)*(void **)x;

  fprintf(stderr, "x1 %p\n", x);

  fprintf(stderr, "pc0 %p\n", *(void **)(x+8));
  fprintf(stderr, "dpc %p\n", *(void **)(x+12));

  asm volatile(
               //"get_local $sp1\n\t"
               //"i32.const -16\n\t"
               //"i32.add\n\t"
               //"i32.load a=2 0\n\t"
               //"i32.load a=2 0\n\t"
               //"i32.load a=2 8\n\t"
               //"get_local $rpc\n\t"
               //"i32.store a=2 0\n\t"

               "%1\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 8\n\t"
               "i32.store a=2 0\n\t"

               "%1\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 16\n\t"
               "i32.store a=2 4\n\t"

               "%1\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "i32.store a=2 8\n\t"

               "%1\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.store a=2 12\n\t"

               "i32.const 0\n\t"
               "set_local $r1\n\t"
               ".dpc .LI7\n\t"
               "set_local $dpc\n\t"
               "i32.const 0\n\t"
               "get_local $sp\n\t"
               "%1\n\t"
               "get_local $r1\n\t"
               "get_local $rpc\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "i32.load a=2 0\n\t"
               "i32.load a=2 0\n\t"
               "call __sigjmp_save\n\t"
               "set_local $rp\n\t"
               "i32.const 3\n\t"
               "get_local $rp\n\t"
               "i32.and\n\t"
               "if[]\n\t"
               "throw1\n\t"
               "end\n\t"
               ".wasmtextlabeldpcdef .LI7\n\t"
               : : "r" (0), "r" (env));
  return 0;
}

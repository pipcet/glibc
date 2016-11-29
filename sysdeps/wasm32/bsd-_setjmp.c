#include <stdio.h>

int _setjmp(void *env)
{
  asm volatile(".flush");

  void *x;

  asm volatile("%S0\n\t"
               "get_local $sp1\n\t"
               "i32.const -16\n\t"
               "i32.add\n\t"
               "%R0\n\t"
               : "=r" (x));


  x = (void *)*(void **)x;
  x = (void *)*(void **)x;

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
               "i32.const -1\n\t"
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

int __longjmp(void *env, int retval)
{
  asm volatile("foreign_abort(-1|0, HEAP32[r0>>2]|0, HEAP32[r0+4>>2]|0, HEAP32[r0+8>>2]|0, r0|0);\n\t"
               "foreign_abort(-1|0, HEAP32[HEAP32[r0+4>>2]>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+4>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+8>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+12>>2]|0);\n\t"
               ".flush\n\t"
               "foreign_abort(-1|0, 0, 0, 0, 0);\n\t"
               "foreign_abort(-1|0, HEAP32[r0>>2]|0, HEAP32[r0+4>>2]|0, HEAP32[r0+8>>2]|0, r0|0);\n\t"
               "foreign_abort(-1|0, HEAP32[HEAP32[r0+4>>2]>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+4>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+8>>2]|0, HEAP32[(HEAP32[r0+4>>2]|0)+12>>2]|0);\n\t"
               "%O2 = HEAP32[%O0+4>>2]|0;\n\t"
               "HEAP32[%O2+8>>2] = HEAP32[%O0>>2]<<4;\n\t"
               "HEAP32[%O2+16>>2] = (HEAP32[%O0+8>>2]|0) + 16|0;\n\t"
               "rv = %O1;\n\t"
               "return %O2|3;\n\t"
               : : "r" (env), "r" (retval), "r" (0));
  while(1) {}
}

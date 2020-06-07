struct __zeropage {
  unsigned long long top_of_memory;
  unsigned long long top_of_sbrk;
  unsigned long long thread_list;
  unsigned long long bottom_of_sbrk;
};

struct __threadpage {
  unsigned long long next;
  unsigned long long prev;
  unsigned long long id;
  unsigned long long bottom_of_stack;
  unsigned long long top_of_stack;
  unsigned long long stop_reason;
  unsigned long long pc;
  unsigned long long sp;
  unsigned long long initsp;
  unsigned long long rv;
  unsigned long long a0;
  unsigned long long a1;
  unsigned long long a2;
  unsigned long long a3;
  unsigned long long tp;
  unsigned long long lp;
  unsigned long long lazyload;
  unsigned long long sigfpe;
  unsigned long long sigsegv;
};

#define __threadpage ((struct __threadpage *)(3 * 4096))

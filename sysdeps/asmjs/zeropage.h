struct __zeropage {
  unsigned long long top_of_memory;
  unsigned long long top_of_sbrk;
  unsigned long long thread_list;
  unsigned long long bottom_of_sbrk;
};

struct __threadpage {
  unsigned long long next_threadpage;
  unsigned long long prev_threadpage;
  unsigned long long bottom_of_stack;
  unsigned long long top_of_stack;
  unsigned long long thread_id;
};

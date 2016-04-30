#define INTERNAL_SYSCALL_ERRNO(rvar)            \
  (-(rvar))

#define INTERNAL_SYSCALL_ERROR_P(rvar)                          \
  ((unsigned long long)(rvar) >= (unsigned long long)-4095LL)

#define __THINTHIN_SYSCALL(name, args...)                               \
  ({                                                                    \
    unsigned long long resultvar = __thinthin_ ## name(args);            \
    if (__glibc_unlikely (INTERNAL_SYSCALL_ERROR_P (resultvar)))        \
      {                                                                 \
        __set_errno (INTERNAL_SYSCALL_ERRNO (resultvar));               \
        resultvar = (unsigned long long)-1;                             \
      }                                                                 \
                                                                        \
    (long long)resultvar;                                               \
  })

extern int __thinthin_access(const char *, int)
  __attribute__((stackcall));
extern int __thinthin_execve(const char *, char *const *, char *const *)
  __attribute__((stackcall));
extern int __thinthin_brk(void *)
  __attribute__((stackcall));
extern int __thinthin_chdir(const char *)
  __attribute__((stackcall));
extern int __thinthin_close(int)
  __attribute__((stackcall));
extern int __thinthin_exit(int)
  __attribute__((stackcall));
extern int __thinthin_faccessat(int, const char *, int, int)
  __attribute__((stackcall));

extern int __thinthin_fcntl_v(int, int)
  __attribute__((stackcall));
extern int __thinthin_fcntl_i(int, int, int)
  __attribute__((stackcall));
extern int __thinthin_fcntl_p(int, int, void *)
  __attribute__((stackcall));

extern int __thinthin_fork(void)
  __attribute__((stackcall));
extern int __thinthin_ftruncate(int, int)
  __attribute__((stackcall));


extern int __thinthin_getcwd(char *, int)
  __attribute__((stackcall));
/* this probably breaks with the new varargs CC */
extern ssize_t __thinthin_getdents(int, char *, size_t)
  __attribute__((stackcall));
extern int __thinthin_gethostname(char *, int)
  __attribute__((stackcall));
struct timeval;
struct timezone;
extern int __thinthin_gettimeofday(struct timeval *, struct timezone *)
  __attribute__((stackcall));

extern ssize_t __thinthin_write(int, const void *, size_t)
  __attribute__((stackcall));
extern int __thinthin_ioctl_p (int, unsigned long, void *)
  __attribute__((stackcall));

extern int __thinthin_isatty(int)
  __attribute__((stackcall));

extern int __thinthin_linkat(int, const char *, int, const char *, int)
  __attribute__((stackcall));

extern int __thinthin_lseek (int, int, int)
  __attribute__((stackcall));

extern int __thinthin_fchmodat(int, const char *, int, int)
  __attribute__((stackcall));

struct rusage;
extern int __thinthin_wait4(int, int *, int, struct rusage *)
  __attribute__((stackcall));

struct stat;
extern int __thinthin_stat (const char *file, struct stat *buf)
  __attribute__((stackcall));
extern int __thinthin_fstat (int fd, struct stat *buf)
  __attribute__((stackcall));

extern int __thinthin_unlinkat(int dirfd, const char *path, int)
  __attribute__((stackcall));

struct pollfd;
extern int __thinthin_ppoll(struct pollfd *fds, int nfds,
                            const void *, const void *)
  __attribute__((stackcall));

extern int __thinthin_openat (int fd, const char *file, int oflag, int mode)
  __attribute__((stackcall));

extern int __thinthin_openat (int fd, const char *file, int oflag, int mode)
  __attribute__((stackcall));

extern int __thinthin_pipe2(int *__pipedes, int flags)
  __attribute__ ((stackcall));

extern int __thinthin_read (int, void *, int)
  __attribute__((stackcall));

extern int __thinthin_renameat2 (int, const char *, int, const char *, int)
  __attribute__((stackcall));

extern int __thinthin_mkdirat (int, const char *, int)
  __attribute__((stackcall));

extern int __thinthin_readlinkat (int, const char *, char *, int)
  __attribute__((stackcall));

struct timespec;
extern int __thinthin_utimensat(int, const char *, const struct timespec *,
                                int)
  __attribute__((stackcall));

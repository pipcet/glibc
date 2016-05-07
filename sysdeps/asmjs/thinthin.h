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

#define __AS __attribute__((stackcall))

struct pollfd;
struct rusage;
struct stat;
struct timespec;
struct timeval;
struct timezone;

extern int __thinthin_access(const char *, int) __AS;
extern int __thinthin_brk(void *) __AS;
extern int __thinthin_chdir(const char *) __AS;
extern int __thinthin_clock_gettime(int, struct timespec *) __AS;
extern int __thinthin_close(int) __AS;
extern int __thinthin_dup2(int, int) __AS;
extern int __thinthin_execve(const char *, char *const *, char *const *) __AS;
extern int __thinthin_exit(int) __AS;
extern int __thinthin_faccessat(int, const char *, int, int) __AS;
extern int __thinthin_fchmodat(int, const char *, int, int) __AS;
extern int __thinthin_fcntl_i(int, int, int) __AS;
extern int __thinthin_fcntl_p(int, int, void *) __AS;
extern int __thinthin_fcntl_v(int, int) __AS;
extern int __thinthin_fork(void) __AS;
extern int __thinthin_ftruncate(int, int) __AS;
extern int __thinthin_getcwd(char *, int) __AS;
extern int __thinthin_getdents(int, char *, int) __AS;
extern int __thinthin_getegid(void) __AS;
extern int __thinthin_geteuid(void) __AS;
extern int __thinthin_getgid(void) __AS;
extern int __thinthin_gethostname(char *, int) __AS;
extern int __thinthin_gettimeofday(struct timeval *, struct timezone *) __AS;
extern int __thinthin_getuid(void) __AS;
extern int __thinthin_ioctl_p (int, unsigned long, void *) __AS;
extern int __thinthin_isatty(int) __AS;
extern int __thinthin_linkat(int, const char *, int, const char *, int) __AS;
extern int __thinthin_lseek (int, int, int) __AS;
extern int __thinthin_mkdirat (int, const char *, int) __AS;
extern int __thinthin_newfstatat (int, const char *, struct stat *, int) __AS;
extern int __thinthin_openat (int, const char *, int, int) __AS;
extern int __thinthin_openat (int, const char *, int, int) __AS;
extern int __thinthin_pipe2(int *, int flags) __AS;
extern int __thinthin_ppoll(struct pollfd *, int, const void *, const void *) __AS;
extern int __thinthin_read (int, void *, int) __AS;
extern int __thinthin_readlinkat (int, const char *, char *, int) __AS;
extern int __thinthin_renameat2 (int, const char *, int, const char *, int) __AS;
extern int __thinthin_unlinkat(int dirfd, const char *path, int) __AS;
extern int __thinthin_utimensat(int, const char *, const struct timespec *, int) __AS;
extern int __thinthin_wait4(int, int *, int, struct rusage *) __AS;
extern int __thinthin_write(int, const void *, int) __AS;

#undef __AS

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

extern long __thinthin_access(const char *, long) __AS;
extern long __thinthin_brk(void *) __AS;
extern long __thinthin_chdir(const char *) __AS;
extern long __thinthin_clock_gettime(long, struct timespec *) __AS;
extern long __thinthin_close(long) __AS;
extern long __thinthin_dup2(long, long) __AS;
extern long __thinthin_execve(const char *, char *const *, char *const *) __AS;
extern long __thinthin_exit(long) __AS;
extern long __thinthin_faccessat(long, const char *, long, long) __AS;
extern long __thinthin_fchmod(long, long) __AS;
extern long __thinthin_fchmodat(long, const char *, long, long) __AS;
extern long __thinthin_fcntl_i(long, long, long) __AS;
extern long __thinthin_fcntl_p(long, long, void *) __AS;
extern long __thinthin_fcntl_v(long, long) __AS;
extern long __thinthin_fork(void) __AS;
extern long __thinthin_ftruncate(long, long) __AS;
extern long __thinthin_getcwd(char *, long) __AS;
extern long __thinthin_getdents(long, char *, long) __AS;
extern long __thinthin_getegid(void) __AS;
extern long __thinthin_geteuid(void) __AS;
extern long __thinthin_getgid(void) __AS;
extern long __thinthin_gethostname(char *, long) __AS;
extern long __thinthin_getpid(void) __AS;
extern long __thinthin_gettimeofday(struct timeval *, struct timezone *) __AS;
extern long __thinthin_getuid(void) __AS;
extern long __thinthin_ioctl_p (long, unsigned long, void *) __AS;
extern long __thinthin_isatty(long) __AS;
extern long __thinthin_linkat(long, const char *, long, const char *, long) __AS;
extern long __thinthin_lseek (long, long, long) __AS;
extern long __thinthin_mkdirat (long, const char *, long) __AS;
extern long __thinthin_newfstatat (long, const char *, struct stat *, long) __AS;
extern long __thinthin_openat (long, const char *, long, long) __AS;
extern long __thinthin_openat (long, const char *, long, long) __AS;
extern long __thinthin_pipe2(int *, long flags) __AS;
extern long __thinthin_ppoll(struct pollfd *, long, const void *, const void *) __AS;
extern long __thinthin_read (long, void *, long) __AS;
extern long __thinthin_readlinkat (long, const char *, char *, long) __AS;
extern long __thinthin_renameat2 (long, const char *, long, const char *, long) __AS;
extern long __thinthin_unlinkat(long dirfd, const char *path, long) __AS;
extern long __thinthin_utimensat(long, const char *, const struct timespec *, long) __AS;
extern long __thinthin_wait4(long, int *, long, struct rusage *) __AS;
extern long __thinthin_write(long, const void *, long) __AS;

#undef __AS

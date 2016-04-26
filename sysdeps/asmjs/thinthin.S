    .set __gcc_bogotics_backwards, 0
    .set __gcc_pc_update, 0
    .set __asmjs_fallthrough, 1
    .include "asmjs-macros.s"
    .include "import-macros.s"

    .import3 thinthin,write,__thinthin_write
    .import3 thinthin,malloc,__thinthin_malloc
    .import3 thinthin,abort,__thinthin_abort
    .import3 thinthin,exit,__thinthin_exit
    .import3 thinthin,open,__thinthin_open
    .import3 thinthin,openat,__thinthin_openat
    .import3 thinthin,read,__thinthin_read
    .import3 thinthin,chdir,__thinthin_chdir
    .import3 thinthin,access,__thinthin_access
    .import3 thinthin,stat,__thinthin_stat
    .import3 thinthin,time,__thinthin_time
    .import3 thinthin,close,__thinthin_close
    .import3 thinthin,fstat,__thinthin_fstat
    .import3 thinthin,readdir,__thinthin_readdir
    .import3 thinthin,fdopen,__thinthin_fdopen
    .import3 thinthin,fclose,__thinthin_fclose
    .import3 thinthin,unlink,__thinthin_unlink
    .import3 thinthin,rename,__thinthin_rename
    .import3 thinthin,lseek,__thinthin_lseek
    .import3 thinthin,getdents,__thinthin_getdents
    .import3 thinthin,gettimeofday,__thinthin_gettimeofday
    .import3 thinthin,gethostname,__thinthin_gethostname
    .import3 thinthin,faccessat,__thinthin_faccessat
    .import3 thinthin,isatty,__thinthin_isatty
    .import3 thinthin,ppoll,__thinthin_ppoll
    .import3 thinthin,ioctl_p,__thinthin_ioctl_p
    .import3 thinthin,sbrk,__thinthin_sbrk
    .import3 thinthin,brk,__thinthin_brk
    .import3 thinthin,getcwd,__thinthin_getcwd
    .import3 thinthin,fcntl_v,__thinthin_fcntl_v
    .import3 thinthin,fcntl_i,__thinthin_fcntl_i
    .import3 thinthin,truncate,__thinthin_truncate
    .import3 thinthin,ftruncate,__thinthin_ftruncate

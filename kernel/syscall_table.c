/* The file syscall_table.c is auto generated. DO NOT EDIT, CHANGES WILL BE LOST. */
/* If you want to add syscalls, use syscall_table_gen.py  */

#include "frosted.h"
#include "syscall_table.h"
/* Syscall: setclock(1 arguments) */
int sys_setclock(uint32_t arg1){
    syscall(SYS_SETCLOCK, arg1, 0, 0, 0, 0); 
}

/* Syscall: sleep(1 arguments) */
int sys_sleep(uint32_t arg1){
    syscall(SYS_SLEEP, arg1, 0, 0, 0, 0); 
}

/* Syscall: suspend(1 arguments) */
int sys_suspend(uint32_t arg1){
    syscall(SYS_SUSPEND, arg1, 0, 0, 0, 0); 
}

/* Syscall: thread_create(3 arguments) */
int sys_thread_create(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    syscall(SYS_THREAD_CREATE, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: test(5 arguments) */
int sys_test(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5){
    syscall(SYS_TEST, arg1, arg2, arg3, arg4, arg5); 
}

/* Syscall: getpid(0 arguments) */
int sys_getpid(void){
    syscall(SYS_GETPID, 0, 0, 0, 0, 0); 
}

/* Syscall: getppid(0 arguments) */
int sys_getppid(void){
    syscall(SYS_GETPPID, 0, 0, 0, 0, 0); 
}

/* Syscall: open(2 arguments) */
int sys_open(uint32_t arg1, uint32_t arg2){
    syscall(SYS_OPEN, arg1, arg2, 0, 0, 0); 
}

/* Syscall: close(1 arguments) */
int sys_close(uint32_t arg1){
    syscall(SYS_CLOSE, arg1, 0, 0, 0, 0); 
}

/* Syscall: read(3 arguments) */
int sys_read(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    syscall(SYS_READ, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: write(3 arguments) */
int sys_write(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    syscall(SYS_WRITE, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: seek(3 arguments) */
int sys_seek(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    syscall(SYS_SEEK, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: mkdir(1 arguments) */
int sys_mkdir(uint32_t arg1){
    syscall(SYS_MKDIR, arg1, 0, 0, 0, 0); 
}

/* Syscall: unlink(1 arguments) */
int sys_unlink(uint32_t arg1){
    syscall(SYS_UNLINK, arg1, 0, 0, 0, 0); 
}

/* Syscall: gettimeofday(1 arguments) */
int sys_gettimeofday(uint32_t arg1){
    syscall(SYS_GETTIMEOFDAY, arg1, 0, 0, 0, 0); 
}

/* Syscall: malloc(1 arguments) */
int sys_malloc(uint32_t arg1){
    syscall(SYS_MALLOC, arg1, 0, 0, 0, 0); 
}

/* Syscall: free(1 arguments) */
int sys_free(uint32_t arg1){
    syscall(SYS_FREE, arg1, 0, 0, 0, 0); 
}

/* Syscall: calloc(2 arguments) */
int sys_calloc(uint32_t arg1, uint32_t arg2){
    syscall(SYS_CALLOC, arg1, arg2, 0, 0, 0); 
}

/* Syscall: realloc(2 arguments) */
int sys_realloc(uint32_t arg1, uint32_t arg2){
    syscall(SYS_REALLOC, arg1, arg2, 0, 0, 0); 
}

/* Syscall: opendir(1 arguments) */
int sys_opendir(uint32_t arg1){
    syscall(SYS_OPENDIR, arg1, 0, 0, 0, 0); 
}

/* Syscall: readdir(2 arguments) */
int sys_readdir(uint32_t arg1, uint32_t arg2){
    syscall(SYS_READDIR, arg1, arg2, 0, 0, 0); 
}

/* Syscall: closedir(1 arguments) */
int sys_closedir(uint32_t arg1){
    syscall(SYS_CLOSEDIR, arg1, 0, 0, 0, 0); 
}

/* Syscall: stat(2 arguments) */
int sys_stat(uint32_t arg1, uint32_t arg2){
    syscall(SYS_STAT, arg1, arg2, 0, 0, 0); 
}

/* Syscall: poll(3 arguments) */
int sys_poll(uint32_t arg1, uint32_t arg2, uint32_t arg3){
    syscall(SYS_POLL, arg1, arg2, arg3, 0,  0); 
}

/* Syscall: chdir(1 arguments) */
int sys_chdir(uint32_t arg1){
    syscall(SYS_CHDIR, arg1, 0, 0, 0, 0); 
}

/* Syscall: getcwd(2 arguments) */
int sys_getcwd(uint32_t arg1, uint32_t arg2){
    syscall(SYS_GETCWD, arg1, arg2, 0, 0, 0); 
}

/* External handlers (defined elsewhere) : */ 
extern int sys_setclock_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_sleep_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_suspend_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_thread_create_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_test_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_getpid_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_getppid_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_open_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_close_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_read_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_write_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_seek_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_mkdir_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_unlink_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_gettimeofday_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_malloc_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_free_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_calloc_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_realloc_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_opendir_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_readdir_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_closedir_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_stat_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_poll_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_chdir_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern int sys_getcwd_hdlr(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

void syscalls_init(void) {
	sys_register_handler(0, sys_setclock_hdlr);
	sys_register_handler(1, sys_sleep_hdlr);
	sys_register_handler(2, sys_suspend_hdlr);
	sys_register_handler(3, sys_thread_create_hdlr);
	sys_register_handler(4, sys_test_hdlr);
	sys_register_handler(5, sys_getpid_hdlr);
	sys_register_handler(6, sys_getppid_hdlr);
	sys_register_handler(7, sys_open_hdlr);
	sys_register_handler(8, sys_close_hdlr);
	sys_register_handler(9, sys_read_hdlr);
	sys_register_handler(10, sys_write_hdlr);
	sys_register_handler(11, sys_seek_hdlr);
	sys_register_handler(12, sys_mkdir_hdlr);
	sys_register_handler(13, sys_unlink_hdlr);
	sys_register_handler(14, sys_gettimeofday_hdlr);
	sys_register_handler(15, sys_malloc_hdlr);
	sys_register_handler(16, sys_free_hdlr);
	sys_register_handler(17, sys_calloc_hdlr);
	sys_register_handler(18, sys_realloc_hdlr);
	sys_register_handler(19, sys_opendir_hdlr);
	sys_register_handler(20, sys_readdir_hdlr);
	sys_register_handler(21, sys_closedir_hdlr);
	sys_register_handler(22, sys_stat_hdlr);
	sys_register_handler(23, sys_poll_hdlr);
	sys_register_handler(24, sys_chdir_hdlr);
	sys_register_handler(25, sys_getcwd_hdlr);
}
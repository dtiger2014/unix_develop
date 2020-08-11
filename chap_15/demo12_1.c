/*
图15-33 在父进程、子进程之间使用/dev/zero的存储映射I/O的IPC

匿名存储映射

注: 
在Linux中，MAP_ANONYMOUS ：匿名映射，映射区不与任何文件关联
MAP_ANON：MAP_ANONYMOUS的别称，不再被使用
*/
#include "../utils/myhead.h"
#include <fcntl.h>
#include <sys/mman.h>

#define NLOOPS 1000
#define SIZE sizeof(long) /* size of shared memory area */

static int update(long *ptr)
{
    return ((*ptr)++); /* return value before increment */
}

int main(void)
{
    int i, counter;
    pid_t pid;
    void *area;

    if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE,
                     MAP_ANONYMOUS | MAP_SHARED, -1, 0)) == MAP_FAILED)
        err_sys("mmap error");

    TELL_WAIT();

    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid > 0) /* parent */
    {
        for (i = 0; i < NLOOPS; i += 2)
        {
            if ((counter = update((long *)area)) != i)
                err_quit("parent: expected %d, got %d", i, counter);

            TELL_CHILD(pid);
            WAIT_CHILD();
        }
    }
    else /* child */
    {
        for (i = 1; i < NLOOPS + 1; i += 2)
        {
            WAIT_PARENT();

            if ((counter = update((long *)area)) != i)
                err_quit("child: expected %d, got %d", i, counter);

            TELL_PARENT(getppid());
        }
    }
    exit(0);
}
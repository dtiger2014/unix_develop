/*
图14-7 死锁检测实例
TODO: 编译失败
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include "demo2.c"
#include "tell_wait.c"

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

static void lockabyte(const char *name, int fd, off_t offset)
{
    if (writew_lock(fd, offset, SEEK_SET, 1) < 0)
    {
        printf("%s: ", name);
        perror("writew_lock error");
        exit(1);
    }
    printf("%s: got the lock, byte %lld\n", name, (long long)offset);
}

int main(void)
{
    int fd;
    pid_t pid;

    /*
    Create a file and write two bytes to it.
    */
    if ((fd = create("templock", FILE_MODE)) < 0)
    {
        perror("create error");
        exit(1);
    }
    if (write(fd, "ab", 2) != 2)
    {
        perror("write error");
        exit(1);
    }

    TELL_WAIT();
    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0) /* child */
    {
        lockabyte("child", fd, 0);
        TELL_PARENT(getppid());
        WAIT_PARENT();
        lockabyte("child", fd, 1);
    }
    else /* parent */
    {
        lockabyte("parent", fd, 1);
        TELL_CHILD(pid);
        WAIT_CHILD();
        lockabyte("parent", fd, 0);
    }
    exit(0);
}
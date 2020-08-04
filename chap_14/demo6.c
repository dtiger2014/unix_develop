/*
图14-12 确定是否支持强制性锁
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "tell_wait.c"
#include "demo2.c"

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) // 644

void set_fl(int fd, int flags)                            /* flags are file status flags to turn on */
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
        perror("fcntl F_GETFL error");
        exit(1);
    }

    val |= flags; /* turn on flags */

    if (fcntl(fd, F_SETFL, val) < 0)
    {
        perror("fcntl F_SETFL error");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    int fd;
    pid_t pid;
    char buf[5];
    struct stat statbuf;

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
    {
        perror("open error");
        exit(1);
    }
    if (write(fd, "abcdef", 6) != 6)
    {
        perror("write error");
        exit(1);
    }

    /* turn on set-group-ID and trun off group-execute */
    if (fstat(fd, &statbuf) < 0)
    {
        perror("fstat error");
        exit(1);
    }
    if (fchmod(fd, (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    {
        perror("fchmod error");
        exit(1);
    }

    TELL_WAIT();

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if (pid > 0) /* parent */
    {
        /* write lock entire file */
        if (write_lock(fd, 0, SEEK_SET, 0) < 0)
        {
            perror("write_lock error");
            exit(1);
        }

        TELL_CHILD(pid);

        if (waitpid(pid, NULL, 0) < 0)
        {
            perror("waitpid error");
            exit(1);
        }
    }
    else /* child */
    {
        WAIT_PARENT(); /* wait for parent to set lock */

        set_fl(fd, O_NONBLOCK);

        /* first let's see what error we get if region is locked */
        if (read_lock(fd, 0, SEEK_SET, 0) != -1) /* no wait */
        {
            perror("child: read_lock successed");
            exit(1);
        }
        printf("read_lock of already-locked region returns %d\n", errno);

        /* now try to read the mandatory locked file */
        if (lseek(fd, 0, SEEK_SET) == -1)
        {
            perror("lseek error");
            exit(1);
        }
        if (read(fd, buf, 2) < 0)
        {
            perror("read failed (mandatory locking works)");
            exit(1);
        }
        else
        {
            printf("read OK (no mandatory locking), buf = %2.2s\n", buf);
        }
    }
    exit(0);
}
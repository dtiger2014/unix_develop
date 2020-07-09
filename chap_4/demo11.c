/*
使用带O_TRUNC选项的open函数将文件长度截断为0，但并不更改访问时间及修改时间
1. stat
2. futimens
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];

    for (i = 1; i < argc; i++)
    {
        if (stat(argv[i], &statbuf) < 0)
        { /* fetch current times */
            printf("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)
        { /* truncate */
            printf("%s: open error", argv[i]);
            continue;
        }

        /*
        struct timespec {
            time_t  tv_sec;	
            long tv_nsec;
        };
        注：不能直接把 st_atime 赋值给 timespec
        */
        times[0].tv_sec = statbuf.st_atime;
        times[0].tv_nsec = 0;
        times[1].tv_sec = statbuf.st_mtime;
        times[1].tv_nsec = 0;
        if (futimens(fd, times) < 0) /* reset times */
            printf("%s: futimens error", argv[i]);
        close(fd);
    }
}
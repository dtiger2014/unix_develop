#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 定义RWRWRW ：创建的文件为 666
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main()
{
    umask(0); // 没有umask 000
    if (creat("foo", RWRWRW) < 0) // 创建后 文件为 666 ： 666-000 = 666
    {
        printf("creat error for foo\n");
        exit(EXIT_FAILURE);
    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); // umask 为 066
    // umask(0266); // 文件为 400
    if (creat("bar", RWRWRW) < 0)   // 创建后 文件为 600 ： 666-066 = 600
    {
        printf("creat error for bar");
        exit(EXIT_FAILURE);
    }
}
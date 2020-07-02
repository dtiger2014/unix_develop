/*
lseek
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
// #include <fcntl.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <stdlib.h>
// #include <dirent.h>

/*
 * Default file access permissions for new files.
 */
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void func1()
{
    off_t currpos;
    currpos = lseek(STDIN_FILENO, 0, SEEK_CUR);
    printf("current pos : %d\n", currpos);
    if (currpos == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
}

// 创建一个具有空洞的文件，使用lseek 设置偏移量
// 查看有空洞的文件可以使用od 命令
// $ od -c file.hole
void func2()
{
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int fd;

    fd = creat("file.hole", FILE_MODE);
    if (fd < 0)
    {
        perror("create error");
        exit(EXIT_FAILURE);
    }

    if (write(fd, buf1, 10) != 10)
    {
        perror("buf write error");
        exit(EXIT_FAILURE);
    }
    // offset now = 10
    if (lseek(fd, 16384, SEEK_SET) == -1)
    {
        perror("lseek error");
        exit(EXIT_FAILURE);
    }

    if (write(fd, buf2, 10) != 10) {
        perror("buf2 write error");
        exit(EXIT_FAILURE);
    }
    // offset now = 16394

    return;
}

int main()
{
    // func1();

    func2();

    return 0;
}
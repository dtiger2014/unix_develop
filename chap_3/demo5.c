/*
ssize_t pread(int fd, void *buf, size_t count, off_t offset);

ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);
*/

#include "utils/myhead.h"
#include <fcntl.h>

void pread_test()
{
    int fd = open("test/test_file.txt", O_RDONLY);
    if (fd < 0)
        err_sys("open failed");

    char buf[1024] = {0};
    int offset = 5;
    ssize_t ret = 0;
    int count = 10;

    // pread
    if ((ret = pread(fd, buf, count, offset)) == -1)
        err_sys("pread failed");

    printf("%s\n", buf);
}

void pwrite_test()
{
    int fd = open("test/test_file.txt", O_RDWR);
    if (fd < 0)
    {
        printf("fd:%d\n", fd);
        err_sys("open failed");
    }

    char buf[4096] = "fanfan 111";
    int offset = 6;
    ssize_t ret;
    int count = 10;

    ret = pwrite(fd, buf, count, offset);
    printf("ret : %d\n", ret);

    if (ret == -1)
        err_sys("pwrite failed");
}

int main()
{
    pread_test();

    pwrite_test();

    return 0;
}

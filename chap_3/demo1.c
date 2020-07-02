/*
open()
openat()
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

extern int errno;

void create_at(char *dir_path, char *relative_path)
{
    int dir_fd;
    int fd;
    int flags;
    mode_t mode;

    // fd参数时通过打开相对路径名所在的目录来获取
    dir_fd = open(dir_path, O_RDONLY);
    printf("dir_fd : %d\n", dir_fd);
    if (dir_fd < 0)
    {
        perror("open error");
        fprintf(stderr, " : %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    flags = O_CREAT | O_TRUNC | O_RDWR;
    mode = 0640; // -rw-r-----
    fd = openat(dir_fd, relative_path, flags, mode);
    printf("fd : %d\n", fd);
    if (fd < 0)
    {
        perror("openat file error");
        fprintf(stderr, ": %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    write(fd, "HELLO FanFan\n", 13);

    close(fd);
    close(dir_fd);
}

// 借用dirfd，将DIR*转换成int类型的文件描述符
void func1()
{
    DIR *dir;
    int dirfd2;
    int fd;
    int n;

    dir = opendir("./test");
    if (dir == NULL)
    {
        perror("open dir error");
        fprintf(stderr, ": %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    dirfd2 = dirfd(dir);
    if (dirfd2 == 2)
    {
        perror("dirfd error");
        fprintf(stderr, ": %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fd = openat(dirfd2, "output.log", O_CREAT | O_RDWR | O_TRUNC,
                S_IRWXU | S_IRWXG | S_IRWXO);
    if (fd == -1)
    {
        perror("openat file error");
        fprintf(stderr, ": %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    n = write(fd, "Hello world!\n", 13);

    printf("wirte n : %d\n", n);

    close(fd);
    closedir(dir);

    return;
}

int main()
{
    // create_at("./test", "test_file.txt");

    func1();
    return 0;
}
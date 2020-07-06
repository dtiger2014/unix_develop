#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // dup
    // int fd = open("hello", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    // if (fd < 0)
    // {
    //     printf("Open Error!!\n");
    //     return EXIT_FAILURE;
    // }

    // int nfd = dup(fd);
    // if (nfd < 0)
    // {
    //     printf("Error!!\n");
    //     return EXIT_FAILURE;
    // }

    // char buf[1000];
    // int n;

    // while ((n = read(STDIN_FILENO, buf, 1000)) > 0)
    // {
    //     if (write(nfd, buf, n) != n)
    //     {
    //         printf("Write Error");
    //     }
    // }

    // return EXIT_SUCCESS;

    // dup2
    int fd = open("hello.file", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    printf("fd:%d\n", fd);
    if (fd < 0)
    {
        printf("Open Error!! fd:%d\n", fd);
        return EXIT_FAILURE;
    }

    int nfd = dup2(fd, STDOUT_FILENO);
    if (nfd < 0)
    {
        printf("Error!!\n");
        return EXIT_FAILURE;
    }

    printf("aaa nfd %d\n", nfd);

    char buf[5];
    int n;

    while ((n = read(STDIN_FILENO, buf, 5)) > 0)
    {
        printf("printf buf:%s\n", buf);
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("Write Error!! n:%d\n", n);
            return EXIT_FAILURE;
        }
    }

    return 0;
}
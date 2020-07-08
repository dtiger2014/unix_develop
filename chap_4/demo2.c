#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("usage: a.out <pathname>");
        return EXIT_FAILURE;
    }

    if (access(argv[1], R_OK) < 0)
    {
        printf("access error for %s", argv[1]);
        return EXIT_FAILURE;
    }
    else
    {
        printf("read access OK \n");
    }

    if (open(argv[1], O_RDONLY) < 0)
    {
        printf("open error for %s", argv[1]);
        return EXIT_FAILURE;
    }
    else
    {
        printf("open for reading OK\n");
    }

    exit(EXIT_SUCCESS);
}
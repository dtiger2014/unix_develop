#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    if (open("tempfile", O_RDWR) < 0)
    {
        perror("open error");
        exit(EXIT_FAILURE);
    }
    if (unlink("tempfile") < 0)
    {
        perror("unlink error");
        exit(EXIT_FAILURE);
    }
    printf("file unlinked\n");

    sleep(15);
    printf("done\n");
    exit(EXIT_SUCCESS);
}
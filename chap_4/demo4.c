#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    struct stat statbuf;

    /* turn on set-group-ID and turn off group-execute */

    if (stat("foo", &statbuf) < 0)
    {
        printf("stat error for foo");
        exit(EXIT_FAILURE);
    }
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    {
        printf("chmod error for foo");
        exit(EXIT_FAILURE);
    }

    /* set absolute mode to "rw-r--r--" */

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    {
        printf("chmod error for bar");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
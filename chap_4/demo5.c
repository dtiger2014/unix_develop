#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main()
{
    int n;

    n = chown("foo", 0, 0);
    int errnum;
    if (n < 0)
    {
        errnum = errno;
        fprintf(stderr, "errno :%d, chown error：%s\n", errnum, strerror(errnum));
    }

    exit(EXIT_SUCCESS);
}
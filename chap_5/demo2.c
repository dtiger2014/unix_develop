#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 4096

int main(void)
{
    char buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL)
        if (fputs(buf, stdout) == EOF)
            perror("output error\n");

    if (ferror(stdin))
        perror("input error\n");

    if (feof(stdin))
        perror("EOF! error\n");

    exit(EXIT_SUCCESS);
}
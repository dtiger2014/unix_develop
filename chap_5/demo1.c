#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
        {
            perror("output error");
            // exit(EXIT_FAILURE);
        }

    if (ferror(stdin))
        perror("input error");

    if (feof(stdin))
        perror("EOF!! error\n");

    exit(EXIT_SUCCESS);
}
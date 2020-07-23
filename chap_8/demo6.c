/*
带有竞争条件的程序
*/

#include <stdio.h>
#include <stdlib.h>

static void charatatime(char *);

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
    }
    exit(EXIT_SUCCESS);
}

static void charatatime(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL); /* set unbuffered */
    for (ptr = str; (c = *ptr++) != 0;)
        putc(c, stdout);
}
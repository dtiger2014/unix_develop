/*
fork 函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globvar = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void)
{
    int var; /* automatic variable on the stack */
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    {
        perror("write error");
        exit(EXIT_FAILURE);
    }    
    printf("before fork\n"); /* we don't flush stdout */

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) /* child */
    {
        printf("This is child === \n");
        globvar++; /* modify variables */
        var++;
    }
    else
    {
        sleep(2); /* parent */
        printf("This is parent === \n");
    }

    printf("pid=%ld, glob=%d, var=%d, ppid=%ld\n\n",
           (long)getpid(), globvar, var, (long)getppid());
    exit(EXIT_SUCCESS);
}
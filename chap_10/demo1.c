/*
捕捉SIGUSR1和SIGUSR2的程序
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sig_usr(int); /* one handler for both signals */

int main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        perror("can't catch SIGUSR1");
        exit(1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        perror("can't catch SIGUSR2");
        exit(1);
    }
    for (;;)
        pause();

    exit(0);
}

static void sig_usr(int signo) /* argument is signal number */
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        printf("received signal %d\n", signo);
}
/*
用sigsuspend等待一个全局变量被设置
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t quitflag; /* set nonzero by signal handler */

static void sig_int(int signo) /* one signal handler for SIGINT and SIGQUIT */
{
    if (signo == SIGINT)
        printf("\ninterrupt\n");
    else if (signo == SIGQUIT)
        quitflag = 1; /* set flag for main loop */
}

int main(void)
{
    sigset_t newmask, oldmask, zeromask;

    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        perror("signal(SIGINT) error");
        exit(1);
    }
    if (signal(SIGQUIT, sig_int) == SIG_ERR)
    {
        perror("signal(SIGQUIT) error");
        exit(1);
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);

    /*
    Block SIGQUIT and save current signal mask.
    */
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
        perror("SIG_BLOCK error");
        exit(1);
    }

    while (quitflag == 0)
        sigsuspend(&zeromask);

    /*
    SIGQUIT has been caught and is now blocked; do whatever
    */
    quitflag = 0;

    /*
    Reset signal mask which unblocks SIGQUIT
    */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    {
        perror("SIG_SETMASK error");
        exit(1);
    }
    exit(0);
}
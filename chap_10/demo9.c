/*
信号设置和sigprocmask实例
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sig_quit(int);

int main(void)
{
    sigset_t newmask, oldmask, pendmask;

    if (signal(SIGQUIT, sig_quit) == SIG_ERR)
    {
        perror("can't catch SIGQUIT");
        exit(1);
    }

    /*
    Block SIGQUIT and save current signal mask.
    */
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
        perror("SIG_BLOCK error");
        exit(1);
    }

    sleep(5); /* SIGQUIT here will remain pending */

    if (sigpending(&pendmask) < 0)
    {
        perror("sigpending error");
        exit(1);
    }
    if (sigismember(&pendmask, SIGQUIT))
        printf("\nSIGQUIT pending\n");

    /*
    Restore signal mask which unblocks SIGQUIT
    */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    {
        perror("SIG_SETMASK error");
        exit(1);
    }
    printf("SIGQUIT unblocked\n");

    sleep(5); /* SIGQUIT here will terminate with core file */
    exit(0);
}

static void sig_quit(int signo)
{
    printf("caught SIGQUIT\n");
    if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
    {
        perror("can't reset SIGQUIT");
        exit(1);
    }
}
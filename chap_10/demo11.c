/*
信号屏蔽、sigsetjmp和siglongjmp实例

如果使用setjmp，longjmp。意味着调用setjmp之后执行main函数时，其SIGUSR1是阻塞的
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>

static void sig_usr1(int);
static void sig_alrm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

void pr_mask(const char *str)
{
    sigset_t sigset;
    int errno_save;

    errno_save = errno; /* we can be called by signal handlers */

    if (sigprocmask(0, NULL, &sigset) < 0)
    {
        perror("sigprocmask error");
        exit(1);
    }
    else
    {
        printf("%s", str);
        if (sigismember(&sigset, SIGINT))
            printf(" SIGINT");
        if (sigismember(&sigset, SIGQUIT))
            printf(" SIGQUIT");
        if (sigismember(&sigset, SIGUSR1))
            printf(" SIGUSR1");
        if (sigismember(&sigset, SIGALRM))
            printf(" SIGALRM");

        /* remaining signals can go here */

        printf("\n");
    }

    errno = errno_save; /* restore errno */
}

int main(void)
{
    if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
    {
        perror("signal(SIGUSR1) error");
        exit(1);
    }
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
    {
        perror("signal(SIGALRM) error");
        exit(1);
    }

    pr_mask("starting main: ");

    if (sigsetjmp(jmpbuf, 1))
    {
        pr_mask("ending main: ");
        exit(0);
    }

    canjump = 1; /* now sigsetjmp() is OK */

    for (;;)
        pause();
}

static void sig_usr1(int signo)
{
    time_t starttime;

    if (canjump == 0)
        return; /* unexpected signal, ignore */

    pr_mask("starting sig_usr1: ");

    alarm(3); /* SIGALRM in 3 seconds */
    starttime = time(NULL);
    for (;;) /* busy wait for 5 seconds */
        if (time(NULL) > starttime + 5)
            break;

    pr_mask("finishing sig_usr1: ");

    canjump = 0;
    siglongjmp(jmpbuf, 1); /* jump back to main don't return */
}

static void sig_alrm(int signo)
{
    pr_mask("in sig_alrm: ");
}
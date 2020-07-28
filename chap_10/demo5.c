/*
在一个捕捉其他信号的程序中调用sleep2

sleep2函数所引起的longjmp使另一个信号处理程序sig_int提早终止，即使它未完成也会如此

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

unsigned int sleep2(unsigned int);
static void sig_int(int);
static jmp_buf env_alrm;

int main(void)
{
    unsigned int unslept;

    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        perror("signal(SIGINT) error");
        exit(1);
    }
    unslept = sleep2(5);
    printf("sleep2 returned: %u\n", unslept);
    exit(0);
}

static void sig_int(int signo)
{
    int i, j;
    volatile int k;

    /*
    Tune these loops to run for more than 5 seconds
    on whatever system this test program is run.
    */
    printf("\nsig_int starting\n");
    for (i = 0; i < 300000; i++)
        for (j = 0; i < 4000; j++)
            k += i * j;
    printf("sig_int finished\n");
}

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int seconds)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return (seconds);

    if (setjmp(env_alrm) == 0)
    {
        alarm(seconds); /* start the timer */
        pause();        /* next caught signal wakes us up */
    }

    return (alarm(0)); /* turn off timer, return unslept time */
}
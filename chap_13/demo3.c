/*
图13-7 守护进程重读配置文件
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <syslog.h>
#include <signal.h>
#include "demo2.c"
#include <string.h>

sigset_t mask;

extern int already_running(void);

void reread(void)
{
    /* ... */
}

void *thr_fn(void *arg)
{
    int err, signo;

    for (;;)
    {
        err = sigwait(&mask, &signo);
        if (err != 0)
        {
            syslog(LOG_ERR, "sigwait failed");
            exit(1);
        }

        switch (signo)
        {
        case SIGHUP:
            syslog(LOG_INFO, "Re-reading configuration file");
            reread();
            break;

        case SIGTERM:
            syslog(LOG_INFO, "got SIGTERM; exiting");
            exit(0);

        default:
            syslog(LOG_INFO, "unexpected signal %d\n", signo);
        }
    }
    return (0);
}

int main(int argc, char *argv[])
{
    int err;
    pthread_t tid;
    char *cmd;
    struct sigaction sa;

    if ((cmd = strchar(argv[0], '/')) == NULL)
        cmd = argv[0];
    else
        cmd++;

    /*
    Become a daemon.
    */
    daemonize(cmd);

    /*
    Make sure only one copy of the daemon is running.
    */
    if (already_running())
    {
        syslog(LOG_ERR, "daemon already running");
        exit(1);
    }

    /*
    Restore SIGHUP default and block all signals.
    */
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0)
    {
        perror("can't restore SIGHUP default");
        exit(1);
    }
    sigfillset(&mask);
    if ((err = pthread_sigmask(SIG_BLOCK, &mask, NULL)) != 0)
    {
        printf("err:%d\n", err);
        perror("SIG_BLOCK error");
        exit(1);
    }

    /*
    Create a thread to handler SIGHUP and SIGTERM
    */
    err = pthread_create(&tid, NULL, thr_fn, 0);
    if (err != 0)
    {
        printf("err:%d\n", err);
        perror("can't create thread");
        exit(1);
    }

    /*
    Proceed with the reset of the daemon
    */
    /* ... */
    exit(0);
}
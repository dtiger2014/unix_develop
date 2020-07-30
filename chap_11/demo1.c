/*
图11-2 打印线程ID

注意：编译时, 添加 -lpthread
$ gcc -lpthread demo1.c

问题原因：
   pthread 库不是 Linux 系统默认的库，连接时需要使用静态库 libpthread.a，
   所以在使用pthread_create()创建线程，以及调用 pthread_atfork()函数
   建立fork处理程序时，需要链接该库。
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
           (unsigned long)tid, (unsigned long)tid);
}

void *thr_fn(void *arg)
{
    printids("neew thread: ");
    return ((void *)0);
}

int main(void)
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
    {
        printf("err : %d\n", err);
        perror("can't create thread");
        exit(1);
    }
    printids("main thread: ");
    sleep(1);
    exit(0);
}
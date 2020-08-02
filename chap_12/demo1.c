/*
图 12-4 以分离状态创建线程
*/

#include <pthread.h>

int makethread(void *(*fn)(void *), void *arg)
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;

    err = phtread_attr_init(&attr);
    if (err != 0)
        return (err);

    // PTHREAD_CREATE_DETACHED 分离模式
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err == 0)
        err = pthread_create(&tid, &attr, fn, arg);
    pthread_attr_destroy(&attr);
    return (err);
}
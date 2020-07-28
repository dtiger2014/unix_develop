/*
在信号处理程序中调用不可再入函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pwd.h>

static void my_alarm(int signo)
{
    struct passwd *rootptr;

    printf("in signal handler \n");
    if ((rootptr = getpwnam("root")) == NULL)
    {
        perror("getpwnam(root) error");
        exit(1);
    }
    alarm(1);
}

int main(void)
{
    struct passwd *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for (;;)
    {
        if ((ptr = getpwnam("sar")) == NULL)
        {
            perror("getpwnam 111 error");
            exit(1);
        }
        if (strcmp(ptr->pw_name, "sar") != 0)
            printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
    }
}
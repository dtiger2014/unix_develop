/*
exec函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) /* specify pathname, specify environment */
    {
        if (execle("/home/sar/bin/echoall", "echoall", "myarg1", "MY ARG2",
                   (char *)0, env_init) < 0)
        {
            perror("execle error");
            exit(EXIT_FAILURE);
        }
    }

    if (waitpid(pid, NULL, 0) < 0)
    {
        perror("wait error");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) < 0)
    {
        perror("wait errpr");
    }
    else if (pid == 0) /* specify filename, inherit environment */
    {
        if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
        {
            perror("execlp error");
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}
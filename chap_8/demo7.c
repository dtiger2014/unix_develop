/*
exec函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

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
        if (execle("/root/linux/unix_develop/chap_8/test1", "test1", "myarg1", "MY ARG2",
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
        if (execlp("test1", "test", "only 1 arg", (char *)0) < 0)
        {
            perror("execlp error");
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}
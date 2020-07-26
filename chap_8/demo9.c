/*
解释器文件
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) /* child */
    {
        if (execl("/root/linux/unix_develop/chap_8/test1", "myarg1", "myarg2", "myarg3", (char *)0) < 0)
        {
            perror("execl error");
            exit(EXIT_FAILURE);
        }
    }

    if (waitpid(pid, NULL, 0) < 0) /* parent */
    {
        perror("waitpid error");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
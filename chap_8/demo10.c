/*
 system函数（没有对信号进行处理）
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int system(const char *cmdstring) /* version without signal handling */
{
    pid_t pid;
    int status;

    if (cmdstring == NULL)
        return (1); /* always a command processor with UNIX */

    if ((pid = fork()) < 0)
    {
        status = -1; /* probably out of processes */
    }
    else if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127); /* execl error */
    }
    else
    {
        while (waitpid(pid, &status, 0) < 0)
        {
            if (errno != EINTR)
            {
                status = -1; /* error other than EINTR from waitpid() */
                break;
            }
        }
    }

    return (status);
}

int main(void)
{
    int status;

    if ((status = system("date")) < 0)
    {
        perror("system() error, date");
        exit(EXIT_FAILURE);
    }

    pr_exit(status);

    if ((status = system("nosuchcommand")) < 0)
    {
        perror("system() error, nosuchcommand");
        exit(EXIT_FAILURE);
    }

    pr_exit(status);

    if ((status = system("who; exit 44")) < 0)
    {
        perror("system(), error, who; exit 44");
        exit(EXIT_FAILURE);
    }

    pr_exit(status);

    exit(EXIT_SUCCESS);
}
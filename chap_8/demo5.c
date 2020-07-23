/*
父进程可能要用紫禁城ID更新日志文件中的一个记录

TELLWAIT
TELL_PARENT
TELL_CHILD
WAIT_PARENT
WAIT_CHILD
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    TELL_WAIT(); /* set things up for TELL_xxx WAIT_xxx */
    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) /* child */
    {
        /* child does whatever is necessary ... */
        TELL_PARENT(getppid());                  /* tell parent we're done */
        WAIT_PARENT(); /* and wait for parent */ /* and the child continues on its way ... */
        exit(0);
    }

    /* parent does whatever is necessary ... */
    TELL_CHILD(pid); /* tell child we're done */
    WAIT_CHILD();    /* and wait for child */
    /* and the parent continues on its way ... */
    exit(0);
}
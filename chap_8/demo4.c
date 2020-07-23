/*
调用两次fork，避免紫禁城处于僵死
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) /* first child */
    {
        if ((pid = fork()) < 0)
        {
            perror("fork error second");
            exit(EXIT_FAILURE);
        }
        else if (pid > 0)
            exit(EXIT_SUCCESS); /* parent from second fork == first child */

        /*
        We're the second child; our parent becomes init as soon
        as our real parent calls exit() in the statement above.
        Here's where we'd continue executing, knowing that when
        we're done, init will reap our status.
        */
        // sleep(1);
        printf("second child, parant pid = %ld, pid=%ld\n", (long)getppid(), (long)getpid());
        exit(EXIT_SUCCESS);
    }

    if (waitpid(pid, NULL, 0) != pid) /* wait for first child */
    {
        perror("waitpid error");
        exit(EXIT_FAILURE);
    }

    /*
    We're the parent (the original process); we continue executing,
    Knowing that we're not the parent of the second child.
    */
    printf("parent finish. pid = %ld, child pid =%ld\n", (long)getpid(), pid);
    exit(0);
}
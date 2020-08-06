/*
图15-19 将两个数相加的过滤程序，使用标准I/O

原先程序不生效，问题：在默认的标准I/O缓冲机制上
*/

#include "../utils/myhead.h"

int main(void)
{
    int int1, int2;
    char line[MAXLINE];

    // 解决
    if (setvbuf(stdin, NULL, _IOLBF, 0) != 0)
        err_sys("setvbuf error");
    if (setvbuf(stdout, NULL, _IOLBF, 0) != 0)
        err_sys("setvbuf error");

    while (fgets(line, MAXLINE, stdin) != NULL)
    {
        if (sscanf(line, "%d%d", &int1, &int2) == 2)
        {
            if (printf("%d\n", int1 + int2) == EOF)
                err_sys("printf error");
        }
        else
        {
            if (printf("invalid args\n") == EOF)
                err_sys("printf error");
        }
    }
    exit(0);
}
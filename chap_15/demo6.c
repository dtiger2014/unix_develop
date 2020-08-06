/*
图15-14 将大写字符变换成小写字符的过滤程序
*/

#include "../utils/myhead.h"
#include <ctype.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if ((isupper(c)))
            c = tolower(c);
        if (putchar(c) == EOF)
            err_sys("output error");
        if (c == '\n')
            fflush(stdout);
    }
    exit(0);
}
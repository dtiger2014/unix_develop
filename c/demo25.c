/*
错误处理：errno.h

- errno, error(), strerror()
    - perror() 函数显示您传给它的字符串，后跟一个冒号、
        一个空格和当前 errno 值的文本表示形式
    - strerror() 函数，返回一个指针，指针指向当前 errno 值的文本表示形式

- 被零除的错误

- 程序退出状态
    - exit() // 程序退出
    - EXIT_FAILURE : 1
    - EXIT_SUCCESS : 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern int errno;

void func1()
{
    fprintf(stdout, "错误号：%d\n", errno);

    FILE *pf;
    int errnum;
    pf = fopen("unexist.txt", "rb");
    if (pf == NULL)
    {
        errnum = errno;
        fprintf(stderr, "错误号：%d\n", errno);
        perror("通过 perror 输出错误");
        fprintf(stderr, "打开文件错误：%s\n", strerror(errnum));
    }
    else
    {
        fclose(pf);
    }
}

// 被零除的错误
void func2()
{
    int dividend = 20;
    int divisor = 10;
    int quotient;

    if (divisor == 0)
    {
        fprintf(stderr, "除数为0 退出运行...\n");
        exit(EXIT_FAILURE);
    }

    quotient = dividend / divisor;
    fprintf(stdout, "quotient 变量的值为：%d\n", quotient);

    exit(EXIT_SUCCESS);
}

int main()
{
    // func1();

    func2();

    printf("结束了吗？\n");

    return 0;
}
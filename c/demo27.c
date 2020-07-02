/*
可变参数

*/

#include <stdio.h>
#include <stdarg.h>

double average(int num, ...)
{
    va_list valist;
    double sum = 0.0;
    int i;

    // 为 num 个参数初始化 valist
    va_start(valist, num);

    int tmp = 0;
    // 访问所有赋给valist 的参数
    for (i = 0; i < num; i++)
    {
        tmp = va_arg(valist, int);
        printf("print valist : %d, ptr = %p\n", tmp, &tmp);
        sum += tmp;
    }

    // 清理为valist保留的内存
    va_end(valist);

    return sum / num;
}

int main()
{
    // average(4,2,3,4,5) 第一个4是参数个数
    printf("Average of 2,3,4,5 = %f\n", average(4, 2, 3, 4, 5));

    printf("Average of 5, 10, 15 =%f\n", average(3, 5, 10, 15));

    return 0;
}
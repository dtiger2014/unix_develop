/*
递归

*/
#include <stdio.h>

// 数的阶乘
double factorial(unsigned int i)
{
    if (i <= 1)
        return 1;
    return i * factorial(i - 1);
}

// 斐波纳挈数列
int fibonaci(int i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    return fibonaci(i - 1) + fibonaci(i - 2);
}

int main()
{
    int i = 15;
    printf("%d 的阶乘为 %f\n", i, factorial(i));

    // 斐波那契
    for (i = 0; i < 10; i++)
        printf("%d\t\n", fibonaci(i));

    return 0;
}
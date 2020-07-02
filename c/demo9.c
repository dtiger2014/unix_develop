/*
函数

- 参数：
    - 传值调用
    - 引用调用
*/

#include <stdio.h>

int max(int num1, int num2);

void swap1(int x, int y);
void swap2(int *x, int *y);

int main()
{
    int a = 100;
    int b = 200;
    int ret;

    ret = max(a, b);

    printf("Max value is :%d\n", ret);

    printf("a: %d, *a: %x\n", a, &a);
    printf("Swap1 === \n");
    swap1(a, b);
    printf("a : %d, b : %d\n", a, b);

    printf("Swap2 === \n");
    swap2(&a, &b);
    printf("a : %d, b : %d\n", a, b);

    return 0;
}

void swap1(int x, int y)
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;

    return;
}

void swap2(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;

    return;
}
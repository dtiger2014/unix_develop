/*
数组

- 多维数组
    type name[size1][siez2]...[sizeN];
- 传递数组给函数
    - 指针：void myFunction(int *param)
    - 定义大小的数组：void myFunction(int param[10])
    - 未定义大小的数组：void myFunction(int param[])
- 从函数返回数组
    - 通过指定不带索引的数组名来返回一个指向数组的指针
- 指向数组的指针
    - 数组名是一个指向数组中第一个元素的常量指针
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getAverage(int arr[], int size);

int *getRandom();

int main()
{
    int n[10]; // 包含10个int 数组

    int i, j;

    for (i = 0; i < 10; i++)
        n[i] = i + 100;

    for (j = 0; j < 10; j++)
        printf("Element[%d] = %d\n", j, n[j]);

    // 传递数组给函数
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    avg = getAverage(balance, 5);

    printf("平均值是：%f\n", avg);

    // 从函数返回数组
    int *p; // 一个指向整数的指针

    p = getRandom(); // 获取 下标0 的指针地址
    for (i = 0; i < 11; i++)
        printf("*(p + %d) : %d\n", i, *(p + i));

    // 指向数组的指针
    double balance1[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p1;

    p1 = balance1; // p1赋值为balace1的第一个元素的地址

    printf("使用指针的数组值\n");
    for (i = 0; i < 5; i++)
        printf("*(p + %d) : %f\n", i, *(p1 + i));

    printf("使用balance作为地址的数组值\n");
    for (i = 0; i < 5; i++)
        printf("*(balance + %d) : %15f, p_addr=%d\n", i, *(balance1 + i), (balance1 + i));

    return 0;
}

double getAverage(int arr[], int size)
{
    int i;
    double avg;
    double sum = 0;

    for (i = 0; i < size; i++)
        sum += arr[i];

    avg = sum / size;

    return avg;
}

int *getRandom()
{
    static int r[10];
    int i;

    // 设置种子
    srand((unsigned)time(NULL));

    for (i = 0; i < 10; i++)
    {
        r[i] = rand();
        printf("r[%d] = %d\n", i, r[i]);
    }
    return r;
    // 返回的是 当前数组的指针位置，
    // 因为数组是连续的空间，可以根据 p + i的形式 获取元素
}
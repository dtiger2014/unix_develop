/*
变量： type variable_list;

extern int i; //声明，不是定义
int i; //声明，也是定义
*/

#include <stdio.h>

int x;
int y;
int addtwonum()
{
    extern int x; // 这个是外部的变量，不是function的
    extern int y;

    x = 1; // 外部的 变量 x 赋值了
    y = 3;

    return x + y;
}

int main()
{
    int result;

    result = addtwonum();

    printf("result 为:%d \n", result);

    return 0;
}
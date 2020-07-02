#include <stdio.h>

// 定义两个全局变量
int x = 1;
int y = 2;
int addtwonum();

int main()
{
    int result;
    result = addtwonum();
    printf("result 为: %d \n", result);
    return 0;
}

/*
编译时：
$ gcc demo3_1.c demo3_2.c
$ gcc demo3_*.c
*/
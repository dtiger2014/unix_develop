/*
条件判断

- if 语句
- if...else 语句
- if...else if...else if...else
- 嵌套 if 语句
- switch 语句
- 嵌套 switch 语句
- ?:运算符（三元运算符）
*/

#include <stdio.h>

int main()
{
    // if
    int a = 10;

    if (a < 20)
    {
        printf("a 小于 20\n");
    }
    else
    {
        printf("a 大于等于 20 \n");
    }

    // switch
    int a1;
    printf("请输入a：");
    scanf("%d", &a1);       // scanf 输入需要注意类型

    printf("输入的a是 %d\n", a1);
    switch (a1)
    {
    case 1:
        printf("a 是 1\n");
    case 2:
        printf("a 是 2\n");
        break;
    case 3:
        printf("a 是 3\n");
        break;
    default:
        printf("a 是 什么？？\n");
        break;
    }

    return 0;
}
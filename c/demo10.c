/*
作用域规则

- 局部变量：函数或块内变量
- 全局变量：在所有函数外部的全局变量
- 形式参数：函数的参数，形式参数，
    被当作该函数内的局部变量，如果与全局变量同名它们会优先使用

- 初始化局部变量和全局变量
    - 当局部变量被定义时，系统不会对其初始化，您必须自行对其初始化。
        定义全局变量时，系统会自动对其初始化
    数据类型 | 初始化默认值
    ---|---
    int | 0
    char | '\0'
    float | 0
    double | 0
    pointer | NULL
*/

#include <stdio.h>

int a = 20; // 全局变量

int main()
{
    // 在main中声明局部变量
    int a = 10;
    int b = 20;
    int c = 0;
    int sum(int, int);

    printf("value of a in main() = %d\n", a);
    c = sum(a, b);
    printf("value of c in main() = %d\n", c);

    return 0;
}

int sum(int a, int b)
{
    printf("value of a in sum() = %d\n", a);
    printf("value of b in sum() = %d\n", b);

    return a + b;
}
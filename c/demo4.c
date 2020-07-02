/*
常量

- 转义符
\\	        \ 字符
\'	        ' 字符
\"	        " 字符
\?	        ? 字符
\a	        警报铃声
\b	        退格键
\f	        换页符
\n	        换行符
\r	        回车
\t	        水平制表符
\v	        垂直制表符
\ooo	    一到三位的八进制数
\xhh...	    一个或多个数字的十六进制数

- 常量定义：
    - #define 预处理器
    - const 关键字
    - 区别：#define是宏定义，不能定义常量，但宏定义可以实现在字面
        意义上和其它定义常量相同的功能，本质的区别就在于#define不为
        宏名分配内存，而const也不为常量分配内存，其实const并不是去定义
        一个常量，而是去改变一个变量的存储类型，把该变量所占的内存变为只读
*/

#include <stdio.h>

#define LENGTH 10
#define WIDTH  5
#define NEWLINE '\n'

int main()
{
    printf("Hello\tWorld\n\n");

    // 常量 #define
    int area;
    
    area = LENGTH * WIDTH;
    printf("value of area: %d", area);
    printf("%c", NEWLINE);

    // 常量 const
    const int LENGTH1 = 20;
    const int WIDTH1  = 5;
    const char NEWLINE1 = '\n';

    int area1;
    area1 = LENGTH1 * WIDTH1;
    printf("value of area1 : %d", area1);
    printf("%c", NEWLINE1);

    return 0;
}
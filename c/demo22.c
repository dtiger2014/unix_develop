/*
预处理器

指令 | 描述
---|---
#define	    | 定义宏
#include	| 包含一个源代码文件
#undef	    | 取消已定义的宏
#ifdef	    | 如果宏已经定义，则返回真
#ifndef	    | 如果宏没有定义，则返回真
#if	        | 如果给定条件为真，则编译下面代码
#else	    | #if 的替代方案
#elif	    | 如果前面的 #if 给定条件不为真，当前条件为真，则编译下面代码
#endif	    | 结束一个 #if……#else 条件编译块
#error	    | 当遇到标准错误时，输出错误消息
#pragma	    | 使用标准化方法，向编译器发布特殊的命令到编译器中

预定义宏

宏 | 描述
---|---
__DATE__	| 当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
__TIME__	| 当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
__FILE__	| 这会包含当前文件名，一个字符串常量。
__LINE__	| 这会包含当前行号，一个十进制常量。
__STDC__	| 当编译器以 ANSI 标准编译时，则定义为 1。

预处理器运算符

- 宏延续运算符(\)
- 字符串常量化运算符（#）
- 标记粘贴运算符（##）:宏定义内的标记粘贴运算符（##）会合并两个参数。
    它允许在宏定义中两个独立的标记被合并为一个标记
- define()运算符：处理器 defined 运算符是用在常量表达式中的，
    用来确定一个标识符是否已经使用 #define 定义过

参数化宏：

*/

#include <stdio.h>

// #define MAX_ARRAY_LENGTH 20
// // #include "myheader.h"

// // #define DEBUG

// #undef FILE_SIZE
// #define FILE_SIZE 42

// #ifndef MESSAGE
// #define MESSAGE "You wish!"
// #endif

// #ifdef DEBUG
// /* Your debugging statements her */
// #endif

// 宏延续运算符（\), 字符串常量化运算符(#)
#define message_for(a, b)                     \
    printf(#a " and " #b ": We love you!\n"); \
    printf("This is new line :" #a "\n");

// 标记粘贴运算符（##）:token##n 变成 token34, 使用上面定义的 int token34值进行运算
#define tokenpaster(n) \
    printf("token" #n " = %d , = %d \n", token##n, token_2_##n);

#define MESSAGE "1111"

// defined() 运算符
#if !defined(MESSAGE)
#define MESSAGE "FANFAN message!"
#endif

// 参数化的宏
// 参数列表是括在圆括号内，且必须紧跟在宏名称的后边。
// 宏名称和左圆括号之间不允许有空格
#define SQUARE(x) ((x) * (x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    printf("File: %s\n", __FILE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("Line: %d\n", __LINE__);
    printf("ANSI: %d\n", __STDC__);

    message_for(FanFan, Piao);

    int token34 = 3131;
    int token_2_34 = 22222;

    tokenpaster(34);

    printf("Her is the message :%s\n", MESSAGE);

    printf("Square 10 : %d\n", SQUARE(10));
    printf("Max between 20 and 10 is %d\n", MAX(10, 20));

    return 0;
}
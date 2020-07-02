/*

- 头文件
    - 头文件是扩展名为 .h 的文件，包含了 C 函数声明和宏定义，被多个源文件中引用共享。有两种类型的头文件：
        - 程序员编写的头文件: #include <file>
        - 编译器自带的头文件: #include "file"

- 只引用一次头文件

- 有条件引用
*/

// 只引用一次头文件, 
#ifndef HEADER_FILE // 如果没有define HEADER_FILE， 进入if语句
#define HEADER_FILE // define HEADER_FILE, 放置下一次进入
#include <stdio.h>
#include <stdlib.h>
void testPreprocess();
#endif  // 结束if

// 有条件引用
#if SYSTEM_1
#include "system_1.h"
#elif SYSTEM_2
#include "system_2.h"
#elif SYSTEM_3
#include "system_3.h"
#endif

// 不是用头文件的名称作为 #include 的直接参数，只需要使用宏名称代替即可
#define SYSTEM_H "system_1.h"
...
#include SYSTEM_H
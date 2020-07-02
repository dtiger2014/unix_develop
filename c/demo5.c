/*
存储类：

- auto : 存储类是所有局部变量默认的存储值
- register : 存储类用于定义存储在寄存器中而不是 
            RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小
            （通常是一个词），且不能对它应用一元的 '&' 运算符
            （因为它没有内存位置）。
- static（单文件 全局变量） : 存储类指示编译器在程序的生命周期内保持局部变量的存在，
        而不需要在每次它进入和离开作用域时进行创建和销毁。
        因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值
- extern （多文件 全局变量） : 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是
        可见的。当您使用 extern 时，对于无法初始化的变量，会把变量名
        指向一个之前定义过的存储位置
*/

// static 测试代码
#include <stdio.h>

// 函数声明
void func1(void);

static int count = 10; // 全局变量 - static 是默认的

int main()
{
    while (count--) {
        func1();
    }

    return 0;
}

void func1(void)
{
    static int thingy = 5;
    thingy++;
    printf("  thingy 为 %d, count 为 %d\n", thingy, count);
}
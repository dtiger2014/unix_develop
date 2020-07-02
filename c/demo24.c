/*
强类型转换: (type_name) expression

整数提升
    - 常用的算术转换是隐式地把值强制转换为相同的类型。编译器首先执行整数提升，
        型不同，则它们会被转换为下列层次中出现的最高层次的类型
    - 如果一个运算符两边的运算数类型不同，先要将其转换为相同的类型，
        即较低类型转换为较高类型，然后再参加运算
    - int -> unsinged int -> long -> unsigned long -> long long 
      -> unsigned long long -> float -> double -> long double

*/

#include <stdio.h>

int main()
{
    int sum = 17, count = 5;
    double mean;

    mean = (double)sum / count;

    printf("Value of mean: %f\n", mean);

    // 整数提升
    // int i = 17;
    // char c = 'c'; // ascii 值是 99

    // sum = i + c;
    // printf("Value of sum : %d\n", sum);

    int i = 17;
    char c = 'c'; // ascii 值是 99
    float sum1;
    sum1 = i + c;
    printf("Value of sum : %f\n", sum1);

    return 0;
}
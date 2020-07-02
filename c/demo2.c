/*
数据类型：
- 整数类型：
char	        1 字节	        -128 到 127 或 0 到 255
unsigned char	1 字节	        0 到 255
signed char	    1 字节	        -128 到 127
int	            2 或 4 字节	    -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647
unsigned int	2 或 4 字节	    0 到 65,535 或 0 到 4,294,967,295
short	        2 字节	        -32,768 到 32,767
unsigned short	2 字节	        0 到 65,535
long	        4 字节	        -2,147,483,648 到 2,147,483,647
unsigned long	4 字节	        0 到 4,294,967,295

- 浮点类型
float	        4 字节	        1.2E-38 到 3.4E+38	6 位小数
double	        8 字节	        2.3E-308 到 1.7E+308	15 位小数
long double	    16 字节	        3.4E-4932 到 1.1E+4932	19 位小数
*/

#include <stdio.h>
#include <float.h>

int main()
{
    // 整数
    printf("整数类型=========\n");
    printf("char 存储大小： %lu \n", sizeof(char));
    printf("unsigned char 存储大小： %lu \n", sizeof(unsigned char));
    printf("signed char 存储大小： %lu \n", sizeof(signed char));
    printf("int 存储大小： %lu \n", sizeof(int));
    printf("unsigned int 存储大小： %lu \n", sizeof(unsigned int));
    printf("short 存储大小： %lu \n", sizeof(short));
    printf("unsinged short 存储大小： %lu \n", sizeof(unsigned short));
    printf("long 存储大小： %lu \n", sizeof(long));
    printf("unsigned long 存储大小： %lu \n", sizeof(unsigned long));

    // 浮点
    printf("\n浮点类型=========\n");
    printf("float 存储最大字节数： %lu \n", sizeof(float));
    printf("float 最小值： %E\n", FLT_MIN);
    printf("float 最大值： %E\n", FLT_MAX);
    printf("float 精度值：%d\n", FLT_DIG);
    printf("double 存储最大字节数： %lu \n", sizeof(double));
    printf("double 最小值： %E\n", DBL_MIN);
    printf("double 最大值： %E\n", DBL_MAX);
    printf("double 精度值：%d\n", DBL_DIG);


    return 0;
}
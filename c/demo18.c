/*
位域

- 位域声明
struct
{
  type [member_name] : width ;
};

元素|描述
---|---
type	    |只能为 int(整型)，unsigned int(无符号整型)，
            signed int(有符号整型) 三种类型，决定了如何解释位域的值。
member_name	|位域的名称。
width	    |位域中位的数量。宽度必须小于或等于指定类型的位宽度。

*/

#include <stdio.h>

// 定义简单的结构：占用8个字节
struct
{
    unsigned int widthValidated;  // 4个字节
    unsigned int heightValidated; // 4个字节
    unsigned int v1;              // 4个字节
} status1;

// 定义位域结构
struct
{
    unsigned int widthValidated : 1;  // 1位
    unsigned int heightValidated : 1; // 1位
    unsigned int v1 : 1;              // 1位
} status2;

struct
{
    unsigned int age : 3;
} Age;

int main()
{
    // status1 : 3个int（4byte）=12byte
    printf("Memory size occupied by status1 : %d\n", sizeof(status1));

    // status2 : 1getint（4byte），其中用了3个位=4Byte
    printf("Memory size occupied by status2 : %d\n", sizeof(status2));

    // Age.age 为3位，范围为 0~7,超过无法赋值。例如8= 1000 ，就变成0
    Age.age = 4;
    printf("Sizeof (Age) : %d. Age.age : %d\n", sizeof(Age), Age.age);

    Age.age = 7;
    printf("Sizeof (Age) : %d. Age.age : %d\n", sizeof(Age), Age.age);

    Age.age = 8; // 超出3位
    printf("Sizeof (Age) : %d. Age.age : %d\n", sizeof(Age), Age.age);

    return 0;
}

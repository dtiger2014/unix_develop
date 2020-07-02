/*
指针

- 指针的算数运算：ptr++
    - 指针的每一次递增，它其实会指向下一个元素的存储单元
    - 指针的每一次递减，它都会指向前一个元素的存储单元
    - 指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，
        比如 int 就是 4 个字节
- 指针数组：int *ptr[MAX]
- 指向指针的指针
- 传递指针给函数
- 从函数返回指针 
*/

#include <stdio.h>

void func1(); // 指针的算数运算
void func2(); // 指针数组
void func3(); // 指向指针的指针
void func4(); // 传递指针给函数

int main()
{
    int var = 20;
    int *ip;

    ip = &var; //

    // &var: 获取指针地址
    printf("Address of var variable: %p\n", &var);

    printf("Address stored in ip variable: %p, ip value: %d\n", ip, *ip);

    // NULL指针
    int *ptr = NULL;
    printf("ptr 的地址是 %p\n", ptr);

    if (ptr)
        printf("ptr is not null\n");
    else
        printf("ptr is null\n");

    func1();

    func2();

    func3();

    func4();

    return 0;
}

void func1()
{
    printf("\n指针的算数运算 =====\n");

    int MAX = 3;
    short var[] = {10, 100, 200};
    int i;
    short *ptr;

    // 指针递增
    ptr = var; // ptr赋值为 var数组的第一个元素的指针地址
    for (i = 0; i < MAX; i++)
    {
        printf("存储地址：var[%d] = %x\n", i, ptr);
        printf("存储值：var[%d] = %d\n", i, *ptr);

        ptr++; // 移动到下一个位置, 递增
    }

    // 指针递减
    ptr = &var[MAX - 1];
    for (i = MAX; i > 0; i--)
    {
        printf("存储地址：var[%d] = %x\n", i - 1, ptr);
        printf("存储值：var[%d] = %d\n", i - 1, *ptr);

        ptr--; // 移动到下一个位置，递减
    }

    // 指针比较
    ptr = var;
    i = 0;
    while (ptr <= &var[MAX - 1])
    {
        printf("Address of var[%d] = %p\n", i, ptr);
        printf("Value of var[%d] = %d\n", i, *ptr);

        ptr++;
        i++;
    }
}

void func2()
{
    printf("\n指针数组 =====\n");

    int MAX = 3;
    int var[] = {10, 100, 200};
    int i, *ptr[MAX];

    for (i = 0; i < MAX; i++)
        ptr[i] = &var[i];

    for (i = 0; i < MAX; i++)
        printf("Value of var[%d] = %d\n", i, *ptr[i]);

    MAX = 4;
    const char *names[] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };
    for (i = 0; i < MAX; i++)
        printf("Value of names[%d] = %s\n", i, names[i]);
}

void func3()
{
    printf("\n指向指针的指针 =======\n");

    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    ptr = &var; // 获取 var 地址

    pptr = &ptr; // 获取 ptr指针地址的地址

    printf("Value of var = %d\n", var);
    printf("Value available at *ptr = %d\n", *ptr);
    printf("Value available at **pptr = %d\n", **pptr);
}

void getSeconds(unsigned long *par);
double getAverage(int *arr, int size);
void func4()
{
    printf("\n传递指针给函数 =====\n");

    unsigned long sec;

    getSeconds(&sec);

    printf("Number of seconds: %ld\n", sec);

    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    avg = getAverage(balance, 5);

    printf("Average value is:%f\n", avg);
}
void getSeconds(unsigned long *par)
{
    *par = time(NULL); // 获取当前的秒数
    return;
}
double getAverage(int *arr, int size)
{
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; i++)
        sum += arr[i];

    avg = (double)sum / size;

    return avg;
}

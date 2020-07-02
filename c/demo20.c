/*
输入 & 输出
*/

#include <stdio.h>

int main()
{
    printf("fanfan \n");

    // getchar() & putchar()： stdin 读取一个char 输出到 stdout
    /*
    int c;

    printf("Enter a value : ");
    c = getchar();

    printf("\nYou entered: ");
    putchar(c);
    printf("\n");
    */

    // gets() & puts()
    // gets() 不建议使用，可能引起buffer overflow。
    // 建议使用fgets(str, sizeof(str), stdin);
    /*
    char str[10];
    printf("sizeof str:%d\n", sizeof(str));
    printf("Enter a value : ");
    // gets(str);
    fgets(str, sizeof(str), stdin);

    printf("\nYou entered : ");
    puts(str);
    */

    /*
    scanf() & printf()
    - int scanf(const char *format, ...) 函数从标准输入流 stdin 读取输入，
        并根据提供的 format 来浏览输入。
    - int printf(const char *format, ...) 函数把输出写入到标准输出流 stdout，
        并根据提供的格式产生输出。
    */
    char str[100];
    int i;

    printf("Enter a value: ");
    scanf("%s %d", str, &i);    // 需要 &i，stdin 地址 赋值

    printf("\nYou entered: %s %d\n", str, i);

    return 0;
}
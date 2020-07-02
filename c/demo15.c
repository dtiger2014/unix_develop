/*
字符串


*/

#include <stdio.h>
#include <string.h>

int main()
{
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '1'};
    char greeting1[] = "World";

    printf("Greeting message: %s\n", greeting);
    printf("Greeting1 message: %s\n", greeting1);

    // strlen 长度
    size_t l;
    l = strlen(greeting1);
    printf("Greeting1 length:%d\n", l);

    // char newChars;
    // newChars = strcpy(greeting, greeting1);
    strcpy(greeting, greeting1);
    printf("Greeting message: %s\n", greeting);
    printf("Greeting1 message: %s\n", greeting1);

    // strcat greeting后面+上greeting1
    strcat(greeting, greeting1);
    printf("Greeting message: %s\n", greeting);
    printf("Greeting1 message: %s\n", greeting1);

    char s1[] = "abc123aaa";
    char s2[] = "123";

    int res;
    // 如果 s1 和 s2 是相同的，则返回 0；
    // 如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
    res = strcmp(s1, s2);
    printf("s1:%s, s2:%s, res:%d\n", s1, s2, res);

    // strchr(s1,ch);
    char *s ="123abc123";
    char *p;
    p = strchr(s, 'c');
    printf("ptr : %p, ptr value : %c\n", p, *p);

    p = strstr(s,"c123");
    printf("ptr :%p, ptr value : %c\n", p, *p);

    return 0;
}
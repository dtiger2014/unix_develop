#include "../utils/myhead.h"

#define BSZ 5

int main()
{
    char *s = "fanfan";
    printf("s : size:%d\n", sizeof(s));

    char text[18] ="My name is fanfan";
    printf("text:%s, size=%d\n", text, strlen(text));

    char cpy[18];
    memcpy(cpy, text, strlen(text));
    printf("cpy:%s, size=%d\n", cpy, strlen(cpy));
}
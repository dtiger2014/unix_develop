/*
循环

- 循环类型
    - for
    - while
    - do...while
    - 嵌套循环
- 循环控制语句
    - break
    - continue
    - goto
- 无限循环
    - for (;;){}
    - while(1){}
*/

#include <stdio.h>

int main()
{
    int a;
    a = 0;
    while (a < 10)
    {
        a++;
        printf("a : %d\n", a);
        if (a == 5)
        {
            printf("a continue 5\n");
            continue;
        }

        if (a == 9)
        {
            printf("a break 9\n");
            break;
        }
    }

    int b;
    for (b = 0; b < 5; b++)
    {
        printf("b : %d\n", b);
    }

    int c;
    c = 10;
    do
    {
        if (c == 5)
        {
            goto LOOP;
        }
        printf("c : %d\n", c);
        c--;
    } while (c >= 0);

LOOP:
    printf("jump to LOOP\n");
    return 0;
}
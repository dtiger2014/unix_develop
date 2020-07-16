
/*
$ gcc demo4.c           // 不进行任何优化的编译
in f1():
globval = 95, autoval = 96, regival = 97, valaval = 98, statval = 99
after longjmp:
globval = 95, autoval = 96, regival = 97, valaval = 98, statval = 99

$ gcc -O demo4.c        // 进行全部优化的变异
in f1():
globval = 95, autoval = 96, regival = 97, valaval = 98, statval = 99
after longjmp:
globval = 95, autoval = 2, regival = 3, valaval = 98, statval = 99

// 全局变量、静态变量和易失变量不受优化的影响
// 如果要编写一个使用非局部跳转的可移植程序，则必须使用volatile属性
*/
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int main(void)
{
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;

    globval = 1;
    autoval = 2;
    regival = 3;
    volaval = 4;
    statval = 5;

    if (setjmp(jmpbuffer) != 0)
    {
        printf("after longjmp:\n");
        printf("globval = %d, autoval = %d, regival = %d,"
               " valaval = %d, statval = %d\n",
               globval, autoval, regival, volaval, statval);
        exit(0);
    }

    /*
    * Change variables after setjmp, but before longjmp
    */
    globval = 95;
    autoval = 96;
    regival = 97;
    volaval = 98;
    statval = 99;

    f1(autoval, regival, volaval, statval); /* never returns */

    exit(0);
}

static void f1(int i, int j, int k, int l)
{
    printf("in f1():\n");
    printf("globval = %d, autoval = %d, regival = %d,"
           " valaval = %d, statval = %d\n",
           globval, i, j, k, l);
    f2();
}

static void f2(void)
{
    longjmp(jmpbuffer, 1);
}
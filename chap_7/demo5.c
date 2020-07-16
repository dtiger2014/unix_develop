
/*
open_data 问题：
当open_data返回时，它在栈上所使用的空间将由下一个被调用函数的栈帧使用。
但是，标准I/O库函数仍将使用这部分存储空间作为该流的缓冲区。这就产生了冲突和混乱

更正：
应该在全局空间静态地（如static或extern）或者动态地（使用一种alloc函数）为数组databuf分配空间
*/

#include <stdio.h>

FILE *open_data(void)
{
    FILE *fp;
    char databuf[BUFSIZ]; // setvbuf makes this the stdio buffer

    if ((fp = fopen("datafile", "r")) == NULL)
        return (NULL);
    if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
        return (NULL);
    return (fp); // error
}
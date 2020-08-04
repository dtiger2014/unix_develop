/*
图14-9 在文件整体上加一把写锁
*/
#include <unistd.h>
#include <fcntl.h>

/*
另一种方法是用write_lock函数定义lockfile函数
#define lockfile(fd) write_lock((fd), 0, SEEK_SET, 0)
*/ 

int lockfile(int fd)
{
    struct flock fl;

    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0;

    return (fcntl(fd, F_SETLK, &fl));
}
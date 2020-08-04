/*
图14-6 测试一个锁条件的函数

可设置为宏
*/

#define is_read_lockable(fd, offset, whence, len)\
    (lock_test((fd), F_RDLCK, (offset), (whence), (len)) == 0) 

#define is_write_lockable(fd, offset, whence, len)\
    (lock_test((fd), F_WRLCK, (offset), (whence), (len)) == 0)

#include <fcntl.h>

pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len)
{
    struct flock lock;

    lock.l_type = type;     /* F_RDLCK or F_WRLCK */
    lock.l_start = offset;  /* byte offset, relative to l_whence */
    lock.l_whence = whence; /* SEEK_SET, SEEK_CUR, SEEK_END */
    lock.l_len = len;       /* #bytes (0 means to EOF) */

    if (fcntl(fd, F_GETLK, &lock) < 0)
    {
        perror("fcntl error");
        exit(1);
    }

    if (lock.l_type == F_UNLCK)
        return (0); /* false, region isn't locked by another proc */

    return (lock.l_pid); /* true, return pid of loc owner */
}
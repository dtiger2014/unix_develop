/**
 * 图16-11 可迁移的支持重试的连接代码 
 */
#include <sys/socket.h>

#define MAXSLEEP 128

int connect_retry(int domain, int type, int protocal, const struct sockaddr *addr, socklen_t alen)
{
    int numsec, fd;

    /**
     * Try to connect with exponential backoff. 
     */
    for (numsec = 1; numsec <= MAXSLEEP; numsec <<= 1)
    {
        if ((fd = socket(domain, type, protocal)) < 0)
            return (-1);

        if (connect(fd, addr, alen) == 0)
        {
            /**
             * Connection accepted. 
             */
            return (fd);
        }
        close(fd);

        /**
         * Delay before trying again. 
         */
        if (numsec <= MAXSLEEP / 2)
            sleep(numsec);
    }
    return (-1);
}
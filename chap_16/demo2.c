/*
图16-10 支持重试的connect

一个问题：代码是不可移植的
Single UNIX Specification警告，如果connect失败，套接字的状态会变成未定义的
*/

#include "../utils/myhead.h"
#include <sys/socket.h>

#define MAXSLEEP 128

int connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
    int numsec;

    /**
     * Try to connect with exponential backoff. 
     */
    for (numsec = 1; numsec <= MAXSLEEP; numsec <<= 1)
    {
        if (connect(sockfd, addr, alen) == 0)
        {
            /**
             * Connection accepted
             */
            return (0);
        }
        /**
         * Delay before trying again. 
         */
        if (numsec <= MAXSLEEP / 2)
            sleep(numsec);
    }
    return(-1);
}
/**
 * 图17-17 open.h 头文件
 */
#include "../../utils/myhead.h"
#include <errno.h>

#define CL_OPEN "open"  /* client's request for server */

int csopen(char *, int);
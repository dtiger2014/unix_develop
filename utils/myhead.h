/*
 * FanFan header, to be included before all standard system headers.
 */

#ifndef _FANFAN_H
#define _FANFAN_H

#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>  /* for convenience */
#include <stdlib.h> /* for convenience */
#include <stddef.h> /* for offsetof */
#include <string.h> /* for convenience */
#include <unistd.h> /* for convenience */
#include <signal.h> /* for SIG_ERR */

#define	MAXLINE	4096			/* max line length */

/*
 * Default file access permissions for new files.
 */
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
 * Default permissions for new directories.
 */
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/*
 * Prototypes for my functions.
 */
void err_sys(const char *, ...) __attribute__((noreturn));

#endif /* _FANFAN_H */
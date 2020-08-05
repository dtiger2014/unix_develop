#!/bin/bash

TARGET=$1
FILEOUT=$2

if [ ! -n "${TARGET}" ] ;then
    echo "no target file."
    exit
fi

if [ ! -n "${FILEOUT}" ] ;then
    FILEOUT="./a.out"
fi

rm -rf ./utils/*.gch
gcc -lpthread -lbsd -lrt ./utils/*.c  ${TARGET} -o ${FILEOUT}

# -lrt : real-time
# -lbsd : bsd 动态库
# -lpthread : 线程库

/*******************************************************
	> File Name: 7_lseek.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define N 16

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more arguments\n");
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    
    printf("文件大小为：%ld\n", lseek(fd, 0, SEEK_END));

    return 0;
}


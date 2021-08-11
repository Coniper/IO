/*******************************************************
	> File Name: 3_read.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define SIZE 128

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

    int ret;
    char buf[SIZE] = {0};
    
    while((ret = read(fd, buf, SIZE)) > 0)
    {
        printf("%s", buf);
        memset(buf, 0, sizeof(buf));
    }

    return 0;
}


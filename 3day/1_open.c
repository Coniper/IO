/*******************************************************
	> File Name: 1_open.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more argmenus\n");
        return -1;
    }

    //int fd = open(argv[1], O_RDONLY);
    //int fd = open(argv[1], O_RDONLY | O_CREAT, 0644);
    int fd = open(argv[1], O_RDONLY | O_CREAT | O_TRUNC, 0644); //O_TRUNC 创建
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    printf("%d\n", fd);

    return 0;
}


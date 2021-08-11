/*******************************************************
  > File Name: 5_cat.c
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

    int fd = open(argv[1], O_RDWR | O_APPEND | O_CREAT, 0644);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }

    int ret;
    char buf[SIZE] = {0};

    while((ret = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
    {
        write(fd, buf, ret);
    }
    
    close(fd);

    return 0;
}


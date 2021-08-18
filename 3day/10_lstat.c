/*******************************************************
  > File Name: 10_lstat.c
  > Author:Coniper
  > Describe: 
  > Created Time: 2021年08月11日
 *******************************************************/
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("uage <filename>\n");
        return -1;
    }

    struct stat st;

    if(-1 == lstat(argv[1], &st))
    {
        perror("lstat");
        return -1;
    }

    //将st_mode成员与掩码相与，不看其他位
    switch (st.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    return 0;
}


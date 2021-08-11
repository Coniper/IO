/*******************************************************
	> File Name: 6_copy_file.c
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
    if(3 > argc)
    {
        printf("uage <src filename> <des filename>\n");
        return -1;
    }

    int sfp = open(argv[1], O_RDONLY);
    if(-1 == sfp)
    {
        perror("open_sfp");
        return -1;
    }

    int dfp = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if(-1 == dfp)
    {
        perror("open_dfp");
        return -1;
    }

    int ret = 0;
    char buf[SIZE] = {0};
    
    while((ret = read(sfp, buf, sizeof(buf))) > 0)
    {
        write(dfp, buf, strlen(buf));
    }

    return 0;
}


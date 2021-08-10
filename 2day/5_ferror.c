/*******************************************************
	> File Name: 5_ferror.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

#define N 5

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more argmenus\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "r+");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    char buf[N] = {0};

    fread(buf, sizeof(char), sizeof(buf) - 1, fp);
    if(ferror(fp))
    {
        printf("read error\n");
        return -1;
    }
    printf("%s\n", buf);

    return 0;
}


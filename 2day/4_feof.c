/*******************************************************
	> File Name: 4_feof.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

#define N 10

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more argmenus\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "w+");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    char buf[N] = {0};
    while(1)
    {
        fread(buf, sizeof(char), sizeof(buf) - 1, fp);
        if(feof(fp))
        {
            printf("读到文件末尾\n");
            break;
        }
    }

    return 0;
}


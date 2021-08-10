/*******************************************************
	> File Name: 8_ftell.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more argmenus\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(NULL == fp)
    {
        perror("fp");
        return -1;
    }

    fseek(fp, 0, SEEK_END);

    printf("文件大小为：%ld字节\n", ftell(fp));

    return 0;
}


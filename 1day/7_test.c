/*******************************************************
	> File Name: 7_test.c
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
    
    FILE* fp = fopen(argv[1], "r");
    if(NULL == fopen)
    {
        perror("fopen");
        return -1;
    }

    int count = 0;
    
    while( EOF != fgetc(fp) )
        count++;
    
    printf("文件大小为: %d 字节\n", count);
    
    fclose(fp);

    return 0;
}


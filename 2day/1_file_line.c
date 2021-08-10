/*******************************************************
	> File Name: 1_file_line.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>
#include <string.h>

#define SIZE 50

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more agemenus\n");
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    int count = 0;
    char buf[SIZE] = {0};

#if 0
    while(EOF != fgetc(fp))
    {
        if('\n' == fgetc(fp))
        {
            count++;
        }
    }
#endif
    
    while(NULL != fgets(buf, SIZE, fp))
    {
        if('\n' == buf[(long)strlen(buf) - 1])
            count++;
    }

    printf("共有%d行\n", count);

    return 0;
}


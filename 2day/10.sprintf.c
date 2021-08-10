/*******************************************************
	> File Name: 10.sprintf.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>

#define N 128

int main(int argc, char *argv[])
{
    char src[N] = {0};
    char des[N] = {0};

    sprintf(src, "%s", "Hello_World");
    sscanf(src, "%s", des);

    printf("%s\n", des);

    return 0;
}


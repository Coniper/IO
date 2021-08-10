/*******************************************************
	> File Name: 2_fflush.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月08日
 *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("hello world");  //stdout是行缓冲
#if 0
    fflush(stdout);     //刷新缓冲区
#else
    int i;
    scanf("%d", &i);    //冲洗缓冲区
#endif
    while(1);

    return 0;
}


/*******************************************************
	> File Name: 11_snprintf.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>

#define N 12

int main(int argc, char *argv[])
{
    char buf[N] = {0};

    snprintf(buf, N, "hello world");    //snprintf是对sprintf的安全版本，且会把有效范围内最后一位转化为'\0'

    printf("%s\n", buf);

    return 0;
}


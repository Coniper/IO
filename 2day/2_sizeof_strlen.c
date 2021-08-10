/*******************************************************
	> File Name: 2_sizeof_strlen.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buf[] = "";
    //char buf[0];
    
    printf("sizeof(buf) = %ld\n", sizeof(buf));
    printf("strlen(buf) = %ld\n", strlen(buf));

    //注：sizeof是关键字，strlen是函数

    return 0;
}


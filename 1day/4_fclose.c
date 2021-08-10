/*******************************************************
	> File Name: 4_fclose.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("hello world\n");
    printf("hello world\n");
    printf("hello world\n");
    
    fclose(stdout); //关闭标准输出，以下打印语句不会显示到终端

    printf("hello world\n");
    printf("hello world\n");
    printf("hello world\n");

    return 0;
}


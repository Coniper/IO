/*******************************************************
	> File Name: 2_close.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("**************\n");
    printf("**************\n");
    
    //close(1);
    close(STDOUT_FILENO);

    printf("**************\n");
    printf("**************\n");

    while(1);

    return 0;
}


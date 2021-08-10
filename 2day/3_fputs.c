/*******************************************************
	> File Name: 3_fputs.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int ret = fputs("hello world\n", stdout);
	if(ret == EOF)
	{
		perror("fputs");
		return -1;
	}

    return 0;
}


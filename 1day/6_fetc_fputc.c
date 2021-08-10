/*******************************************************
	> File Name: 6_fgetc.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    //int ch = getc(stdin);
    int ch = fgetc(stdin);

    //putc(ch, stdout);
    fputc(ch, stdout);
    
    printf("\n");

    return 0;
}


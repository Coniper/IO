/*******************************************************
	> File Name: 6_fwrite.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buf[] = "hello world\n";

    int ret = fwrite(buf, sizeof(char), strlen(buf), stdout);
    if(ret != strlen(buf))
    {
        perror("fweite");
        return -1;
    }

    return 0;
}


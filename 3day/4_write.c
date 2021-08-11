/*******************************************************
	> File Name: 4_write.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>
#include <string.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
    char buf[] = "hello world\n";

    int ret = write(STDOUT_FILENO, buf, strlen(buf));
    if(-1 == ret)
    {
        perror("write");
        return -1;
    }

    return 0;
}


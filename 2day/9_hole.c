/*******************************************************
	> File Name: 9_hole.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more argmenus\n");
        return -1;
    }

    char buf[] = "k";

    FILE* fp = fopen(argv[1], "w+");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    fseek(fp, 1023, SEEK_END);

    fwrite(buf, strlen(buf), 1, fp);

    fclose(fp);

    return 0;
}


/*******************************************************
  > File Name: 5_count_FILE.c
  > Author:Coniper
  > Describe: 
  > Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;
    FILE *fp = NULL;

    while(1)
    {
        fp = fopen("test.txt", "a");
        if(NULL == fp)
        {
            perror("fopen");
            break;
        }
        printf("count = %d\n", ++count);
    }
    //循环打开检查可以打开多少个流(除去默认3个，共1024个)

    return 0;
}


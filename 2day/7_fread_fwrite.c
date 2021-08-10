/*******************************************************
	> File Name: 7_fread_fwrite.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>


//结构体的实现是用二进制，写入文件后，仅为机器码
typedef struct test {
    int i;
    char ch;
}test;

int main(int argc, char *argv[])
{
    if(2 > argc)
    {
        printf("need more argmenus\n");
        return 1;
    }

    test t1 = {10, 'k'};

    FILE *fp = fopen(argv[1], "w+");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    fwrite(&t1, sizeof(test), 1, fp);

    test t2;
    
    fseek(fp, 0, SEEK_SET); //读写指针为同一个,把指针再指向开头

    fread(&t2, sizeof(test), 1, fp);
    if(feof(fp))
    {
        printf("read over\n");
        return -1;
    }

    printf("t2.i: %d, t2.ch: %c\n", t2.i, t2.ch);

    fclose(fp);

    return 0;
}


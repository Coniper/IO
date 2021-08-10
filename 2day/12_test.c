/*******************************************************
	> File Name: 12_test.c
	> Author:Coniper
	> Describe:用fread/fwrite实现文件拷贝 
	> Created Time: 2021年08月10日
 *******************************************************/
#include <stdio.h>

#define SIZE 128

int main(int argc, char *argv[])
{
    if(2 >= argc)
    {
        printf("need more argmenus\n");
        return -1;
    }
    char buf[SIZE] = {0};
    
    FILE* fp1 = fopen(argv[1], "r");
    if(NULL == fp1)
    {
        perror("fopen_1");
        return -1;
    }

    FILE* fp2 = fopen(argv[2], "w");
    if(NULL == fp2)
    {
        perror("fopen_2");
        return -1;
    }

    size_t temp = 0;

    for(;;)
    {
        fread(buf, SIZE, 1, fp1);
        temp = fwrite(buf, SIZE, 1, fp2);
        

        if(feof(fp1) == temp)
        {
            printf("copy is complete\n");
            break;
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}


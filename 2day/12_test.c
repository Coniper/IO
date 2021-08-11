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
        printf("Uage <src filename> <des filename>\n");
        return -1;
    }
    
    FILE* sfp = fopen(argv[1], "r");
    if(NULL == sfp)
    {
        perror("fopen_sfp");
        return -1;
    }

    FILE* dfp = fopen(argv[2], "w");
    if(NULL == dfp)
    {
        perror("fopen_dfp");
        return -1;
    }

    size_t count = 0;
    char buf[SIZE] = {0};

/*
    for(;;)
    {
        fread(buf, 1, SIZE, sfp);
        temp = fwrite(buf, 1, SIZE, dfp);
        

        if(feof(sfp) == count)
        {
            printf("copy is complete\n");
            break;
        }
    }
*/
    while( (counte = fread(buf, 1, SIZE, sfp)) > 0 )
        fwrite(buf, 1, SIZE, dfp)

    fclose(sfp);
    fclose(dfp);

    return 0;
}


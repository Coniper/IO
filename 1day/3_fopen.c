/*******************************************************
	> File Name: 3_fopen.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月09日
 *******************************************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    /*
    FILE *fp = fopen("test.txt", "r");  //只读，文件必须存在  
    FILE *fp = fopen("test.txt", "rb"); //打开二进制文件，只读，文件必须存在
    FILE *fp = fopen("test.txt", "r+"); //读写，文件必须存在
    FILE *fp = fopen("test.txt", "w");  //只写，文件存在则清空，不存在则创建
    FILE *fp = fopen("test.txt", "w+"); //读写，文件存在则清空，不存在则创建
    FILE *fp = fopen("test.txt", "a");  //只写追加，文件存在则追加，不存在则创建
    */
    FILE *fp = fopen("test.txt", "a+"); //读写追加，文件存在则追加，不存在则创建
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    return 0;
}


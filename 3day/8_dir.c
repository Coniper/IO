/*******************************************************
	> File Name: 8_dir.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年08月11日
 *******************************************************/
#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    //1.打开目录
    DIR * dir = opendir(".");
    if(NULL == dir)
    {
        perror("opendir");
        return -1;
    }

    //2.读目录下文件名
    struct dirent *dip;
    while((dip = readdir(dir)) != NULL)
        printf("%s\n", dip->d_name);

    //3.关闭目录
    closedir(dir);

    return 0;
}


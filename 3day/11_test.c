/*******************************************************
  > File Name: 11_test.c
  > Author:Coniper
  > Describe: 实现 ls -l 
  > Created Time: 2021年08月11日
 *******************************************************/
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if(2 != argc)
    {
        printf("uage <filename>\n");
        return -1;
    }

    struct stat st;
    //获取某个文件的属性
    if ( stat(argv[1],  &st) < 0){
        perror("stat");
        return -1;
    }

    //文件类型
    switch (st.st_mode & S_IFMT) {
        case S_IFBLK:  printf("b");     break;
        case S_IFCHR:  printf("c");     break;
        case S_IFDIR:  printf("d");     break;
        case S_IFIFO:  printf("p");     break;
        case S_IFLNK:  printf("l");     break;
        case S_IFREG:  printf("-");     break;
        case S_IFSOCK: printf("s");     break;
        default:       printf("?");     break;
    }

    int i;
    //文件权限
    for(i = 8; i >= 0; i--){
        if ( st.st_mode & (1 << i)){
            switch(i % 3){
                case 2:
                    printf("\033[32mr\033[0m"); break;
                case 1:
                    printf("\033[32mw\033[0m"); break;
                case 0:
                    printf("\033[32mx\033[0m"); break;
            }
        } else {
            printf("-");
        }
    }

    //单独分割
    printf(" ");

    //链接数
    printf("%ld ", st.st_nlink);

    //UID
    struct passwd * pw = getpwuid(st.st_uid);
    printf("%s ", pw->pw_name);

    //GID
    struct group *gp = getgrgid(st.st_gid);
    printf("%s ", gp->gr_name);

    //字节数
    printf("%ld ", st.st_size);

    //最后操作的时间
    struct tm * tm = localtime(&st.st_atime);
    if(NULL == tm)
    {
        fprintf(stderr, "localtime failed\n");
        return -1;
    }
    printf("\033[33m%d月 %2d %.2d:%2d \033[0m", \
            tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min);

    //文件名
    printf("\033[47;34m%s\033[0m\n", argv[1]);

    return 0;
}

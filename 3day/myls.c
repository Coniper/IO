#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
int  displayfile(char *dir,char *filename,int lflag)
{
	/*判断是否有-l参数，有的话打印长信息*/
	if(lflag ==1)
	{
		struct stat buf;
		char out[100];
		if(lstat(dir,&buf)<0)
		{
			fprintf(stderr,"stat error:%s\n",strerror(errno));
			return -1;
		}
		/*判断文件类型*/
		switch(buf.st_mode & S_IFMT)
		{
		case S_IFREG:	
			printf("-");
			break;
		case S_IFDIR:	
			printf("d");
			break;
		case S_IFCHR:	
			printf("c");
			break;
		case S_IFBLK:	
			printf("b");
			break;
		case S_IFIFO:	
			printf("p");
			break;
		case S_IFLNK:	
			printf("l");
			break;
		case S_IFSOCK:	
			printf("s");
			break;
		}
		/*判断文件权限*/
		int n;
		for(n=8;n>=0;n--)
		{
			if(buf.st_mode&(1<<n))
			{
				switch(n%3)
				{
				case 2:
					printf("r");
					break;
				case 1:
					printf("w");
					break;
				case 0:
					printf("x");
					break;
				default:
					break;

				}
			}
			else
			{
				printf("-");
			}
		}
		/*文件的hard links*/
		printf(" %ld",buf.st_nlink);

		/*文件的uid*/
		struct passwd *pw;
		pw = getpwuid(buf.st_uid);
		printf(" %s",pw->pw_name);

		/*文件的gid*/
		struct group *gr;
		gr = getgrgid(buf.st_gid);
		printf(" %s",gr->gr_name);

		/*文件的大小*/
		printf(" %ld",buf.st_size);

		/*文件的最后访问时间*/
		struct tm *t;
		t = localtime(&buf.st_atime);
		printf(" %d-%d-%d %d:%d",t->tm_year+1900,
				t->tm_mon+1,
				t->tm_mday,
				t->tm_hour,
				t->tm_min);
		printf(" %s ",filename);	

		/*如果文件是符号链接文件，打印其源文件*/
		if(S_ISLNK(buf.st_mode))
		{
			printf(" -> ");
			if(readlink(filename,out,100)==-1)
			{

			}
			printf("%s",out);

		}
		printf("\n");
	}
	else
	{
		printf("%s\t",filename);
	}
	return 0;
}

int displaydir(char *w,int aflag,int lflag)
{
	struct stat buf;
	char name[100];
	/*获取文件属性*/
	if(lstat(w,&buf)<0)
	{
		fprintf(stderr,"stat error:%s\n",strerror(errno));
		return -1;
	}
	/*判断是否为目录文件*/
	if(S_ISDIR(buf.st_mode))
	{
		DIR *dir;
		dir = opendir(w);
		struct dirent *pdr;
		while ((pdr = readdir(dir))!=NULL)
		{
			if(aflag==0)
			{
				/*如果不加-a参数的话，不打印.和..目录信息*/
				if(pdr->d_name[0]=='.')
				{
				}
				else
				{
					/*组装成为文件的路径名，传给displayfile打印长信息*/
					memset(name,0,100);
					strcpy(name,w);
					strcat(name,"/");
					strcat(name,pdr->d_name);
					displayfile(name,pdr->d_name,lflag);
				}
			}
			else
			{
				memset(name,0,100);
				strcpy(name,w);
				strcat(name,"/");
				strcat(name,pdr->d_name);
				displayfile(name,pdr->d_name,lflag);
			}
		}
		closedir(dir);
	}
	else
	/*如果不是目录的话直接交给displayfile打印长信息*/
	{
		displayfile(w,w,lflag);
	}
	return 0;
}
int main(int argc,char **argv)
{
	int aflag =0;
	int lflag =0;
	char c;
	int i;
	/*判断命令参数*/
	while((c = getopt(argc,argv,"al"))!=-1)
	{
		switch(c)
		{
		case 'a':
			aflag =1;
			break;
		case 'l':
			lflag =1;
			break;
		default:
			break;
		}
	}
	/*判断是否查询指定文件，缺省遍历当前目录文件*/
	if(argc == optind )
	{
		displaydir(".",aflag,lflag);
	}
	/*指定了文件的情况*/
	else
	{
		for(i=optind;i<argc;i++)
			displaydir(argv[i],aflag,lflag);
	}
	printf("\n");
	return 0;
}

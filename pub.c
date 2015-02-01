#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define MAXLINE 512

void err_sys(char *errStr)
{
	fprintf(stderr, "error: %s", errStr);
	fflush(stderr);
}

void str_echo(int sockfd)
{
	int readNum = 0;
	char buff[MAXLINE];
	while((readNum = read(sockfd, buff, MAXLINE)) > 0 || EINTR == errno)
	{
		if( readNum > 0)
		{
			write(sockfd, buff, readNum);	
		}
	}
	if(readNum < 0) 
	{
		err_sys("read error.\n");
	}
}
void str_cli(int sockfd)
{
	char buff[MAXLINE];
	while(NULL != fgets(buff, MAXLINE, stdin))
	{
		int rCount;
		write(sockfd, buff, strlen(buff));
		rCount = read(sockfd, buff, MAXLINE);
		if(0 < rCount)
		{
			fputs(buff, stdout);
		}
	}
}

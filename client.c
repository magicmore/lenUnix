#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include "pub.h"
#define MAXLINE 512

void printValue(void* inVal, int len)
{
 	int i = 0;
 	unsigned char *p = (char *)inVal;
	for (i = 0; i < len; i++)
 	{
 	 	printf("%d ", *(p+i));
 	}
 	printf("\n");
}

int main(int argc, char* argv[])
{
	int sockfd;
	int n;
	char recvline[MAXLINE];
	struct sockaddr_in servaddr;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error.\n");
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))<0)
	{
		printf("connect error.\n");
	}
	str_cli(sockfd);
	return 0;
}

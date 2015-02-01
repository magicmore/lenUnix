#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>
#include "pub.h"
int main(int argc, char* argv[])
{
	int listenFd, connFd;
	struct sockaddr_in servAddr;
	struct sockaddr_in recAddr;

	time_t ticks;
	char pTmp[INET_ADDRSTRLEN];
	char buff[512] = {1 ,2,3};
	int len = 0;
	char tempbuf[] = "hello!";
	int buffSize = 0;
	if((listenFd = socket(AF_INET, SOCK_STREAM, 0)))
	{
		
	}
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(13); 
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(listenFd, (struct sockaddr*)&servAddr, sizeof(servAddr));
	listen(listenFd, 5);
	while(1)
	{
		connFd = accept(listenFd, (struct sockaddr*)&recAddr, &len);
		inet_ntop(AF_INET, &recAddr.sin_addr, pTmp, INET_ADDRSTRLEN); 
		//snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		str_echo(connFd);
		//snprintf(buff + strlen(buff),sizeof(buff), "%s\n", pTmp); 
		//write(connFd, buff, strlen(buff));
		close(connFd);
	}
	return 0;
}



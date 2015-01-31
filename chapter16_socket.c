#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
#include <poll.h>
#include <netdb.h>
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

	struct hostent *hent;
	struct netent  *nent;
	hent = gethostbyname("www.google.com.hk");
	nent = getnetbyaddr(inet_network("169.254.0.0"), AF_INET);
	printf("hostname: %s.\n", hent->h_name);
	printf("host address: ");
	printValue(*hent->h_addr_list, 4);
	printf("network name: %s.\n", nent->n_name);
	printf("netwok address type:%d, \n", nent->n_addrtype);
	return 0;
}

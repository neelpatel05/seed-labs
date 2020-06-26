#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/ip.h>

int main()
{
	struct sockaddr_in client;
	struct sockaddr_in server;

	int clientlen;
	char buffer[1024];

	int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	memset((char *)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(9090);

	if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		error("Error on binding\n");
	}

	while(1) 
	{
		bzero(buffer, 1024);
		recvfrom(sock, buffer, 1024-1, 0, (struct sockaddr *)&client, &clientlen);
		printf("%s\n",buffer);
		
	}
	return 0;
}

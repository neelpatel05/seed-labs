#include<stdio.h>
#include<stdlib.h>
#include<netinet/ip.h>
#include<sys/socket.h>
#include<string.h>

int main()
{
	struct sockaddr_in dest_info;
	char *data = "Hello Server";

	int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	memset((char *) &dest_info, 0, sizeof(dest_info));
	dest_info.sin_family = AF_INET;
	dest_info.sin_addr.s_addr = inet_addr("192.168.147.149");
	dest_info.sin_port = htons(9090);

	sendto(sock, data, strlen(data), 0, (struct sockaddr *)&dest_info, sizeof(dest_info));
	return 0;
}

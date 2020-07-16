#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<stdint.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int listenfd, connfd;

void function(char* str)
{
	char readbuffer[256];
	char writebuffer[256];
	strcpy(readbuffer, str);
	sprintf(writebuffer, readbuffer);
	write(connfd, writebuffer, strlen(writebuffer));
}

int main(int argc, char** argv)
{
	char line[1024];
	struct sockaddr_in servaddr;
	ssize_t n;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(7776);

	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	listen(listenfd, 1024);

	for(;;)
	{
		connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
		write(connfd, "> ",2);
		n = read(connfd, line, sizeof(line)-1);
		line[n] = 0;
		function(line);
		close(connfd);
	}
}

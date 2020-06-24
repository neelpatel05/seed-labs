#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main() {

	int fd;
	fd = open("/etc/zzz", O_RDWR | O_APPEND);

	if (fd == -1) {
		printf("Cannot open /etc/zzz\n");
		exit(0);
	}

	setuid(getuid());

	char *buffer[2];
	buffer[0] = "/bin/sh";
	buffer[1] = 0;
	execve(buffer[0], buffer , 0);

	return 0;
}

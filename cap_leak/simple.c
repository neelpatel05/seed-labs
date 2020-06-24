#include<stdio.h>
#include<stdlib.h>

int main() {
	int x = getuid();
	int y = geteuid();
	printf("User id %d \nEffective user id %d \n",x,y);
	return 0;
}

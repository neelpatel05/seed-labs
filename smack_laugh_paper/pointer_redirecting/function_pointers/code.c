#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void function(char* str)
{
	printf("%s\n",str);
	system("any command");
}

int main(int argc, char** argv)
{
	void (*ptr)(char* str);
	ptr = &function;
	char buffer[64];
	strcpy(buffer, argv[1]);
	(*ptr)(argv[2]);
	return 0;
}

#include<stdio.h>
#include<string.h>

void function(char* str)
{
	char buffer[100];
	strcpy(buffer, str);
	puts("Inside function");
}

void secret()
{
	puts("You called secret succesfully");
}

int main(int argc, char** argv)
{
	function(argv[1]);
	return 0;
}

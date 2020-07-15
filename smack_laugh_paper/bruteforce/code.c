#include<stdio.h>
#include<string.h>

void function(char* str)
{
	char buffer[4096];
	strcpy(buffer, str);
}

int main(int argc, char** argv)
{
	function(argv[1]);
	return 0;
}

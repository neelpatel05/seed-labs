#include<stdio.h>
#include<string.h>

char globalbuffer[100];

void function(char* str)
{
	char localbuffer[100];
	strcpy(localbuffer, str);
	strcpy(globalbuffer, localbuffer);
}

int main(int argc, char** argv)
{
	function(argv[1]);
	return 0;
}

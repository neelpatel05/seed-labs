#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	char buffer[100];
	char *conf = "test -/ progc";
	char *license = "This software is really good";
	puts(license);
	strcpy(buffer, argv[1]);

	if (system(conf))
	{
		puts("Missing progc");
	}
	return 0;
}

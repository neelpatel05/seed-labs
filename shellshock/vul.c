#include<stdio.h>

int main()
{
	setuid(geteuid());
	system("ls -l");
}

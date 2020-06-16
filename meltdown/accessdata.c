#include<stdio.h>

int main(int argc, char** argv) {
	char *kernel_data_addr = (char*)0xf90a3000;
	char kernel_data = *kernel_data_addr;
	printf("Done\n");
	return 0;
}

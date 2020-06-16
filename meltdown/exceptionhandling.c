#include<stdio.h>
#include<setjmp.h>
#include<signal.h>

static sigjmp_buf jbuf;

static void catch_segv() {
	siglongjmp(jbuf, 1);
}

int main() {
	unsigned long kernel_data_addr = 0xf90a3000;

	signal(SIGSEGV, catch_segv);

	if (sigsetjmp(jbuf, 1) == 0) {
		char kernel_data = *(char*)kernel_data_addr;
		printf("Kernel data at address %lu is: %c\n", kernel_data_addr, kernel_data);
	} else {
		printf("Memory access violation!\n");
	}

	printf("Program continues to execute\n");
	return 0;
}

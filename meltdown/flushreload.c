#include<stdio.h>
#include<stdint.h>
#include<emmintrin.h>
#include<x86intrin.h>

#define CACHE_HIT_THRESHOLD (80)
#define DELTA 1024

uint8_t array[256*4096];
int temp;
char secret = 94;

void flushSideChannel() {
	int i;
	for (i = 0; i < 256; i++) {
		array[i*4096] = 1;
	}
	for (i = 0; i < 256; i++) {
		_mm_clflush(&array[i*4096 + DELTA]);
	}
}

void victim() {
	temp = array[secret*4096 + DELTA];
}

void reloadSideChannel() {
	int junk = 0;
	register uint64_t time1, time2;
	volatile uint8_t *addr;
	int i;
	for (i = 0; i < 256; i++) {
		addr = &array[i*4096 + DELTA];
		time1 = __rdtscp(&junk);
		junk = *addr;
		time2 = __rdtscp(&junk) - time1;
		if (time2 < CACHE_HIT_THRESHOLD) {
			printf("array[%d*4096 + %d] is in cache\n",i,DELTA);
			printf("The secret is %d\n",i);
		}
	}
}

int main(int argc, char** argv) {
	flushSideChannel();
	victim();
	reloadSideChannel();
	return 0;
}

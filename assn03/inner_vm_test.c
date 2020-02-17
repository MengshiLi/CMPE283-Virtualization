#include <stdio.h>

static inline void native_cpuid(unsigned int* eax, 
		unsigned int* ebx, 
		unsigned int* ecx,
		unsigned int* edx) {
	asm volatile("cpuid"
			: "=a" (*eax),
			  "=b" (*ebx),
			  "=c" (*ecx),
			  "=d" (*edx)
			: "0" (*eax), "2" (*ecx) );
}


int main(int argc, char **argv) {
	unsigned int eax, ebx, ecx, edx;

	eax = 0x4FFFFFFF;
	native_cpuid(&eax, &ebx, &ecx, &edx);
	printf("Total Exits: 0x%08x\n", eax);
        printf("Total CPU Cycles Handling Exits: 0x%08x%08x \n", 
		ebx, ecx);

	return 0;
}


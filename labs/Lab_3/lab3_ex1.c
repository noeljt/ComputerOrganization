// display entries 32-127 of ASCII table to stdout
#include <stdio.h>
int main(void) {
	int i;
	printf("dec hex  oct   char\n");
	for (i=32;i<=127;i++) {
		printf("%-3d 0x%-3x 0o%-3o %3c\n",i,i,i,i);
	}
	return 0;			
}
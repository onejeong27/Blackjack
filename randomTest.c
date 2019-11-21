#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int i, random;
	
	srand((unsigned)time(NULL));
	
	for (i = 0; i < 10; i++) {
		random = rand() % 10;
		printf("%d ", random);
	}
}

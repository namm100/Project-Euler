#include <stdio.h>

bool divis(int start, int end, int num) {
	if (start <= 0 || end < start) {
		return false;
	}
	for (int i = start; i <= end; i++) {
		if (num % i != 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv) {
	int count = 20;
	while (!divis(1,20,count)) {
		count += 20;
	}
	printf("Min num divis 1-20: %d\n", count);
	return 0;
}

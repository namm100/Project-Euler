#include <stdio.h>
#include <algorithm>
/*
Sort all the permutations of {0,1,2,3,4,5,6,7,8,9}
and find the millionth permutation
*/
using namespace std;
void printPermutations(int n, int* A, int stop) {
	sort(A, A+n);
	int count = 1;
	do {
		printf("%d:",count);
		for (int i = 0; i < n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		if (count == stop)
			break;
		count++;
	} while (next_permutation(A, A+n));
}

int main(int argc, char** argv) {
	int A[] = {0,1,2,3,4,5,6,7,8,9};
	printPermutations(10, A, 1000000);
}

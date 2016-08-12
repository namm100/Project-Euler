#include <stdio.h>
#include <vector>


/*
If the prime factors of 13195 are 5, 7, 13, 29
find the largest prime factor of 600851475143
*/

using namespace std;

long max_long(long size, long* A) {
	if (size == 0) {
		return 0;
	}
	if (size == 1) {
		return A[0];
	}
	long before = A[0];
	for (long i = 1; i < size; i++) {
		if (A[i] > before) {
			before = A[i];
		}
	}
	return before;
}

long get_lcf(long number) {
	vector<long> factors;
	long n = number;	
	for (long i = 2; i <= n; i++) {
		while (n % i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	
	long factors_arr [factors.size()] = {};
	for (long j = 0; j < factors.size(); j++) {
		factors_arr[j] = factors.at(j);
	}
	return max_long(factors.size(), factors_arr);  
}


int main(int argc, char** argv) {
	
	long number = 600851475143;
	long big = get_lcf(number);
	printf("Max Prime Factor of %ld: %ld\n",number, big);

	return 0;
}

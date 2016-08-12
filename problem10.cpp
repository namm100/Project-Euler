#include <stdio.h>

/*
The sum of primes below 10 is 2+3+5+7=17
Find the sum of all the primes below two million
*/

bool is_prime(long num) {
	if (num == 0 || num == 1) 
		return false;
	if (num == 2)
		return true;
	for (long i = 2; i < (num/2)+1; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

long sum_primes(long max_exclusive) {
	long rolling_sum = 0;
	for (long i  = 0; i < max_exclusive; i++) {
		if (is_prime(i)) {
			rolling_sum += i;
			printf("prime:%lu\n", i);
		}
	}
	return rolling_sum;		
}

int main(int argc, char** argv) {
	long max = 2000000;
	long sum = sum_primes(max);
	printf("max:%ld sum:%ld\n", max, sum); 
	return 0;
}

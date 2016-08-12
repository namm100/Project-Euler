#include <stdio.h>

/*
2, 3, 5, 7, 11, 13 the 6th prime is 13
find the 10001st prime number
*/

using namespace std;

bool is_prime(long n) {
	if (n == 0 || n == 1) {
		return false;
	} 
	if (n == 2) {
		return true;
	}
	for (long i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;	
}

long get_n_prime(long n) {
	long count = 0;
	long prime_count = 0;
	while (prime_count < n) {
		count++;
		if (is_prime(count)) {
			prime_count += 1;
		}
		
		
	}
	return count;	
}

int main(int argc, char** argv) {
	
	long n_prime = 10001;
	printf("%ld prime: %ld\n", n_prime, get_n_prime(n_prime));
	return 0;
}	

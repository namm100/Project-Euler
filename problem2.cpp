#include <stdio.h>
#include <math.h>

/*
find sum of even-valued terms whoes values in the fibonacci sequence 
doesn't excede 4,000,000
*/

double fib(int n) {
	double phi = (1.0 + sqrt(5.0)) / 2.0;
	double psi = (1.0 - sqrt(5.0)) / 2.0;
	return (pow(phi, n) - pow(psi, n)) / sqrt(5.0);
}

int main(int argc, char** argv) {
	
	float sum = 0.0;
	
	for (int i = 1; fib(i) < 4000000; i++) {
		if ((int) fib(i) % 2 == 0) {
			sum += fib(i);
		}	
	}
	printf("Sum: %d\n",(int) sum);
	return 0;
}	
	


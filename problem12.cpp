#include <stdio.h>
#include <vector>

/* 
What is the value of the first triangle number to have over
500 divisors?
divisors -> 15: 1,3,15
*/

using namespace std;

long triangle(long n) {
	return (n * (n+1)) / 2;
}

void print_vector(vector<long> A) {
	for (long i = 0; i < A.size(); i++) {
		printf("%ld ", A.at(i));
	}
	printf("\n");
}

bool contains(long num, vector<long> A) {
	for (long i = 0; i < A.size(); i++) {
		if (A.at(i) == num)
			return true;
	}
	return false;
}	

vector<long> factors(long num) {
	vector<long> facts;
	for (int i = 1; i < (num / 2); i++) {
		if (num % i == 0) {
			if (contains(i, facts) && contains(num / i, facts));
			if (!contains(i, facts))
				facts.push_back(i);
			if (!contains(num / i, facts))
				facts.push_back(num / i);
			
		}
	}
	return facts;
}

int main(int argc, char** argv) {
	int size = 0;
	long tri_count = 0;
	int divisible = 100;
	while (size < 500) {
		tri_count++;
		long tri = triangle(tri_count);
		if (tri % divisible != 0) 
			continue;
		size = factors(tri).size();
		printf("#%ld:%ld with %d factors\n", tri_count, triangle(tri_count), size);
	}
	//print_vector(factors(42));
	printf("Triangle Number:%ld\n", triangle(tri_count));	
	return 0;
}



#include <stdio.h>
#include <cmath>
/*
Find the difference between the sum of the squares of the first
one hundred natural numbers and the square of the sum
*/

int sum(int end) {
	return (end * (end+1)) / 2.0;
}
int main(int argc, char** argv) {
	int square_sum = sum(100) * sum(100);
	int sum_square = 0;
	for (int i = 0; i <= 100; i++) {
		sum_square += i * i;
	}
	printf("sum of squares: %d\n", sum_square);
	printf("square of sum: %d\n", square_sum);
	printf("difference: %d\n",(int) std::abs(sum_square - square_sum));
	return 0;
}

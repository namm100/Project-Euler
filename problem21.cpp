#include <stdio.h>
#include <vector>

using namespace std;

void printVector(vector<int> A) {
	printf("< ");
	for (int i = 0; i < A.size(); i++) {
		printf("%d ", A.at(i));
	}
	printf(">\n");
}

int sumVector(vector<int> A) {
	int roll = 0;
	for (int i = 0; i < A.size(); i++) {
		roll += A.at(i);
	}
	return roll;
}

vector<int> getDivisors(int num) {
	vector<int> A;
	if (num == 1 || num == 0) {
		A.push_back(0);	
	} else {
		for (int i = 1; i < (num / 2) + 2; i++) {
			if (num % i == 0)
				A.push_back(i);
		}
	}
	return A;
}

int d(int n) {
	return sumVector(getDivisors(n));
}

bool contains(vector<int> A, int num) {
	for (int i = 0; i < A.size(); i++) {
		if (A.at(i) == num) {
			return true;
		}
	}
	return false;
}

bool isAmicable(int a) {
	printf("%d:",a); printVector(getDivisors(a));
	int b = d(a);
	int c = d(b);
	printf("n:%d b:%d c:%d\n", a, b, c);
	if (b == a)
		return false;
	
	if (a == c) 
		return true;
	else
		return false;
}

void checkAmicable(int n) {
	if (isAmicable(n)) 
		printf("%d is amicable\n", n);
	else 
		printf("%d is not amicable\n", n);
}

int main(int argc, char** argv) {
	int roll = 0;
	for (int i = 1; i < 10000; i++) {
		if (isAmicable(i)) {
			printf("%d is amicable\n", i);
			roll += i;
		}
	}
	printf("Sum of amicable nums: %d\n", roll);
	return 0;
}

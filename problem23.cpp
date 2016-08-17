#include <stdio.h>
#include <vector>

using namespace std;



void printVector(vector<int> A) {
	printf("< ");	
	for (int i = 0; i < A.size(); i++) 
		printf("%d ", A.at(i));
	printf(">\n");
}
int sum(vector<int> A) {
	int roll = 0;
	for (int i = 0; i < A.size(); i++) 
		roll += A.at(i);
	return roll;
}

vector<int> getDivisors(int num) {
	vector<int> A;
	if (num == 1 || num == 0) 
		return A;
	for (int i = 1; i < (num / 2) + 2; i++) {
		if (num % i == 0) 
			A.push_back(i);
	}
	return A;
}

int d(int num) {
	return sum(getDivisors(num));
}

bool isPerfect(int num) {
	return num == d(num);
}

void checkNum(int max) {
	for (int i = 0; i < 
}
int main(int argc, char** argv) {
	
	for (int i = 1; i < 51; i++) {
		//printf("%d: ",i);
		//printVector(getDivisors(i));
		//printf("sum:%d\n", d(i)); 
		printf("%d: %s\n", i, (isPerfect(i))?"is perfect":"is not perfect");
	}
	return 0;
}


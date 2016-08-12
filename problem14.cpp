#include <stdio.h>
#include <vector>

/*
A Collatz sequence is 
n-> n / 2(n is even)
n-> 3n + 1(n is odd)
a sequence starts at n, goes through those patterns till 1
Which starting number under one million produces the
longest chain?
*/

using namespace std;


void print(vector<long> A) {
	printf("vector with size:%lu\n", A.size());
	for (int i = 0; i < A.size(); i++) {
		printf("%ld\n", A.at(i));
	}
}
long next_collatz(long n) {
	if (n % 2 == 0)
		return n / 2;
	else
		return 3*n + 1;
}

vector<long> generate_collatz(long n) {
	
	vector<long> seq; 
	long next = n;
	seq.push_back(n);
	while (next != 1) {
		long next_num = next_collatz(next);	
		seq.push_back(next_num);
		next = next_num;
		if (next < 0)
			break;
	}
	return seq;
}

int main(int argc, const char** argv) {
	
	/*
	vector<long> rands = generate_collatz(113383);
	printf("113383: %ld\n", rands.size());
	*/
	
	long big_start_num = 0;
	unsigned long sizes = 0;
	for (long i = 1; i < 1000000; i++) {
		vector<long> curr = generate_collatz(i);
		printf("start:%ld, size:%lu\n",i,curr.size());
		if (curr.size() > sizes) {
			big_start_num = i;
			sizes = curr.size();
		}
	} 
	printf("number with biggest collatz:%ld\n",big_start_num);
	printf("size of collatz:%lu\n", sizes);
	

	return 0;
}

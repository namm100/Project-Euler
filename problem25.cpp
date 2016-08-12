#include <stdio.h>
#include "BigInteger.h"
#include <string>
#include <sstream>
/*
What is the index of the first term in the fibonacci
sequence to contain 1000 digits?
*/
using namespace std;

void endDig(string stop) {
	printf("{\n");
	string currDig = "0";
	string count = "1";
	while (!(currDig.compare(stop) == 0)) {
		string currF = BigInteger::fibonacciStr(count);
		int currF_int = (int) currF.length();
		ostringstream ss;
		ss << currF_int;
		currDig = ss.str();
		printf("%s: %s: %s\n", count.c_str(), currF.c_str(),currDig.c_str());
		count = BigInteger::addStr(count, "1");
	}
	printf("}\n");	
}
int main(int argc, char** argv) {
	endDig("1000");	
	return 0;
}

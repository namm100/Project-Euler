#include <stdio.h>
#include "BigInteger.h"
#include <string>
#include <stdlib.h>
/*
What is the sum of the digits of the number 2 to the power of 1000
*/
using namespace std;

string digitSum(string number) {
	if (!BigInteger::isStrNum(number))
		return 0;
	string sum = "0";
	for (int i = 0; i < number.length(); i++) 
		sum = BigInteger::addStr(sum, number.substr(i,1));
	return BigInteger::trimZeroes(sum);
}

int main(int argc, char** argv) {
	string huge = BigInteger::powStr("2", "1000");
	printf("sum of digits:%s\n", digitSum(huge).c_str());
	return 0;
}


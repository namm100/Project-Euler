#include <stdio.h>
#include "BigInteger.h"
#include <string>
#include <sstream>

/*
Find the sum of the digits in the 
number 100!
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
	string huge = BigInteger::factorialStr("100");
	printf("100!: %s\n", huge.c_str());
	printf("num digits: %s\n", digitSum(huge).c_str());
	return 0;
}

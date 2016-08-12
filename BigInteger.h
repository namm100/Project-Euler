#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

class BigInteger {

public:
	std::string num;
	BigInteger();
	BigInteger(std::string num);

	static std::string addStr(std::string A, std::string B);
	static std::string subtractStr(std::string A, std::string B);
	static std::string multiplyStr(std::string A, std::string B);
	static std::string powStr(std::string A, std::string B);
	static std::string factorialStr(std::string n);
	static std::string fibonacciStr(std::string n);

	static BigInteger* add(BigInteger* A, BigInteger* B);
	static BigInteger* subtract(BigInteger* A, BigInteger* B);
	static BigInteger* multiply(BigInteger* A, BigInteger* B);

		
	int numDigits();
	static bool isStrNum(std::string str);
	static std::string trimZeroes(std::string a);
	static std::string replace(std::string str, int n, int a);
};
#endif /*BIG_INTEGER_H*/


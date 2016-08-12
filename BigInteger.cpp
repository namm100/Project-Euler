#include "BigInteger.h"

BigInteger::BigInteger(std::string num) {
	if (BigInteger::isStrNum(num))
		(*this).num = num;
	else
		(*this).num = "0";
}

BigInteger::BigInteger() {
	(*this).num = "0";
}

int BigInteger::numDigits() {
	return (int) (*this).num.size();
}

std::string BigInteger::addStr(std::string A, std::string B) {
	bool lll = BigInteger::isStrNum(A);
	bool llll = BigInteger::isStrNum(B);
	bool lllallll = lll && llll;
	if (!lllallll) {
		printf("%s and/or %s are not number strings\n", A.c_str(), B.c_str());
		return "0";
	}
	int size_dif = A.length() - B.length();
	if (size_dif > 0) {
		// A is bigger
		std::string zeroes = "";
		for (int i = 0; i < size_dif; i++) 
			zeroes += "0";
		B = zeroes + B;
	} else if (size_dif < 0) {
		// B is bigger
		size_dif *= -1;
		std::string zeroes = "";
		for (int i = 0; i < size_dif; i++) 
			zeroes += "0";
		A = zeroes + A;
	}
	// add bit by bit	
	int carry = 0;
	std::string new_num = "";
	for (int i = A.length() - 1; i >= 0; i--) {
		int a_curr = atoi(A.substr(i,1).c_str());
		int b_curr = atoi(B.substr(i,1).c_str());
		int res = a_curr + b_curr + carry;
		//printf("%d: %d + %d = %d\n", i, a_curr, b_curr, res);
		if (res > 9) {
			std::ostringstream ss;
			ss << res;	
			std::string res_str = ss.str();
			carry = atoi(res_str.substr(0,1).c_str());
			new_num = res_str.substr(1,1) + new_num;
		} else {
			std::ostringstream ss2;
			ss2 << res;
			std::string res_str2 = ss2.str();
			new_num = res_str2 + new_num;
			carry = 0;
		}
	}
	std::ostringstream ss3;
	ss3 << carry;
	std::string carry_str = ss3.str();
	new_num = carry_str + new_num;
	return BigInteger::trimZeroes(new_num);
}

std::string BigInteger::subtractStr(std::string A, std::string B) {

	std::string top, bot;
	A = BigInteger::trimZeroes(A);
	B = BigInteger::trimZeroes(B);
	if (A.length() > B.length()) {
		top = A;
		bot = B;
	} else if (B.length() > A.length()) {
		top = B;
		bot = A;
	} else {
		if (A.compare(B) == 0)
			return "0";
		// check digit by digit
		for (int i = 0; i < A.length(); i++) {
			int cA = atoi(A.substr(i,1).c_str());
			int cB = atoi(B.substr(i,1).c_str());
			if (cA > cB) {
				top = A;
				bot = B;
				break;
			} else if (cB > cA) {
				top = B;
				bot = A;
				break;
			} else {
				continue;
			}
		}
	}
	// top is always bigger than bottom
	int numZeroes = top.length() - bot.length();
	for (int i = 0; i < numZeroes; i++) {
		bot = "0" + bot;
	}
	//perform subtraction
	//put them into arrays
	int topArr[top.length()];
	int botArr[bot.length()];
	for (int i = 0; i < top.length(); i++) {
		topArr[i] = atoi(top.substr(i,1).c_str());
		botArr[i] = atoi(bot.substr(i,1).c_str());
	}
	int res[top.length()];
	//do the algorithm
	for (int i = top.length() - 1; i >= 0; i--) {
		if (botArr[i] > topArr[i]) {
			topArr[i] += 10;
			topArr[i-1] -= 1;
			int j;
			for (j = i-1; topArr[j] < 0; j--) {
				topArr[j] += 10;
				topArr[j-1] -= 1;
			}
		}
		res[i] = topArr[i] - botArr[i];
	}
	std::string res_str = "";
	for (int i = 0; i < top.length(); i++) {
		std::ostringstream ss;
		ss << res[i];
		res_str = res_str + ss.str();
	}
	return BigInteger::trimZeroes(res_str);
}	

std::string BigInteger::multiplyStr(std::string A, std::string B) {
	std::string res = "0";
	std::string counter = B;
	while (!(counter.compare("0") == 0)) {
		res = BigInteger::addStr(res, A);
		counter = BigInteger::subtractStr(counter, "1");
	}
	return res;
}

std::string BigInteger::powStr(std::string A, std::string B) {
	std::string res = "1";
	std::string counter = B;
	while (!(counter.compare("0") == 0)) {
		res = BigInteger::multiplyStr(res, A);
		counter = BigInteger::subtractStr(counter, "1");
	}
	return res;
}

std::string BigInteger::factorialStr(std::string n) {
	std::string res = "1";
	std::string count = n;
	while (!(count.compare("0") == 0)) {
		res = BigInteger::multiplyStr(res, count);
		count = BigInteger::subtractStr(count, "1");
	}
	return res;
}

std::string BigInteger::fibonacciStr(std::string n) {
	if (n.compare("0") == 0)
		return "0";
	else {
		std::string x = "0";
		std::string y = "1";
		std::string count = BigInteger::subtractStr(n, "1");
		while (!(count.compare("0") == 0)) {
			std::string z = BigInteger::addStr(x,y);
			x = y;
			y = z;
			count = BigInteger::subtractStr(count, "1");
		}
		return y;
	}
}
	
BigInteger* BigInteger::add(BigInteger* A, BigInteger* B) {
	std::string new_num = BigInteger::addStr(A->num, B->num);
	return new BigInteger(new_num);
}

BigInteger* BigInteger::subtract(BigInteger* A, BigInteger* B) {
	//Check to see which is greater..
	std::string new_num = BigInteger::subtractStr(A->num, B->num);
	return new BigInteger(new_num);	
}
	
BigInteger* BigInteger::multiply(BigInteger* A, BigInteger* B) {	
	std::string new_num = BigInteger::multiplyStr(A->num, B->num);
	return new BigInteger(new_num);
}

bool BigInteger::isStrNum(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		int curr = (int) str.at(i);
		//printf("%d: %c: %d\n", i+1, str.at(i), curr);
		// check if 10 to 19
		if (curr >= 58 || curr <= 47) 
			return false;
	}
	//printf("%s is a num string\n", str.c_str());
	return true;
}

std::string BigInteger::replace(std::string str, int n, int a) {
	std::ostringstream ss;
	ss << a;
	return str.substr(0,n) + ss.str() + str.substr(n+1, str.length() - (n+1));
}
std::string BigInteger::trimZeroes(std::string a) {
	if (a.compare("0") == 0 || a.length() == 0) 
		return a;
	int firstN = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) != '0') 
			break;
		else
			firstN++;
	}
	return a.substr(firstN, a.length() - firstN);
}


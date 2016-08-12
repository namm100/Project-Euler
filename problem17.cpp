#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

/*
Sum the number of letters from 1 to 1000
using british spelling
*/

using namespace std;

string to_string(int n) {
	ostringstream oss;
	oss << n;
	return oss.str();
}
int to_int(string n) {
	int s = atoi(n.c_str());
	return s;
}

string getFirstDigit(int num) {
	switch (num) {
		case 0:
			return "";
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		default:
			return "ERR";
	}
}

string getTeenWord(int num) {
	switch (num) {
		case 10:
			return "ten";
		case 11:
			return "eleven";
		case 12:
			return "twelve";
		case 13:
			return "thirteen";
		case 14:
			return "fourteen";
		case 15:
			return "fifteen";
		case 16:
			return "sixteen";
		case 17:
			return "seventeen";
		case 18:
			return "eighteen";
		case 19:
			return "nineteen";
		default:
			return "ERR";
	}	
}

string getSecondDigit(int num) {
	switch (num) {
		
		case 1: case 0:
			return "";
		case 2:
			return "twenty";
		case 3:
			return "thirty";
		case 4:
			return "forty";
		case 5:
			return "fifty";
		case 6:
			return "sixty";
		case 7:
			return "seventy";
		case 8:
			return "eighty";
		case 9:
			return "ninety";
		default:
			return "ERR";
	}
}


string getWrittenWord(int num) {
	string num_str = to_string(num);
	int num_digits = num_str.length();
	//printf("%s has %d digits\n", num_str.c_str(), num_digits);
	if (num_digits == 0)
		return "";
	if (num_digits == 1)
		return getFirstDigit(num);
	if (num_digits == 2) {
		if (num >= 10 && num <= 19) {
			return getTeenWord(num);
		}
		int f_int = to_int(num_str.substr(0,1));
		string f = getSecondDigit(f_int);
		int s_int = to_int(num_str.substr(1,1));
		string s = getWrittenWord(s_int);
		return f + " " + s;
	}
	if (num_digits == 3) {
		int f_int = to_int(num_str.substr(0,1));
		string f = getWrittenWord(f_int) + " hundred ";
		
		int s_int = to_int(num_str.substr(1,2));
		if (s_int == 0) {
			return f;
		}
		f += "and ";
		string s = getWrittenWord(s_int);
		return f + s;
	}
	if (num_digits == 4) {
		return "one thousand";
	}
	return "TOO MANY DIGITS";
}

string clip_whitespace(string s) {
	string n = "";
	for (int i = 0; i < s.length(); i++) {
		string curr(1, s.at(i));
		if (curr != " ")
			n += curr;
	}
	return n;
}

int main(int agc, const char** argv) {
	int num_letters = 0;
	for (int i = 1; i <= 1000; i++) {
		string curr = getWrittenWord(i);
		string curr_white = clip_whitespace(curr);
		num_letters += curr_white.length();
		printf("%d: %s\n", i, curr_white.c_str());
	}
	printf("total letters:%d\n", num_letters);
	return 0;
}

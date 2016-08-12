#include <stdio.h>
#include <string>
#include <sstream>

/*find the largest palindrome made from the product of two 3 digit numbers*/

using namespace std;

string reverse(string str) {
	string str_rev = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		string letter(1, str.at(i));
		str_rev = str_rev + letter;
	}
	return str_rev;
}

bool is_palindrome(int number) {
	string num_str = static_cast<ostringstream*>( &(ostringstream() << number) )->str();
	int len = num_str.length();
	if (len % 2 == 0) {
		string first_half = num_str.substr(0, len / 2);
		string second_half = num_str.substr(len / 2, len / 2);
		string rev_sec_half = reverse(second_half);
		if (first_half.compare(rev_sec_half) == 0) {
			return true;
		} else {
			return false; 
		}
	} else {
		string first_half = num_str.substr(0, (len - 1) / 2);
		string second_half = num_str.substr((len + 1) / 2, (len - 1) / 2);	
		string rev_sec_half = reverse(second_half);
		if (first_half.compare(rev_sec_half) == 0) {
			return true;
		} else {
			return false;	
		}
	}
}

int main(int argc, char** argv) {
	int greatest_pal = -1;
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			int k = i * j;
			if (is_palindrome(k)) {
				if (greatest_pal == -1) {
					greatest_pal = k;
				} else {
					if (k > greatest_pal) {
						greatest_pal = k;
					}
				}
			}
		}
	}
	printf("Greatest Palindrome: %d\n", greatest_pal);		
	return 0;
}

#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>

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

void printVect(vector<int> a) {
	printf("< ");
	for (int i =0; i < a.size(); i++) {
		printf("%d ", a.at(i));
	}
	printf(">\n");
}

vector<int> parseString(string ab) {
	vector<int> a;
	string roll = "";
	for (int i = 0; i < ab.length(); i++) {
		string curr(1, ab.at(i));
		if (curr.compare(" ") == 0) {
			int roll_int = to_int(roll);
			a.push_back(roll_int);
			roll = "";
		} else if(i == ab.length() - 1) {
			roll += curr;
			int roll_int = to_int(roll);
			a.push_back(roll_int);
		} else {
			roll += curr;
		}
	}
	
	// omit whitespace
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i)  == 0)
			a.erase(a.begin()+i);	
	}
	return a;
}

int main(int argc, const char** argv) {

	vector<string> triangle;
	triangle.push_back("75");
	triangle.push_back("95 64");
	triangle.push_back("17 47 82");
	triangle.push_back("18 35 87 10");
	triangle.push_back("20 04 82 47 65");
	triangle.push_back("19 01 23 75 03 34");
	triangle.push_back("88 02 77 73 07 63 67");
	triangle.push_back("99 65 04 28 06 16 70 92");
	triangle.push_back("41 41 26 56 83 40 80 70 33");
	triangle.push_back("41 48 72 33 47 32 37 16 94 29");
	triangle.push_back("53 71 44 65 25 43 91 52 97 51 14");
	triangle.push_back("70 11 33 28 77 73 17 78 39 68 17 57");
	triangle.push_back("91 71 52 38 17 14 91 43 58 50 27 29 48");
	triangle.push_back("63 66 04 68 89 53 67 30 73 16 69 87 40 31");
	triangle.push_back("04 62 98 27 23 09 70 98 73 93 38 53 60 04 23");
	vector< vector<int> > tri;
	for (int i =0; i < triangle.size(); i++) {
		tri.push_back(parseString(triangle.at(i)));
	}	
	// print tri
	for (int i = 0; i < tri.size(); i++) {
		printVect(tri.at(i));	
	}
	
	//
	int rolling_sum = 0;
	int curr_index 0;
	for (int i = 0; i < tri.size(); i++) {
		
	}
	return 0;
}

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>

/*Find the score of each word in the list
a score of a word is the sum of the place
of each letter in the alphabet
multiply the score by place of the word in the alphabetized list
*/
using namespace std;

void printVector(vector<string> A) {
	printf("{\n");
	for (int i = 0; i < A.size(); i++) {
		printf("%s\n", A.at(i).c_str());
	}
	printf("}\n");
}

vector<string> parseString(string text, char pattern) {

	vector<string> A;
	
	string curr = "";
	for (int i = 0; i < text.length(); i++) {
		char currChar = text.at(i);
		if (currChar == pattern) {
			A.push_back(curr);
			curr = "";
		} else if(i == text.length() - 1) {
			string currStr = text.substr(i,1);
			curr += currStr;
			A.push_back(curr);
			curr = "";
		} else {
			string currString = text.substr(i,1);
			curr += currString;
		}
	}
	return A;
}

bool isBefore(string a, string b) {
	return a.compare(b) < 0;
}


vector<string> alphabetize(vector<string> A) {

	vector<string> toSend;
	int initSize = (int) A.size();
	for (int i = 0; i < initSize; i++) {
		int low = 0;
		string low_str = A.at(0);
		for (int i = 1; i < A.size(); i++) {
			if (isBefore(A.at(i), low_str)) {
				low = i;
				low_str = A.at(i);
			}
		}
		toSend.push_back(low_str);
		// delete at that index
		A.erase(A.begin() + low);
		/*
		find lowest in alphabet
		delete that word
		add that word to the back of toSend
		iterate till all is done
		*/	
	}
	return toSend;
}

int getWordScore(string str) {
	int roll = 0;
	for (int i = 0; i < str.length(); i++) 
		roll += ((int) str.at(i)) - 64;
	return roll;
}

long getNamesScore(vector<string> A) {
	long roll = 0L;
	for (int i = 0; i < A.size(); i++) {
		string curr_str = A.at(i);
		int factor = i+1;
		int score = getWordScore(curr_str);
		roll += (long) (score * factor);
		printf("%d: %s: %d\n",  factor, curr_str.c_str(), score);
	}
	return roll;
}

int main(int argc, char** argv) {

	ifstream myReadFile;
	myReadFile.open("names22mod.txt");
	string text;
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			string local;
			getline(myReadFile, local);
			if (local != "")
				text = local;
		}
	}

	vector<string> names = parseString(text, ',');
	vector<string> ordered_names = alphabetize(names);
	//printVector(ordered_names);

	long score = getNamesScore(ordered_names);
	printf("score: %lu\n", score);
	
	myReadFile.close();
	return 0;
}

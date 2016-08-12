#include <stdio.h>
#include "BigInteger.h"
#include <string>

using namespace std;


int main(int argc, char** argv) {
	
	string a = "7";
	string fb = "0";
	string res = BigInteger::powStr(a,fb);
	
	printf("%s - %s = %s\n", a.c_str(), fb.c_str(), res.c_str());
	
	return 0;
}

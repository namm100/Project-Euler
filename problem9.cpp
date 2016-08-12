#include <stdio.h>
#include <math.h>

/*
There exists exactly one Pythagorean triplet for which a+b+c= 1000
find the product a*b*c
*/
using namespace std;

bool is_int(double a) {
	double a_int = (double) ((int) a);
	return (a - a_int == 0);
}

bool is_triple(double a, double b, double c) {
	double rhs = a * a + b * b;
	double lhs = c * c;
	if (rhs == lhs && is_int(lhs)) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char** argv) {
	
	double a,b,c;
	bool found = false;
	for (int i = 1; i < 500; i++) {
		if (found)
			break;
		for (int j = 1; j < 500; j++) {
			double c_temp = sqrt( i*i + j*j);
			if (is_triple(i, j, c_temp)) {
				if (i + j + c_temp == 1000) {
					a = i;
					b = j;
					c = c_temp;
					found = true;
					break;
				}
			}
		}
	}	
	double prod = a * b * c;
	printf("a:%d b:%d c:%d prod:%d\n",(int) a, (int)  b,(int) c,(int) prod);
	return 0;
}

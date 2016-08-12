#include <stdio.h>
#include <vector>
#include <cmath>
/*
Starting in the top left corner of a 2x2 grid, only able 
to move up and down, there are 6 possible routes
how many routes through a 20x20?
*/

using namespace std;

void print_arr2D(int rows, int cols, int** A) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int curr = A[i][j];
			if (curr < 10) 
				printf("0%d ", curr);
			else
				printf("%d ", curr);
		}
		printf("\n");
	}
}

int** create_arr2D(int n) {
	int count = 0;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 1; j <= n; j++) {
			arr[i][j-1] = count + j;
		}
		count++;
	}
	return arr;
}

int num_possible_routes(int n) {

	return 0; // temp	
}

class Path {

public:
	vector<int> rows;
	vector<int> cols;
	vector<int> values;
	void add(int row, int col, int value);
	
};
int main(int argc, const char** argv) {
	int** arr = create_arr2D(20);
	print_arr2D(20, 20, arr);
	delete[] arr;
	return 0;
}

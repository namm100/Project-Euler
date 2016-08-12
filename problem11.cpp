#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector> 

/*
What is the greatest product of four adjacent numbers in the
same direction (up, down, left, right, diagonally) in the
grid?
*/

using namespace std;

void print_arr(int len, int* A) {
	for (int i = 0; i < len; i++)
		printf("at[%d]:%d\n", i, A[i]);
}

void print_arr2D(int row, int col, int** A) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (A[i][j] < 10) 
				printf("0%d ", A[i][j]);
			else
				printf("%d ", A[i][j]);	
		}
		printf("\n");
	}
	printf("\n");
}	

void print_arr(int len, string* A) {
	for (int i = 0; i < len; i++)
		printf("at[%d]:%s\n", i, A[i].c_str());
}


int* parse_string(string str,int part_size) {
	vector<int> list;
	for (int i = 0; i <= (str.length() - part_size) ; i+=part_size) {
		string curr_str = str.substr(i,part_size);
		int curr_int = atoi(curr_str.c_str());
		list.push_back(curr_int);
	}
	int* arr = new int[list.size()];
	for (int i = 0; i < list.size(); i++) {
		arr[i] = list.at(i);
	}
	return arr;
}

string* break_string(string str, string letter) {
	vector<string> list;
	string curr = "";
	for (int i = 0; i < str.length(); i++) {
		string curr_let = string(1, str.at(i));
		if (curr_let.compare(letter) == 0) {
			list.push_back(curr);
			curr = "";
		} else {
			curr = curr + curr_let;
		}	
	}
	
	string* arr = new string[list.size()];
	for (int i = 0; i < list.size(); i++) {
		arr[i] = list.at(i);
	}
	return arr;	
}

int vector_max(vector<int> arr) {
	if (arr.size() == 0) 
		return 0;
	if (arr.size() == 1)
		return arr.at(0);
	int biggest = arr.at(0);
	for (int i = 1; i < arr.size(); i++) {
		if (arr.at(i) > biggest) {
			biggest = arr.at(i);
		}
	}
	return biggest;
}
 
int max_prod(int len, int* A, int split) {
	int curr_prod = 1;
	vector<int> arr;
	for (int i = 0; i <= len-split; i++) {
		for (int j = i; j < i+split; j++) {
			curr_prod *= A[j];
		}
		arr.push_back(curr_prod);
		curr_prod = 1;
	} 
	int max_val = vector_max(arr);
	return max_val;	
}

int max_row_prod(int rows, int cols, int**A, int split) {
	vector<int> arr_maxs;
	for (int i = 0; i < rows; i++) {
		arr_maxs.push_back(max_prod(cols, A[i], split));
	}
	int max = vector_max(arr_maxs);
	return max;
}

int max_col_prod(int rows, int cols, int** A, int split) {
	// transpose A
	int** A_t = new int*[cols];
	for (int i = 0; i < cols; i++) {
		A_t[i] = new int[rows];	
	}
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			A_t[i][j] = A[j][i];
		}
	}
	int max = max_row_prod(cols, rows, A_t, 4);
	delete[] A_t;
	return max;
	
}

int max_diag_prod_foward(int rows, int cols, int** A, int split) {
	vector< vector<int> > elem;
	// UP AND DOWN	
	for (int i = rows - split; i >= 0; i--) {
		vector<int> curr_v;
		int j, temp_i;
		for (j = 0, temp_i = i; temp_i < rows && j < cols; j++, temp_i++) {
			curr_v.push_back(A[temp_i][j]);
		} 
		elem.push_back(curr_v);
	}
	// SIDE TO SIDE
	// i is the column second elem
	for (int i = cols - split; i >= 0; i--) {
		vector<int> curr_v;
		int j, temp_i;
		for (j = 0, temp_i = i; (temp_i < rows) && (j < cols); j++, temp_i++) {
			curr_v.push_back(A[j][temp_i]);
		}
		elem.push_back(curr_v);
	}

	int biggest = 0;
	for (int i = 0; i < elem.size(); i++) {
		int curr_size = elem.at(i).size();
		int curr_arr[curr_size];
		for (int j = 0; j < curr_size; j++) {
			curr_arr[j] = elem.at(i).at(j);
		}
		int curr_max = max_prod(curr_size, curr_arr, split);
		if (curr_max > biggest) {
			biggest = curr_max;
		}
	}
	return biggest;
}

int* reverse(int len, int* A) {
	int* rev = new int[len];
	for (int i = 0; i < len; i++) {
		int from = (len - i) - 1;
		rev[i] = A[from];
	}
	return rev;
}

int max_diag_prod_backwards(int rows, int cols, int** A, int split) {
	// FLIP THE ARRAY AROUND THE VERTICAL AXES
	int** rev_arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		rev_arr[i] = reverse(cols, A[i]);
	}
	int maximum = max_diag_prod_foward(rows, cols, rev_arr, split);
	delete[] rev_arr;
	return maximum;
}
	
int main(int argc, char** argv) {
	string to_parse = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 ?49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 ?81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 ?52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 ?22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 ?24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 ?32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 ?67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 ?24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 ?21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 ?78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 ?16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 ?86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 ?19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 ?04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 ?88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 ?04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 ?20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 ?20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 ?01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 ?";
	
	string* broken_str = break_string(to_parse, "?");
	int** num_arr = new int* [20];
	for (int i = 0; i < 20; i++) {
		num_arr[i] = parse_string(broken_str[i], 3);
	}
	vector <int> maxs;
	
	int row_max = max_row_prod(20, 20, num_arr, 4);
	printf("row max:%d\n", row_max);
	maxs.push_back(row_max);
	int col_max = max_col_prod(20, 20, num_arr, 4);
	printf("col max:%d\n", col_max);
	maxs.push_back(col_max);
	int diag_max_foward = max_diag_prod_foward(20, 20, num_arr, 4);
	printf("diagonal max foward:%d\n", diag_max_foward);
	maxs.push_back(diag_max_foward);
	int diag_max_backwards = max_diag_prod_backwards(20, 20, num_arr, 4);
	printf("diagonal max backwards:%d\n", diag_max_backwards);
	maxs.push_back(diag_max_backwards);
	
	int max = vector_max(maxs);
	printf("max product:%d\n", max);

	delete[] broken_str;
	delete[] num_arr;
	return 0;
	
}

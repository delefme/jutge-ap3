#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> MI;

MI res;
int NMAX = 500;

int FSIZE = 0;
int ISIZE = 0;

bool inbounds(int i, int j) {
	return i >= 0 and j >= 0 and i <= ISIZE and j < FSIZE;
}

int corners(int i, int j) {
	int sum = 0;
	if (inbounds(i, j - 1)) sum += res[i][j - 1];
	if (inbounds(i - 1, j)) sum += res[i - 1][j];
	if (inbounds(i - 1, j - 1)) sum -= res[i - 1][j - 1];
	return sum;
}

// Use: 1 + ... + n = n*(n+1)/2
int getval(char c) {
	int n = c - 'A' + 1;
	return n*(n+1)/2;
}

void print_matrix(const MI& A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j > 0) cout << " ";
			cout << A[i][j]; 
		}
		cout << endl;
	}
}

int main() {
	string f;
		
	// Set empty matrix
	res = MI (0, VI (0));
	
	while (cin >> f) {
		// Set the matrix
		if (res.size() == 0) {
			FSIZE = f.size();
			res = MI (NMAX, VI (FSIZE, 0));
		}
		
		// For each character in f
		// add it to the last row of the matrix
		int j = 0;
		for (char c : f) {
			res[ISIZE][j] = getval(c);
			res[ISIZE][j] += corners(ISIZE, j);
			++j;
		}
		
		++ISIZE;
	}
	
	print_matrix(res, ISIZE, FSIZE);
}

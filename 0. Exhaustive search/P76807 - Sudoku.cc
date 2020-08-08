#include <iostream>
#include <vector>
using namespace std;

using VC = vector<char>;
using MC = vector<VC>;

using VE = vector<int>;
using ME = vector<VE>;

using VB = vector<bool>;
using MB = vector<VB>;

ME pos;
MB sub;
MC sudo;

bool done;

void write(MC& A) {
	for (int i = 0; i < 9; ++i) {
		cout << endl;
		for (int j = 0; j < 9; ++j) {
			if (j != 0) cout << " ";
			cout << A[i][j] - '0';
		}
	}
}

int subset(int i, int j) {
	if ((0 <= i and i <= 2) and (0 <= j and j <= 2)) return 0;
	if ((3 <= i and i <= 5) and (0 <= j and j <= 2)) return 1;
	if ((6 <= i and i <= 8) and (0 <= j and j <= 2)) return 2;
	
	if ((0 <= i and i <= 2) and (3 <= j and j <= 5)) return 3;
	if ((3 <= i and i <= 5) and (3 <= j and j <= 5)) return 4;
	if ((6 <= i and i <= 8) and (3 <= j and j <= 5)) return 5;

	if ((0 <= i and i <= 2) and (6 <= j and j <= 8)) return 6;
	if ((3 <= i and i <= 5) and (6 <= j and j <= 8)) return 7;
	if ((6 <= i and i <= 8) and (6 <= j and j <= 8)) return 8;
}

int toNum(char c) {
	return c - '0';
}

char toChar(int n) {
	return (char) (n + '0');
}

bool legal(int num, int i, int j) {
	if (sub[num][subset(i,j)]) return false;
	if (pos[num][i] > -1) return false;
	for (int c = 0; c < 9; ++c) {
		if (c == i) continue;
		if (sudo[c][j] == sudo[i][j]) return false;
	}
	return true;
}

void first_check() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (sudo[i][j] != '.') {
				int num = toNum(sudo[i][j]) - 1;
				pos[num][i] = j;
				sub[num][subset(i,j)] = true;
			}
		}
	}
}

void solve(int i, int j) {
	if (done) return;
	if (j >= 9) solve(i + 1, 0);
	else if (i >= 9) {
		write(sudo);
		done = true;
	} else if (sudo[i][j] != '.') solve(i, j + 1);
	else {
		// cout << i << " " << j << endl;
		for (int k = 0; k < 10; ++k) {
			if (k == 9) {
				sudo[i][j] = '.';
			} else {
				sudo[i][j] = toChar(k + 1);
				if (legal(k, i, j)) {
					pos[k][i] = j;
					sub[k][subset(i,j)] = true;
					solve(i, j + 1);
					pos[k][i] = -1;
					sub[k][subset(i,j)] = false;
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	cout << n;
	
	for (int k = 0; k < n; ++k) {
		done = false;

		sudo = MC(9, VC(9));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cin >> sudo[i][j];
			}
		}
		
		pos = ME(9, VE(9, -1));
		sub = MB(9, VB(9, false));
		first_check();
		cout << endl;
		solve(0, 0);
	}
	cout << endl;
}
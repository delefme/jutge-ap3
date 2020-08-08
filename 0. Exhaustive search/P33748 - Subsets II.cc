#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VB = vector<bool>;
using VS = vector<string>;

int n;
VS llista;
VB contained;

void print_subset() {
	bool first = true;
	cout << "{";
	for (int i = 0; i < n; i++) {
		if (contained[i]) {
			if (first) first = false;
			else cout << ","; 
			cout << llista[i];
		}
	}
	cout << "}" << endl;
}

void allperms(int i, int r) {
	if (r < 0) return;
    // Espais que queden menors als uns que ens falta posar
    if (n - i < r) return;
	
	if (i == n) {
		if (r == 0) print_subset();
	} else {
		contained[i] = false; allperms(i + 1, r);
		contained[i] = true; allperms(i + 1, r - 1);
	}
}

int main() {
	int r;
	cin >> r >> n;
	
	contained = VB(n);
	llista = VS(n);
	
	for (string& e : llista) cin >> e;
	allperms(0, r);
}


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

void allperms(int i) {
	if (i == n) {
		print_subset();
	} else {
		contained[i] = false; allperms(i + 1);
		contained[i] = true; allperms(i + 1);
	}
}

int main() {
	cin >> n;
	
	contained = VB(n);
	llista = VS(n);
	
	for (string& e : llista) cin >> e;
	allperms(0);
}


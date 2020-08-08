#include <iostream>
#include <vector>
using namespace std;

int n;
string vocs, cons;
vector<bool> usedvocs, usedcons;

void print_word(vector<char>& word) {
	for (char c : word) cout << c;
	cout << endl;
}

void search(int k, vector<char>& word) {
	if (k == 2*n) {
		print_word(word);
	} else if (k%2 == 0) {
		for (int i = 0; i < n; ++i) {
			char c = cons[i];
			if (not usedcons[i]) {
				word[k] = c;
				usedcons[i] = true;
				search(k + 1, word);
				usedcons[i] = false;
			}
		}
	} else {
		for (int i = 0; i < n; ++i) {
			char c = vocs[i];
			if (not usedvocs[i]) {
				word[k] = c;
				usedvocs[i] = true;
				search(k + 1, word);
				usedvocs[i] = false;
			}
		}
	}
}

int main() {
	cin >> n >> cons >> vocs;
	usedvocs = vector<bool> (n, false);
	usedcons = vector<bool> (n, false);
	vector<char> word(2*n); 
	search(0, word);
}
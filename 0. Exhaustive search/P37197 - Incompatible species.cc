#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<bool> VB;
typedef vector<VB> MB;

MB incomp;
VC species;
VB used;
int n;

void print_word(const VC& word) {
	for (char c : word) cout << c;
	cout << endl;
}

void search(int k, VC& word) {
	if (k == n) {
		print_word(word);
	} else {
		for (int i = 0; i < n; ++i) {
			char s = species[i];
		
			if (used[i]) continue;
			if (k > 0 and incomp[word[k-1]][s]) continue;
			
			word[k] = s;
			used[i] = true;
			search(k + 1, word);
			used[i] = false;
		}
	}
}

int main() {
	cin >> n;
	species = VC (n);
	for (char& s : species) cin >> s;
	
	int m;
	cin >> m;
	int SIZE_INCOMP = max('z','Z') + 1;
	incomp = MB (SIZE_INCOMP, VB (SIZE_INCOMP, false));
	
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		incomp[s[0]][s[1]] = true;
		incomp[s[1]][s[0]] = true;
	}
	
	VC word(n);
	used = VB (n, false);
	search(0, word);
}

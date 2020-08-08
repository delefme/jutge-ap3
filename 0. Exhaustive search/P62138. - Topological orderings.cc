#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> MI;

typedef vector<bool> VB;
typedef vector<VB> MB;

MI before;
VI count;
int n, m;

void print_ordering(const VI& ordering) {
	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << " ";
		cout << ordering[i];
	}
	cout << endl;
}

void search(int k, VI& ordering) {
	if (k == n) {
		print_ordering(ordering);
	} else {
		for (int i = 0; i < n; ++i) {
			if (count[i] == 0) {
				--count[i]; // ~ used[i] = true
				for (int b : before[i]) --count[b];
				ordering[k] = i;
				search(k + 1, ordering);
				for (int b : before[i]) ++count[b];
				++count[i];
			}
		}
	}
}

int main() {
	cin >> n >> m;
	before = MI (n, VI (0));
	count = VI (n, 0);
	for (int i = 0; i < m; ++i) {
		int s, f; cin >> s >> f;
		before[s].push_back(f);
		++count[f];
	}
	
	VI ordering(n);
	search(0, ordering);
}

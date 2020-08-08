#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int INF = 1e9;
int m = 0;

vector<int> cardsval = {1, 5, 8, 14};

void fill_numcards(vector<int>& numcards) {
	numcards[0] = 0;
	for (int i = 0; i < m + 1; ++i) {
		for (int val : cardsval) {
			if (i >= val) {
				numcards[i] = min(numcards[i],
						numcards[i - val] + 1);
			}
		}
	}
}

int main() {
	int n;
	queue<int> cua;
	while (cin >> n and n > -1) {
		cua.push(n);
		m = max(m, n);
	}
	
	vector<int> numcards(++m, INF);
	fill_numcards(numcards);
	
	while (not cua.empty()) {
		n = cua.front(); cua.pop();
		cout << numcards[n] << endl;
	}
	
}

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> MI;

VI arthur, bob;
MI common;

int find_common(int n, int m) {
	// If known, return the value
	if (common[n][m] > -1) return common[n][m];
	// If one of them is 0 it means there's no score to compare
	if (n == 0 or m == 0) return common[n][m] = 0;
	
	if (arthur[n - 1] == bob[m - 1]) {
		// If last score is the same +1
		return common[n][m] = 1 + find_common(n - 1, m - 1);
	} else {
		// Check which has the longest common score,
		// removing one of arthur or one of bob
		return common[n][m] = max(find_common(n - 1, m),
					find_common(n, m - 1));
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		arthur = VI (n, 0);
		bob = VI (m, 0);
		
		for (int& score : arthur) cin >> score;
		for (int& score : bob) cin >> score;
		
		common = MI (n + 1, VI (m + 1, -1));
		cout << find_common(n, m) << endl;
	}
}

#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using MI = vector<VI>;

int C;
VI costos;
string s, z;
MI saved;

int cost(int p, bool is_s) {
	if (is_s) return costos[s[p] - 'a'];
	else return costos[z[p] - 'a'];
}

int total(int n, int m) {
	if (saved[n][m] > -1) return saved[n][m];
	if (n == 0 and m == 0) return saved[0][0] = 0;
	if (n == 0) return saved[0][m] = cost(m - 1, 0) + total(n, m - 1);
	if (m == 0) return saved[n][0] = cost(n - 1, 1) + total(n - 1, m);
	
	if (s[n - 1] == z[m - 1]) return saved[n][m] = 0 + total(n - 1, m - 1);
	else return saved[n][m] = min(cost(n - 1, 1) + total(n - 1, m),
							cost(m - 1, 0) + total(n, m - 1));
}

int main() {
	while (cin >> C) {
		costos = VI (C);
		for (int& val : costos) cin >> val;
		cin >> s >> z;
		saved = MI (s.size() + 1, VI (z.size() + 1, -1));
		cout << total(s.size(), z.size()) << endl;
	}
}

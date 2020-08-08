#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vec;

int n, u;
Vec V;

void write() {
	cout << V[0];
	for(int i = 1; i < V.size(); ++i) {
		cout << " " << V[i];
	}
	cout << endl;
}

void zeros(int i, int uns) {
    if (n - i < uns or uns < 0) return;
    
    if (i == n) {
        if (uns == 0) write();
    } else {
        V[i] = 0; zeros(i + 1, uns);
        V[i] = 1; zeros(i + 1, uns - 1);
    }
}

int main() {
	cin >> n >> u;
	V = Vec(n);
	zeros(0, u);
}
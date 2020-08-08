#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

void write(const vector<int>& w) {
    int m = w.size();
    for (int i = 0; i < m; ++i) {
        if (i != 0) cout << " ";
        cout << w[i];
    }
    cout << endl;
}

void zeros(int i) {
    if (i == n) {
        write(v);
    } else {
        v[i] = 0; zeros(i + 1);
        v[i] = 1; zeros(i + 1);
    }
}

int main() {
    cin >> n;
    v = vector<int> (n);
    zeros(0);
}
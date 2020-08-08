#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VB = vector<bool>;

int n, S;
VE els;
VB cont;

void write_subset() {
    bool first = true;
    cout << "{";
    for (int i = 0; i < n; ++i) {
        if (cont[i]) {
            if (first) first = false;
            else cout << ",";
			
            cout << els[i];
        }
    }
    cout << "}";
    cout << endl;
}

void rec(int s, int i, bool new_el, int total) {
    if (s > S) return;
    if (s + total < S) return;
    if (s == S and new_el) write_subset();
    
    if (i < n) {
        total -= els[i];
        cont[i] = true; rec(s + els[i], i + 1, true, total);
        cont[i] = false; rec(s, i + 1, false, total);
    }
}

int main() {
    cin >> S >> n;
    els = VE(n);
    cont = VB(n);
	
    int total = 0;
    for (int& e : els) {
        cin >> e;
        total += e;
    }

    rec(0, 0, true, total);
}
#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VB = vector<bool>;

int n, S;
VE nums;
VB cont;

void write_subset() {
    bool first = true;
    cout << "{";
    for (int i = 0; i < n; ++i) {
        if (cont[i]) {
            if (first) first = false;
            else cout << ",";
			
            cout << nums[i];
        }
    }
    cout << "}";
    cout << endl;
}

void rec(int s, int i, bool new_el) {
    if (s == S and new_el) write_subset();
    
    if (i < n) {
        cont[i] = true; rec(s + nums[i], i + 1, true);
        cont[i] = false; rec(s, i + 1, false);
    }
}

int main() {
    cin >> S >> n;
    nums = VE(n);
    for (int& e : nums) cin >> e;
    cont = VB(n);
    rec(0, 0, true);
}
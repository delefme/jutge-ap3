#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n, k;
VI v;
VB used;

void escriu(vector<int>& V) {
    cout << '(';
    for (int j = 0; j < V.size(); ++j) {
        if(j != 0) cout << ',';
        cout << V[j]+1;
    }
    cout << ')' << endl;
}

void f(int i, int inv) {
    if(k < inv or k > inv + ((n-i)*(n-i-1))/2) return;
    if(i == n) {
        escriu(v);
        return;
    }
    int compt = 0;
    for(int j = 0; j < n; ++j) {
        if(not used[j]) {
            used[j] = true;
            v[i] = j;
            f(i+1, inv + compt);
            used[j] = false;
            ++compt;
        }
    }
    return;
}

int main() {
    while(cin >> n >> k){
        v = VI(n);
        used = VB(n, false);
        f(0, 0);
    }
}

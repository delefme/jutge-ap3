#include <iostream>
#include <vector>
using namespace std;

using VL = vector<long long>;

int NMAX = 67;
VL cats;

void get_catalans() {
    cats[0] = 0;
    cats[1] = 1;
    for (int k = 2; k < NMAX; ++k) {
        cats[k] = 2*(2*k - 1) * cats[k-1];
        cats[k] /= k + 1;
    }
}

int main() {
    cats = VL(NMAX);
    get_catalans();
    
    int n;
    while (cin >> n) {
        if (n%2 == 0) cout << cats[n/2] << endl;
        else cout << 0 << endl;
    }
}

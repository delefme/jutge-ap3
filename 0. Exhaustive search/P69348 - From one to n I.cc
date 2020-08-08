#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>;
using VB = vector<bool>;

int n;
VB use_it;
VE perm;

void write() {
    cout << "(";
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ",";
        cout << perm[i] + 1;
    }
    cout << ")";
    cout << endl;
}

void allperms(int k) {
    if (k == n) {
		write();
    } else {
        for (int i = 0; i < n; ++i) {
            if (use_it[i]) {
                use_it[i] = false;
		
				perm[k] = i;
				allperms(k + 1);
					
                use_it[i] = true;
            }
        }
    } 
}

int main() {
    cin >> n;
    use_it = VB(n, true);
    perm = VE(n);
    allperms(0);
}


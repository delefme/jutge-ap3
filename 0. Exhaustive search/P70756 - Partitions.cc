#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VE = vector<int>;

int n, p;
VS set;
VE contained;

void write_partition() {
    for (int j = 0; j < p; ++j) {
        cout << "subset " << j + 1 << ": ";
        cout << "{";
		
		bool first = true;
        for (int i = 0; i < n; ++i) {
            if (contained[i] == j) {
                if (first) first = false;
                else cout << ',';
				
                cout << set[i];
            }
        }
		
        cout << "}";
        cout << endl;
    }
    
    cout << endl;
}

void allperms(int i) {
    if (i == n) {
        write_partition();
    } else {
        for (int k = 0; k < p; ++k) {
            contained[i] = k; allperms(i + 1);
        }
    }
}

int main() {
    cin >> n;
    set = VS(n);
	contained = VE(n);
    for (string& e : set) cin >> e;
    cin >> p;
    allperms(0);
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(),v.end());
        int x;
        cin >> x;
        vector<int> w(x, -1);
        int imax = 0;
        for (int i = v[0]-1; i < x; ++i) {
            if(i == v[imax]-1) {
                w[i] = v[imax];
                if(imax < n-1)++imax;
            }
            else for(int j = imax; j >= 0; --j) {
                if(i >= v[j] and w[i-v[j]] > 0) {
                    w[i] = v[j];
                    j = -1;
                }
            }
        }
        if(w[x-1] == -1) cout << -1 << endl;
        else {
            int val = x-1;
            bool principi = true;
            while(val >= 0) {
                if(principi) principi = false;
                else cout << ',';
                cout << w[val];
                val -= w[val];
            }
            cout << endl;
        }
    }
}

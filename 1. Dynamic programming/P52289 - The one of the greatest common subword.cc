#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool es_mes_petit(string& s, int j, int pos, int& maxsize) {
    for (int i = 0; i < maxsize; ++i) {
        if (s[j-maxsize+i]-s[pos-maxsize+i] < 0) return true;
        else if (s[j-maxsize+i]-s[pos-maxsize+i] > 0) return false;
    }
    return true;
}

int main() {
	string s, t;
	while (cin >> s >> t) {
		int n = s.size()+1;
		int m = t.size()+1;
		vector<vector<int> > mat(n, vector<int> (m, 0));
		int maxsize = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if(s[i-1] == t[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
				if(mat[i][j] > maxsize) maxsize = mat[i][j];
			}
		}
		if (maxsize == 0) cout << endl;
		else {
            bool trobat = false;
            int pos;
            for (int i = 1; i < n; ++i) {
                for (int j = 1; j < m; ++j) {
                    if (mat[i][j] == maxsize) {
                        if (not trobat) {
                            pos = i;
                            trobat = true;
                        }
                        else {
                            if (es_mes_petit(s, i, pos, maxsize)) pos = i;
                        }
                    }
                }
            }
            for (int i = 0; i < maxsize; ++i) {
                cout << s[pos-maxsize+i];
            }
            cout << endl;
		}
	}
}

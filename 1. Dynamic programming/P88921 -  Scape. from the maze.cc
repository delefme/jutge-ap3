// Nombre de camins per escapar d'una quadricula amb possibles caselles prohibides. 


#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> V;
typedef vector<V> Taula;
typedef vector<char> C;
typedef vector<C> TaulaChar;


Taula T;
TaulaChar M;
int n, m;



int f(int i, int j) {
  if(i < 0 or j < 0) return 0;

  if (T[i][j] != -1) return T[i][j];
  if (M[i][j] == 'X') return T[i][j] = 0;
  if (i == 0 and j == 0) return T[i][j] = 1;

  T[i][j] = f(i - 1, j) + f(i, j - 1);
  if (T[i][j] >= 1e6) T[i][j] = 1e7;
  return T[i][j];

}


int main() {
  while(cin >> n >> m and n + m > 0) {
    M = TaulaChar(n, C(m));
    T = Taula(n, V(m, -1));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cin >> M[i][j];
    }

    int res = f(n - 1, m - 1);
    if(res > 1e6) cout << "!!!" << endl; 
    else cout << res << endl;
  }
}

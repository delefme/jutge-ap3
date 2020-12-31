#include <iostream>
#include <vector>
using namespace std;


const int N = 91;


typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> Taula;


Taula F0(N, VL(N, -1));
Taula F1(N, VL(N, -1));
Taula F2(N, VL(N, -1));

ll f0(int z, int u);
ll f1(int z, int u);
ll f2(int z, int u);

ll f0(int z, int u) {
  if(z < 0 or u < 0) return 0;
  if(F0[z][u] != -1) return F0[z][u];

  if(z <= 1 and u == 0) {
    F0[z][u] = 1;
    return F0[z][u];
  }

  F0[z][u] = f1(z, u-1) + f0(z-1, u);
  return F0[z][u];
}

ll f1(int z, int u) {
  if(z < 0 or u < 0) return 0;
  if(F1[z][u] != -1) return F1[z][u];

  if(z == 0 and u == 1) {
    F1[z][u] = 1;
    return F1[z][u];
  }

  F1[z][u] = f0(z, u-1) + f2(z-1, u);
  return F1[z][u];
}

ll f2(int z, int u) {
  if(z < 0 or u < 0) return 0;
  if(F2[z][u] != -1) return F2[z][u];

  if(z == 1 and u == 1) {
    F2[z][u] = 1;
    return F2[z][u];
  }

  F2[z][u] = f1(z-1, u) + f2(z, u-1);
  return F2[z][u];
}

int main() {
  int z, u;

  while (cin >> z >> u) {
  	cout << f0(z, u) << endl;
  }
}

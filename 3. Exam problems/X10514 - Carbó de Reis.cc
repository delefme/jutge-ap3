#include <iostream>
#include <vector>
using namespace std;
const int UNDEF = -1;

int n, b, a;

vector<int> p;
vector<int> c;
vector<int> m;
vector<vector<vector<int>>> dp;

/* Inspiració Knapsack. Per cada miner escullo si el contracto o no.
La productivitat serà la suma de les productivitats de cada miner que contracto.
El maxim amb n miners disponibles, b diners disponibles i a kg disponibles és el
maxim entre contractar aquest miner 'n' prenent la maxima prod dels n-1 restants
i no contractar-lo prenent la maxima prod dels n-1 restants.  */
int max_prod(int n, int b, int a) {
  if (n == 0 || b == 0 || a == 0) return 0;  // cas base: no em queden miners, diners, o llocs al ascensor.
  int& res = dp[n][b][a]; // Referència per no escriure tant
  if (res != UNDEF) return res;  // ja hem calculat aquest cas anteriorment

  /* començo a zero per si no el puc contractar, que em fagi maxim amb la segona
   branca recursiva (i sempre es quedi amb la segona que es 'no contractar') */
  int tmp1 = 0;
  /* Si puc el contracto */
  if (c[n] <= b && m[n] <= a) {
    tmp1 = p[n] + max_prod(n - 1, b - c[n], a - m[n]);
  }
  /* No el contracto */
  int tmp2 = max_prod(n - 1, b, a);
  /* maxim entre contractar-lo o no */
  return res = max(tmp1, tmp2);
}

int main() {
  while (cin >> n >> b >> a) {
    /* Declarem els vectors amb n+1 per poder treballar en l'interval [1, n] en comptes de [0, n-1] */
    p = vector<int>(n+1);
    c = vector<int>(n+1);
    m = vector<int>(n+1);
    for (int i = 1; i <= n; ++i) {
      cin >> p[i] >> c[i] >> m[i];
    }
    /* Declarem la matriu de memorització de programació dinàmica. Inicialment a undefined.
     n+1, b+1 i a+1 pel mateix motiu d'abans. */
    dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(b+1, vector<int>(a+1, UNDEF)));
    cout << max_prod(n, b, a) << endl;
  }
}

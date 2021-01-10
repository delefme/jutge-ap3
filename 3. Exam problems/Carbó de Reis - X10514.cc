#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

VI p, c, m;
VVVI M;

const int UNDEF = -1;

int opt(int k, int w1, int w2)
{
	int& res = M[k][w1][w2];
	if(res != UNDEF) return res;
	if(k == 0) return res = 0;
	if(c[k-1] > w1 or m[k-1] > w2) return res = opt(k-1, w1, w2);
	else{
   		return res = max(p[k-1] + opt(k-1, w1 - c[k-1], w2 - m[k-1]), opt(k-1, w1, w2));
	}
}

int main()
{
	int n, a, b;
	while(cin >> n >> a >> b){
		p = c = m = VI(n);
		M = VVVI(n+1, VVI(a+1, VI(b+1, UNDEF)));
		for(int i = 0; i < n; ++i) cin >> p[i] >> c[i] >> m[i];
		cout << opt(n, a, b) << endl;
	}
}
#include <iostream>
#include <vector>
using namespace std;

void gen(int k, vector<int>& s, vector<bool>& b, int l)
{
	if(l == int(s.size())){
		cout << "(" << s[0] +1;
		for(int i = 1; i < int(s.size()); ++i){
			cout << "," << s[i] +1;
		}
		cout << ")" << endl;
	}
	else{
		for(int i = 0; i < int(s.size()); ++i){
			if(i != k and not b[i] and ((s[i] == -1 and l != int(s.size())-1) or (l == int(s.size()) -1))){
				s[k] = i;
				b[i] = true;
				gen(i, s, b, l+1);
				s[k] = -1;
				b[i] = false;
			}
		}
	}
}

int main()
{
	int n; cin >> n;
	vector<int> s(n, -1);
	vector<bool> b(n, false);

	if(n == 1) cout << "(1)" << endl;
	gen(0, s, b, 0);
}
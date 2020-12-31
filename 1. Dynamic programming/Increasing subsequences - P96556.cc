#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	while(cin >> s){
		int n = int(s.size());
		vector<long long int> t(n, 0);

		long long int tot = 0;
		for(int i = 1; i < n; ++i){
			for(int j = 0; j < i; ++j){
				if(s[i] > s[j]) t[i] += 1 + t[j];
			}
			tot += t[i];
		}

		cout << tot << endl;
	}
}
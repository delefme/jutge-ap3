#include <iostream>
#include <vector>
using namespace std;
typedef long long int lint;

int main()
{
	int n, m;
	while(cin >> n >> m){
		vector<lint> c (n, 0);
		c[0] = m;

		for(int i = 0; i < n; ++i){
			if((i+1)%2 == 0) c[i] = 0;
			else{
				for(int n1 = 0; n1 < i -5; n1 += 2){
					int n2 = i - n1 -6;
					c[i] += c[n1]*c[n2];
				}

				if(i > 0) c[i] += c[i -2];
			}
		}

		cout << c[n-1] << endl;
	}
}

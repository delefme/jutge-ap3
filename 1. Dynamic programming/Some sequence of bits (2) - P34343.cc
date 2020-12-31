#include <iostream>
#include <vector>
using namespace std;
typedef long long int lint;

int main()
{
	vector<vector<lint>> s(91, vector<lint> (92, 0));
	s[0][1] = s[1][1] = s[0][2] = s[0][3] = s[1][5] = 1;
	s[1][2] = s[1][4] = 2;
	s[1][3] = 3;

	int z, o;
	while(cin >> z >> o){
		++o;

		for(int i = 2; i <= z; ++i){
			for(int j = 2; j <= o; ++j){
				s[i][j] = s[i-1][j-1] + s[i-1][j-2];
			}
		}

		cout << s[z][o] << endl;
	}
}
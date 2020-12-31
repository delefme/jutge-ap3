#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int k;
	while(cin >> k){
		int n; cin >> n;

		priority_queue<int, vector<int>, greater<int>> pq;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			pq.push(x);
		}

		int prev = 0;
		int s = 0;
		if(n != 0){
			prev = pq.top();
			pq.pop();
			s = 1;
		}

		while(not pq.empty()){
			int curr = pq.top(); pq.pop();

			if(prev + k < curr){
				++s;
				prev = curr;
			}
		}

		cout << s << endl;
	}
}
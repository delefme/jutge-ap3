#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	while(cin >> n){
		priority_queue<int> pq;
		for(int i = 0; i < 3*n; ++i){
			int x; cin >> x;
			pq.push(x);
		}


		int cost = 0;
		int i = 1;
		while(not pq.empty()){
			if(i%3 != 0) cost += pq.top();

			++i;
			pq.pop();
		}

		cout << cost << endl;
	}
}

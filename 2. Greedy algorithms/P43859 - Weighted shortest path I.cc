#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Aresta {
	int target, weight;
};

typedef vector<Aresta> Row;
typedef vector<Row> Graf;

const int INF = 1e9;

int mincost(Graf& G, int x, int y) {
	int n = G.size();
	vector<int> dist(n, INF);
	vector<int> parent(n, INF);
	priority_queue<int> encuats;

	dist[x] = 0;
	
	for (int i = 0; i < n; ++i) encuats.push(i);
	
	while (not encuats.empty()) {
		int u = encuats.top();
		encuats.pop();
		for (auto vei : G[u]) {
			if (dist[u] + vei.weight < dist[vei.target]) {
				dist[vei.target] = dist[u] + vei.weight;
				parent[vei.target] = u;
				encuats.push(vei.target);
			}
		}	
	}

	return dist[y];
}

int main(){
	int n, m;
	while (cin >> n >> m) {
		Graf G(n, Row (0));

		int a, b, w;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> w;

			Aresta A;
			A.target = b;
			A.weight = w;

			G[a].push_back(A);
		}

		int x, y;
		cin >> x >> y;
		int c = mincost(G, x, y);
		if (c < INF) cout << c << endl;
		else cout << "no path from " << x << " to " << y << endl;
	}
}
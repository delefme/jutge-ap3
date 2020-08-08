#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP; // {cost, {source, target}}
typedef vector<P> Adj; // {cost, target}
typedef vector<Adj> Graf;

int find(int s, vector<int>& parent) {
    if (parent[s] == s) return s;
    return parent[s] = find(parent[s], parent);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        priority_queue<PP> Q;
        
        for (int i = 0; i < m; ++i) {
            int a, b, w;
            cin >> a >> b >> w;
            Q.push({-w, {a - 1, b - 1}});
        }
        
        int counter = 1;
        int sum = 0;
        
        vector<int> parent(n);
        // Makeset
        for (int u = 0; u < n; ++u) parent[u] = u;
        
        while (counter < n and not Q.empty()) {
            auto u = Q.top();
            int a = u.second.first;
            int b = u.second.second;
            Q.pop();
            
            int parent_a = find(a, parent);
            int parent_b = find(b, parent);
            
            if (parent_a != parent_b) {
                sum += -u.first; // += weight
                parent[parent_b] = parent_a; // unio(a, b)
                ++counter;
            }
        }
        
        cout << sum << endl;
    }
}

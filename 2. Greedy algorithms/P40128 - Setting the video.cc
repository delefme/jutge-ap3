#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef priority_queue<pii> pqi;

int n;
pqi episodes;

int count_max_eps() {
    int eps_chosen = 0;
    while (not episodes.empty()) {
        // Choose episode to record
        pii chosen = episodes.top();
        episodes.pop();
        ++eps_chosen;
        
        // Discard the ones that begin before it ends
        while (not episodes.empty()
                and episodes.top().second <= -chosen.first) {
            episodes.pop();
        }
    }
    return eps_chosen;
}

int main() {
    while (cin >> n) {
        episodes = pqi();
        for (int i = 0; i < n; ++i) {
            int s, f; cin >> s >> f;
            episodes.push({-f, s});
        }
        
        int episodes = count_max_eps();
        cout << episodes << endl;
    }
}

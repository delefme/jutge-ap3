#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using Matrix_int = vector<vector<int>>;

Matrix_int read_costs(int n)
{
    Matrix_int M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    }
    return M;
}

void minimum_cost(Matrix_int &M, int &cost, vector<bool> &visited, int vertex, int &min_cost, int steps)
{
    if (cost >= min_cost)
        return;
    int n = visited.size();
    if (steps == n - 1)
    {
        min_cost = min(min_cost, cost + M[vertex][0]);
        return;
    }
    visited[vertex] = true;
    for (int i = 0; i < n; i++)
    {
        if (not visited[i])
        {
            cost += M[vertex][i];
            minimum_cost(M, cost, visited, i, min_cost, steps + 1);
            cost -= M[vertex][i];
        }
    }
    visited[vertex] = false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        Matrix_int M = read_costs(n);
        int cost = 0, min_cost = INT_MAX;
        vector<bool> visited(n, false);
        minimum_cost(M, cost, visited, 0, min_cost, 0);
        cout << min_cost << endl;
    }
}

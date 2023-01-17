#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void gen(int k, int sum, const vector<int> &v, int difference, int &min_dif, int n)
{
    if (k == n)
    {
        if (abs(difference) < min_dif)
            min_dif = abs(difference);
    }
    else if (abs(difference) - min_dif > sum)
        return;
    else
    {
        gen(k + 1, sum - v[k], v, difference + v[k], min_dif, n);
        gen(k + 1, sum - v[k], v, difference - v[k], min_dif, n);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        int sum = 0;
        for (int &x : v)
        {
            cin >> x;
            sum += x;
        }

        vector<int> partition(n, -1);
        int min_dif = INT_MAX;
        gen(0, sum, v, 0, min_dif, n);
        cout << abs(min_dif) << endl;
    }
}

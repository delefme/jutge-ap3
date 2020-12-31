#include <bits/stdc++.h>

using namespace std;

int dp[2][3][4][5][6][7];

int fun(int x1, int x2, int x3, int x4, int x5, int x6) {
    if (dp[x1][x2][x3][x4][x5][x6]!=-1)
        return dp[x1][x2][x3][x4][x5][x6];
    for (int i=1; i<=x1; ++i)
        if (!fun(x1-i, x2, x3, x4, x5, x6))
            return dp[x1][x2][x3][x4][x5][x6]=1;
    for (int i=1; i<=x2; ++i)
        if (!fun(x1, x2-i, x3, x4, x5, x6))
            return dp[x1][x2][x3][x4][x5][x6]=1;
    for (int i=1; i<=x3; ++i)
        if (!fun(x1, x2, x3-i, x4, x5, x6))
            return dp[x1][x2][x3][x4][x5][x6]=1;
    for (int i=1; i<=x4; ++i)
        if (!fun(x1, x2, x3, x4-i, x5, x6))
            return dp[x1][x2][x3][x4][x5][x6]=1;
    for (int i=1; i<=x5; ++i)
        if (!fun(x1, x2, x3, x4, x5-i, x6))
            return dp[x1][x2][x3][x4][x5][x6]=1;
    for (int i=1; i<=x6; ++i)
        if (!fun(x1, x2, x3, x4, x5, x6-i))
            return dp[x1][x2][x3][x4][x5][x6]=1;
    return dp[x1][x2][x3][x4][x5][x6]=0;
}

int main() {
    memset(dp, -1, 7*6*5*4*3*2*4);
    dp[0][0][0][0][0][0]=0;
    int t;
    string a, b;
    int p1, p2, p3, p4, p5, p6;
    cin>>t;
    for (int i=1; i<=t; ++i) {
        cin>>a>>b;
        cin>>p1>>p2>>p3>>p4>>p5>>p6;
        cout<<"Game #"<<i<<": ";
        if (fun(p1, p2, p3, p4, p5, p6))
            cout<<a;
        else
            cout<<b;
        cout<<endl;
    }
}

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

struct Problem
{
    int p, t;
};

bool cmp(Problem a, Problem b)
{
    return a.p > b.p;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    Problem a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].p >> a[i].t;
    }
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i].t; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - a[i].t] + a[i].p);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
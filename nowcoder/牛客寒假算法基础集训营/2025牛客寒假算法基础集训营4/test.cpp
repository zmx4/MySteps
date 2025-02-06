#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> dg(n + m, 0), udg(n + m, 0);
    vector<vector<ll>> tu(n, vector<ll>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tu[i][j];
            dg[i + j] += tu[i][j];
            udg[j - i + n - 1] += tu[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            ll total = dg[i + j] + udg[j - i + n - 1] - tu[i][j];
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
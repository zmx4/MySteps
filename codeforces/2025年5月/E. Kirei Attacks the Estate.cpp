#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
vector<vector<int>> G;
array<ll, N> threat, ans;
void dfs(int u, int p, ll maxn, ll minn)
{
    ans[u] = max(threat[u], threat[u] - minn);
    minn = min(threat[u] - maxn, threat[u]);
    for (auto v : G[u])
    {
        if (v == p)
            continue;
        dfs(v, u, ans[u], minn);
    }
}
void solve()
{
    int n;
    cin >> n;
    G.assign(n + 10, vector<int>());
    for (int i = 0; i < n; i++)
        cin >> threat[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1, 0, 0);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        // cout<<1<<endl;
        solve();
    }

    return 0;
}
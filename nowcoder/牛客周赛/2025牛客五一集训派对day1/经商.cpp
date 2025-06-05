#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
struct node
{
    int x,y;
    bool operator < (const node &a) const
    {
        return x < a.x || (x == a.x && y > a.y);
    }
};
void solve()
{
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> cost(N+1), profit(N+1);
    for (int i = 2; i <= N; i++) {
        cin >> cost[i] >> profit[i];
    }
    vector<vector<int>> adj(N+1);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<char> vis(N+1, 0);
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    vector<int> items;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    for (int v = 2; v <= N; v++) {
        if (vis[v]) {
            items.push_back(v);
        }
    }
    vector<int> dp(C+1, 0);
    for (int v : items) {
        int w = cost[v], val = profit[v];
        for (int c = C; c >= w; c--) {
            dp[c] = max(dp[c], dp[c - w] + val);
        }
    }
    cout << dp[C] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T = 1;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}
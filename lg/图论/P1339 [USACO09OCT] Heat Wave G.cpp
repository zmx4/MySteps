#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<vector<pair<int, int>>> g;
void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    g.assign(n + 1, vector<pair<int, int>>());
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w); // 无向图
    }
    vector<int> dist(n + 1, inf);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s}); // {距离, 节点}
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue; // 如果当前距离大于已知最短距离，跳过
        for(auto [v, w] : g[u])
        {
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout<< (dist[t] == inf ? -1 : dist[t]) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    // cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}
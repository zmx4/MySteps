#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

struct Node
{
    ll d;
    int u;
    int mask;
    bool operator<(const Node &other) const
    {
        return d > other.d; // 小根堆
    }
};

void solve()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> special;
    vector<int> idx(n + 1, -1); // 节点 -> 特殊点下标
    if (k > 0)
    {
        special.resize(k);
        for (int i = 0; i < k; ++i)
        {
            cin >> special[i];
            idx[special[i]] = i;
        }
    }
    vector<int> req(k, 0); // 每个特殊点需要的前置集合
    for (int i = 0; i < t; ++i)
    {
        int x, y;
        cin >> x >> y;
        int ix = idx[x], iy = idx[y];
        if (ix != -1 && iy != -1)
        {
            req[iy] |= (1 << ix);
        }
    }

    // k == 0 直接普通最短路
    if (k == 0)
    {
        const ll INF = (ll)4e18;
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
                continue;
            for (auto &[v, w] : g[u])
            {
                if (dist[v] > d + w)
                {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        if (dist[n] == INF)
            cout << "impossible" << endl;
        else
            cout << dist[n] << endl;
        return;
    }

    int S = 1 << k;
    const ll INF = (ll)4e18;
    vector<vector<ll>> dist(n + 1, vector<ll>(S, INF));
    priority_queue<Node> pq;
    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll d = cur.d;
        int u = cur.u;
        int mask = cur.mask;
        if (d != dist[u][mask])
            continue;
        if (u == n)
        {
            // 已经满足进入 n 的条件（进入时检查过），直接输出最优
            cout << d << endl;
            return;
        }
        for (auto &[v, w] : g[u])
        {
            int newMask = mask;
            // 若 v 是特殊点，检查能否进入
            if (idx[v] != -1)
            {
                int idv = idx[v];
                // 未满足前置
                if ((req[idv] & ~mask) != 0)
                    continue;
                newMask = mask | (1 << idv);
            }
            if (dist[v][newMask] > d + w)
            {
                dist[v][newMask] = d + w;
                pq.push({dist[v][newMask], v, newMask});
            }
        }
    }

    // 未在循环中返回，则找最小 dist[n][*]
    ll ans = INF;
    for (int mask = 0; mask < S; ++mask)
        ans = min(ans, dist[n][mask]);
    if (ans == INF)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
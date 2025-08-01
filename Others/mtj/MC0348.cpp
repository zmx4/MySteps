#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 100000 + 10;


struct DSU
{
    vector<int> p;
    DSU(int n) : p(n + 1)
    {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        p[b] = a;
        return true;
    }
};

vector<vector<int>> g;
vector<int> parent;
vector<bool> vis;

// DFS 用于寻找 u 到 v 的路径，并记录父节点
void dfs(int u, int p)
{
    vis[u] = true;
    parent[u] = p;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        if (!vis[v])
        {
            dfs(v, u);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    parent.assign(n + 1, 0);
    vis.assign(n + 1, false);
    DSU dsu(n + 1);

    int cycle_u = -1, cycle_v = -1;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        if (!dsu.unite(u, v))
        {
            cycle_u = u;
            cycle_v = v;
        }
    }
    dfs(cycle_u, 0);

    vector<int> cycle;
    int curr = cycle_v;
    while (curr != 0)
    {
        cycle.push_back(curr);
        if (curr == cycle_u)
            break;
        curr = parent[curr];
    }

    sort(cycle.rbegin(), cycle.rend());

    for (int i = 0; i < cycle.size(); ++i)
    {
        cout << cycle[i] << (i == cycle.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
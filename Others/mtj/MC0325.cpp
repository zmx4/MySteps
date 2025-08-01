#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<vector<int>> g;
struct e{
    int x, y, w;
    e(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
    bool operator<(const e a)
    {
        return w < a.w;
    }
};
struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
    void merge(int x, int y)
    {
    x = find(x);y = find(y);
    p[x] = y;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;cin>>n;
    DSU dsu(n + 1);
    g.assign(n+1, vector<int>(n+1));
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> g[i][j];
        }
    }
    vector<e> edges;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            edges.emplace_back(i, j, g[i][j]);
        }
    }
    sort(edges.begin(),edges.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < (int)edges.size(); i++)
    {
        int x = edges[i].x, y = edges[i].y, w = edges[i].w;
        if (dsu.unite(x, y))
        {
            ans += w; // 累加边权
            cnt++;
            if (cnt == n - 1) break; // 最小生成树边数为 n-1
        }
    }
    cout << ans << endl; // 输出最小生成树的总权重
        return 0;
}
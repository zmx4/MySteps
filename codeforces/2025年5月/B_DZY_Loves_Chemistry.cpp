#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
struct DSU
{
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0)
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
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<pair<int, int>> edges(m);
    ll ans = 1LL<<n;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        dsu.unite(edges[i].first, edges[i].second);
    }
    for(int i = 1;i <= n;i++)
    {
        if(dsu.find(i) == i)
        {
            ans/=2;
        }
    }
    cout << ans << endl;
    return 0;
}
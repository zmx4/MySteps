#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f, INF = 0x3f3f3f3f;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define int long long
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
            os << ", ";
        os << *it;
    }
    return os << "]";
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
#define dbg(...) cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = ", _dbg(__VA_ARGS__), cerr << endl
void _dbg() {}
template <typename T, typename... Args>
void _dbg(T &&arg, Args &&...args)
{
    cerr << arg;
    if (sizeof...(args) > 0)
        cerr << ", ";
    _dbg(args...);
}
template <typename T, typename N, typename... Args>
void _dbg(T *arr, N n, Args &&...rest)
{
    cerr << "[";
    for (N i = 0; i < n; ++i)
    {
        if (i != 0)
            cerr << ", ";
        cerr << arr[i];
    }
    cerr << "]";
    if (sizeof...(rest) > 0)
        cerr << ", ";
    _dbg(rest...);
}
const int N = 5e5 + 10, M = 1e5 + 10;
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
    void merge(int x, int y)
    {
        x = find(x);y = find(y);
        p[x] = y; // 直接将 x 集合的根的父亲设为 y
    }
};
DSU dsu(N);
bool vis[N];
int ans[N];
vector<int> g[N];
vector<pair<int, int>> asks[N];
int n, m, s;
void tarjan(int x)
{
    vis[x] = true;
    for (int i = 0; i < g[x].size(); i++)
    {
        int y = g[x][i];
        if (vis[y])
            continue; // 无向图 防止遍历自己爹
        tarjan(y);
        dsu.merge(y, x);
    }
    for (int i = 0; i < asks[x].size(); i++)
    {
        int y = asks[x][i].first;
        int id = asks[x][i].second;
        if (vis[y])
            ans[id] = dsu.find(y);
    }
}
inline void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // function<void(int)> tarjan = [&](int u)
    // {
    //     vis[u] = true;
    //     for (auto v : g[u])
    //     {
    //         if (vis[v])
    //             continue;
    //         tarjan(v);
    //         dsu.unite(u, v);
    //     }
    //     for (auto [y, id] : asks[u])
    //     {
    //         if (vis[y])
    //         {
    //             ans[id] = dsu.find(y);
    //         }
    //     }
    // };
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            ans[i] = x;
        }
        else
        {
            asks[x].pb({y, i});
            asks[y].pb({x, i});
        }
    }
    tarjan(s);
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << endl;
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1; // cin>>T;
    while (T--)
    {
        solve();
    }

    return 0;
}
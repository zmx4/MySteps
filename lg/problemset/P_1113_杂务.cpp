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
const int N = 1e5 + 10, M = 1e5 + 10;
int in[N], cost[N], dp[N];
vector<vector<int>> g;
inline void solve()
{
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x >> cost[x];
        int y;
        while (cin >> y && y != 0)
        {
            g[y].pb(x);
            in[x]++;
        }
    }
    queue<int> q;
    int ans = 0;
    // 入度为 0 的根任务，dp=cost
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 0;
        if (in[i] == 0)
        {
            dp[i] = cost[i];
            q.push(i);
            ans = max(ans, dp[i]);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            // v 依赖 u 完成，更新最早完成 v 的时间
            dp[v] = max(dp[v], dp[u] + cost[v]);
            if (--in[v] == 0)
            {
                q.push(v);
                ans = max(ans, dp[v]);
            }
        }
    }

    // 输出总的最短完成时间
    cout << ans << endl;
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
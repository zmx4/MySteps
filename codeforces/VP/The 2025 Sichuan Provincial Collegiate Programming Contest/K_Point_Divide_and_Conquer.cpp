#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define int long long
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){os << "[";for (auto it = v.begin(); it != v.end(); ++it){if (it != v.begin())os << ", ";os << *it;}return os << "]";}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
#define dbg(...) cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = ", _dbg(__VA_ARGS__), cerr << endl
void _dbg() {}
template <typename T, typename... Args>
void _dbg(T &&arg, Args &&...args){cerr << arg;if (sizeof...(args) > 0)cerr << ", ";_dbg(args...);}
template <typename T, typename N, typename... Args>
void _dbg(T *arr, N n, Args &&...rest){cerr << "[";for (N i = 0; i < n; ++i){if (i != 0)cerr << ", ";cerr << arr[i];}cerr << "]";if (sizeof...(rest) > 0)cerr << ", ";_dbg(rest...);}
const int N = 1e5 + 10, M = 1e5 + 10;
vector<vector<int>> g;
vector<int> a, fa;
struct DSU
{
    vector<int> p;
    DSU() {}
    DSU(int n) { init(n); }
    void init(int n)
    {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    // 强制把 ry 并到 x 上（使 x 成为代表）
    void attach_to(int ry, int x) { p[ry] = x; }
};

inline void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    DSU dsu(n);
    vector<int> fa(n + 1, 0);
    vector<char> active(n + 1, 0);
    dsu.init(n);

    for (int i = n; i >= 1; --i)
    {
        int x = p[i];
        active[x] = 1;
        dsu.p[x] = x;

        for (int y : g[x])
        {
            if (!active[y])
                continue;
            int ry = dsu.find(y);
            if (ry == x)
                continue;
            if (fa[ry] == 0)
                fa[ry] = x;      
            dsu.attach_to(ry, x);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << fa[i] << (i == n ? '\n' : ' ');
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
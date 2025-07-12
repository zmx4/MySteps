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
const int N = 2e5 + 10, M = 1e5 + 10;
char g[3][N];
bool vis[3][N];
int n;
bool ok = 0;
void dfs(int x,int y)
{
    
    if(g[x][y] == '>') y++;
    else
        y--;
    if (x < 1 || x > 2 || y < 1 || y > n)
        return;
    if (x == 2 && y == n)
    {
        ok = 1;
        return;
    }
    if (vis[x][y])
        return;
    vis[x][y] = 1;
    dfs(x + 1, y);
    if(ok) return;
    dfs(x - 1, y);
    if(ok) return;
    dfs(x, y + 1);
    if(ok) return;
    dfs(x, y - 1);
}
inline void solve()
{
    memset(g, 0, sizeof g);
    memset(vis, 0, sizeof vis);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> g[1][i];
    for (int i = 1; i <= n; i++)
        cin >> g[2][i];
    ok = 0;
    dfs(1, 2);
    dfs(2, 1);
    if(ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
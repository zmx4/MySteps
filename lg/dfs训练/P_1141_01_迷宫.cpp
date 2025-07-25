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
const int N = 1e7 + 10, M = 1e5 + 10;
char g[1010][1010];
int comp[1010][1010];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
inline void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            comp[i][j] = -1;
    vector<int> comp_size;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
        comp_size.reserve(n * n / 2);
    // BFS 标记每个连通分量
    int cid = 0;
    queue<pair<int,int>> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (comp[i][j] != -1) continue;
            // 新分量
            int sz = 0;
            comp[i][j] = cid;
            que.push({i,j});
            while (!que.empty()) {
                auto [x, y] = que.front(); que.pop();
                sz++;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                    if (comp[nx][ny] != -1) continue;
                    if (g[nx][ny] == g[x][y]) continue;
                    comp[nx][ny] = cid;
                    que.push({nx,ny});
                }
            }
            comp_size.push_back(sz);
            cid++;
        }
    }
    // 处理查询
    while (q--) {
        int x, y;
        cin >> x >> y;
        int id = comp[x][y];
        cout << comp_size[id] << "\n";
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	//cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
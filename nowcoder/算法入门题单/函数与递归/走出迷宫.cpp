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
const int N = 1e5 + 10, M = 1e5 + 10;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[600][600];
char g[600][600];
inline void solve()
{
    int n, m;
    while(cin>>n>>m)
    {
        bool found = false;
        int sx, sy, ex, ey;
        //g.resize(n, vector<char>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == 'S')
                {
                    sx = i; sy = j;
                }
                else if(g[i][j] == 'E')
                {
                    ex = i; ey = j;
                }
            }
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        vis[sx][sy] = true;
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if(x == ex && y == ey)
            {
                cout << "Yes" << endl;
                found = true;
            }
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && g[nx][ny] != '#')
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        if(!found)cout << "No" << endl;
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	//in>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
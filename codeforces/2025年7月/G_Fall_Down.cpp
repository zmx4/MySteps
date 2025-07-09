#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define fi first
#define se second
#define pb push_back
// #define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
const int N = 1e5+10, M = 1e5+10;
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
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
vector<vector<char>> g;
vector<vector<int>> dis;
void solve()
{
	int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<char>(m + 1));
    //dis.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> g[i][j];
        }
    }
	// for(int i = n - 1; i >= 1; --i)
    // {
    //     for(int j = 1; j <= m; ++j)
    //     {
    //         if(g[i][j]=='*')
    //         {
    //             int k = i + 1;
    //             if(g[k][j]=='o'||g[k][j]=='*')break;
    //             for(;k < n; ++k)
    //             {
    //                 if(g[k][j]=='o'||g[k][j]=='*')
    //                 {
    //                     k--;
    //                     break;
    //                 }
    //             }
    //             swap(g[i][j], g[k][j]);
    //         }
    //     }
    // }
    for (int j = 1; j <= m; ++j) {
        int cur = n;
        for (int i = n; i >= 1; --i) {
            if (g[i][j] == 'o') {
                cur = i - 1;
            } else if (g[i][j] == '*') {
                g[i][j] = '.';
                g[cur][j] = '*';
                --cur;
            }
        }
    }
	for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cout << g[i][j];
        }
        cout << endl;
    }
	cout << endl;
	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	// char readBuffer[1 << 20];
	// cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T = 1;	cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
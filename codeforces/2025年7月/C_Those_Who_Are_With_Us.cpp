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
vector<vector<int>> g;
inline void solve()
{
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, vector<int>(m+1));
    int maxVal = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> g[i][j];
            maxVal = max(maxVal, g[i][j]);
        }
    }
    vector<pair<int, int>> maxpos;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(g[i][j] == maxVal)
            {
                maxpos.emplace_back(i, j);
            }
        }
    }
    vector<int> rowCnt(n + 1, 0), colCnt(m + 1, 0);
    for(auto &[x, y] : maxpos)
    {
        rowCnt[x]++;
        colCnt[y]++;
    }
    bool flag = false;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(rowCnt[i]+colCnt[j]-(g[i][j] == maxVal)==maxpos.size())
            {
                flag = true;
            }
            
        }
    }
    if (flag)
        cout << maxVal - 1 << endl;
    else 
        cout << maxVal << endl;
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
/*
0 1 1
1 0 0
1 0 0



*/
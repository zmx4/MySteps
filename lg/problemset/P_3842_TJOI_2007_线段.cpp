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
array<int, N> l, r;
int f[N][3];
inline void solve()
{
    int n;
    cin >> n;
	for(int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
    }
    f[1][0] = r[1] + r[1] - l[1] - 1;
    f[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = min(f[i - 1][0] + abs(l[i - 1] - r[i]) + r[i] - l[i] + 1, f[i - 1][1] + abs(r[i - 1] - r[i]) + r[i] - l[i] + 1),
        f[i][1] = min(f[i - 1][0] + abs(l[i - 1] - l[i]) + r[i] - l[i] + 1, f[i - 1][1] + abs(r[i - 1] - l[i]) + r[i] - l[i] + 1);
    }
    cout << min(f[n][0] + n - l[n], f[n][1] + n - r[n])<<endl;
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
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
const int MOD = 998244353;
// int A161664(int n)
// {
    // ll m = std::sqrt(n);
    // __int128 sum = 0;
    // for (int k = 1; k <= m; ++k)
    // {
        // sum += n / k;
    // }
    // // return n * (n + 1) / 2 + m * m - 2 * sum;
// }
int qpow(int x, int y)
{
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % MOD)
    {
        if (y & 1)
            res = 1ll * x * res % MOD;
    }
    return res;
}
inline void solve()
{
	int n;
    cin >> n;
    ll S = 0;
    for (ll l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        (S += 1ll * ((r - l + 1) % MOD) * ((n / l) % MOD) % MOD) %= MOD;
    }
    ll inv2 = (MOD + 1) / 2;
    ll T = n % MOD * ((n + 1) % MOD) % MOD * inv2 % MOD;
    ll ans = (T - S) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
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
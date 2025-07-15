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
inline void solve()
{
	int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // int l = 1, r = n;
    // vector<int>costl(n+2, 0), costr(n+2, 0);
    // while(l <= n)
    // {
    //     // dbg(a[l], a[l - 1]);
    //     if (a[l] == a[l - 1])
    //     {
    //         costl[l] = costl[l-1];
    //     }
    //     else
    //     {
    //         costl[l] = (l - 1) * a[l];
    //     }
    //     l++;
    // }
    // while(r >= 1)
    // {
    //     if(a[r]==a[r+1])
    //     {
    //         costr[r] = costr[r+1];
    //     }
    //     else
    //     {
    //         costr[r] = (n - r) * a[r];
    //     }
    //     r--;
    // }
    //dbg(costl);
    int ans = LLONG_MAX;
    for(int i = 1; i <= n; ++i)
    {
        int r = i + 1;
        while(a[i]==a[r] && r <= n) r++;
        ans = min(ans,(n + i - r) * a[i]);
        i = r - 1; // Skip to the next different value
    }
    cout << ans << endl;
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
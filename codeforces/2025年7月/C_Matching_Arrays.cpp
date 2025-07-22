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
const int N = 2e5 + 10, M = 1e5 + 10;
inline void solve()
{
	int n,x;
    cin >> n >> x;
    vector<int> a(n),b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    vector<pair<int, int>> aa(n);
    for (int i = 0; i < n; i++)
    {
        aa[i].first = a[i];
        aa[i].second = i;
    }
    sort(aa.begin(), aa.end());
    ranges::sort(b);
    int idx1 = n - x, idx2 = 0;
    bool ok = true;
    vector<int> ans(n, 0);
    for (int i = 0; i < x; i++)
    {
        if (aa[idx1].first <= b[idx2])
        {
            ok = false;
        }
        ans[aa[idx1].second] = b[idx2];
        idx1++;
        idx2++;
    }
    idx1 = 0;
    for (int i = 0; i < n - x; i++)
    {
        if (aa[idx1].first > b[idx2])
        {
            ok = false;
        }
        ans[aa[idx1].second] = b[idx2];
        idx1++;
        idx2++;
    }
    if (!ok)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
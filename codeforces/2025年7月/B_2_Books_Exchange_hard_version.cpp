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
const int N = 2e5+10, M = 1e5+10;
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
array<int, N> a;
array<int, N> ans;
bool vis[N];
void solve()
{
    memset(ans.begin(), 0, sizeof(ans));
    memset(vis, false, sizeof(vis));
	int n;
    cin>> n;
    for(int i = 1;i <= n;i++)cin>> a[i];
	for(int i = 1;i <= n;i++)
    {
        if(vis[i])continue;
        vector<int> v;
        int cnt = 0;
        int d = i;
        vis[i] = true;
        v.push_back(i);
        if(a[i]==d)
        {
            vis[i] = true;
            ans[i]=1;
            continue;  
        }
        while(a[d] != i)
        {
            cnt++;
            d = a[d];
            vis[d] = true;
            v.push_back(d);
        }
        for(auto x : v)
        {
            ans[x] = cnt + 1;
        }
    }
	// cout << endl;
	for(int i = 1;i <= n;i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
	
	
	
}

signed main()
{
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr);
	// char readBuffer[1 << 20];
	// cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T = 1;	cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define fi first
#define se second
#define pb push_back
void test()
{
#if ONLINE_JUDGE
printf("Welcome to the world of competitive programming!\n");
#endif
}
// #define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
const int N = 6e5+10, M = 1e5+10;
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
#define MOD 32768
int s = INT_MAX;
int dis[N];
bool vis[N];
void init()
{   
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        int d = dis[x];
        int v1 = (x - 1 + MOD) % MOD;
        if (dis[v1] > d + 1) {
            dis[v1] = d + 1;
            q.push(v1);
        }
        if (x % 2 == 0) {
            int v2 = x / 2;
            if (dis[v2] > d + 1) {
                dis[v2] = d + 1;
                q.push(v2);
            }
            // 同时还要加上 MOD/2 才能满足 (2*v3)%MOD == u
            int v3 = x / 2 + MOD / 2;
            if (dis[v3] > d + 1) {
                dis[v3] = d + 1;
                q.push(v3);
            }
        }
    }
}
void solve()
{
	int n;
    cin>>n;
    
	cout<<dis[n]<<' ';
	
}

signed main()
{
	test();
	//ios::setvbuf(stdout, nullptr, _IOFBF, 1 << 20);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
	// char readBuffer[1 << 20];
	// cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    init();
	int T = 1;	cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
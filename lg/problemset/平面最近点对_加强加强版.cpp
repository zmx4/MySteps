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
const ll inf = 0x3f3f3f3f3f3f3f3f,INF = 0x3f3f3f3f;
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

const int N = 4e5 + 10, M = 1e5 + 10;
struct point
{
    int x, y;
    bool operator<(const point &p) const
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
};
point p[N];
int a[N];
int n;
bool cmp(int a, int b)
{
    return p[a].y < p[b].y;
}
inline ll cla(int l,int r)
{
    return (p[l].x - p[r].x) * (p[l].x - p[r].x) + (p[l].y - p[r].y) * (p[l].y - p[r].y);
}
ll s(int l,int r)
{
    if(l == r)
        return inf;
    if(l + 1 == r)
        return cla(l, r);
    int mid = (l + r) / 2;
    ll ans = min(s(l, mid), s(mid + 1, r));
    int tt = 0;
    for (int i = l; i <= r;i++)
    {
        if (abs(p[mid].x - p[i].x) * abs(p[mid].x - p[i].x) < ans)
            a[++tt] = i;
    }
    sort(a + 1, a + 1 + tt, cmp);
    for (int i = 1; i <= tt; i++)
        for (int j = i + 1; j <= tt && (p[a[j]].y - p[a[i]].y) * (p[a[j]].y - p[a[i]].y) < ans; j++)
            ans = min(ans, cla(a[i], a[j]));
    return ans;
}


inline void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + n);
    ll ans = s(0, n - 1);
    if (ans == inf)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        cout << ans << endl;
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
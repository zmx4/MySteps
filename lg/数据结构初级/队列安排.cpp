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
const int N = 1e5 + 10, M = 1e5 + 10;
struct node{
int front,rear;
int val;
}a[N];
// int idx;
int n;
bool st[N];
inline void solve()
{
	cin>>n;
    a[0].val = 0;
    a[0].rear = 1;
    a[1].front = 0;
    a[1].val = 1;
    a[1].rear = n + 1;
    a[n + 1].front = a[1].val;
    a[n + 1].val = n + 1;
    for (int i = 2; i <= n;i++)
    {
        a[i].val = i;
        int k, p;cin>>k>>p;
        if(p==0)
        {
            a[a[k].front].rear = i;
            a[i].front = a[k].front;
            a[i].rear = k;
            a[k].front = i;
        }
        else
        {
            a[a[k].rear].front = i;
            a[i].rear = a[k].rear;
            a[i].front = k;
            a[k].rear = i;
        }
    }
    int m;cin>>m;
    while(m--)
    {
        int x;cin>>x;
        if(st[x]) continue;
        st[x] = true;
        a[a[x].front].rear = a[x].rear;
        a[a[x].rear].front = a[x].front;
        // a[x].front = 0;
        
    }
    int cur = a[0].rear;
    while(cur!=n+1)
    {
        cout<<a[cur].val<<" ";
        cur = a[cur].rear;
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
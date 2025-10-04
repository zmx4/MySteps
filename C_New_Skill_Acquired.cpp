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
constexpr int inf = 0x3f3f3f3f;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void test(){cout<<"test"<<endl;}
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
#define int long long
bool visited[200005];
constexpr int N = 1e5 + 10, M = 1e5 + 10;
inline void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n+1);
    int cnt = 0;
    queue<int> q;
    for(int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        // v.push_back({x, y});
        v[i]={x, y};
        if(x==0 && y==0)
            q.push(i), cnt++;
    }
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; ++i)
    {
        int x = v[i].first;
        int y = v[i].second;
        if(x!=0 || y!=0)
        {
            adj[x].push_back(i);
            adj[y].push_back(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto &child: adj[node])
        {
            if(visited[child]) continue;
            visited[child] = true;
            cnt++;
            q.push(child);
        }
    }
    cout<<cnt<<endl;

}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	
    // cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
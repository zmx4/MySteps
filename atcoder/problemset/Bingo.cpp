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
//ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
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
bool st[4][4];
inline void solve()
{
    array<pair<int, int>, 110> a;
    
    for (int i = 1; i <= 3;i++)
    {
        for (int j = 1; j <= 3;j++)
        {
            int x;
            cin >> x;
            a[x] = {i, j};
        }
    }
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        if(x<101)st[a[x].first][a[x].second] = true;
    }
    auto check = [&]() {
        if(st[1][1] && st[2][2] && st[3][3]) return true;
        if(st[1][3] && st[2][2] && st[3][1]) return true;
        if(st[1][1] && st[1][2] && st[1][3]) return true;
        if(st[2][1] && st[2][2] && st[2][3]) return true;
        if(st[3][1] && st[3][2] && st[3][3]) return true;
        if(st[1][1] && st[2][1] && st[3][1]) return true;
        if(st[1][2] && st[2][2] && st[3][2]) return true;
        if(st[1][3] && st[2][3] && st[3][3]) return true;
        return false;
    };
    if(check())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
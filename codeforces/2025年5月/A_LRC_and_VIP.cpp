#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
const int N = 1e5+10, M = 1e5+10;
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
void solve()
{
	int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int maxx = *max_element(a.begin(), a.end());
    int minn = *min_element(a.begin(), a.end());
    if(maxx == minn)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i = 0;i < n;i++)
        {
            if(a[i]==maxx)
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<2<<" ";
            }
        }
    }
	cout<<endl;
    return;
	
	
	
	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T = 1;	cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
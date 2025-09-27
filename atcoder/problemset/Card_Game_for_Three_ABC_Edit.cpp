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
constexpr int N = 1e5 + 10, M = 1e5 + 10;
string a, b, c;
int n, m, k;
int now = 1;
int check(char x)
{
    if(x == 'a')
    {
        return 1;

    }
    if(x == 'b') return 2;
    if(x == 'c') return 3;
    return 0;
}
bool flag = true;
void output()
{
    if(now == 1 && n== 0) 
    {
        cout << "A" << endl;
        flag = false;
    }
    else if(now == 2 && m == 0)
    {
        cout << "B" << endl;
        flag = false;
    }
    else if(now == 3 && k == 0) 
    {
        cout << "C" << endl;
        flag = false;
    }
}
inline void solve()
{
    
    cin >> a >> b >> c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    n = a.size(), m = b.size(), k = c.size();
    
    while(n >= 0 && m >= 0 && k >= 0)
    {
        output();
        if(!flag) break;
        if(now == 1)
        {
            now = check(a.back());
            a.pop_back();
            n--;
        }
        else if(now == 2)
        {
            now = check(b.back());
            b.pop_back();
            m--;
        }
        else
        {
            now = check(c.back());
            c.pop_back();
            k--;
        }
    }
    

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
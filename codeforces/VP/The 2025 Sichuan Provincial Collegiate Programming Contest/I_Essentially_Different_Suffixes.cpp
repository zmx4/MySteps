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
const int N = 3e5 + 10, M = 1e5 + 10;
int a[N][26], idx;
void insert(const char* str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!a[p][u])
            a[p][u] = ++idx;
        p = a[p][u];
    }
}
signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
    int n;cin>>n;
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        string s;cin>>s;
        reverse(s.begin(), s.end());
        insert(s.c_str());
    }
    cout << idx << endl;
    // for(auto x:st)
    //     cout << x << endl;
    // cout << st.size() << endl;

    return 0;
}
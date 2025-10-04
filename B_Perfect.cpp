#include <bits/stdc++.h>
#define endl "\n"
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
constexpr int inf = 0x3f3f3f3f;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void test() { cout << "test" << endl; }
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
#define int long long
constexpr int N = 1e5 + 10, M = 1e5 + 10;
inline void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<int, pair<int, long>> mp;
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        cin >> x >> y;
        mp[x].first = i;
        mp[x].second |= (1LL << (y - 1));
    }
    vector<pair<int, int>> v;
    long target = 0;
    for (int i = 1; i <= m; ++i)
        target |= (1LL << (i - 1));
    // long target = (1LL << m) - 1;
    for (auto &[x, p] : mp)
    {
        if (p.second == target)
        {
            v.push_back({x, p.first});
        }
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });
    // dbg(v.size());
    if (v.size() == 0)
        cout << " " << endl;
    else
    {
        for (auto &[x, y] : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }

    return 0;
}
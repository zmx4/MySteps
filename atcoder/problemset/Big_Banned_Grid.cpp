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
const int inf = 0x3f3f3f3f, INF = 0x3f3f3f3f;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define int long long
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
const int N = 2e5 + 10, M = 1e5 + 10;
constexpr int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};
inline void solve()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<pair<ll, ll>> p(k);
    auto encode = [](int x, int y)
    { return (x << 32) ^ y; };
    unordered_map<ll, int> idx;
    idx.reserve(k * 2);
    for (int i = 0; i < k;i++)
    {
        cin >> p[i].first >> p[i].second;
        idx[encode(p[i].first, p[i].second)] = i;
    }
    DSU dsu(k);
    for (int i = 0; i < k; i++)
    {
        ll r = p[i].first, c = p[i].second;
        for (int d = 0; d < 8; d++)
        {
            ll nr = r + dx[d], nc = c + dy[d];
            ll code = encode(nr, nc);
            auto it = idx.find(code);
            if (it != idx.end())
            {
                dsu.unite(i, it->second);
            }
        }
    }
    vector<bool> t(k, 0), b(k, 0), l(k, 0), r(k, 0);
    for (int i = 0;i < k;i++)
    {
        int rt = dsu.find(i);
        ll rr = p[i].first, c = p[i].second;
        if(rr == 1)
            t[rt] = 1;
        if(rr == h)
            b[rt] = 1;
        if(c == 1)
            l[rt] = 1;
        if(c==w)
            r[rt] = 1;
    }
    bool flag = false;
    for (int i = 0; i < k;i++)
    {
        if(dsu.find(i)==i)
        {
            if((t[i]&&b[i])||(r[i]&&l[i])||(t[i]&&r[i])||(b[i]&&l[i]))
            {
                flag = true;
                break;
            }
        }
    }
    if(!flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
    //cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
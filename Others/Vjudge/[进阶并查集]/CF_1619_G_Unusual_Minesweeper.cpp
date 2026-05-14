#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdint>
#include <map>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cstring>
#include <climits>
#include <iterator>
#include <bitset>
#include <numeric>
#include <array>
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
using std::cout, std::bitset, std::cin, std::cerr, std::vector, std::string, std::pair, std::map, std::set, std::priority_queue, std::queue, std::stack, std::sort, std::unordered_map, std::greater, std::unordered_set, std::min, std::max, std::reverse, std::swap, std::abs, std::ostream, std::to_string, std::lower_bound, std::upper_bound, std::deque, std::iota, std::array;
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
ll log2(ll x) { return 63 - __builtin_clzll(x); }
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
#pragma region solve
#define int long long
namespace solve
{
    constexpr int N = 1e5 + 10, M = 1e5 + 10;
    struct DSU
    {
        vector<int> p, r;
        DSU(int n) : p(n + 1), r(n + 1, 0)
        {
            iota(p.begin(), p.end(), 0);
        }
        int find(int x)
        {
            return p[x] == x ? x : p[x] = find(p[x]);
        }
        bool unite(int a, int b)
        {
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
        void merge(int x, int y)
        {
            x = find(x);
            y = find(y);
            p[x] = y;
        }
    };
    struct edge
    {
        int u, v, w, id;
    };
    inline void Tick()
    {
        int n, k;
        cin >> n >> k;
        DSU dsu(n);
        vector<edge> edges(n);
        // for(auto &[u, v, w, id] : edges)
        // {
        //     cin >> u >> v >> w;
        //     id = &u - &edges[0].u;
        // }
        for (int i = 0; i < n; ++i)
        {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            edges[i].id = i;
        }
        sort(edges.begin(), edges.end(), [](const edge &a, const edge &b)
             {
    if (a.u != b.u) return a.u < b.u;
    return a.v < b.v; });
        for (int i = 0; i < n - 1; ++i)
        {
            if (edges[i].u == edges[i + 1].u && abs(edges[i].v - edges[i + 1].v) <= k)
            {
                dsu.merge(edges[i].id, edges[i + 1].id);
            }
        }
        sort(edges.begin(), edges.end(), [](const edge &a, const edge &b)
             {
    if (a.v != b.v) return a.v < b.v;
    return a.u < b.u; });
        for (int i = 0; i < n - 1; ++i)
        {
            if (edges[i].v == edges[i + 1].v && abs(edges[i].u - edges[i + 1].u) <= k)
            {
                dsu.merge(edges[i].id, edges[i + 1].id);
            }
        }
        vector<int> minn(n, inf);
        for (int i = 0; i < n; ++i)
        {
            int root = dsu.find(edges[i].id);
            minn[root] = min(minn[root], edges[i].w);
        }

        vector<int> times;
        for (int i = 0; i < n; ++i)
        {
            if (dsu.find(i) == i)
            {
                times.push_back(minn[i]);
            }
        }

        sort(times.begin(), times.end(), greater<int>());
        int m = times.size();

        int res = m - 1;
        for (int i = 0; i < m; ++i)
        {
            res = min(res, max(i - 1, times[i]));
        }
        cout << res << endl;
    }
}
#pragma endregion

#pragma region main
signed main()
{
    cin.tie(nullptr)->std::ios::sync_with_stdio(false);
    cout.tie(nullptr);
    // cin.exceptions(cin.failbit | cin.badbit);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve::Tick();
    }

    return 0;
}
#pragma endregion
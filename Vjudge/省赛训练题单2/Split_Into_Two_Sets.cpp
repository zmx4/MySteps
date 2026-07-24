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
typedef int64_t i64;typedef int32_t i32;using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;using std::cout, std::bitset, std::cin, std::cerr, std::vector, std::string, std::pair, std::map, std::set, std::priority_queue, std::queue, std::stack, std::sort, std::unordered_map, std::greater,std::unordered_set, std::min, std::max, std::reverse, std::swap, std::abs, std::ostream, std::to_string, std::lower_bound, std::upper_bound, std::deque, std::iota, std::array;
constexpr int inf = 0x3f3f3f3f;constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void test(){cout<<"test"<<endl;}
ll log2(ll x) { return 63 - __builtin_clzll(x); }
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
#pragma region solve
#define int long long
namespace solve
{
constexpr int N = 2e5 + 10, M = 1e5 + 10;
int a[N], b[N],cnt[N],h1[N],h2[N];
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
    void merge(int x, int y)
    {
    x = find(x);y = find(y);
    p[x] = y;
    }
};

inline void Tick()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = 0;
        h1[i] = 0;
        h2[i] = 0;
    }
    DSU dsu(2*n + 10);
    bool flag = true;
    for (int i = 1; i <= n;++i)
    {
        cin >> a[i] >> b[i];
        if(a[i] == b[i])
        {
            flag = false;
        }
        cnt[a[i]]++;
        cnt[b[i]]++;
        if(cnt[a[i]] > 2 || cnt[b[i]] > 2)
        {
            // cout << "NO" << endl;
            // return;
            flag = false;
        }
        if (h1[a[i]])
            h2[a[i]] = i;
        else
            h1[a[i]] = i;
        if (h1[b[i]])
            h2[b[i]] = i;
        else
            h1[b[i]] = i;
    }
    if(!flag)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n;++i)
    {
        if(!h2[i])continue;
        int x = h1[i], y = h2[i];
        dsu.merge(x + n, y);
        dsu.merge(x, y + n);
        if(dsu.find(x) == dsu.find(x + n))
        {
            cout << "NO" << endl;
            return;
        }
        if(dsu.find(y) == dsu.find(y + n))
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
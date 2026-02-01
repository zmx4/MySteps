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
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;typedef int32_t i32;using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;using std::cout, std::bitset, std::cin, std::cerr, std::vector, std::string, std::pair, std::map, std::set, std::priority_queue, std::queue, std::stack, std::sort, std::unordered_map, std::greater,std::unordered_set, std::min, std::max, std::reverse, std::swap, std::abs, std::ostream, std::to_string, std::lower_bound, std::upper_bound, std::deque, std::iota;
constexpr int inf = 0x3f3f3f3f;constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
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
#pragma region solve
#define int long long
namespace solve
{
constexpr int N = 5e5 + 10, M = 1e5 + 10;
long long a[N], ls[N];
template <typename T>
struct BIT
{
    const int n;
    std::vector<T> tree;
    BIT(int n) : n(n), tree(n + 1) {};
    T Query(int x)
    {
        T res = 0;
        for (int i = x; i > 0; i -= (i & -i))
        {
            res += tree[i];
        }
        return res;
    }
    void Modify(int l, T z)
    {
        if (l <= 0)
            return;
        for (int i = l; i <= n; i += (i & -i))
        {
            tree[i] += z;
        }
    }
    T rangeQuery(int l, int r)
    {
        return Query(std::min(n, r)) - Query(std::max(0ll, l - 1));
    }
}; // 树状数组
BIT<long long> bit(N);
inline bool cmp(int x, int y)
{
    return ls[x] == ls[y] ? x > y : ls[x] > ls[y];
}
inline void Tick()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> ls[i];
        a[i] = i;
    }
    std::sort(a + 1, a + n + 1, cmp);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        // int idx = a[i];
        bit.Modify(a[i], 1ll);
        ans += bit.Query(a[i] - 1);
    }
    cout << ans << endl;
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
    // cin >> T;
    while (T--)
    {
        solve::Tick();
    }

    return 0;
}
#pragma endregion
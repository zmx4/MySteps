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
vector<vector<int>> g;
vector<vector<int>> grid;
bitset<N> vis;
vector<int> dis;
int now = 0;
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : grid[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    dis[u] = now++;
}
inline void Tick()
{
    int n,k;
    cin>> n >> k;
    vis.reset();
    dis.assign(n + 1, -1);
    g.assign(k + 1, vector<int>(n+1));
    vector<int> a(k + 1);
    for (int i = 1; i <= k; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> g[i][j];
        }
        a[i] = g[i][0];
    }
    grid.assign(n + 1, vector<int>());
    for (int i = 1; i <= k;i++)
    {
        for (int j = 2; j < n;++j)
        {
            int u = g[i][j];
            int w = g[i][j + 1];
            grid[u].push_back(w);
        }
    }
    // dbg(grid);
    for(int i = 1; i <= n; ++i)
    {
        if (dis[i] == -1)
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= k;++i)
    {
        for (int j = 2; j < n;++j)
        {
            int u = g[i][j];
            int w = g[i][j + 1];
            if (dis[u] < dis[w])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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
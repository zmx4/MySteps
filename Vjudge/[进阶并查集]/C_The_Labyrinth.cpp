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
constexpr int N = 2e6 + 10, M = 1e5 + 10;
vector<string> g;
vector<vector<int>> a;
vector<vector<bool>> vis;
int sz[N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int cnt = 0;
int n, m;
void dfs(int x, int y)
{
    vis[x][y] = true;
    a[x][y] = cnt;
    sz[cnt]++;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '*' || vis[nx][ny])
            continue;
        dfs(nx, ny);
    }
}
inline void Tick()
{
    cin >> n >> m;
    g.resize(n + 1);
    a.assign(n + 1, vector<int>(m + 1));
    vis.assign(n + 1, vector<bool>(m + 1));
    for (int i = 1; i <= n; ++i)
    {
        cin >> g[i];
        g[i] = " " + g[i];
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (g[i][j] == '*' || vis[i][j])
                continue;
            cnt++;
            dfs(i, j);
        }
    }
    auto getans = [&](int x, int y) -> int
    {
        set<int> s;
        int sum = 1;
        for (int i = 0; i < 4;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '*')
                continue;
            if(!s.count(a[nx][ny]))sum += sz[a[nx][ny]];
                s.insert(a[nx][ny]);
        }
        return sum % 10;
    };
    for (int i = 1;i <= n;++i)
    {
        for (int j = 1; j <= m;++j)
        {
            if (g[i][j] == '*')
                cout << getans(i, j);
            else
                cout << '.';
        }
        cout << endl;
    }
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
    char readBuffer[1 << 21];
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
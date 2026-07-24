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
constexpr int N = 1e3 + 10, M = 1e5 + 10;
struct star{
    int x, y, t;
};
vector<star> stars;
int a[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[N][N];
inline void Tick()
{
    int n;
    cin >> n;
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            a[i][j] = inf;
    for (int i = 1; i <= n;i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        a[x][y] = min(a[x][y], t);
        stars.pb({x, y, t});
        for (int i = 0; i < 4;i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx <= 1000 && ny <= 1000)
                a[nx][ny] = min(a[nx][ny], t);
        }
    }
    queue<star> q;
    if(a[0][0]>0){
        q.push({0, 0, 0});
        vis[0][0] = 1;
    }
    while(!q.empty())
    {
        // cout << q.size() << endl;
        auto [x, y, t] = q.front();
        q.pop();
        if(a[x][y]==inf)
        {
            cout << t << endl;
            return;
        }
        for (int i = 0; i < 4;i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            int nt = t + 1;
            if(nx < 0||ny < 0 ||nx > 1000||ny > 1000||vis[nx][ny])
            {
                continue;
            }
            if(nt < a[nx][ny])
            {
                vis[nx][ny] = 1;
                q.push({nx, ny, nt});
            }
        }
    }
    cout << -1 << endl;
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
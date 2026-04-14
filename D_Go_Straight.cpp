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
#include <tuple>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;typedef int32_t i32;using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;using std::cout, std::bitset, std::cin, std::cerr, std::vector, std::string, std::pair, std::map, std::set, std::priority_queue, std::queue, std::stack, std::sort, std::unordered_map, std::greater,std::unordered_set, std::min, std::max, std::reverse, std::swap, std::abs, std::ostream, std::to_string, std::lower_bound, std::upper_bound, std::deque, std::iota, std::array, std::tuple;
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
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    char dirc[4] = {'D', 'R', 'U', 'L'};

    inline void Tick()
    {
        int n, m;
        cin >> n >> m;
        vector<string> g(n);
        int sx = -1, sy = -1, ex = -1, ey = -1;

        // 使用 0-indexed 处理迷宫，避免各种奇怪的越界问题
        for (int i = 0; i < n; ++i)
        {
            cin >> g[i];
            for (int j = 0; j < m; ++j)
            {
                if (g[i][j] == 'S')
                    sx = i, sy = j;
                else if (g[i][j] == 'G')
                    ex = i, ey = j;
            }
        }

        vector<vector<vector<int>>> prevd(n, vector<vector<int>>(m, vector<int>(4, -2)));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < 4; ++i)
        {
            int nx = sx + dx[i], ny = sy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#')
            {
                prevd[nx][ny][i] = -1;
                q.emplace(nx, ny, i);
            }
        }
        int ans_dir = -1;
        while (!q.empty())
        {
            auto [x, y, dir] = q.front();
            q.pop();
            if (x == ex && y == ey)
            {
                ans_dir = dir;
                break;
            }
            for (int i = 0; i < 4; ++i)
            {
                if (g[x][y] == 'o' && i != dir)
                    continue;
                if (g[x][y] == 'x' && i == dir)
                    continue;
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#')
                {
                    if (prevd[nx][ny][i] == -2)
                    {
                        prevd[nx][ny][i] = dir;
                        q.emplace(nx, ny, i);
                    }
                }
            }
        }
        if (ans_dir == -1)
        {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        // 【核心修正】：使用迭代反向重构路径
        string path = "";
        int cx = ex, cy = ey, cd = ans_dir;
        while (cx != sx || cy != sy)
        {
            path += dirc[cd];
            int pcd = prevd[cx][cy][cd];
            cx -= dx[cd];
            cy -= dy[cd];
            cd = pcd;
        }
        reverse(path.begin(), path.end());
        cout << path << "\n";
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
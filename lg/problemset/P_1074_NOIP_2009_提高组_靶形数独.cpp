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
const int N = 1e5 + 10, M = 1e5 + 10;
const vector<vector<int>> points = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0},
    {0, 6, 7, 7, 7, 7, 7, 7, 7, 6, 0},
    {0, 6, 7, 8, 8, 8, 8, 8, 7, 6, 0},
    {0, 6, 7, 8, 9, 9, 9, 8, 7, 6, 0},
    {0, 6, 7, 8, 9, 10, 9, 8, 7, 6, 0},
    {0, 6, 7, 8, 9, 9, 9, 8, 7, 6, 0},
    {0, 6, 7, 8, 8, 8, 8, 8, 7, 6, 0},
    {0, 6, 7, 7, 7, 7, 7, 7, 7, 6, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
const vector<vector<int>> area = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 0},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 0},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 0},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6, 0},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6, 0},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6, 0},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9, 0},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9, 0},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int g[11][11], gong[11][11], row[11][11], col[11][11];
int now = 0, idx;
struct F
{
    int id, cnt;
    bool operator<(const F &f) const
    {
        return cnt < f.cnt;
    }
} f[10];
int info[4][200];
int ans = -1;
void dfs(int u, int sum)
{
    if (u == idx)
    {
        ans = max(ans, sum + now); // 在这里加上初始分数
        return;
    }
    // 剪枝：如果当前分数加上剩余所有格子都填9的分数还不如已知最大分数，就返回
    // 这是一个可选的优化，但非常有效
    int remaining_score_upper_bound = 0;
    for (int i = u; i < idx; ++i)
    {
        remaining_score_upper_bound += 9 * info[2][i];
    }
    if (sum + now + remaining_score_upper_bound <= ans)
    {
        return;
    }

    int r = info[0][u];
    int c = info[1][u];
    int p = info[2][u];
    int a = info[3][u];

    for (int i = 1; i <= 9; i++)
    {
        if (col[c][i] == 0 && row[r][i] == 0 && gong[a][i] == 0)
        {
            col[c][i] = 1;
            row[r][i] = 1;
            gong[a][i] = 1;
            // g[r][c] = i; // 这一行其实不是必须的，因为我们只关心分数
            dfs(u + 1, sum + i * p);
            // g[r][c] = 0;
            col[c][i] = 0;
            row[r][i] = 0;
            gong[a][i] = 0;
        }
    }
}
inline void solve()
{
    for (int i = 1; i <= 9; i++)
        f[i].id = i, f[i].cnt = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> g[i][j];
            if (g[i][j] > 0)
            {
                col[j][g[i][j]]++;
                row[i][g[i][j]]++;
                gong[area[i][j]][g[i][j]]++;
                now += g[i][j] * points[i][j];
            }
            else
                f[i].cnt++;
        }
    }
    sort(f + 1, f + 10);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (g[f[i].id][j] == 0)
            {
                info[0][idx] = f[i].id;
                info[1][idx] = j;
                info[2][idx] = points[f[i].id][j];
                info[3][idx] = area[f[i].id][j];
                idx++;
            }
        }
    }
    dfs(0, 0);
    cout << ans << endl;
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

    while (T--)
    {
        solve();
    }

    return 0;
}
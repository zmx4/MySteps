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
typedef int64_t i64;typedef int32_t i32;using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;using std::cout, std::bitset, std::cin, std::cerr, std::vector, std::string, std::pair, std::map, std::set, std::priority_queue, std::queue, std::stack, std::sort, std::unordered_map, std::unordered_set, std::min, std::max, std::sort, std::reverse, std::swap, std::abs, std::ostream, std::to_string, std::lower_bound, std::upper_bound, std::deque, std::iota ,std::iota;
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
#define int long long
constexpr int N = 1e5 + 10, M = 1e5 + 10;
namespace solve
{
constexpr int N = 1e5 + 10, M = 1e5 + 10;
int n, p;
vector<vector<pair<int,int>>> g;
vector<int> in, out;
queue<int> q;
vector<int> val;
vector<bool> visited;
inline void Tick()
{
    cin >> n >> p;
    g.resize(n+1);
    out.resize(n + 1);
    in.resize(n + 1);
    val.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i <= n;i++)
    {
        int init, u;
        cin >> init >> u;
        val[i] = init;
        if(init)
        {
            q.push(i);
            visited[i] = true;
        }
        else
        {
            val[i]-=u;
        }
    }
    for (int i = 1; i <= p;i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        g[a].emplace_back(b, v);
        out[a]=1;
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(val[x] < 0) continue;
        for(auto [y,w] : g[x])
        {
            val[y] += val[x] * w;
            if(!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
    bool flag = false;
    for (int i = 1; i <= n;i++)
    {
        if(!out[i] && val[i] > 0)
        {
            flag = true;
            cout << i << " " << val[i] << endl;
        }
    }
    if(!flag)
    {
        cout << "NULL" << endl;
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
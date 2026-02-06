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
constexpr int N = 1e5 + 10, M = 1e5 + 10;
inline void Tick()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n+1);
    vector<int> deg(n+1);
    map<int,vector<int>,greater<int>> mp;
    vector<int> ddeg;
    vector<int> ans(n + 1, -1);
    vector<int> dis(n + 1, -1);
    vector<vector<int>> b;
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int maxx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] > maxx)
            maxx = deg[i];
    }
    b.resize(maxx + 1);
    for (int i = 1; i <= n; i++)
    {
        mp[deg[i]].push_back(i);
        b[deg[i]].push_back(i);
    }
    for(auto &[k,_]:mp)ddeg.pb(k);
    for(auto d:ddeg)
    {
        for(auto x:b[d])
        {
            ans[x] = dis[x];
            dis[x] = 0;
            q.push(x);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v:g[u])
            {
                if(dis[v] > dis[u] + 1||dis[v]==-1)
                {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        cout<<ans[i]<<" ";
        
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
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
#include <format>
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
    void Tick()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);
        vector<vector<bool>> edge(n, vector<bool>(n, false));

        for (int i = 1; i <= m; i++)
        {
            char A, lt, B;
            cin >> A >> lt >> B;
            int u = A - 'A', v = B - 'A';
            if (!edge[u][v])
            {
                g[u].push_back(v);
                indeg[v]++;
                edge[u][v] = true;
            }
            // 做一次拓扑检测
            vector<int> deg = indeg;
            queue<int> q;
            for (int j = 0; j < n; j++)
            {
                if (deg[j] == 0)
                    q.push(j);
            }
            bool unique = true;
            vector<int> res;
            while (!q.empty())
            {
                if (q.size() > 1)
                    unique = false;
                int x = q.front();
                q.pop();
                res.push_back(x);
                for (int y : g[x])
                {
                    if (--deg[y] == 0)
                        q.push(y);
                }
            }
            if ((int)res.size() < n)
            {
                cout << "Inconsistency found after " << i << " relations.\n";
                return;
            }
            if (unique)
            {
                cout << "Sorted sequence determined after " << i
                     << " relations: ";
                for (int x : res)
                    cout << char('A' + x);
                cout << ".\n";
                return;
            }
        }
        cout << "Sorted sequence cannot be determined.\n";
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
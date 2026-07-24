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
constexpr int N = 1e5 + 10, M = 1e5 + 10;
inline void Tick()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    set<int> s[3];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    vector<pair<int, int>> ans;
    // test();
    auto check = [&](void) -> bool
    {
        int cnt = 0;
        vector<int> idx;
        for (int i = 0; i < 3; ++i)
            if (!s[i].empty())
                cnt++, idx.push_back(i);
        if (cnt == 1)
            return true;
        else if (cnt == 2)
        {
            if (*prev(s[idx[0]].end()) < *s[idx[1]].begin())
                return true;
            return false;
        }
        else if (*prev(s[idx[0]].end()) < *s[idx[1]].begin() && *prev(s[idx[1]].end()) < *s[idx[2]].begin())
            return true;
        return false;
    };
    while (!check())
    {
        if (!s[0].empty() && !s[1].empty())
        {
            int i = *prev(s[0].end()), j = *s[1].begin();
            if (i > j)
            {
                ans.emplace_back(i, j);
                s[0].erase(i);
                s[1].erase(j);
                s[0].insert(j);
                s[1].insert(i);
            }
        }
        if (check())
            break;
        if (!s[1].empty() && !s[2].empty())
        {
            int i = *prev(s[1].end()), j = *s[2].begin();
            if (i > j)
            {
                ans.emplace_back(i, j);
                s[1].erase(i);
                s[2].erase(j);
                s[1].insert(j);
                s[2].insert(i);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &[i, j] : ans)
        cout << i << " " << j << endl;
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
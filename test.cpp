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
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using ULL = unsigned long long;
using std::cout, std::bitset, std::cin, std::cerr, std::vector, std::string, std::pair, std::map, std::set, std::priority_queue, std::queue, std::stack, std::sort, std::unordered_map, std::greater, std::unordered_set, std::min, std::max, std::reverse, std::swap, std::abs, std::ostream, std::to_string, std::lower_bound, std::upper_bound, std::deque, std::iota;
constexpr int inf = 0x3f3f3f3f;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void test() { cout << "test" << endl; }
ll log2(ll x) { return 63 - __builtin_clzll(x); }
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
#pragma region solve
#define int long long
namespace solve
{
    constexpr int N = 1e5 + 10, M = 1e5 + 10;
    constexpr int mod = 1e9 + 7;
    inline void Tick()
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            long long c, w;
            cin >> c >> w;
            vector<pair<long long, long long>> a(1);
            a[0] = {c, w};
            auto solveHuffman = [&](vector<pair<long long, long long>> &a) -> long long
            {
                const long long MOD = 1000000007LL;
                sort(a.begin(), a.end(), [](auto &p1, auto &p2)
                     { return p1.second < p2.second; });
                int idx = 0;                   // 指向 a 中当前处理的种类
                long long remain = a[0].first; // 当前种类剩余个数
                long long curW = a[0].second;
                priority_queue<long long, vector<long long>, greater<long long>> pq;
                long long ans = 0;

                // 取一个最小权值
                auto take_one = [&]() -> long long
                {
                    if (idx < (int)a.size() && (pq.empty() || a[idx].second <= pq.top()))
                    {
                        long long w = a[idx].second;
                        // 从这一种里取一个
                        remain--;
                        if (remain == 0)
                        {
                            idx++;
                            if (idx < (int)a.size())
                            {
                                remain = a[idx].first;
                            }
                        }
                        return w % MOD;
                    }
                    else
                    {
                        long long w = pq.top();
                        pq.pop();
                        return w % MOD;
                    }
                };

                // 初始化 remain, curW 已经设置
                remain = a[0].first;
                idx = 0;

                long long totalCnt = 0;
                for (auto &p : a)
                    totalCnt += p.first;
                if (totalCnt == 1)
                    return 0; // 只有一个堆，无需合并

                while (totalCnt > 1)
                {
                    long long x = take_one();
                    long long y = take_one();
                    long long z = (x + y) % MOD;
                    ans = (ans + z) % MOD;
                    pq.push(z);
                    totalCnt--;
                }
                return ans % MOD;
            };

            long long ans = solveHuffman(a);
            cout << ans % 1000000007LL << endl;
            return;
        }

        vector<pair<long long, long long>> a(n); // {c_i, w_i}
        long long totalCnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].first >> a[i].second;
            totalCnt += a[i].first;
        }

        const long long MOD = 1000000007LL;

        // 排序按权值升序
        sort(a.begin(), a.end(), [](auto &p1, auto &p2)
             { return p1.second < p2.second; });

        // idx 指向当前种类；remain 是该种类还没取完的数量
        int idx = 0;
        long long remain = a[0].first;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        auto take_one = [&]() -> long long
        {
            // 从“原始权值序列” a 中取，还是从 pq 中取？
            // 谁小取谁
            if (idx < n && (pq.empty() || a[idx].second <= pq.top()))
            {
                long long w = a[idx].second;
                remain--;
                if (remain == 0)
                {
                    idx++;
                    if (idx < n)
                    {
                        remain = a[idx].first;
                    }
                }
                return w % MOD;
            }
            else
            {
                long long w = pq.top();
                pq.pop();
                return w % MOD;
            }
        };

        long long ans = 0;
        if (totalCnt == 1)
        {
            cout << 0 << endl;
            return;
        }

        while (totalCnt > 1)
        {
            long long x = take_one();
            long long y = take_one();
            long long z = (x + y) % MOD;
            ans = (ans + z) % MOD;
            pq.push(z);
            totalCnt--;
        }

        cout << ans % MOD << endl;
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
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
ll MOD = 1e9 + 7;
inline void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    // vector<int> cnt(64, 0);
    // for(auto &x : a)
    // {
    //     for(int i = 0; i < 64; ++i)
    //     {
    //         if(x & (1LL << i))
    //             cnt[i]++;
    //     }
    // }
    // ll sum = 0;
    // for(auto &x : a)
    // {
    //     ll cur = 0;
    //     for(int i = 0; i < 64; ++i)
    //     {
    //         if(x & (1LL << i))
    //         {
    //             cur += (1LL << i) * (n - cnt[i]);
    //         }
    //         else
    //         {
    //             cur += (1LL << i) * cnt[i];
    //         }
    //     }
    //     sum += cur;
    //     sum %= MOD;
    // }
    // cout << sum/2 << endl;
    ll total_xor_sum = 0;
    ll power_of_2 = 1;

    // 遍历每一位 (0 to 59)
    for (int i = 0; i < 60; ++i)
    {
        ll count_one = 0;
        for (auto &x : a)
        {
            if (x & (1LL << i))
            {
                count_one++;
            }
        }

        ll count_zero = n - count_one;

        ll pairs_contribution = (count_one * count_zero) % MOD;
        ll bit_contribution = (pairs_contribution * power_of_2) % MOD;

        total_xor_sum = (total_xor_sum + bit_contribution) % MOD;

        power_of_2 = (power_of_2 * 2) % MOD;
    }

    cout << total_xor_sum << endl;
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
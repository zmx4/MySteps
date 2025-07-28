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
const int N = 100005;
map<ll, int> mpl, mpr;
map<ll, int>::iterator it;
int n, a[N];
ll sum, ans;
inline void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        mpr[a[i]]++;
    }
    // int sum = accumulate(a.begin(), a.end(), 0LL);
    // if (sum % 2 != 0)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    // int l = 0, r = n - 1;
    // int presum = 0, sufsum = 0;
    // while(l <= r)
    // {
    //     if(presum < sufsum)
    //     {
    //         presum += a[l];
    //         l++;
    //     }
    //     else
    //     {
    //         sufsum += a[r];
    //         r--;
    //     }
    //     //dbg(presum, sufsum, l, r);
    // }
    // if(l!=r)
    // {
    //     if(presum < sufsum)
    //     {
    //         presum += a[l];
    //         l++;
    //     }
    //     else
    //     {
    //         sufsum += a[r];
    //         r--;
    //     }
    //     dbg(presum, sufsum, l, r);
    // }
    // if(presum == sufsum)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    // // dbg(presum, sufsum, l, r);
    // sort(a.begin(),a.begin() + l);
    // bool flag = false;
    // for (int i = r; i < n; i++)
    // {
    //     int tper = presum + a[i];
    //     int tsuf = sufsum - a[i];
    //     int tar = (tper - tsuf) / 2;
    //     if(binary_search(a.begin(), a.begin() + l, tar))
    //     {
    //         flag = true;
    //         break;
    //     }
    // }
    // if(flag)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }
    // int tar = sum / 2;
    // int persum = 0;
    // unordered_set<int> s;
    // for(int i = 0; i < n; i++)
    // {
    //     persum += a[i];
    //     s.insert(a[i]);
    //     if(persum == tar )
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     ll dif = tar - persum;
    //     if(dif > 0 && s.count(dif))
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // s.clear();
    // int sufsum = 0;
    // for(int i = n - 1; i >= 0; i--)
    // {
    //     sufsum += a[i];
    //     s.insert(a[i]);
    //     if(sufsum == tar)
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     ll dif = tar - sufsum;
    //     if(dif > 0 && s.count(dif))
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }
    // cout << "NO" << endl;
    // bool flag = false;
    // ll persum = 0;
    // int index;
    // for (index = 0; index < n; index++)
    // {
    //     persum += a[index];
    //     if (persum > tar)
    //     {
    //         break;
    //     }
    // }
    // for (int j = 0; j <= index; j++)
    // {
    //     if (persum - a[j] == tar)
    //     {
    //         flag = true;
    //         break;
    //     }
    // }
    // ll sufsum = 0;
    // for (index = n - 1; index >= 0; index--)
    // {
    //     sufsum += a[index];
    //     if (sufsum > tar)
    //     {
    //         break;
    //     }
    // }
    // for (int j = n - 1; j >= index; j--)
    // {
    //     if (sufsum - a[j] == tar)
    //     {
    //         flag = true;
    //         break;
    //     }
    // }
    // if (flag)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }
    if (sum % 2)
    {
        cout << "NO" << endl;
        return;
    }
    int flag = 0;
    sum = sum / 2;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i]; // 累计进前缀和。
        if (ans == sum)
        {
            flag = 1;
            break;
        }
        mpl[a[i]]++;
        mpr[a[i]]--;
        if (ans > sum && mpl[ans - sum])
        {
            flag = 1;
            break;
        }
        if (ans < sum && mpr[sum - ans])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "YES"
             << endl;
    }
    else
    {
        cout << "NO"
             << endl;
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1; // cin>>T;
    while (T--)
    {
        solve();
    }

    return 0;
}
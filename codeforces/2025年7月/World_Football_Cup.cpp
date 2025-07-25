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
inline void solve()
{
    int n;
    cin >> n;
    
    map<string, int> score, win, has;
    for(int i = 0; i < n; i++)
    {
        string team;
        cin >> team;
        score[team] = 0;
        win[team] = 0;
        has[team] = 0;
    }
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        string a, b;
        int x, y;
        string tmp;
        cin >> tmp;
        a = tmp.substr(0, tmp.find('-'));
        b = tmp.substr(tmp.find('-') + 1);
        cin >> tmp;
        x = stoi(tmp.substr(0, tmp.find(':')));
        y = stoi(tmp.substr(tmp.find(':') + 1));
        if(x > y)
        {
            score[a] += 3;
            win[a]+=x - y;
            has[a]+=x;
            score[b] += 0;
            win[b]+=y - x;
            has[b]+=y;
        }
        else if(x < y)
        {
            score[b] += 3;
            win[b]+=y - x;
            has[b]+=y;
            score[a] += 0;
            win[a]+=x - y;
            has[a]+=x;
        }
        else
        {
            score[a] += 1;
            score[b] += 1;
            win[a]+=x - y;
            win[b]+=y - x;
            has[a]+=x;
            has[b]+=y;
        }
    }
    vector<pair<string, int>> ans;
    for (auto &it : score)
    {
        ans.push_back({it.first, it.second});
    }
    sort(ans.begin(), ans.end(), [&](pair<string, int> &a, pair<string, int> &b) {
        if (a.second != b.second)
            return a.second > b.second;
        if (win[a.first] != win[b.first])
            return win[a.first] > win[b.first];
        if (has[a.first] != has[b.first])
            return has[a.first] > has[b.first];
        return a.first < b.first;
    });
    vector<string> output;
    for (int i = 0; i < n / 2;i++)
    {
        output.push_back(ans[i].first);
    }
    sort(output.begin(), output.end());
    for (const auto &team : output)
    {
        cout << team << endl;
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
    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
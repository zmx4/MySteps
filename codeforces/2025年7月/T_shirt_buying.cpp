#include <bits/stdc++.h>
#define endl " "
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
const int N = 2e5 + 10, M = 1e5 + 10;
int p[N], a[N], b[N];
/*
1 1 1
1 2 2
1 3 3
2 2 4
2 3 5
3 3 6
*/
priority_queue<int, vector<int>, greater<int>> q[7];

inline void process(int x,int y,int price)
{
    if(x>y)swap(x,y);
    if(x==1&&y==1)
    {
        q[1].push(price);
        return;
    }
    if(x==1&&y==2)
    {
        q[2].push(price);
        return;
    }
    if(x==1&&y==3)
    {
        q[3].push(price);
        return;
    }
    if(x==2&&y==2)
    {
        q[4].push(price);
        return;
    }
    if(x==2&&y==3)
    {
        q[5].push(price);
        return;
    }
    if(x==3&&y==3)
    {
        q[6].push(price);
        return;
    }
}
inline void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)process(a[i], b[i], p[i]);
    int m;
    cin >> m;
    while(m--)
    {
        int x;
        cin >> x;
        if(x==1)
        {
            if(q[1].empty()&&q[2].empty() && q[3].empty())
            {
                cout << -1 << endl;
                continue;
            }
            int x1 = 1e18, x2 = 1e18, x3 = 1e18;
            if(!q[1].empty())x1 = q[1].top();
            if(!q[2].empty())x2 = q[2].top();
            if(!q[3].empty())x3 = q[3].top();
            if(x1 <= x2 && x1 <= x3)
            {
                cout << x1 << endl;
                q[1].pop();
            }
            else if(x2 <= x1 && x2 <= x3)
            {
                cout << x2 << endl;
                q[2].pop();
            }
            else
            {
                cout << x3 << endl;
                q[3].pop();
            }
        }
        else if(x==2)
        {
            if(q[2].empty() && q[4].empty() && q[5].empty())
            {
                cout << -1 << endl;
                continue;
            }
            int x1 = 1e18, x2 = 1e18, x3 = 1e18;
            if(!q[2].empty())x1 = q[2].top();
            if(!q[4].empty())x2 = q[4].top();
            if(!q[5].empty())x3 = q[5].top();
            if(x1 <= x2 && x1 <= x3)
            {
                cout << x1 << endl;
                q[2].pop();
            }
            else if(x2 <= x1 && x2 <= x3)
            {
                cout << x2 << endl;
                q[4].pop();
            }
            else
            {
                cout << x3 << endl;
                q[5].pop();
            }
        }
        else if(x==3)
        {
            if(q[3].empty() && q[5].empty() && q[6].empty())
            {
                cout << -1 << endl;
                continue;
            }
            int x1 = 1e18, x2 = 1e18, x3 = 1e18;
            if(!q[3].empty())x1 = q[3].top();
            if(!q[5].empty())x2 = q[5].top();
            if(!q[6].empty())x3 = q[6].top();
            if(x1 <= x2 && x1 <= x3)
            {
                cout << x1 << endl;
                q[3].pop();
            }
            else if(x2 <= x1 && x2 <= x3)
            {
                cout << x2 << endl;
                q[5].pop();
            }
            else
            {
                cout << x3 << endl;
                q[6].pop();
            }
        }
        else
        {
            cout << -1 << endl;
        }
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
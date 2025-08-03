#include <bits/stdc++.h>
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

int maxx; // 全局变量，存储好感度最高的人，供比较函数使用

// 询问1：真心话
int zxh(int p1, int p2, int p3)
{
    cout << "1 " << p1 << " " << p2 << " " << p3 << endl;
    // fflush(stdout);
    int x;
    cin >> x;
    return x;
}

// 询问2：大冒险
int dmx(int p1, int p2)
{
    cout << "2 " << p1 << " " << p2 << endl;
    // fflush(stdout);
    int uu;
    cin >> uu;
    return uu;
}

// 排序用的比较函数
bool cmp(int p1, int p2)
{
    // 因为 maxx 是最好的，所以 p1, p2, maxx 的中位数一定是 p1 和 p2 中更好的那个
    return zxh(p1, p2, maxx) == p1;
}

inline void solve()
{
    int n;
    cin >> n;

    // --- 步骤 1: 找出好感度最高的人 ---
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    // 通过“真心话”询问，将候选人缩减到2个以内
    while (q.size() > 2)
    {
        int p1 = q.front();
        q.pop();
        int p2 = q.front();
        q.pop();
        int p3 = q.front();
        q.pop();

        int median = zxh(p1, p2, p3);

        // 中位数一定不是最好的，淘汰掉，把另外两个放回队列
        if (p1 != median)
            q.push(p1);
        if (p2 != median)
            q.push(p2);
        if (p3 != median)
            q.push(p3);
    }

    // 从剩下的1或2个候选人中确定最终的 maxx
    if (q.size() == 1)
    {
        maxx = q.front();
    }
    else // q.size() == 2
    {
        int p1 = q.front();
        q.pop();
        int p2 = q.front();
        q.pop();
        maxx = dmx(p1, p2);
    }

    // --- 步骤 2: 对剩下的人进行排序 ---
    vector<int> others;
    for (int i = 1; i <= n; ++i)
    {
        if (i != maxx)
        {
            others.push_back(i);
        }
    }
    sort(others.begin(), others.end(), cmp);

    // --- 步骤 3: 输出答案 ---
    cout << "3 " << maxx;
    for (int person : others)
    {
        cout << " " << person;
    }
    cout << endl;
    // fflush(stdout);
}

signed main()
{

    int T = 1; // cin>>T;
    while (T--)
    {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
#define int long long
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
const int N = 1e5 + 10, M = 1e5 + 10;
vector<vector<pair<int,int>>> tree;
int in[N];
// void pre(int u)
// {
//     int l = -1, r = -1;
//     for(auto [v,w] : tree[u])
//     {
//         if(w==0)
//         l = v;
//         else if(w==1)
//         r = v;
//     }
//     cout << u << " ";
//     if(l != -1)
//     {
//         pre(l);
//     }
//     if(r != -1)
//     {
//         pre(r);
//     }
// }
// void mid(int u)
// {
//     int l = -1, r = -1;
//     for(auto [v,w] : tree[u])
//     {
//         if(w==0)
//         l = v;
//         else if(w==1)
//         r = v;
//     }
//     if(l != -1)
//     {
//         mid(l);
//     }
//     cout << u << " ";
//     if(r != -1)
//     {
//         mid(r);
//     }
// }
// void post(int u)
// {
//     int l = -1, r = -1;
//     for(auto [v,w] : tree[u])
//     {
//         if(w==0)
//         l = v;
//         else if(w==1)
//         r = v;
//     }
//     if(l != -1)
//     {
//         post(l);
//     }
//     if(r != -1)
//     {
//         post(r);
//     }
//     cout << u << " ";
// }
// void cenci(int u)
// {
//     queue<int> q;
//     q.push(u);
//     while(!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         cout << x << " ";
//         int l = -1, r = -1;
//         for(auto [v,w] : tree[x])
//         {
//             if(w==0)
//             l = v;
//             else if(w==1)
//             r = v;
//         }
//         if(l != -1)
//         {
//             q.push(l);
//         }
//         if(r != -1)
//         {
//             q.push(r);
//         }
//     }
// }
void pre(int u)
{
    stack<int> st;
    st.push(u);
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        cout << x << " ";
        int l = -1, r = -1;
        for (auto [v, w] : tree[x])
        {
            if (w == 0)
                l = v;
            else if (w == 1)
                r = v;
        }
        // 先右后左，保证左边先弹出
        if (r != -1)
            st.push(r);
        if (l != -1)
            st.push(l);
    }
}

// 非递归中序遍历
void mid(int u)
{
    stack<int> st;
    int curr = u;
    while (curr != -1 || !st.empty())
    {
        while (curr != -1)
        {
            st.push(curr);
            int l = -1;
            for (auto [v, w] : tree[curr])
                if (w == 0)
                    l = v;
            curr = l;
        }
        curr = st.top();
        st.pop();
        cout << curr << " ";
        int r = -1;
        for (auto [v, w] : tree[curr])
            if (w == 1)
                r = v;
        curr = r;
    }
}

// 非递归后序遍历
void post(int u)
{
    stack<int> st1, st2;
    st1.push(u);
    while (!st1.empty())
    {
        int x = st1.top();
        st1.pop();
        st2.push(x);
        int l = -1, r = -1;
        for (auto [v, w] : tree[x])
        {
            if (w == 0)
                l = v;
            else if (w == 1)
                r = v;
        }
        if (l != -1)
            st1.push(l);
        if (r != -1)
            st1.push(r);
    }
    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
}

// 层次遍历原本就是非递归的队列实现，不用改
void cenci(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        int l = -1, r = -1;
        for (auto [v, w] : tree[x])
        {
            if (w == 0)
                l = v;
            else if (w == 1)
                r = v;
        }
        if (l != -1)
            q.push(l);
        if (r != -1)
            q.push(r);
    }
}
inline void solve()
{
	int n;
    cin>>n;

    tree.assign(n + 2, vector<pair<int,int>>());
    for(int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[v].pb({u, w});
        in[u]++;
    }
	int fa = -1;
    for (int i = 1;i <= n; i++)
    {
        if (in[i] == 0)
        {
            fa = i;
            break;
        }
    }
    pre(fa);
    cout << endl;
    mid(fa);
    cout << endl;
    post(fa);
    cout << endl;
    cenci(fa);
    cout << endl;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;
	
	solve();
	
	
	return 0;
}
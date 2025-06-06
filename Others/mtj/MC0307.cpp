#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e7+10;
vector<int> a;
bool ok = false;
bool vis[N];
int dist[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    memset(dist, -1, sizeof(dist));
    int n, x, y;
    cin >> n >> x >> y;
    a.resize(n+1);
    for (int i = 1; i<= n;i++)cin>>a[i];
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    vis[x] = true;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == y)
            break;
        int k = a[u];
        int v = u + k;
        if (v <= n && !vis[v])
        {
            vis[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
        v = u - k;
        if (v >= 1 && !vis[v])
        {
            vis[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    cout << dist[y] << endl;
    
    return 0;
}
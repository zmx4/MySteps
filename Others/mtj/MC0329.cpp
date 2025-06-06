#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
vector<vector<int>> g;
int dis[N];
bool vis[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; i++)
    {
        int u, k;
        cin >> u >> k;
        for (int j = 1; j <= k; j++)
        {
            int v;
            cin >> v;
            g[u].push_back(v);
        }
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    vis[1] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(i!=1&&dis[i]==0)
        {
            cout << i << " " << -1 << endl;
        }
        else
        {
            cout << i << " " << dis[i] << endl;
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3+10;
int g[N][N];
bool vis[N];
int dist[N];
void solve()
{
    int n;
    cin>> n;
    for(int i = 1; i <= n; i++)
    {
        int val, l, r;
        cin >> val >> l >> r;
        if(l!=0)
        {
            g[i][l] = val;
            g[l][i] = val;
        }
        if(r!=0)
        {
            g[i][r] = val;
            g[r][i] = val;
        }
        dist[i] = val;
    }
    auto bfs = [&](int s)
    {
        memset(vis, 0, sizeof vis);
        ll dis = 0;
        queue<pair<int, int>> q;
        q.push({s, 0});
        vis[s] = true;
        while(!q.empty())
        {
            auto [u, d] = q.front();
            q.pop();
            dis += d*dist[u];
            for(int i = 1; i <= n; i++)
            {
                if(g[u][i] && !vis[i])
                {
                    vis[i] = true;
                    q.push({i, d + 1});
                }
            }
        }
        return dis;
    };
    ll ans = inf;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, bfs(i));
    }
    cout << ans << endl;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    // cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}
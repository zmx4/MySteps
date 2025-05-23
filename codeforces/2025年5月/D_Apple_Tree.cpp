#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<vector<int>> g;
vector<int>cnt;
void dfs(int u,int fa)
{
    if(g[u].size() == 1 && g[u][0] == fa)
    {
        cnt[u] = 1;
    }
    else
    {
        for(auto v:g[u])
        {
            if(v == fa)continue;
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    g.assign(n, vector<int>());
    for(int i = 1;i < n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt.assign(n, 0);
    dfs(0, -1);
    int m;
    cin>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        ll ans = cnt[a] * cnt[b];
        cout<<ans<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}
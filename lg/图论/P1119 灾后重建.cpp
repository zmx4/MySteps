#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 300;
int g[N][N] ,tt[N];
inline void update(int k)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]),g[j][i] = g[i][j];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = (i == j ? 0 : inf);
    for(int i = 0; i < n; i++)cin >> tt[i];
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    int Q;
    cin >> Q;
    int now = 0;
    for (int i = 1; i <= Q;i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        while(tt[now]<= t && now<n)
        {
            update(now);
            now++;
        }
        if(tt[x]>t || tt[y]>t)
        {
            cout << "-1" << endl;
            continue;
        }
        else
        {
            if(g[x][y] == inf)
                cout << "-1" << endl;
            else
                cout << g[x][y] << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    cout.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    // cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}
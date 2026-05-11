#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 50;
int g[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ddx[4] = {2, 0, -2, 0}, ddy[4] = {0, 2, 0, -2};
bool vis[100][100];
int n, m, k;
int ans = INT_MAX;
void dfs(int res)
{
    ans = min(ans, res);
    if (res == 1 || res == 0)
        return;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!g[i][j])
                continue;
            for (int k = 0; k < 4; ++k)
            {
                int nx = i + dx[k], ny = j + dy[k];
                int nnx = i + ddx[k], nny = j + ddy[k];
                if (nx < 1 || nnx < 1 || nx > n || nnx > n)
                    continue;
                if (ny < 1 || nny < 1 || ny > m || nny > m)
                    continue;
                if(g[nx][ny]==1&&g[nnx][nny]==0)
                {
                    g[i][j] = g[nx][ny] = 0;
                    g[nnx][nny] = 1;
                    dfs(res - 1);
                    g[i][j] = g[nx][ny] = 1;
                    g[nnx][nny] = 0;
                }
            }
        }
    }
}
void solve()
{
    ans = INT_MAX;
    cin >> n >> m >> k;
    memset(vis, false, sizeof vis);
    memset(g, 0, sizeof g);
    int u, v;
    for (int i = 1; i <= k; ++i)
    {
        cin >> u >> v;
        g[u][v] = 1;
    }
    dfs(k);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
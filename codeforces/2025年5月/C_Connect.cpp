#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[100][100];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    int startx, starty;
    cin >> startx >> starty;
    int endx, endy;
    cin >> endx >> endy;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            g[i][j] = (c == '1' ? 1 : 0);
        }
    }
    vector<pair<int, int>> points1, points2;
    queue<pair<int, int>> q;
    q.push({startx, starty});
    vis[startx][starty] = true;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        points1.push_back({x, y});
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && g[nx][ny] == 0)
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    if (vis[endx][endy])
    {
        cout << 0 << endl;
        return 0;
    }
    memset(vis, false, sizeof(vis));
    q.push({endx, endy});
    vis[endx][endy] = true;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        points2.push_back({x, y});
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && g[nx][ny] == 0)
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    int ans = INT_MAX;
    for (auto [x1, y1] : points1)
    {
        for (auto [x2, y2] : points2)
        {
            ans = min(ans, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
    }
    cout << ans << endl;

    return 0;
}
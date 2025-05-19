#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define sc scanf
#define ff first
#define ss second

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(n, -1));
    // 顺时针螺旋：down, right, up, left
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int d = 0;
    int x = 0, y = 0;
    for (int i = n * n - 1; i >= 0; i--)
    {
        p[x][y] = i;
        int nx = x + dx[d];
        int ny = y + dy[d];
        // 增加下边界检查，避免 nx<0 或 ny<0 越界
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || p[nx][ny] != -1)
            d = (d + 1) % 4;
        x += dx[d];
        y += dy[d];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << p[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
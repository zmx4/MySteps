#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

char g[1005][1005];
bool vis[1005][1005];
int w, h, ans = 1;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int stx, sty;

inline void dfs(int x, int y)
{
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > h || ny < 1 || ny > w || vis[nx][ny] || g[nx][ny] == '#')
			continue;
		ans++;
		dfs(nx, ny);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> w >> h;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			cin >> g[i][j];
			if (g[i][j] == '@')
				stx = i, sty = j;
		}
	dfs(stx, sty);
	cout << ans << endl;

	return 0;
}
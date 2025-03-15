#include <bits/stdc++.h>
using namespace std;

char a[3011][3011]; // Changed to char array
int n, m;
bool vis[3011][3011];
// 定义四个方向的移动：右、左、下、上
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int stx, sty;
int ans = 1;

// Renamed to dfs to reflect actual algorithm
inline void dfs(int x, int y)
{
	vis[x][y] = true;
	// Removed debug output
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || a[nx][ny] == '#')
			continue;
		ans++;
		dfs(nx, ny);
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j]; // Directly store as char
			if (a[i][j] == '@')
				stx = i, sty = j;
		}

	vis[stx][sty] = 1;
	dfs(stx, sty);
	cout << ans << endl;
	return 0;
}
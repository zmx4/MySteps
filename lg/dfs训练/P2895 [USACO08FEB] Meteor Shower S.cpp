#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
struct star
{
	int x, y, time;
};
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[1005][1005];
int times[1005][1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	for (int i = 0;i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			times[i][j] = inf;
	int m;
	cin >> m;
	vector<star> stars(m);
	for (int k = 0; k < m; k++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		times[x][y] = min(times[x][y], t);
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && ny >= 0 && nx <= 1000 && ny <= 1000)
			{
				times[nx][ny] = min(times[nx][ny], t);
			}
		}
	}
	queue<star> q;
	if (times[0][0] > 0)
	{
		q.push({0, 0, 0});
		vis[0][0] = true;
	}
	while (!q.empty())
	{
		//cout << 1 << endl;
		auto cur = q.front();
		q.pop();
		if (times[cur.x][cur.y] == inf)
		{
			cout << cur.time << endl;
			return 0;
		}
		for (int d = 0; d < 4; d++)
		{
			int nx = cur.x + dx[d], ny = cur.y + dy[d];
			int nt = cur.time + 1;
			if (nx < 0 || ny < 0 || nx > 1000 || ny > 1000)
				continue;
			if (vis[nx][ny])
				continue;
			if (nt < times[nx][ny])
			{
				vis[nx][ny] = true;
				q.push({nx, ny, nt});
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
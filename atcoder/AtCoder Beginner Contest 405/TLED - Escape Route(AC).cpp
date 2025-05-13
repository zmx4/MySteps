#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1005;
char g[N][N],ans[N][N];
int dis[N][N];
vector<pair<int, int>> p;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char sign[] = {'^','<','v','>'};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	memset(dis,0x3f,sizeof(dis));
	int h, w;
	cin >> h >> w;
	for(int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> g[i][j];
			if (g[i][j] == 'E')
			{
				p.push_back({i, j});
			}
			if(g[i][j]!='.')
				ans[i][j] = g[i][j];
		}
	}

	queue<pair<int, int>> q;
	for(auto [x, y] : p)
	{
		dis[x][y] = 0;
		q.push({x, y});
	}
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || nx > h || ny < 1 || ny > w)continue;
			if (g[nx][ny] == '#')continue;
			if(dis[nx][ny] > dis[x][y] + 1)
			{
				dis[nx][ny] = dis[x][y] + 1;
				q.push({nx, ny});
				ans[nx][ny] = sign[i];
			}
		}
	}
	
	for(int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (g[i][j] == '#')cout << '#';
			else if (g[i][j] == 'E')cout << 'E';
			else cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
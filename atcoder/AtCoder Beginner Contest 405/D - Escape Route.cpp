#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int INF_DIST = 0x3f3f3f3f;
const int N = 1005;
char g[N][N];	
char ans[N][N]; 
int dis[N][N];	

int dx[4] = {1, 0, -1, 0};			 
char sign[4] = {'^', '<', 'v', '>'};
int dy[4] = {0, 1, 0, -1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dis, 0x3f, sizeof(dis));

	int h, w;
	cin >> h >> w;

	vector<string> g1(h);
	for (int i = 0; i < h; ++i)
	{
		cin >> g1[i];
	}

	queue<pair<int, int>> q;

	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			g[i][j] = g1[i - 1][j - 1];
			ans[i][j] = g[i][j];
			if (g[i][j] == 'E')
			{
				dis[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		int r = curr.first;
		int c = curr.second;

		for (int i = 0; i < 4; ++i)
		{						
			int nr = r + dx[i]; 
			int nc = c + dy[i];
			if (nr < 1 || nr > h || nc < 1 || nc > w)
			{
				continue;
			}
			if (g[nr][nc] == '.')
			{
				if (dis[nr][nc] == INF_DIST)
				{
					dis[nr][nc] = dis[r][c] + 1;
					ans[nr][nc] = sign[i];
					q.push({nr, nc});
				}
			}
		}
	}
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
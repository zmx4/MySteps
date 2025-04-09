#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
bool vis[55][55];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void solve()
{
	int m, n;
	cin >> m >> n;

	// 读取地图，外围加一圈水域方便处理
	vector<vector<int>> grid(m + 2, vector<int>(n + 2, 0));
	for (int i = 1; i <= m; i++)
	{
		string line;
		cin >> line;
		for (int j = 1; j <= n; j++)
		{
			grid[i][j] = line[j - 1] - '0';
		}
	}

	// 标记各个岛屿
	vector<vector<int>> islandId(m + 2, vector<int>(n + 2, 0));
	int islandCount = 0;

	// 标记每个岛屿
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (grid[i][j] == 1 && islandId[i][j] == 0)
			{
				islandCount++;
				queue<pair<int, int>> q;
				q.push({i, j});
				islandId[i][j] = islandCount;

				while (!q.empty())
				{
					auto [x, y] = q.front();
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 1 && nx <= m && ny >= 1 && ny <= n &&
							grid[nx][ny] == 1 && islandId[nx][ny] == 0)
						{
							islandId[nx][ny] = islandCount;
							q.push({nx, ny});
						}
					}
				}
			}
		}
	}

	// 标记外部水域（从边界水域开始flood fill）
	vector<vector<bool>> isOuterWater(m + 2, vector<bool>(n + 2, false));
	queue<pair<int, int>> q;

	// 将边界水域入队
	for (int i = 0; i <= m + 1; i++)
	{
		for (int j = 0; j <= n + 1; j++)
		{
			if ((i == 0 || i == m + 1 || j == 0 || j == n + 1) ||
				(grid[i][j] == 0 && (i == 1 || i == m || j == 1 || j == n)))
			{
				isOuterWater[i][j] = true;
				q.push({i, j});
			}
		}
	}

	// BFS扩展外部水域
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx <= m + 1 && ny >= 0 && ny <= n + 1 &&
				grid[nx][ny] == 0 && !isOuterWater[nx][ny])
			{
				isOuterWater[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}

	// 检查每个岛屿是否与外部水域相邻
	vector<bool> isOuterIsland(islandCount + 1, false);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (grid[i][j] == 1)
			{
				int id = islandId[i][j];
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx <= m + 1 && ny >= 0 && ny <= n + 1 && isOuterWater[nx][ny])
					{
						isOuterIsland[id] = true;
					}
				}
			}
		}
	}

	// 统计外层岛屿数量
	int count = 0;
	for (int i = 1; i <= islandCount; i++)
	{
		if (isOuterIsland[i])
		{
			count++;
		}
	}

	cout << count << endl;
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
		memset(vis, 0, sizeof vis);
		solve();
	}
	
	return 0;
}
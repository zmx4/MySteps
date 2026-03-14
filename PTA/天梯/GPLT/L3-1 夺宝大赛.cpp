#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

const int N = 105;
int g[N][N];
int tx, ty;
bool vis[N][N];
int dist[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int m, n;
unordered_map<int,vector<pair<int,int>>> mp;
/*
int bfs(int startR, int startC)
{
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int>> q;
	q.push({startR, startC});
	vis[startR][startC] = true;
	int res = 0;
	while (!q.empty())
	{
		int sz = q.size();
		while (sz--)
		{
			auto cur = q.front();
			q.pop();
			int r = cur.first, c = cur.second;
			if (r == tx && c == ty)
				return res;
			for (int i = 0; i < 4; i++)
			{
				int nr = r + dx[i], nc = c + dy[i];
				if (nr >= 1 && nr <= m && nc >= 1 && nc <= n && !vis[nr][nc] && g[nr][nc] != 0)
				{
					vis[nr][nc] = true;
					q.push({nr, nc});
				}
			}
		}
		res++;
	}
	return -1;
}
*/
void bfs()
{
	memset(dist, -1, sizeof(dist)); // -1表示不可达
	queue<pair<int, int>> q;
	q.push({tx, ty});
	dist[tx][ty] = 0;

	while (!q.empty())
	{
		auto [r, c] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dx[i], nc = c + dy[i];
			if (nr >= 1 && nr <= m && nc >= 1 && nc <= n && g[nr][nc] != 0 && dist[nr][nc] == -1)
			{
				dist[nr][nc] = dist[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> g[i][j];
			if (g[i][j] == 2)
			{
				tx = i, ty = j;
			}
		}
	}

	bfs();

	int t;
	cin >> t;
	vector<pair<int, int>> times;

	for (int i = 1; i <= t; i++)
	{
		int col, row;
		cin >> col >> row;
		if (dist[row][col] != -1)
		{
			times.push_back({i, dist[row][col]});
		}
	}

	if (times.empty())
	{
		cout << "No winner." << endl;
		return 0;
	}

	unordered_map<int, int> freq;
	for (auto [id, time] : times)
	{
		freq[time]++;
	}

	int winTime = INT_MAX, winId = -1;
	for (auto [id, time] : times)
	{
		if (freq[time] == 1 && time < winTime)
		{
			winTime = time;
			winId = id;
		}
	}

	if (winId == -1)
	{
		cout << "No winner." << endl;
	}
	else
	{
		cout << winId << " " << winTime << endl;
	}

	return 0;
}
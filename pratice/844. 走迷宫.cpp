#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int n, m;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(vector<vector<int>> &a)
{
	list<pair<int, int>> q;
	q.push_back({0, 0});
	vector<vector<int>> dist(n, vector<int>(m, -1));
	dist[0][0] = 0;
	while(!q.empty())
	{
		auto [x, y] = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] != -1)
				continue;
			if (a[nx][ny] == 1)
				continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push_back({nx, ny});
		}
	}
	return dist[n - 1][m - 1];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	cout << bfs(a) << endl;
	return 0;
}
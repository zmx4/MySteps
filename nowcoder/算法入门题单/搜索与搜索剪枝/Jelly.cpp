#include <bits/stdc++.h>
using namespace std;

const int MAX_R = 100 * 100 + 5; 
const int MAX_C = 105;			 

char a[MAX_R][MAX_C]; 
int dis[MAX_R][MAX_C];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int rows = n * n; 
	int cols = n;	  
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			cin >> a[i][j];
		}
	}

	memset(dis, 0, sizeof(dis));
	queue<pair<int, int>> q;
	q.push({1, 1});
	dis[1][1] = 1;


	int dx[6] = {1, -1, 0, 0, n, -n};
	int dy[6] = {0, 0, 1, -1, 0, 0};

	while (!q.empty())
	{
		auto [r, c] = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = r + dx[i], ny = c + dy[i];

			if (dx[i] == 1 || dx[i] == -1)
			{
				int x = (r - 1) % n + 1;
				if (dx[i] == 1 && x == n)
					continue;
				if (dx[i] == -1 && x == 1)
					continue;
			}
			if (dx[i] == n)
			{
				int z = (r - 1) / n + 1;
				if (z == n)
					continue;
			}
			if (dx[i] == -n)
			{
				int z = (r - 1) / n + 1;
				if (z == 1)
					continue;
			}

			if (nx < 1 || nx > rows || ny < 1 || ny > cols)
				continue;
			if (a[nx][ny] == '*')
				continue;
			if (dis[nx][ny] != 0)
				continue;

			dis[nx][ny] = dis[r][c] + 1;
			q.push({nx, ny});
		}
	}

	int res = dis[rows][cols];
	if (res == 0)
		cout << -1 << "\n";
	else
		cout << res << "\n";

	return 0;
}
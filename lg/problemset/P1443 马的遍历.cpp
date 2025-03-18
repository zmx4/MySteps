#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int n, m, x, y;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> m >> x >> y;
	vector<vector<int>> a(n + m, vector<int>(m + n, 0));
	vector<vector<int>> ans(n + m, vector<int>(m + n, -1));
	queue<pair<int,int>> q;
	q.push({x, y});
	ans[x][y] = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && ans[nx][ny]==-1)
			{
				ans[nx][ny] = ans[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << format("{:<5d}", ans[i][j]);
		}
		cout << endl;
	}
	return 0;
}
//"/C/Env/MSYS/mingw64/include/c++/14.2.0/x86_64-w64-mingw32/bits/stdc++.h"
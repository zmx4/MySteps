#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> grid[i];
	}

	vector<vector<char>> result(n, vector<char>(m, '0'));

	int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == '*')
			{
				result[i][j] = '*';
			}
			else
			{
				int count = 0;
				for (int k = 0; k < 8; ++k)
				{
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*')
					{
						count++;
					}
				}
				result[i][j] = count + '0';
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << result[i][j];
		}
		cout << endl;
	}

	return 0;
}
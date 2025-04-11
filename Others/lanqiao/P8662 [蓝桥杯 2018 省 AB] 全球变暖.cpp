#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1005;
char f[N][N], s[N][N];
int n;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void dfss(int x, int y)
{
	s[x][y] = '.';
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && s[xx][yy] != '.')
			dfss(xx, yy);
	}
}

// dfsf：对原图 f 进行 DFS，将连通区域清空，用于统计原始岛屿数
void dfsf(int x, int y)
{
	f[x][y] = '.';
	for (int i = 0; i < 4; i++)
	{
		int xt = x + dx[i], yt = y + dy[i];
		if (xt >= 1 && xt <= n && yt >= 1 && yt <= n && f[xt][yt] == '#')
			dfsf(xt, yt);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> f[i][j];
			s[i][j] = f[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i][j] == '#' &&
				(s[i - 1][j] == '.' || s[i + 1][j] == '.' || s[i][j - 1] == '.' || s[i][j + 1] == '.'))
				s[i][j] = '-';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i][j] == '#')
			{
				dfss(i, j);
				cnt++;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (f[i][j] == '#')
			{
				dfsf(i, j);
				sum++;
			}
		}
	}

	cout << sum - cnt  << endl;

	return 0;
}
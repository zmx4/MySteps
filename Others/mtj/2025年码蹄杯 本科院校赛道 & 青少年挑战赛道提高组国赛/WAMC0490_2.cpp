#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
int yy1[110][110], yy2[110][110], yy3[110][110], yy4[110][110];
int g[1010][1010];
int n, m, q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			if (c == '#')yy1[i][j] = 1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			yy2[j][m - i + 1] = yy1[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			yy4[m - j + 1][i] = yy1[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			yy3[m - j + 1][m - i + 1] = yy1[i][j];
		}
	}



	int now = 0;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			now++;
			now %= 4;
		}
		else
		{
			if (now == 0)
			{
				int x, y;
				cin >> x >> y;
				for (int i = x; i <= x + m; i++)
				{
					for (int j = y; j <= y + m; j++)
					{
						g[i][j] += yy1[i - x + 1][j - y + 1];
					}
				}
			}
			else if (now == 1)
			{
				int x, y;
				cin >> x >> y;
				for (int i = x; i <= x + m; i++)
				{
					for (int j = y; j <= y + m; j++)
					{
						g[i][j] += yy2[i - x + 1][j - y + 1];
					}
				}
			}
			else if (now == 2)
			{
				int x, y;
				cin >> x >> y;
				for (int i = x; i <= x + m; i++)
				{
					for (int j = y; j <= y + m; j++)
					{
						g[i][j] += yy3[i - x + 1][j - y + 1];
					}
				}
			}
			else if (now == 3)
			{
				int x, y;
				cin >> x >> y;
				for (int i = x; i <= x + m; i++)
				{
					for (int j = y; j <= y + m; j++)
					{
						g[i][j] += yy4[i - x + 1][j - y + 1];
					}
				}
			}
		}
	}
	for (int i = 1 ; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
/*

5 3 7
##.
##.
...
2 1 1
1
2 1 1
1
2 1 1
1
2 1 1

*/

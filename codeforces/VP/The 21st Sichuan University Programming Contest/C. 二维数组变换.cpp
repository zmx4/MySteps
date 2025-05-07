#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < q; i++)
	{
		int op, x0, y0, x1, y1;
		cin >> op >> x0 >> y0 >> x1 >> y1;
		x0--;
		y0--;
		x1--;
		y1--;
		int len = x1 - x0 + 1;
		vector<vector<int>> tmp(len, vector<int>(len));
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				tmp[i][j] = a[x0 + i][y0 + j];
			}
		}
		vector<vector<int>> tmp2(len, vector<int>(len));
		if (op == 1)
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					tmp2[j][len - 1 - i] = tmp[i][j];
				}
			}
		}
		else if (op == 2)
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					tmp2[i][len - 1 - j] = tmp[i][j];
				}
			}
		}
		else if (op == 3)
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					tmp2[len - 1 - i][j] = tmp[i][j];
				}
			}
		}
		else if (op == 4)
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					tmp2[j][i] = tmp[i][j];
				}
			}
		}
		else if (op == 5)
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					tmp2[len - 1 - j][len - 1 - i] = tmp[i][j];
				}
			}
		}
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				a[x0 + i][y0 + j] = tmp2[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << (j + 1 < n ? " " : endl);
		}
	}

	return 0;
}
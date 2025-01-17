#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int a[10][10];
bool st[10];



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> a[i][j];
		}
	}

	memset(st, 0, sizeof(st));

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (st[a[i][j]])
			{
				cout << "NO" << endl;
				return 0;
			}
			st[a[i][j]] = true;
		}
		memset(st, 0, sizeof(st));
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (st[a[j][i]])
			{
				cout << "NO" << endl;
				return 0;
			}
			st[a[j][i]] = true;
		}
		memset(st, 0, sizeof(st));
	}
	for (int p = 1; p <= 9; p += 3)
	{
		for (int q = 1; q <= 9; q += 3)
		{
			int st[9] = {0};
			for (int m = 1; m <= 3; m++)
			{
				for (int n = 1; n <= 3; n++)
				{
					st[a[m][n]]++;
				}
			}
			for (int k = 1; k <= 9; k++)
			{
				if (st[k] == 0)
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
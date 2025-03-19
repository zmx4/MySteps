#include <bits/stdc++.h>
using namespace std;
int a[50][50];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
	bool flag = false;
	for (int i = 2; i < m; ++i)
	{
		for (int j = 2; j < n; ++j)
		{
			if (a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1])
			{
				cout << a[i][j] << " " << i << " " << j << endl;
				flag = true;
			}
		}
	}
	if (!flag)
	{
		cout << "None " << m << " " << n << endl;
	}
	return 0;
}
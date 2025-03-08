#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
vector<vector<int>> a(40, vector<int>(40, 1));
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 0)
				a[i][j] = 2;
		}
	for (int i = 1; i <= 39; i++)
	{
		a[0][i] = 9;
		a[i][0] = 9;
	}
		// 四周不可能被替换
	for (int i = 0;i <= n + 1;i++)
	{
		if(a[1][i] == 2)
			a[1][i] = 0;
		if(a[i][1] == 2)
			a[i][1] = 0;
		if(a[n][i] == 2)
			a[n][i] = 0;
		if(a[i][n] == 2)
			a[i][n] = 0;
	}
	for (int k = 49;k >= 48;k--)
		for (int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(a[i][j] != 1)
				{
					int cnt = 0;
					for (int l = 0;l < 4;l++)
						if(a[i + dx[l]][j + dy[l]] == 0)
							a[i][j]= 0;
				}
	for (int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cout<<a[i][j]<<((j == n) ? "\n" : " ");
	return 0;
}
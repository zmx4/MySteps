#include <bits/stdc++.h>
using namespace std;

const int N = 40;

char p[N][N];
bool coal[N], dg[N*2], udg[N*2];
int n;

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)
		{
			puts(p[i]);
		}
		puts("");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!coal[i] && !dg[i + u] && !udg[n - u + i])
		{
			p[u][i] = 'Q';
			coal[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			coal[i] = dg[u + i] = udg[n - u + i] = false;
			p[u][i] = '.';
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = '.';
		}
	}
	dfs(0);

	return 0;
}
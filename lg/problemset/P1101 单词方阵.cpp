#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int N = 105;
int grid[N][N];
string match = "yizhong";
int n;
bool ma[N][N];
int dfs(int x,int y,int cnt)
{
	if(x<1||y<1||x>n||y>n)
		return 0;
	if(grid[x][y]==match[cnt])
	{
		if(cnt == 7)
		{
			ma[x][y] = 1;
			return 1;
		}
		if (dfs(x + 1, y, cnt + 1) || dfs(x - 1, y, cnt + 1) || dfs(x, y + 1, cnt + 1) || dfs(x, y - 1, cnt + 1) || dfs(x - 1, y - 1, cnt + 1) || dfs(x + 1, y - 1, cnt + 1) || dfs(x - 1, y + 1, cnt + 1) || dfs(x + 1, y + 1, cnt + 1))
		{
			ma[x][y] == 1;
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n;j++)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 1; i <= n;i++)
		for (int j = 1; j <= n;j++)
			dfs(i, j, 1);
	

			return 0;
}
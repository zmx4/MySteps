#include <iostream>
using namespace std;

const int N = 40;
int n;
char p[N][N];
bool cola[N], dg[N*2], udg[N*2],row[N];

void dfs(int x,int y,int s)
{
	if(y == n)
	{
		y = 0;
		x++;
	}
	if(x == n)
	{
		if(s == n)
		{
			for(int i = 0;i < n;i++)
			{
				puts(p[i]);
			}
			puts("");
			
		}
		return;
	}
	//不放皇后
	dfs(x,y+1,s);

	//放皇后
	if(!row[x]&&!cola[y] && !dg[x+y] && !udg[n-x+y])
	{
		p[x][y] = 'Q';
		row[x]=cola[y] = dg[x+y] = udg[n-x+y] = true;
		dfs(x,y+1,s+1);
		row[x]=cola[y] = dg[x+y] = udg[n-x+y] = false;
		p[x][y] = '.';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	cin>>n;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			p[i][j] = '.';
		}
	}
	dfs(0,0,0);
	return 0;
}
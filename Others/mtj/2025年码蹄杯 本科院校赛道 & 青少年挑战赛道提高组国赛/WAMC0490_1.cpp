#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;using ull = unsigned long long;using LL = long long;using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
int yy1[105][105],yy2[105][105],yy3[105][105],yy4[105][105];
int g[1010][1010];
int n,m,q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin>>n>>m>>q;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			char c;cin>>c;
			if(c=='#')yy1[i][j]=1;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			yy2[j][m - i + 1]=yy1[i][j];
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			yy3[j][m - i + 1]=yy2[i][j];
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			yy4[j][m - i + 1]=yy3[i][j];
		}
	}
	
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cout<<yy4[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}
/*

5 3 8
#..
.#.
..#
2 1 1
2 1 1
1
2 2 2
2 3 3
2 3 3
2 3 3
2 3 3



*/

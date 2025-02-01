#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin>>n;
	int a[n+1][n+1];
	memset(a,0,sizeof(a));
	a[1][n/2+1]=1;
	int dx = 1,dy = n/2+1;
	for (int k = 2;k <= n*n;k++)
	{

		// 1.若(K - 1) 在第一行但不在最后一列，则将 K 填在最后一行，(K - 1) 所在列的右一列； 
		if(dx == 1 && dy != n)
		{
			dx = n;
			dy = dy + 1;
			a[dx][dy] = k;
		}
		// 2.若(K - 1) 在最后一列但不在第一行，则将 K 填在第一列，(K - 1) 所在行的上一行； 
		else if(dx != 1 && dy == n)
		{
			dx = dx - 1;
			dy = 1;
			a[dx][dy] = k;
		}
		// 3.若(K - 1) 在第一行最后一列，则将 K 填在(K - 1) 的正下方；
		else if(dx == 1 && dy == n)
		{
			dx = dx + 1;
			a[dx][dy] = k;
		} 
		// 4.若(K - 1) 既不在第一行，也最后一列，如果(K - 1) 的右上方还未填数，则将 K 填在(K - 1) 的右上方，否则将 L 填在(K - 1) 的正下方。
		else if(dx != 1 && dy != n)
		{
			if(a[dx-1][dy+1] == 0)
			{
				dx = dx - 1;
				dy = dy + 1;
				a[dx][dy] = k;
			}
			else
			{
				dx = dx + 1;
				a[dx][dy] = k;
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cout<<a[i][j]<<(j == n ? "":" ");
		}
		cout<<endl;
	}

	return 0;
}
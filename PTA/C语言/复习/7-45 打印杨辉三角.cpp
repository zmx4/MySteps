#include <bits/stdc++.h>
using namespace std;
/*
1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5  10  10   5   1
*/
int a[100][100];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;cin>>n;
	a[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j = 1;j <= i;j++)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j = n;j > i;j--)
		{
			printf(" ");
		}
		for(int j = 1;j <= i;j++)
		{
			printf("%4d",a[i][j]);
		}
		
		printf("\n");
	}
	return 0;
}
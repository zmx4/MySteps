#include<bits/stdc++.h>
using namespace std;


signed main()
{
	long n;cin>>n;
	long arr[n];
	memset(arr,0,sizeof(arr));
	for(int i = 1;i < n;i++)
	{
		cin>>arr[i];
	}
	int qwq[n][n];
	
	for(int i = 1;i < n;i++)
	{
		for(int j = i + 1 ;j <= n;j++)
		{
			qwq[i][j] = 100000;
			for(int k = i;k < j;k++)
			{
				qwq[i][j] = min(arr[k],qwq[i][j]);
			}
		}
	}
	long t;cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int l = min(a,b);
		int r = max(a,b);
		
		cout<<qwq[l][r]<<endl;
	}
}
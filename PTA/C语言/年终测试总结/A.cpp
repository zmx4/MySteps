#include<bits/stdc++.h>
using namespace std;


signed main()
{
	long n;cin>>n;
	long arr[n];
	memset(arr,0,sizeof(arr));
	for(int i = 1;i <= n;i++)
	{
		cin>>arr[i];
	}
	long t;cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int l = min(a,b);
		int r = max(a,b);
		long minNum = 100000;
		for(int i = a;i <= b;i++)
		{
			minNum = min(arr[i],minNum);
		}
		cout<<minNum<<endl;
	}
}
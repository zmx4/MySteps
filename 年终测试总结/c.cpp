#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n,t;
	cin>>n>>t;
	long long a[n];
	memset(a,0,sizeof(a));
	long long maxNum = INT_MIN;
	long long sum = 0,pos = 0;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
		if(a[i]>maxNum)
		{
			maxNum = a[i];
			pos = i;
		}
		sum+=a[i];
	}
	if(sum<t)
	{
		cout<<0<<endl;
	}
	else if(n < 3)
	{
		cout<<1<<endl;
	}
	else
	{
		long long suma = a[pos];
		int l = pos - 1,r = pos + 1;
		int cnt = 0;
		while(suma<t)
		{
			if(a[l]>a[r]&&l >=0)
			{
				suma+=a[l];
				l--;
			}
			else(r<n)
			{
				suma+=a[r];
				r++;
			}
			cnt++;
		}
	}
}
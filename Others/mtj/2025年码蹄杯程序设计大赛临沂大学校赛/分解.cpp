#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
using ll = long long;

signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i = n;i <= m;i++)
	{
		int x = i,y = i;
		bool ok = true;
		while(y)
		{
			x=y%10;
			if(x==0)
			{
				ok = false;
				break;
			}
			if(i % x!=0)
			{
				ok = false;
				break;
			}
			y/=10;
		}
		if(ok)cout<<i<<" ";
	}
	
}

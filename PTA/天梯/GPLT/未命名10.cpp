#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using namespace std;
map<int,vector<int>>mp;
int ff = -2;
signed main()
{
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	while(m--)
	{
		int op;cin>>op;
		if(op == 1)
		{
			int l,r;
			cin>>l;
			vector<int>b(l);
			for(int i = 0;i < l;i++)cin>>b[i];
			int j = 0;
			cin>>r;
			vector<int>b2(r);
			for(int i = 1;i <= n - l;i++)
			{
				int ii = i;
				if(a[ii]==b[j])
				{
					while(a[ii]==b[j])
					{
						ii++,j++;
						if(j == l)
						{
							for(int k = i;k <= j;k++)
							{
								a[i]=-1;
							}
							a[i]=ff;
							ff--;
							mp[i]=b2;
						}
					}
				}
			}
		}
	}
}
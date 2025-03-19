#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;cin>>n;
	while(n--)
	{
		int m;cin>>m;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=m;++j)
				cin>>a[i][j];

		bool flag = true;
		
		for(int i = 2;i <= m;++i)
		{
			for(int j = 1;j < i;++j)
			{
				if(a[i][j] != 0)
				{
					flag = false;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

	return 0;
}
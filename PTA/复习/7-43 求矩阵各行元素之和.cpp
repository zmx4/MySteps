#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n,m;cin>>n>>m;
	int sum = 0;
	for(int i=1;i<=n;++i)
	{
		sum = 0;
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
			sum+=a[i][j];
		}
		cout<<sum<<endl;
	}

	return 0;
}
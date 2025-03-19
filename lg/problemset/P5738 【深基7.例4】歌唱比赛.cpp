#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;cin>>n>>m;
	double ans = 0;
	for(int i=1;i<=n;i++)
	{
		vector<int> a(m);
		for(int j=0;j<m;j++)
			cin>>a[j];
		sort(a.begin(),a.end());
		double sum = 0;
		for(int j=1;j<m-1;j++)
			sum+=a[j];
		ans=max(sum/(m-2),ans);
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
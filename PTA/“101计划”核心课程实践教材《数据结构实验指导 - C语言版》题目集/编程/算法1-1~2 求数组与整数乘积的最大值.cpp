#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans = 0;
	for(int &i: a)
	{
		i *= m;
		ans = max(ans, i);
	}
	cout<<ans<<endl;
	return 0;
}
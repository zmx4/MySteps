#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int t;cin>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		vector<int> a(n,0);
		for (auto &x : a)
		{
			cin>>x;
		}
		int ans=0;
		sort(a.begin(), a.end(), greater<int>());
		
		for (auto &x : a)
		{
			if (ans + x <= k)
				ans += x;
			else
				break;
		}
		cout<<k-ans<<endl;
	}

	return 0;
}
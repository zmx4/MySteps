#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	map<string,int> mp;
	while(n--)
	{
		string s;
		cin>>s;
		mp[s]++;
	}
	string ans;
	int mx=0;
	for(auto i:mp)
	{
		if(i.second>mx)
		{
			mx=i.second;
			ans=i.first;
		}
	}
	cout<<ans<<endl;

	return 0;
}
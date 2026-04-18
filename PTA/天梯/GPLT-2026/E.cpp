#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
signed main()
{
	int n;
	cin >> n;
	map<int,int>mp,cnt;
	for(int i = 1;i <= n;++i)
	{
		int a,b;cin >> a >> b;
		mp[a]+=b;
	}
	vector<int>v;
	for(auto [a,b]:mp)
	{
		if(b==0)v.push_back(a);
	}
	if(v.empty())
	{
		cout << "NONE" << endl;
		return 0;
	}
	sort(v.begin(),v.end());
	bool flag = 0;
	for(auto x:v)
	{
		if(flag)cout << " ";
		cout << x;
		flag = 1;
	}
	
	return 0;
}

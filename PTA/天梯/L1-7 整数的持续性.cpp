#include <bits/stdc++.h>
#define endl "\n"
using ll = int;
using namespace std;

unordered_map<int,set<ll>> mp;
int maxn = 0;
void sustain(ll original)
{
	ll n = original;
	int cnt = 0;	
	while (n >= 10)	
	{
		ll temp = n;
		ll product = 1;
		while (temp > 0)
		{
			product *= (temp % 10);
			temp /= 10;
		}
		n = product;
		cnt++;
	}
	mp[cnt].insert(original);
	maxn = max(maxn, cnt);
}

	signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll l, r;
	cin >> l >> r;
	for(ll i = l; i <= r; ++i)
	{
		sustain(i);
	}
	vector<ll> ans;
	for(auto i : mp[maxn])
	{
		ans.push_back(i);
	}
	cout<<maxn<<endl;
	sort(ans.begin(),ans.end());
	for(int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i];
		if(i!=ans.size()-1)
			cout<<" ";
	}
	return 0;
}
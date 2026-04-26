#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<bool> vis(n+1);
	vector<pair<int,int>> a(n+1);
	vector<int> r(n+1);
	
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i].first;
		a[i].second = i;
		r[i] = a[i].first;
	}
	sort(a.begin()+1,a.end(),[](pair<int,int> a,pair<int,int> b){
		if(a.first==b.first)return a.second > b.second;
		return a.first < b.first;
	});
	sort(r.begin()+1,r.end());
	int ans = 0;
	while(m--)
	{
		int t,z;
		cin >> t >> z;
		auto it = upper_bound(r.begin()+1,r.end(),z) - r.begin();
		for(;it>0;it--)
		{
			if(a[it].second >= t && a[it].first <= z&&!vis[it])
			{
				vis[it]=1;
				ans += a[it].first;
				break;
			}
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}

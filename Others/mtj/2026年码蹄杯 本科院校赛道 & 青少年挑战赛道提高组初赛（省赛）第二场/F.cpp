#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n,m;cin >> n >> m;
	vector<vector<int>> g(n+1);
	vector<int> in(n+1);
	vector<int> cnt(n+1);
	vector<pair<int,int>> e;
	for(int i = 1;i <= m;++i)
	{
		int u,v;
		cin >> u >> v;
		in[u]++;
		in[v]++;
		e.push_back({u,v});
	}
	for(auto [u,v]:e)
	{
		if(in[u] < in[v])
		{
			cnt[u]++;
		}
		else if(in[u] > in[v])
		{
			cnt[v]++;
		}else if(cnt[u]%2==0)cnt[u]++;
		else cnt[v]++;
		
	}
	int ans = 0;
	for(int i = 1;i <= n;++i)
	{
		if(cnt[i]%2==1)ans++;
	}
	cout << ans << endl;
	
	
	
	return 0;
}

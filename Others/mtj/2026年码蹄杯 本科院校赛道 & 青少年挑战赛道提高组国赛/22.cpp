#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nd
{
	int now, w, mint, maxt;
};
struct edge
{
	int v, w, t;
};

const int N = 3e5+10;
vector<edge> e[N];
signed main()
{
	int n, k;
	cin >> n >> k;
	
	
	for (int i = 1; i <= n - 1; ++i)
	{
		int u,v,w,t;
		edge eg1,eg2;
		
		cin >> u >> v >> w >> t;
		e[u].push_back({v,w,t});
		e[v].push_back({u,w,t});
	}
	int ans = 0;
	for(int idx = 1;idx <= n;++idx)
	{
	vector<bool> vis(n+1);
	queue<nd> pq;
	for (auto eg : e[idx])
	{
		ans = max(ans, eg.w);
		pq.push({eg.v, eg.w, eg.t, eg.t});
	}
	
	while (!pq.empty())
	{
		auto eg = pq.front();
		vis[eg.now]=1;
		pq.pop();
		ans = max (ans,eg.w);
		for (auto nxt : e[eg.now])
		{
			int nmin = min(nxt.t, eg.mint);
			int nmax = max(nxt.t, eg.maxt);
			if (nmax - nmin > k||vis[nxt.v])continue;
			pq.push({nxt.v,eg.w+nxt.w,nmin,nmax});
		}
	}
	}
	cout << ans << endl;
	
	return 0;
};

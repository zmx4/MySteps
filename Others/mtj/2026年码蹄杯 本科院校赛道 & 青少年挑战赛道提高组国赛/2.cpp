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
		int u;
		edge eg;
		cin >> u >> eg.v >> eg.w >> eg.t;
		e[u].push_back(eg);
//		edge eg2;
//		eg2.v=u;eg2.w=eg.w;eg2.t=eg.t;
//		e[eg.v].push_back(eg2);
	}
	int ans = 0;
//	for(int index = 1;index <= 1;++index)
//	{
		queue<nd> pq;
		vector<bool>vis(n+1,false);
		for (auto eg : e[1])
		{
			ans = max(ans, eg.w);
			pq.push({eg.v, eg.w, eg.t, eg.t});
		}
		
		while (!pq.empty())
		{
			auto eg = pq.front();
			pq.pop();
			vis[eg.now]=1;
			ans = max (ans,eg.w);
			for (auto nxt : e[eg.w])
			{
				int nmin = min(nxt.t, eg.mint);
				int nmax = max(nxt.t, eg.maxt);
				if (nmax - nmin > k||vis[nxt.v])continue;
				pq.push({nxt.v,eg.w+nxt.w,nmin,nmax});
			}
		}
//	}
	cout << ans << endl;

	return 0;
};

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 1e5+5;
vector<int> G[N];
bool vis[N];
int n,m;
int ans[N];
void dfs(int u,int now)
{
	if(vis[u])
		return;
	vis[u]=1;
	ans[u] = now;
	for(auto v:G[u])
	{
		if(!vis[v])
		{
			dfs(v, now);
		}
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		G[v].push_back(u);
	}
	for (int i = n; i >= 1;i--)
	{
		dfs(i, i);
	}
	for(int i = 1; i <= n; i++)
		cout<<ans[i]<<" ";
		return 0;
}
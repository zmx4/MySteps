#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
bool vis[N];
bool cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.second!=b.second)return a.second > b.second;
	return a.first < b.first;
}
vector<vector<pair<int,int>>> g;
void dfs(int u)
{
	vis[u]=1;
	cout << "->" << u;
	for(auto [v,w]:g[u])
	{
		if(!vis[v])
		{
			dfs(v);
			break;
		}
	}
}
signed main()
{
	cin.tie(0);	
	ios::sync_with_stdio(0);
	int n,m;cin >> n >> m;
	g.resize(n+1);
	for(int i = 1;i <= m;++i)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
	}
	for(int i = 1;i <= n;i++)
	{
		if(g[i].size()!=0)
		{
			sort(g[i].begin(),g[i].end(),cmp);
		}
	}
//	cout << g[1].size();
	int k;cin >> k;
	while(k--)
	{
		int x;cin >> x;
		cout << x;
		vis[x]=1;
		if(g[x].size()==0)
		{
			cout << endl;
			continue;
		}
		dfs(g[x][0].first);
		cout << endl;
		memset(vis,0,sizeof vis);
	}
	
	
	return 0;
}

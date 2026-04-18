#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
bool vis[N];
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	
	vector<vector<int>> g(n+1);
	vector<int> a(n+1);
	map<int,int>fa;
	for(int i = 1;i < n;i++)
	{
		int x,y;
		cin >> x >>y;
		g[x].push_back(i);
		fa[i]=x;
		a[i]=y;
	}
	cout << endl;
	queue<pair<int,int>> q;
	q.emplace(0,100);
	int ans = 0;
	int bk = -1;
	vector<int>ansp;
	while(!q.empty())
	{
		auto [u,w] = q.front();
		q.pop();
		if(vis[u])continue;
		else vis[u]=1;
		if(!g[u].size())
		{
			if(w>ans)
			{
				bk = u;
				ansp.clear();
				ansp.push_back(u);
				
			}
			else if(w==ans)
			{
				ansp.push_back(u);
			}
			ans = max(ans,w);
		}
		for(auto v:g[u])
		{
			int s = min(w,a[v]);
			q.emplace(v,s);
		}
	}
	cout << ans << endl;
	bool flag = 0;
	for(auto x:ansp)
	{
		if(flag)cout << " ";
		flag = 1;
		cout << x ;
	}
	
	
	return 0;
}

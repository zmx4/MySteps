#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int n, d;
const int N = 1e5 + 5;
bool vis[N];
vector<int> g[N];
int ans;
void dfs(int u,int dis)
{
	vis[u] = true;
	if(dis>d)
		return;
	for(auto v : g[u])
	{
		if(!vis[v])
		{
			if(dis + 1 <= d)
				ans++;
			dfs(v, dis + 1);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	cout << ans << endl;





	return 0;
}
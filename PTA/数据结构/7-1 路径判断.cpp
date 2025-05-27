#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<vector<int>> G;
bool vis[N];
int i, j;
bool flag = false;
void dfs(int u)
{
	if(u == j)
	{
		flag = true;
		return;
	}
	vis[u] = true;
	for (auto v : G[u])
	{
		if (!vis[v])
		{
			dfs(v);
		}
	}
}
void solve()
{
	flag = false;
	int n, e;
	cin >> n >> e;
	G.assign(n + 1, vector<int>());
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> i >> j;
	dfs(i);
	if (flag)
	{
		printf("There is a path between %d and %d.", i, j);
	}
	else
	{
		printf("There is no path between %d and %d.", i, j);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T = 1;//cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
bool st[N];
vector<int>graph[N];
void addEdge(int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}
int res;
int dp[N][2];
void dfs(int u, int fa)
{
	int ans = 0;
	for(auto v : graph[u])
	{
		if (v == fa) continue;
		dfs(v, u);
		if(!st[v])ans++;
	}
	if(!st[u]&&ans)
	{
		st[u] = true;
		st[fa] = true;
		res++;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	dfs(1, 0);
	// int cover = min(dp[1][0], dp[1][1]);
	// int ans = (cover + 1) / 2;
	cout << res << endl;

	return 0;
}
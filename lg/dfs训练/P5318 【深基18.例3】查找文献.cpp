#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N], st[N]; 
int n, m;

void addEdge(int u, int v)
{
	g[u].push_back(v);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		addEdge(x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(g[i].begin(), g[i].end());
	}

	function<void(int, int)> dfs = [&](int u, int fa)
	{
		cout << u << " ";
		for (auto v : g[u])
		{
			if (st[v])
				continue;
			st[v] = true;
			if (v == fa)
				continue;
			dfs(v, u);
		}
	};
	st[1] = true;
	dfs(1, 0);
	cout << endl;

	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (vis[cur])
			continue;
		vis[cur] = true;
		cout << cur << " ";
		for (auto v : g[cur])
		{
			if (!vis[v])
				q.push(v);
		}
	}
	cout << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 31) - 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}

	vector<ll> dist(n + 1, INF);
	vector<char> vis(n + 1, 0);
	dist[s] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	pq.push({0, s});

	while (!pq.empty())
	{
		auto [d, u] = pq.top();
		pq.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto &e : adj[u])
		{
			int v = e.first;
			ll w = e.second;
			if (dist[v] > d + w)
			{
				dist[v] = d + w;
				pq.push({dist[v], v});
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << (i < n ? ' ' : '\n');
	}
	return 0;
}
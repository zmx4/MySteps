#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> G[1000];
int n, m;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int start, end;
	cin >> start >> end;
	auto bfs  = [&](int start, int end) -> int
	{
		queue<int> q;
		vector<int> dis(n + 1, inf);
		q.push(start);
		dis[start] = 0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(auto v : G[u])
			{
				if(dis[v] == inf)
				{
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		return dis[end];
	};

	int ans = bfs(start, end);
	if(ans != inf)
		printf("There is a path between %d and %d.", start, end);
	else
		printf("There is no path between %d and %d.", start, end);

	return 0;
}
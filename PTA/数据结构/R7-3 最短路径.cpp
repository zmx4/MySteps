#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
const int inf = 0x3f3f3f3f;
std::vector<int> G[20];
int n, m, start, end;
int dis[20];
bool vis[20];
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		std::cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	std::cin >> start >> end;

	memset(dis, 0x3f,sizeof dis);
	dis[start] = 0;
	vis[start] = 1;
	std::queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v : G[u])
		{
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				if(!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	if(dis[end] == inf)
	{
		printf("There is no path between %d and %d.", start, end);
	}
	else
	{
		printf("The length of the shortest path between %d and %d is %d.", start, end, dis[end]);
	}
	return 0;
}
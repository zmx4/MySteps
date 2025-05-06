#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> G[1000];
int n, m,k;
bool safe[1000];
int dis[1000][1000];
signed main()
{
	memset(dis, 0x3f, sizeof dis);
	cin >> m >> n >> k;
	for (int i = 0; i < n;i++)
	{
		int x;
		cin >> x;
		safe[x] = 1;
	}
	for(int i = 0; i < k;i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		dis[u][v] = dis[v][u] = 1;
	}

	int start, end;
	cin >> start >> end;

	if(!safe[end])
	{
		printf("The city %d is not safe!", end);
		return 0;
	}
	auto bfs = [&](int start, int end) -> int
	{
		queue<int> q;
		vector<int> dis(n + 1, inf);
		if(safe[start])q.push(start);
		dis[start] = 0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(auto v : G[u])
			{
				if(dis[v] == inf && safe[v])
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
		printf("The city %d can arrive safely!", end);
	else
		printf("The city %d can not arrive safely!", end);
	return 0;
}
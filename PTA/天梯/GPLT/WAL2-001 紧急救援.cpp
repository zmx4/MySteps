#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 510;
vector<int> weight(N), dis(N, INT_MAX), vis(N);
vector<vector<int>> graph(N, vector<int>(N, INT_MAX));
vector<int> path(N, -1);	 // 记录路径
vector<int> maxRescue(N, 0); // 记录最大救援队数量

void dijkstra(int s, int n)
{
	fill(vis.begin(), vis.begin() + n, 0);
	fill(dis.begin(), dis.begin() + n, INT_MAX);
	fill(maxRescue.begin(), maxRescue.begin() + n, 0);
	fill(path.begin(), path.begin() + n, -1);

	dis[s] = 0;				  // 起点到自己的距离为0
	maxRescue[s] = weight[s]; // 起点的救援队数量

	for (int i = 0; i < n; i++)
	{
		int u = -1, minDis = INT_MAX;
		// 找到当前未访问的距离最小的顶点
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && dis[j] < minDis)
			{
				minDis = dis[j];
				u = j;
			}
		}
		if (u == -1)
			break;	// 不连通
		vis[u] = 1; // 标记已访问

		// 更新u的邻接顶点
		for (int v = 0; v < n; v++)
		{
			if (!vis[v] && graph[u][v] != INT_MAX)
			{
				// 如果找到更短路径
				if (dis[v] > dis[u] + graph[u][v])
				{
					dis[v] = dis[u] + graph[u][v];
					maxRescue[v] = maxRescue[u] + weight[v];
					path[v] = u;
				}
				// 如果路径长度相同但能召集更多的救援队
				else if (dis[v] == dis[u] + graph[u][v])
				{
					if (maxRescue[v] < maxRescue[u] + weight[v])
					{
						maxRescue[v] = maxRescue[u] + weight[v];
						path[v] = u;
					}
				}
			}
		}
	}
}

// 重建路径
vector<int> getPath(int s, int d)
{
	vector<int> pathNodes;
	int cur = d;
	while (cur != -1)
	{
		pathNodes.push_back(cur);
		cur = path[cur];
	}
	reverse(pathNodes.begin(), pathNodes.end());
	return pathNodes;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, s, d;
	cin >> n >> m >> s >> d;

	for (int i = 0; i < n; i++)
		cin >> weight[i];
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = graph[b][a] = c;
	}

	dijkstra(s, n);

	vector<int> pathNodes = getPath(s, d);
	int edgeCount = pathNodes.size() - 1;

	cout << edgeCount << " " << maxRescue[d] << endl;

	// 输出路径
	for (int i = 0; i < pathNodes.size(); i++)
	{
		cout << pathNodes[i];
		if (i < pathNodes.size() - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}
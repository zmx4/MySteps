#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5,M = 1e6+5;
struct Edge
{
	int to,dis,next;
}edge[M];
int hh[N], dis[N], cnt;
bool vis[N];
int n, m, s;
struct node
{
	int u, d;
	bool operator < (const node &a) const
	{
		return d > a.d;
	}
};

void add(int u, int v,int d)
{
	edge[cnt].to = v;
	edge[cnt].dis = d;
	edge[cnt].next = hh[u];
	hh[u] = cnt++;
}
priority_queue<node> q;
inline void dijkstra(int s)
{
	for(int i = 1; i <= n; i++)
	{
		dis[i] = inf;
		vis[i] = false;
	}
	dis[s] = 0;
	q.push({s, 0});
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		int u = x.u;
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = hh[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to, d = edge[i].dis;
			if (dis[v] > dis[u] + d)
			{
				dis[v] = dis[u] + d;
				q.push({v, dis[v]});
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> m >> s;
	memset(hh, -1, sizeof(hh));
	for (int i = 1; i <= m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		add(u, v, d);
		//add(v, u);
	}
	dijkstra(s);
	for (int i = 1; i <= n; i++)
	{
		//if (dis[i] == inf) cout << "INF" << endl;
		cout << dis[i] << " ";
	}








	return 0;
}
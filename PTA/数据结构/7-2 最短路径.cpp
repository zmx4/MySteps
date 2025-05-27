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
void solve()
{
	int n, e;
	cin >> n >> e;
	G.assign(n + 1, vector<int>());
	for(int k = 0; k < e; k++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	auto dijistra = [&](int start, int end) {
		vector<int> dist(n + 1, inf);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[start] = 0;
		pq.push({0, start});
		
		while(!pq.empty())
		{
			auto [d, u] = pq.top();
			pq.pop();
			if(d > dist[u]) continue;
			for(auto v : G[u])
			{
				if(dist[v] > d + 1)
				{
					dist[v] = d + 1;
					pq.push({dist[v], v});
				}
			}
		}
		
		return dist[end];
	};
	int start, end;
	cin >> start >> end;
	int distance = dijistra(start, end);
	if(distance == inf)
	{
		printf("There is no path between %d and %d.", start, end);
	}
	else
	{
		printf("The length of the shortest path between %d and %d is %d.", start, end, distance);
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
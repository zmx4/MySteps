#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 510;
int n, m;
int g[N][N], d[N];
bool vis[N];

int dijkstra()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;

	for (int i = 0; i < n;i++)
	{
		int t = -1;
		for (int j = 1;j <= n;j++)
			if(!vis[j] && (t == -1 || d[j] < d[t]))
				t = j;
			
		vis[t] = true;
		
		for (int j = 1; j <= n; j++)
		{
			// if(!vis[j] && g[t][j] != inf)
			d[j] = min(d[j], d[t] + g[t][j]);
		}
	}
	if(d[n] == inf)
		return -1;
	else
		return d[n];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	cin>>n>>m;
	memset(g, 0x3f, sizeof g);
	while(m--)
	{
		int u, v, w;
		cin>>u>>v>>w;
		g[u][v] = min(g[u][v], w);
	}

	int t = dijkstra();

	cout<<t<<endl;

	return 0;
}
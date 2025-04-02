#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int N = 510;
int n, m, s;
int g[N][N], d[N];
bool vis[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	cin>>n>>m>>s;
	memset(g, 0x3f, sizeof g);
	while(m--)
	{
		int u, v, w;
		cin>>u>>v>>w;
		g[u][v] = min(g[u][v], w);
	}







	return 0;
}
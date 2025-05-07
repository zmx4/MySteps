#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1000 + 10;
int g[N][N], d[N];
bool vis[N];
int n, m, s, t, k;
struct DSU
{
	vector<int> p, r;
	DSU(int n) : p(n + 1), r(n + 1, 0)
	{
		iota(p.begin(), p.end(), 0);
	}
	int find(int x)
	{
		return p[x] == x ? x : p[x] = find(p[x]);
	}
	bool unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)
			return false;
		if (r[a] < r[b])
			swap(a, b);
		p[b] = a;
		if (r[a] == r[b])
			r[a]++;
		return true;
	}
};
struct edge
{
	int u, v, w;
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m >> s >> t >> k;
	vector<edge> e(m);
	for (int i = 0; i < m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e.begin(), e.end(), [](edge a, edge b)
		 { return a.w > b.w; });
	DSU dsu(n);
	ll ans = 0;
	for (int i = 0; i < m; i++)
	{
		dsu.unite(e[i].u, e[i].v);
		if (dsu.find(s) == dsu.find(t))
		{
			ans = e[i].w;
			break;
		}
	}
	cout << min(k, ans) << endl;
	return 0;
}
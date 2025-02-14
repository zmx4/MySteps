#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int s, t;
bool st[N];
int dfs(int u, int len)
{
	if (u == t)
		return 1;
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
			if (dfs(j, len + 1))
				return len;
	}
	return -1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		add(x, y), add(y, x);
	}

	cin >> s >> t;

	return 0;
}
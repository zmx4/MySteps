#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e6 + 10;

int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
vector<int> ans;
int s, t;
bool st[N];
int dfs(int u)
{
	if (u == t)
		return 1;
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j] && (ne[ne[h[j]]] == -1 || u == s || u == t))
			if (dfs(j))
			{
				cout<<j<<endl;
				return 1;
			}
	}
	return 0;
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
		add(x, y);
	}

	cin >> s >> t;
	if (dfs(s))
		cout << "Tangled" << endl;
	else
		cout << "Not Tangled" << endl;
	return 0;
}
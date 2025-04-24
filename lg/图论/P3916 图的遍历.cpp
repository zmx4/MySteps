#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
vector<int> G[N];
int A[N];
int n, m;

void dfs(int u, int fa)
{
	if (A[u])
		return;
	A[u] = fa;
	for (auto v : G[u])
	{
		dfs(v, fa);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		G[y].push_back(x);
	}

	for (int i = n;i >= 1; i--)dfs(i, i);
	for(int i = 1; i <= n; i++)cout << A[i] << " ";
		return 0;
}
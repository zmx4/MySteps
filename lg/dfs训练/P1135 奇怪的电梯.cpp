#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 210;
int N, A, B;
int a[MAXN];
bool vis[MAXN];
int ans = 0x3f3f3f3f;
// void dfs(int u, int n)
// {
// 	if (u == B)
// 	{
// 		ans = min(ans, n);
// 		return;
// 	}
// 	if (u > N || u < 1)
// 		return;
	
// 	vis[u] = true;
// 	if (u + a[u] <= N && !vis[u + a[u]] && u + a[u] >= 1)
// 		dfs(u + a[u], n + 1);
// 	if (u - a[u] >= 1 && !vis[u - a[u]] && u - a[u] <= N)
// 		dfs(u - a[u], n + 1);
// 	vis[u] = false;
// }
int bfs()
{
	queue<pair<int, int>> q;
	q.push({A, 0});
	vis[A] = true;
	while(!q.empty())
	{
		auto [u, n] = q.front();
		q.pop();
		if (u == B)
			return n;
		if (u + a[u] <= N && !vis[u + a[u]] && u + a[u] >= 1)
		{
			q.push({u + a[u], n + 1});
			vis[u + a[u]] = true;
		}
		if (u - a[u] >= 1 && !vis[u - a[u]] && u - a[u] <= N)
		{
			q.push({u - a[u], n + 1});
			vis[u - a[u]] = true;
		}
	}
	return -1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}

	//dfs(A, 0);

	// if (ans != 0x3f3f3f3f)
		// cout << ans << endl;
	// else
		// cout << -1 << endl;
	cout << bfs() << endl;
	return 0;
}
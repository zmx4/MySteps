#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int N = 1e5 + 5, M = 1e6 + 5;
vector<int> G[N];
int d[N], u[N], v[N], w[N];
int n, m;
signed main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i];
		d[u[i]]++;
		d[v[i]]++;
	}
	for (int i = 1; i <= m; i++)
	{
		if (d[u[i]] > 1 && d[v[i]] > 1)
		{
			ans += (ll)(d[u[i]] - 1) * (d[v[i]] - 1) * 2;
		}
	}
	cout << ans << endl;
	return 0;
}
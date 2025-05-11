#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define sc scanf
#define ff first
#define ss second
/*0 0 0 0
  0 0 0 0
  0 0 0 0
  0 0 0 0
*/
int n, m, x;
int sum = 0;
// int cnt = 0; // 1
int res = 0;
// int s = 0; //?;
#define int long long
void solve()
{
	int n, m, x;
	cin >> n >> m >> x;
	vector<string> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int N = n * m;
	ll INF64 = (ll)4e18;
	ll C = (ll)N + 1;
	auto idx = [&](int i, int j)
	{ return i * m + j; };
	vector<ll> dist(N, INF64);
	ll init = (p[0][0] == '0' ? C : (p[0][0] == '?' ? 1 : 0));
	dist[0] = init;
	priority_queue<tuple<ll, int, int>> pq;
	pq.push({-init, 0, 0});
	int di[2] = {1, 0}, dj[2] = {0, 1};
	while (!pq.empty())
	{
		auto [nc, i, j] = pq.top();
		pq.pop();
		ll cost = -nc;
		int id = idx(i, j);
		if (cost != dist[id])
			continue;
		if (i == n - 1 && j == m - 1)
			break;
		for (int d = 0; d < 2; d++)
		{
			int ni = i + di[d], nj = j + dj[d];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m)
				continue;
			ll w = (p[ni][nj] == '0' ? C : (p[ni][nj] == '?' ? 1 : 0));
			ll nd = cost + w;
			int nid = idx(ni, nj);
			if (nd < dist[nid])
			{
				dist[nid] = nd;
				pq.push({-nd, ni, nj});
			}
		}
	}
	ll best = dist[idx(n - 1, m - 1)];
	ll zeros = best / C;
	ll questions = best % C;
	ll path_len = n + m - 1;
	ll ans;
	if (questions <= x)
		ans = path_len - zeros;
	else
		ans = path_len - zeros - (questions - x);
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
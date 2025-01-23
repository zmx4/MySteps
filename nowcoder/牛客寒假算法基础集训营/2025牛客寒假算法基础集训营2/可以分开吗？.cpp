#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	vector<string> jz(n);
	for (auto &s : jz)
		cin >> s;
	vector<vector<bool>> st(n, vector<bool>(m, false));
	ll ans = INT_MAX;
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < m; ++j)
		{
			if (jz[i][j] == '1' && !st[i][j])
			{
				queue<pair<ll, ll>> q;
				q.push({i, j});
				st[i][j] = true;
				vector<pair<ll, ll>> adj0;
				while (!q.empty())
				{
					pair<ll, ll> po = q.front();
					q.pop();
					ll x = po.first,y = po.second;
					for (int dir = 0; dir < 4; ++dir)
					{
						ll nx = x + dx[dir],ny = y + dy[dir];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
						{
							if (jz[nx][ny] == '1' && !st[nx][ny])
							{
								st[nx][ny] = true;
								q.push({nx, ny});
							}
							else if (jz[nx][ny] == '0')
							{
								adj0.emplace_back(nx, ny);
							}
						}
					}
				}
				sort(adj0.begin(), adj0.end());
				adj0.erase(unique(adj0.begin(), adj0.end()), adj0.end());
				ans = min(ans, (ll)adj0.size());
			}
		}
	}

	cout << ans;
	return 0;
}
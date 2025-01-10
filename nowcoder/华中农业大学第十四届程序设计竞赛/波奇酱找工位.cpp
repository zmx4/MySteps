#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int, int>> members(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> members[i].fi >> members[i].se;
	}

	int maxDist = INT_MIN;
	pair<int, int> pos;

	for (int x = 1; x <= n; ++x)
	{
		for (int y = 1; y <= m; ++y)
		{
			bool isUsed = false;
			for (const auto &member : members)
			{
				if (member.fi == x && member.se == y)
				{
					isUsed = true;
					break;
				}
			}
			if (isUsed)
				continue;

			int minDist = INT_MAX;
			for (const auto &member : members)
			{
				int dist = abs(member.fi - x) + abs(member.se - y);
				minDist = min(minDist, dist);
			}

			if (minDist > maxDist)
			{
				maxDist = minDist;
				pos = {x, y};
			}
			else if (minDist == maxDist)
			{
				if (x < pos.fi || (x == pos.fi && y < pos.se))
				{
					pos = {x, y};
				}
			}
		}
	}

	cout << maxDist << endl;
	cout << pos.fi << " " << pos.se << endl;

	return 0;
}
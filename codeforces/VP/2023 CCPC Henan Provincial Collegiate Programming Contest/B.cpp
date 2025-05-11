#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 2), premax(n + 2), sufmin(n + 2);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	premax[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		premax[i] = max(premax[i - 1], a[i]);
	}
	sufmin[n + 1] = inf;
	for (int i = n; i >= 1; i--)
	{
		sufmin[i] = min(sufmin[i + 1], a[i]);
	}

	ll ans = 0;
	for (int k = 1; k <= n; k++)
	{
		bool flag = true;
		for (int i = k; i < n; i += k)
		{
			if (premax[i] > sufmin[i + 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
	}

	cout << ans << endl;
	return 0;
}
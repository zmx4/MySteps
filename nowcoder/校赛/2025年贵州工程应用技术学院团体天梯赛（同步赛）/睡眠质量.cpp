#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(5, 0);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x, m;
		cin >> x >> m;
		a[x] += m;
		if (x >= 0 && x <= 2)
			sum += m;
	}
	double deep_ratio = (sum == 0 ? 0.0 : a[2] * 100.0 / sum);
	double light_ratio = (sum == 0 ? 0.0 : a[1] * 100.0 / sum);
	double rem_ratio = (sum == 0 ? 0.0 : a[0] * 100.0 / sum);
	bool deep_ok = (deep_ratio >= 20.0 && deep_ratio <= 60.0);
	bool light_ok = (light_ratio < 55.0);
	bool rem_ok = (rem_ratio >= 10.0 && rem_ratio <= 30.0);

	string ans;
	if (!deep_ok)
	{
		ans = "Bad!";
	}
	else
	{
		int not_ok = (!light_ok) + (!rem_ok);
		if (not_ok == 0)
			ans = "Great!";
		else if (not_ok == 1)
			ans = "Normal";
		else
			ans = "Little Bad";
	}
	cout << ans << " " << sum << "\n";
}

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll que = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		que += a[i];
		if (i >= 10)
			que -= a[i - 10];
		ans = max(ans, que);
	}
	cout << ans << endl;
	return 0;
}
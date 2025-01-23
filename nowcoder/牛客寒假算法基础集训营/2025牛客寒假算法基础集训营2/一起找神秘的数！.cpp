#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		ll l, r;
		cin >> l >> r;

		ll len = r - l + 1;
		ll ans = len * (len - 1) / 2;
		if (l <= r)
			ans++;

		cout << ans << endl;
	}
	return 0;
}
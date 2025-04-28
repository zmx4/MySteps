#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

bool check(ll y, ll k)
{
	ll sum = 0;
	for (ll i = 4; i <= y;)
	{
		sum += y / i - y / (25 * i);
		i *= 100;
	}
	return y - sum >= k;
}

void solve()
{
	ll k;
	cin >> k;
	k += 1533;

	ll l = 1, r = 2e18;
	while (l <= r)
	{
		ll mid = l + (r - l) / 2;
		if (check(mid, k))
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << l << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
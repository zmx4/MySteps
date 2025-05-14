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
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll cnt = 0;
	
	int G = 0;
	for (int i = 1; i <= n; i++)
	{
		int d = abs(i - a[i]);
		G = gcd(G, d);
	}

	if (G == 0)
	{
		cout << n << endl;
		return 0;
	}

	int ans = 0;
	for (int d = 1; ll(d) * d <= G; d++)
	{
		if (G % d == 0)
		{
			ans++;
			if (d * d != G)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n, c;
	cin >> n >> c;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0;
	for(ll i = 0; i < n; i++)
	{
		ans += (upper_bound(a.begin(), a.end(), a[i] + c) - a.begin()) - (lower_bound(a.begin(), a.end(), a[i] + c) - a.begin());
	}
	cout << ans << endl;
	return 0;
}
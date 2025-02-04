#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n+1,0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n;i++)
	{
		if(a[i]>=0)
			ans += a[i];
		else
			ans += a[i] * i;
	}
	cout << ans;
	return 0;
}
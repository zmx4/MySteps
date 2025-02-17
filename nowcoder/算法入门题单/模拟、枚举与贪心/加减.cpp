#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
vector<ll> a(100010), q(100010, 0);
ll n, k;
int check(ll l, ll r)
{
	ll mid = (l + r) >> 1;
	ll ans = a[mid] * (mid - l + 1) - (q[mid] - q[l - 1]) + (q[r] - q[mid]) - a[mid] * (r - mid);
	if (ans <= k)
	{
		return 1;
	}
	return 0;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	for (int i = 1; i <= n; i++)
	{
		q[i]=q[i-1]+a[i];
	}
	
	ll ans = -1;
	for(ll i = 1; i <= n; i++)
	{
		ll l = i, r = n;
		ll cnt = -1;
		while (l <= r)
		{
			ll mid = (l + r) >> 1;
			if (check(i, mid))
			{
				cnt = max(cnt, mid - i + 1);
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans << endl;
	
	/*
		ll ans = 1;
		int i = 1;
		for (int j = 1; j <= n; j++)
		{
			while (a[j] * (j - i) - (q[j - 1] - q[i - 1]) > k)
			{
				i++;
			}
			ans = max(ans, (ll)j - i + 1);
		}
	*/
	//cout << ans << endl;
	return 0;
}
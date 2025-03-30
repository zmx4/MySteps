#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<ll> b(n), w(m);
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < m; ++i)
		cin >> w[i];

	sort(b.begin(), b.end(), greater<ll>());
	sort(w.begin(), w.end(), greater<ll>());


	ll ans = 0;
	ll sum_b = 0, bcnt = 0;
	for (int i = 0; i < n && b[i] > 0; ++i)
	{
		sum_b += b[i];
		bcnt++;
	}

	ans = max(ans, sum_b);

	for (ll wcnt = 1; wcnt <= m; ++wcnt)
	{
		ll required_b = max(wcnt, bcnt);
		if (required_b > n)
			break;
		ll sum = 0;
		for (int i = 0; i < required_b; ++i)
		{
			sum += b[i];
		}
		for (int i = 0; i < wcnt; ++i)
		{
			sum += w[i];
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;
	return 0;
}
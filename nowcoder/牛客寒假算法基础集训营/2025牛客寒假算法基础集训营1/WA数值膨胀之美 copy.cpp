#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	ll maxN = 0, minN = 10000;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxN = max(maxN, a[i]);
		minN = min(minN, a[i]);
	}
	sort(a.begin(), a.end());
	a[0] *= 2;
	sort(a.begin(), a.end());
	cout << a[n - 1] - a[0] << endl;
	return 0;
}
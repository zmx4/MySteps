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

	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = 0;
	if(a[1]>x)
	{
		ans += a[1] - x;
		a[1] -= a[1]-x;
	}
	for (int i = 1; i < n; i++)
	{
		ll sum = a[i] + a[i + 1];
		if (sum > x)
		{
			ans += sum - x;
			a[i + 1] -= sum - x;
		}
	}
	
	
	cout << ans << endl;
		return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
#define int long long
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n < 2)
	{
		cout << 0 << endl;
		return;
	}
	ll ans = 0;
	int premax = a[0];
	for (int j = 1; j < n; j++)
	{
		if (premax > a[j])
			ans = max(ans, premax + a[j]);
		premax = max(premax, a[j]);
	}
	cout << ans << endl;
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
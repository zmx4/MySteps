#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const ll INFLL = (ll)1e18;
const int N = 2e5 + 10;
int a[N], b[N];
int n, m;
void solve()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];

	int cur = 0;
	for (int i = 0; i < n && cur < m; i++)
		if (a[i] >= b[cur])
			cur++;
	if (cur == m)
	{
		cout << 0 << endl;
		return;
	}

	vector<int> pref(n + 1, 0), suff(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int p = pref[i];
		pref[i + 1] = p + (p < m && a[i] >= b[p]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int s = suff[i + 1];
		suff[i] = s + (s < m && a[i] >= b[m - 1 - s]);
	}
	auto ok = [&](ll k)
	{
		for (int i = 0; i <= n; i++)
		{
			int p = pref[i];
			if (p < m && k >= b[p])
				p++;
			if (suff[i] >= m - p)
				return true;
		}
		return false;
	};
	if (!ok(INFLL))
	{
		cout << -1 << endl;
		return;
	}
	ll lo = 1, hi = *max_element(b, b + m), ans = hi;
	while (lo <= hi)
	{
		ll mid = (lo + hi) >> 1;
		if (ok(mid))
		{
			ans = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
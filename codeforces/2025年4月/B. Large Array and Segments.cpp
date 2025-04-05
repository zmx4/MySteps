#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, k;
	ll x;
	cin >> n >> k >> x;
	vector<ll> a(n+1),pre(n+1);
	pre[0] = 0;
	for (int i = 1; i <= n;i++)cin>> a[i];
	for (int i = 1; i <= n;i++)pre[i] = pre[i - 1] + a[i];
	//for (int i = n; i >= 1;i--)suf[i] = suf[i + 1] + a[i];
	ll suma;
	suma    = pre[n];
	ll sumb;
	sumb = suma * k;
	//cout << k << endl;
	if(sumb < x)
	{
		cout << 0 << endl;
		return;
	}
	ll ans = 0;
	for (int j = 0; j < k; j++)
	{
		ll r = suma * (k - j) - x;
		if(r < 0)break;
		int cnt = upper_bound(pre.begin(), pre.begin() + n, r) - pre.begin();
		ans+= cnt;
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
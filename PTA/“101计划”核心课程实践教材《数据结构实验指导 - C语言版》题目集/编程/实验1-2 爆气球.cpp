#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (int i = 0;i < n;++i)
	{
		cin >> a[i];
		a[i]+=1e6+10;
	}
	int ans = 0;
	for(int i = 0;i < n;++i)
	{
		int p = lower_bound(a.begin(), a.end(), m - a[i]) - a.begin();
		if (p < n && a[i] + a[p] <= m && i != p)
		{
			ans=max(ans,p-i);
		}
	}
	cout << ans << endl;
	return 0;
}
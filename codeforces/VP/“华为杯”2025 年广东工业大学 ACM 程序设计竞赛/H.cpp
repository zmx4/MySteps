#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> pre(n + 2, 0), suf(n + 2, 0);

	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + (s[i - 1] == '1' ? +1 : -1);
	}
	for (int i = n; i >= 1; i--)
	{
		suf[i] = suf[i + 1] + (s[i - 1] == '1' ? +1 : -1);
	}

	ll ans = LLONG_MIN;
	for (int i = 1; i < n; i++)
	{
		ans = max(ans, (ll)pre[i] * (ll)suf[i + 1]);
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
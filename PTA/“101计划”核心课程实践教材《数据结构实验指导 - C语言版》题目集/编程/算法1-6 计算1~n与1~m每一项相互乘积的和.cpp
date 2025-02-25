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
	ll ans = 0;
	for (int i = 1;i <= n;++i)
		for (int j = 1;j <= m;++j)
			ans += i * j;
	cout << ans << endl;
	return 0;
}
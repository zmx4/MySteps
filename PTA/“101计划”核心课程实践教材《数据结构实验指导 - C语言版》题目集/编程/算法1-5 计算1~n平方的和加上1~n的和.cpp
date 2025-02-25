#pragma GCC optimize(2)
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

	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1;i <= n*n;++i)
		ans += i;
	for (int i = 1;i <= n;++i)
		ans += i;
	cout << ans << endl;

		return 0;
}
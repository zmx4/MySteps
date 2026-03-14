#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int l, n;
	cin >> l >> n;
	ll total = 1;
	for (int i = 0; i < l;i++)total *= 26;
	ll index = total - n;
	string ans(l,' ');
	for (int i = l - 1; i >= 0;i--)
	{
		ans[i] = 'A' + index % 26;
		index /= 26;
	}
	cout << ans << endl;
		return 0;
}
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

	int w;
	cin >> w;
	int n;cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end(), [](int a, int b) {
		return a > b;
	});
	int l = 1, r = n;
	int ans = 0;
	while (l <= r)
	{
		if (a[l] + a[r] <= w)
		{
			l++;
			r--;
		}
		else
		{
			l++;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
#define int long long
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> h(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	sort(h.begin() + 1, h.end(), [](int a, int b) {
		return a > b;
	});
	ll ans = 0;
	ans+=h[1]*h[1];
	int l = 1, r = n;
	while (l < r)
	{
		ans += (h[l] - h[r]) * (h[l] - h[r]);
		l++;
		if (l < r)
		{
			ans += (h[r] - h[l]) * (h[r] - h[l]);
			r--;
		}
	}
	cout << ans << endl;





	return 0;
}
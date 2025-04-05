#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

struct minist
{
	int left, right;
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	int kl = 0, kr = 0;
	cin >> kl >> kr;
	vector<minist> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i].left >> a[i].right;
	sort(a.begin(), a.end(), [](const minist &x, const minist &y)
		 { return (ll)x.left * y.right > (ll)y.left * x.right; });

	ll ans = 0;
	ll l = kl, r = kr;
	for (int i = 0; i < n; i++)
	{
		ans += l / a[i].right;
		l += a[i].left;
	}
	cout << ans << endl;
	return 0;
}
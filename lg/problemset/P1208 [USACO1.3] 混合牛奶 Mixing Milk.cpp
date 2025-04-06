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


	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m + 1);
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin() + 1, a.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	});
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if(n > a[i].second)
		{
			n -= a[i].second;
			ans += a[i].first * a[i].second;
		}
		else
		{
			ans += n * a[i].first;
			break;
		}
	}
	cout << ans << endl;






	return 0;
}
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

	int n, s;
	cin >> n >> s;
	int a, b;
	cin >> a >> b;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = {x, y};
	}
	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	});
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second <= s && v[i].first <= a+b )
		{
			s -= v[i].second;
			ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}
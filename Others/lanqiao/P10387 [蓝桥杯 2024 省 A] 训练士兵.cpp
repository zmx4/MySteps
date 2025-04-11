#include <bits/stdc++.h>
#define endl "\n"
#define int long long
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
	vector<pair<int, int>> a(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin>> a[i].first >> a[i].second;
		sum+= a[i].first;
	}
	sort(a.begin() + 1, a.end(), [](pair<int, int> x, pair<int, int> y) {
		return x.second < y.second;
	});
	int ans = 0, p = 0;
	for(int i = 1; i <= n; i++)
	{
		if (sum >= s) 
		{
			ans += (a[i].second - p) * s;
			sum -= a[i].first;
			p += a[i].second - p;
		}
		else 
		{
			ans += (a[i].second - p) * a[i].first;
			sum -= a[i].first;
		}
	}
	cout << ans << endl;
	
	return 0;
}
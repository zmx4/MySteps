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

	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
		return x.second*y.first > y.second*x.first;
	});
	double val = 0;
	int rest = t;
	for (int i = 0; i < n; ++i) {
		if (rest <= 0) break;
		if (a[i].first <= rest) {
			val += a[i].second;
			rest -= a[i].first;
		} else {
			val += a[i].second * (double)rest / a[i].first;
			break;
		}
	}
	cout<<format("{:.2f}", val)<<endl;

	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool cmp(pair<double, double> a, pair<double, double> b)
{
	return a.second * b.first > b.second * a.first;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	double n, d;
	cin >> n >> d;
	vector<pair<double, double>> a(n);
	for (int i = 0; i < n;i++)cin >> a[i].first;
	for (int i = 0; i < n; i++)
		cin >> a[i].second;
	ranges::sort(a,cmp);
	double ans = 0;
	for (int i = 0; i < n;i++)
	{
		if(d<=0)
			break;
		double sold = min(d, a[i].first);
		d -= sold;
		ans += a[i].second * ((double)sold / a[i].first);
	}
	printf("%.2f", ans);
	return 0;
}
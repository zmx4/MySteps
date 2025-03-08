#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first * b.second > b.first * a.second;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first;
	for(int i = 0; i < n; i++)
		cin >> a[i].second;
	sort(a.begin(), a.end(),cmp);
	double ans = 0;
	for (int i = 0; i < n;i++)
	{
		int x = min(a[i].second, m);
		ans += x * 100.0 / a[i].second * a[i].first;
		m -= x;
	}
	cout << format("{:.4f}", ans) << endl;
	return 0;
}
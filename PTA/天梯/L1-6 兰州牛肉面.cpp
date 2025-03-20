#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<double> price(n + 1);
	vector<int> sold(n + 1);
	for (int i = 1; i <= n;i++)
		cin >> price[i];
	int x, y;
	while (cin >> x >> y)
	{
		if(x==0)
			break;
		sold[x] += y;
	}
	double ans = 0;
	for (int i = 1; i <= n;i++)
	{
		cout << sold[i] << endl;
		ans += price[i] * sold[i];
	}
	//cout << format("{:.2f}", ans) << endl;
	printf("%.2f", ans);
	return 0;
}
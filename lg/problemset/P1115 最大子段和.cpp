#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = a[0], sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		ans = max(ans, sum);
		if (sum < 0)
			sum = 0;
	}
	cout << ans << endl;

	return 0;
}
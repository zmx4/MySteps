#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum = accumulate(a.begin(), a.begin() + k, 0);
	int ans = sum;
	for (int i = k; i < n; i++)
	{
		sum += a[i] - a[i - k];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
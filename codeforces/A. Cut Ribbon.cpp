#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> dp(n + 1, INT_MIN);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i - a >= 0)
		{
			dp[i] = max(dp[i], dp[i - a] + 1);
			//cout<<dp[i]<<endl;
		}
		if (i - b >= 0)
		{
			dp[i] = max(dp[i], dp[i - b] + 1);
			//cout << dp[i] << endl;
		}
		if (i - c >= 0)
		{
			dp[i] = max(dp[i], dp[i - c] + 1);
			//cout << dp[i] << endl;
		}
	}
	cout << dp[n] << endl;

	return 0;
}
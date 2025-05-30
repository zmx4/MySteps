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
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> a[i][j];
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
		{
			if (i == 0)
				dp[i][j] = a[i][j];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j] + a[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + a[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
		}
	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
	return 0;
}
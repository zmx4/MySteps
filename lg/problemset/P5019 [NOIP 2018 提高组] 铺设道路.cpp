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

	int n;cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	vector<int> dp(n+1, 0);
	dp[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if(a[i] <= a[i-1])
		{
			dp[i] = dp[i-1];
		}
		else
		{
			dp[i] = dp[i-1] + a[i] - a[i-1];
		}
	}
	cout << dp[n] << endl;
		return 0;
}
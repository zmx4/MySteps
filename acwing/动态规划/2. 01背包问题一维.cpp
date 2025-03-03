#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 1010;
int n,m;
int v[N], w[N];
int dp[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n;i++)cin >> v[i] >> w[i];
	for (int i = 1; i <= n;i++)
	{
		for (int j = m; j >= v[i];j--)
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << dp[m];
	return 0;
}
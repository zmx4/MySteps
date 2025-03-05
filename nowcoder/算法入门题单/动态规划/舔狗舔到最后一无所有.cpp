#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int MOD = 1e9+7;

void solve()
{
	int n;
	cin >> n;
	vector<vector<ll>> dp(4, vector<ll>(n+1, 0));
	dp[1][1] = dp[2][1] = dp[3][1] = 1;
	if (n >= 2)
	{
		dp[1][2] = dp[2][2] = dp[3][2] = 3;
	}
	for (int i = 3; i <= n;i++)
	{	
		dp[1][i] = (dp[2][i-1]+dp[2][i-2]+dp[3][i-1]+dp[3][i-2]) % MOD;
		dp[2][i] = (dp[1][i-1]+dp[1][i-2]+dp[3][i-1]+dp[3][i-2]) % MOD;
		dp[3][i] = (dp[1][i-1]+dp[1][i-2]+dp[2][i-1]+dp[2][i-2]) % MOD;
	}
	cout << (dp[1][n] + dp[2][n] + dp[3][n]) % MOD << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int MOD = 1e9+7;

void solve()
{
	int n;
	cin >> n;
	vector<int> dp(n, 0);
	dp[1]=3;
	if (n >= 2)
	{
		dp[2] = 9;
	}
	for (int i = 3; i <= n;i++)
	{
		dp[i] = (dp[i - 1] * 2 % MOD + dp[i - 2] * 2 % MOD) % MOD;
	}
	cout << (dp[n]) % MOD << endl;
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
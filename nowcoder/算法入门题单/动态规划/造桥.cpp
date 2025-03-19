#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n;cin>>n;
	vector<string> s(n+1);
	for(int i=1;i<=n;i++)
		cin>>s[i];
	vector<int> dp(26,0);
	for (int i = 1; i <= n;i++)
	{
		int l = s[i][0] - 'a',r = s[i][s[i].size()-1] - 'a';
		int n = s[i].size();
		dp[r] = max(dp[r], dp[l] + n);
	}
	int ans = 0;
	for (int i = 0;i <26;i++)
		ans = max(ans, dp[i]);
	cout<<ans<<endl;
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
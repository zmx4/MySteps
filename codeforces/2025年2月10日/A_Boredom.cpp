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
    vector<ll> cnt(100005, 0);
    vector<ll> dp(100005, 0);
    for(int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2;i <= 100000;i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + i*cnt[i]);
    }
    cout << dp[100000] << endl;
	return 0;
}
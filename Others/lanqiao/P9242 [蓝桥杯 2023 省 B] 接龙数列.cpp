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

	int n;
	cin >> n;
	vector<int> dp(11, 0);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int first = s[0] - '0';
		int last = s[s.size() - 1] - '0';
		dp[last] = max(dp[last], dp[first] + 1);
	}
	int ans = 0;
	for (int i = 0;i <= 9; i++)ans= max(ans, dp[i]);
	cout << n-ans << endl;
	return 0;
}
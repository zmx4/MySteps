#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
void solve()
{
	int n;
	cin >> n;
	vector<string> s(n);
	for (auto &x : s)
		cin >> x;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			const string &A = s[i], &B = s[j];
			int m = A.size(), k = B.size();
			vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
			int common = 0;
			for (int a = 0; a < m; a++)
			{
				for (int b = 0; b < k; b++)
				{
					if (A[a] == B[b])
					{
						dp[a + 1][b + 1] = dp[a][b] + 1;
						common = max(common, dp[a + 1][b + 1]);
					}
				}
			}
			ans = max(ans, common);
		}
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
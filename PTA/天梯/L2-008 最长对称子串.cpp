#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	getline(cin, s);

	int n = s.size(), ans = 1;
	for (int i = 0; i < n; i++)
	{
		int l = i, r = i;
		while (l >= 0 && r < n && s[l] == s[r])
		{
			ans = max(ans, r - l + 1);
			l--;
			r++;
		}
		l = i, r = i + 1;
		while (l >= 0 && r < n && s[l] == s[r])
		{
			ans = max(ans, r - l + 1);
			l--;
			r++;
		}
	}
	cout << ans;
	return 0;
}
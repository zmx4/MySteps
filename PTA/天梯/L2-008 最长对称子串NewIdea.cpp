#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int expandAroundCenter(const string &s, int left, int right)
{
	while (left >= 0 && right < s.size() && s[left] == s[right])
	{
		left--;
		right++;
	}
	return right - left - 1;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	getline(cin, s);

	int n = s.size();
	int ans = 1;

	for (int i = 0; i < n; i++)
	{
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		ans = max(ans, max(len1, len2));
	}

	cout << ans;
	return 0;
}
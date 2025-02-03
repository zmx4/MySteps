#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		while (ans.size() && s[i] > ans.back())
			ans.pop_back();
		ans += s[i];
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;

	return 0;
}
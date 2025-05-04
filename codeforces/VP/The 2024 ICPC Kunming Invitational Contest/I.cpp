#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<pair<char, int>> cnt;
	for (int i = 0; i < n; ++i)
	{
		int j = i + 1;
		while (j < n && s[j] == s[i])
			j++;
		cnt.emplace_back(s[i], j - i);
		i = j - 1;
	}
	if (cnt.size() == 1)
	{
		cout << cnt[0].second / 2 << endl;
		return;
	}
	if (cnt.front().first == cnt.back().first)
	{
		cnt.front().second += cnt.back().second;
		cnt.pop_back();
	}
	bool flag = false;
	int ans = 0;
	for (auto &pr : cnt)
	{
		int len = pr.second;
		ans += len / 2;
		if (len % 2 == 0)
			flag = true;
	}
	if (flag)
		ans--;
	cout << ans << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}
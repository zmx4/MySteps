#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vector<int> next(m, 0);
	for (int i = 1, j = 0; i < m; i++)
	{
		while (j > 0 && t[i] != t[j])
			j = next[j - 1];
		if (t[i] == t[j])
			j++;
		next[i] = j;
	}
	vector<pair<int, int>> kmp;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != t[j])
			j = next[j - 1];
		if (s[i] == t[j])
			j++;
		if (j == m)
		{
			int r = i + 1;
			int l = r - m + 1;
			kmp.emplace_back(l, r);
			j = next[j - 1];
		}
	}
	sort(kmp.begin(), kmp.end(), [](pair<int, int> a, pair<int, int> b)
		 { return a.second < b.second; });
	int ans = 0, r = 0;
	for (auto [l, rr] : kmp)
	{
		if (l > r)
		{
			ans++;
			r = rr;
		}
	}
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
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
	vector<int> a(n + 1);
	unordered_map<int, int> mp;
	mp.reserve(2 * n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<int> grid;
	for (auto &[_, v] : mp)
	{
		grid.push_back(_);
	}
	sort(grid.begin(), grid.end());
	ll cnt = 0;

	int m = grid.size();
	for (int i = 0; i < m;)
	{
		int j = i;
		while (j + 1 < m && grid[j + 1] == grid[j] + 1)
			j++;
		int len = j - i + 1;
		if (len >= 2)
		{
			cnt += 1;
		}
		else
		{
			cnt += mp[grid[i]];
		}
		i = j + 1;
	}
	if (cnt > 0)
		cnt--;
	cout << cnt << endl;
	//cout << flush;
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
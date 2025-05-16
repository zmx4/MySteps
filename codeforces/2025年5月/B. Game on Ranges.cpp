#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1005;
bool st[N], used[N];
vector<pair<int, int>> a;
vector<int> ans;

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		st[i] = false;
		used[i] = false;
	}
	a.resize(n + 1);
	ans.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin() + 1, a.end(), [](pair<int, int> a, pair<int, int> b)
		 { return a.second - a.first < b.second - b.first; });
	for (int i = 1; i <= n; i++)
	{
		if (a[i].first == a[i].second)
		{
			ans[i] = a[i].first;
			st[a[i].first] = true;
		}
		else
		{
			for (int j = a[i].first; j <= a[i].second; j++)
			{
				if (!st[j])
				{
					st[j] = true;
					ans[i] = j;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i].first << " " << a[i].second << " " << ans[i] << endl;
	}
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
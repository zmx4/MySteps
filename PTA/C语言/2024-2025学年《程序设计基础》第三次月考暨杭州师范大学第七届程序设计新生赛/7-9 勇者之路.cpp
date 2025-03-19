#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	vector<int> b(n + 1, 0);
	vector<int> c(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n / 2; ++i)
	{
		b[i] = b[i - 1] + a[i];
	}
	int minL = min_element(b.begin(), b.end()) - b.begin();
	vector<int> suffix(n + 2, 0);
	for (int i = n; i > n / 2; --i)
	{
		suffix[i] = suffix[i + 1] + a[i];
	}
	long long total = accumulate(a.begin() + 1, a.end(), 0LL);
	long long maxBlood = total;
	for (int p = 0; p <= n / 2; ++p)
	{
		for (int q = n / 2 + 1; q <= n; ++q)
		{
			long long current = total - 2 * (b[p] + suffix[q]);
			maxBlood = max(maxBlood, current);
		}
	}
	cout << maxBlood << endl;
}
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> cnt(x, 0);
	for (auto num : a)
	{
		if (num < x)
			cnt[num]++;
	}

	int missing = 0;
	for (int i = 0; i < x; i++)
	{
		if (cnt[i] == 0)
			missing++;
	}

	int xcnt = 0;
	for (auto num : a)
	{
		if (num == x)
			xcnt++;
	}

	int operations = max(missing, xcnt);

	cout << operations;

	return 0;
}
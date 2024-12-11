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
	if (n <= 1)
	{
		cout << 0 << endl;
		return 0;
	}
	unordered_map<int, int> mp;
	int x;
	cin >> x;
	int minVal = x;
	int maxVal = x;
	mp[x]++;
	int cnt = 0;
	for (int i = 1; i < n; ++i)
	{
		cin >> x;
		if (x < minVal || x > maxVal)
		{
			cnt++;
		}
		mp[x]++;
		if (x < minVal)
			minVal = x;
		if (x > maxVal)
			maxVal = x;
	}
	cout << cnt << endl;
	return 0;
}
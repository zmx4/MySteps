#include <bits/stdc++.h>
using namespace std;
int a[2051];
unordered_map<int, int> frequencyMap;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	while (n--)
	{
		int temp;
		cin >> temp;
		++frequencyMap[temp];
	}

	int maxCount = 0;
	int mode = numeric_limits<int>::min();

	for (const auto &pair : frequencyMap)
	{
		if (pair.second > maxCount)
		{
			maxCount = pair.second;
			mode = pair.first;
		}
	}
	cout << mode << " " << maxCount;
	return 0;
}
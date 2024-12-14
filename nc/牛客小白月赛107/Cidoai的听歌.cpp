#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);

	int maxNum = INT_MIN, minNum = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxNum = max(maxNum, a[i]);
		minNum = min(minNum, a[i]);
	}

	int steps = maxNum - minNum;
	int finalNum = (maxNum + minNum) / 2;
	if ((maxNum + minNum) % 2 != 0)
		finalNum++;

	cout << steps << " " << finalNum << endl;
	return 0;
}
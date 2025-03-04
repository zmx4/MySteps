#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	m %= n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	list<int> l(nums.begin(), nums.end());
	for (int i = 0; i < m; i++)
	{
		auto it = l.begin();
		l.splice(l.end(), l, it);
	}

	auto it = l.begin();
	for (int i = 0; i < n; i++)
	{
		cout << *it++;
		if (i < n - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}
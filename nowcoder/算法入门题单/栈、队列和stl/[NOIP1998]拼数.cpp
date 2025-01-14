#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool cmp(const string &a, const string &b)
{
	return a + b > b + a;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<string> nums(n);

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), cmp);

	string ans;
	for (const string &num : nums)
	{
		ans += num;
	}

	cout << ans;
	return 0;
}
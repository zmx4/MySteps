#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> nums(n+1);
	for (int i = 1; i <= n; i++)
		cin >> nums[i];
	int maxpos = 0, maxnum = 0;
	int minpos = 0, minnum = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		if (nums[i] > maxnum)
		{
			maxnum = nums[i];
			maxpos = i;
		}
		if (nums[i] < minnum)
		{
			minnum = nums[i];
			minpos = i;
		}
	}
	int left = min(minpos, maxpos), right = max(minpos, maxpos);
	if(abs(left-1)>abs(n-right))
		left = 1;
	else
		right = n;
	cout << right - left;
	return 0;
}
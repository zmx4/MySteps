#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int n, h;
	cin >> n >> h;
	vector<int> balloons(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> balloons[i];
	}

	int max_popped = 0;
	int best_position = INT_MIN;

	// 检查每个可能的最优位置
	set<int> position_set;
	for (int i = 0; i < n; ++i)
	{
		position_set.insert(balloons[i] - h);
	}

	for (int pos : position_set)
	{
		// 使用二分查找确定范围内的气球数量
		auto left = lower_bound(balloons.begin(), balloons.end(), pos);
		auto right = upper_bound(balloons.begin(), balloons.end(), pos + h);

		int count = right - left;

		// 更新最优解
		if (count > max_popped || (count == max_popped && pos < best_position))
		{
			max_popped = count;
			best_position = pos;
		}
	}

	cout << best_position << " " << max_popped << endl;
	return 0;
}
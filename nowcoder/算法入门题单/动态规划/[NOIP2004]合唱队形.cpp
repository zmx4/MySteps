#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	// dp1[i] 表示以 a[i] 结尾的最长严格递增子序列长度
	// dp2[i] 表示从 a[i] 开始的最长严格递减子序列长度
	vector<int> dp1(n, 1), dp2(n, 1);

	// 求最长递增序列
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}

	// 求最长递减序列（从右向左计算）
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	// 求最长的“合唱队形”：对于每个 i，以 a[i] 为峰值，队形长度为 dp1[i] + dp2[i] - 1
	int maxBitonic = 0;
	for (int i = 0; i < n; i++)
	{
		maxBitonic = max(maxBitonic, dp1[i] + dp2[i] - 1);
	}

	// 最少出列的同学数 = n - (最长合唱队形的长度)
	cout << n - maxBitonic << "\n";

	return 0;
}
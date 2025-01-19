#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

// 使用分治法解决问题
class Solution
{
private:
	// 合并两个有序区间并统计频率
	vector<pair<long long, int>> merge(const vector<pair<long long, int>> &left,
									   const vector<pair<long long, int>> &right)
	{
		vector<pair<long long, int>> result;
		int i = 0, j = 0;

		while (i < left.size() && j < right.size())
		{
			if (left[i].first < right[j].first)
			{
				result.push_back(left[i++]);
			}
			else if (left[i].first > right[j].first)
			{
				result.push_back(right[j++]);
			}
			else
			{
				// 如果和相同，合并频率
				result.push_back({left[i].first, left[i].second + right[j].second});
				i++;
				j++;
			}
		}

		// 处理剩余元素
		while (i < left.size())
			result.push_back(left[i++]);
		while (j < right.size())
			result.push_back(right[j++]);

		return result;
	}

	// 分治处理子数组
	vector<pair<long long, int>> solve(const vector<int> &arr, int start, int end)
	{
		if (start == end)
		{
			// 基础情况：单个元素
			return {{arr[start], 1}};
		}

		int mid = (start + end) / 2;
		// 递归处理左右两半
		auto left = solve(arr, start, mid);
		auto right = solve(arr, mid + 1, end);

		// 处理跨越中点的子区间
		vector<pair<long long, int>> cross;
		long long sum = 0;
		map<long long, int> freq;

		// 计算从中点开始向右的所有前缀和
		for (int i = mid + 1; i <= end; i++)
		{
			sum += arr[i];
			freq[sum]++;
		}

		// 计算从中点开始向左的所有前缀和，并与右侧组合
		sum = 0;
		for (int i = mid; i >= start; i--)
		{
			sum += arr[i];
			for (const auto &[rsum, count] : freq)
			{
				cross.push_back({sum + rsum, 1});
			}
		}

		// 合并左半部分、右半部分和跨越部分的结果
		auto merged = merge(merge(left, right), cross);
		return merged;
	}

public:
	int countUniqueRanges(vector<int> &arr)
	{
		if (arr.empty())
			return 0;

		// 获取所有区间及其频率
		auto ranges = solve(arr, 0, arr.size() - 1);

		// 统计只出现一次的区间
		int count = 0;
		for (const auto &[sum, freq] : ranges)
		{
			if (freq == 1)
				count++;
		}

		return count;
	}
};
int main()
{
	Solution solution;

	// 测试用例
	vector<int> arr = {1, 2, 1, 3, 2, 1,4,4,5,2,6,8,4,5,2,3,0,5,4,8,6,9,5,2,4};
	int result = solution.countUniqueRanges(arr);
	cout  << result << endl;

	return 0;
}
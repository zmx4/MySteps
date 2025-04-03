#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int closest = INT_MAX;
		int minDiff = INT_MAX; 
		for (int i = 0; i < n - 2; i++)
		{
			int left = i + 1, right = n - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				int diff = abs(sum - target);
				if (diff < minDiff)
				{
					minDiff = diff;
					closest = sum;
				}
				if (sum < target)
					left++;
				else if (sum > target)
					right--;
				else
					return sum;
			}
		}
		return closest;
	}
};
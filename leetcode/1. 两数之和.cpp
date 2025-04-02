#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++)
		{
			int oth = target - nums[i];
			if (mp.find(oth) != mp.end())
			{
				return {mp[oth], i};
			}
			mp[nums[i]] = i;
		}
		return {};
	}
};
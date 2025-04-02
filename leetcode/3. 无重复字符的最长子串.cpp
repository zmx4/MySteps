#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> mp;
		int left = 0, right = 0, maxLength = 0;
		int len = s.size();
		for(int i = 0; i < len; i++)
		{
			if (mp.find(s[i]) != mp.end())
			{
				left = max(left, mp[s[i]] + 1);
			}
			mp[s[i]] = i;
			maxLength = max(maxLength, i - left + 1);
		}
		return maxLength;
	}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int expandAroundCenter(const string &s, int left, int right)
	{
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--;
			right++;
		}
		return right - left - 1;
	}
	string longestPalindrome(string s)
	{
		int len = s.size();
		int start = 0, maxLength = 1;
		for(int i = 0; i < len; i++)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int maxLen = max(len1, len2);
			if (maxLen > maxLength)
			{
				maxLength = maxLen;
				start = i - (maxLength - 1) / 2;
			}
		}
		return s.substr(start, maxLength);
	}
};
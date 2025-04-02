#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	map<int,string> mp;
	
	Solution()
	{
		mp[2] = "abc";
		mp[3] = "def";
		mp[4] = "ghi";
		mp[5] = "jkl";
		mp[6] = "mno";
		mp[7] = "pqrs";
		mp[8] = "tuv";
		mp[9] = "wxyz";
	}
	// BFS
	vector<string> letterCombinations(string digits)
	{
		queue<string> q;
		vector<string> ans;
		if (digits.empty())
		{
			return ans;
		}
		q.push("");
		while (!q.empty())
		{
			string s = q.front();
			q.pop();
			if (s.size() == digits.size())
			{
				ans.push_back(s);
				continue;
			}
			int digit = digits[s.size()] - '0';
			for (char c : mp[digit])
			{
				q.push(s + c);
			}
		}
		return ans;
	}
};
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<string> letterCasePermutation(string s)
	{
		vector<string> ans;
		queue<string> q;
		q.push("");
		int n = s.size();
		while (!q.empty())
		{
			string tmp = q.front();
			q.pop();
			if (tmp.size() == n)
			{
				ans.push_back(tmp);
			}
			else
			{
				int idx = tmp.size();
				if (isdigit(s[idx]))
				{
					q.push(tmp + s[idx]);
				}
				else
				{
					q.push(tmp + (char)tolower(s[idx]));
					q.push(tmp + (char)toupper(s[idx]));
				}
			}
		}
		return ans;
	}
};
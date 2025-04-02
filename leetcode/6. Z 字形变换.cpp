#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	string convert(string s, int numRows)
	{
		string ans = "";
		size_t len = s.size();
		if (numRows == 1 || numRows >= len)
			return s;
		int cycle = 2 * numRows - 2; // 每个周期的长度
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j + i < len; j += cycle)
			{
				ans += s[j + i]; // 竖着的字符
				if (i != 0 && i != numRows - 1 && j + cycle - i < len) // 斜着的字符
					ans += s[j + cycle - i];
			}
		}
		return ans;
	}
};
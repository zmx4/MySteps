#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 给定一个后缀表达式，返回它的结果
	 * @param str string字符串
	 * @return long长整型
	 */
	long long legalExp(string str)
	{
		// write code here
		stack<long long> stk;
		string num;
		for (size_t i = 0; i < str.length(); i++)
		{
			if(str[i]<='9'&&str[i]>='0')
				num += str[i];
			else if(str[i]=='#')
			{
				stk.push(stoll(num));
				num = "";
			}
			else
			{
				long long b = stk.top();
				stk.pop();
				long long a = stk.top();
				stk.pop();
				
				if(str[i]=='+')
					stk.push(a + b);
				else if(str[i] == '-')
					stk.push(a - b);
				else if (str[i] == '*')
					stk.push(a * b);
			}
		}
		return stk.top();
	}
};
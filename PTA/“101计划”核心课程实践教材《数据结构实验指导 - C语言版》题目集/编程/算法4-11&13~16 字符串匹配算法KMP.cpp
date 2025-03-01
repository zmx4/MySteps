#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s1, s2;
	getline(cin, s1);				  // 读入主串
	getline(cin, s2);				  // 读入模式串
	int n = s2.size(), m = s1.size(); // n是模式串长度，m是主串长度
	s1 = ' ' + s1, s2 = ' ' + s2;	  // 转为1-indexed

	vector<int> ne(n + 1); // next数组
	// 构建模式串的next数组
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && s2[i] != s2[j + 1])
			j = ne[j];
		if (s2[i] == s2[j + 1])
			j++;
		ne[i] = j;
	}

	int pos = 0;
	bool found = false;
	// KMP匹配过程
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && s1[i] != s2[j + 1])
			j = ne[j];
		if (s1[i] == s2[j + 1])
			j++;
		if (j == n) // 找到匹配
		{
			pos = i - n + 1;
			found = true;
			break;
		}
	}

	if (found)
		cout << s1.substr(pos) << endl; // 输出主串中从匹配位置开始的子串
	else
		cout << "匹配失败。" << endl;

	return 0;
}
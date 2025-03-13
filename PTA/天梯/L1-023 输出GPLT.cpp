#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	map<char, int> mp;
	int cnt = 0;
	for (int i = 0; i < s.size();i++)
	{
		s[i] = toupper(s[i]);
		if (s[i] == 'G' || s[i] == 'P' || s[i] == 'L' || s[i] == 'T' )
		{
			cnt++;
			mp[s[i]]++;
		}
	}
	string a = "GPLT";
	string res;
	while (true)
	{
		bool printed = false;
		for (char ch : a)
		{
			if (mp[ch] > 0)
			{
				res.push_back(ch);
				mp[ch]--;
				printed = true;
			}
		}
		if (!printed)
			break; // 四个字符均已用完则退出
	}
	cout << res;
	return 0;
}
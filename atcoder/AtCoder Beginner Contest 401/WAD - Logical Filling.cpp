#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	string s;
	cin >> n >> k >> s;
	s = " " + s + " ";
	int len = s.size() - 2;
	for (int i = 1; i <= len; i++)
	{
		if (s[i] == 'o')
			k--;
	}

	for (int i = 1; i <= len; i++)
	{
		if (s[i - 1] == 'o' || s[i + 1] == 'o')
			s[i] = '.';
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= len; i++)
	{
		if (s[i] == '?')
			cnt1++;
		else if (cnt1 > 0)
		{
			if (cnt1 % 2 == 1)
				cnt2 += cnt1 / 2 + 1;
			else
				cnt2 += cnt1 / 2;
			cnt1 = 0;
		}
	}
	if (cnt1 > 0)
	{
		if (cnt1 % 2 == 1)
			cnt2 += cnt1 / 2 + 1;
		else
			cnt2 += cnt1 / 2;
		cnt1 = 0;
	}
	if (cnt2 > k)
	{
		cout << s.substr(1, len) << endl;
		return 0;
	}
	else
	{
		int index = -1;
		cnt1 = 0;
		for (int i = 1; i <= len; i++)
		{
			if (s[i] == '?')
			{
				cnt1++;
				if (cnt1 == 1)
					index = i;
			}
			else if (cnt1 > 0)
			{
				if (cnt1 % 2 == 1)
				{
					bool flag = true;
					for (int j = index; j < i; j++)
					{
						if (flag)
							s[j] = 'o';
						else
							s[j] = '.';
						flag = !flag;
					}
				}
				cnt1 = 0;
				index = -1;
			}
		}
		if (cnt1 > 0)
		{
			if (cnt1 % 2 == 1)
			{
				bool flag = true;
				for (int j = index; j <= len; j++)
				{
					if (flag)
						s[j] = 'o';
					else
						s[j] = '.';
					flag = !flag;
				}
			}
		}
	}
	cout << s.substr(1, len) << endl;
	return 0;
}
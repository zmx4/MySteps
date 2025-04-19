#include <bits/stdc++.h>
using namespace std;

int countVK(const string &s)
{
	int cnt = 0;
	for (int i = 0; i + 1 < s.size(); ++i)
		if (s[i] == 'V' && s[i + 1] == 'K')
			cnt++;
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ans = countVK(str);
	for (int i = 0; i < n; ++i)
	{
		char orig = str[i];
		for (char c : {'V', 'K'})
		{
			if (orig == c)
				continue;
			str[i] = c;
			ans = max(ans, countVK(str));
		}
		str[i] = orig;
	}
	cout << ans << endl;
	return 0;
}
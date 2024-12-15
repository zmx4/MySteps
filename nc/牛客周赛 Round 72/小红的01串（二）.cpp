#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	long long cnt = 0;
	int len = 1;
	/*
	101010101010101110101010101010101010
	*/
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != s[i - 1])
		{
			len++;
			cnt += (long long)(len - 1);
		}
		else
		{
			len = 1;
		}
	}

	cout << cnt << endl;
	return 0;
}
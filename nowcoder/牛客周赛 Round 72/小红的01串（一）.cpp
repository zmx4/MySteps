#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	int count = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != s[i - 1])
			count++;
	}
	cout << count << endl;
	return 0;
}
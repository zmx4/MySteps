#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	getline(cin, s);
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == '6')
		{
			int j = i;
			while (j < s.size() && s[j] == '6')
			{
				j++;
			}
			int cnt = j - i;
			if (cnt > 3)
			{
				if (cnt > 9)
					cout << "27";
				else
					cout << "9";
			}
			else
			{
				cout << s.substr(i, cnt);
			}
			i = j;
		}
		else
		{
			cout << s[i];
			i++;
		}
	}

	return 0;
}
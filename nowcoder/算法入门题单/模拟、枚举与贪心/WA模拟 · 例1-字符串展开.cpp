#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int p1, p2, p3;
	string s;
	cin >> p1 >> p2 >> p3 >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-' && i != 0 && i != s.size() - 1)
		{
			if (s[i - 1] >= s[i + 1] || (s[i - 1] >= '0' && s[i + 1] <= '9' && s[i - 1] + p1 >= s[i + 1]))
			{
				cout << "-";
				continue;
			}
			if (s[i - 1] + 1 == s[i + 1])
				continue;
			if (p3 == 1)
			{
				if (s[i - 1] + 1 < s[i + 1])
				{
					for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
					{
						for (int k = 0; k < p2; k++)
						{
							if (p1 == 1)
								cout << (char)j;
							else if (p1 == 2)
								cout << (char)(j - 'a' + 'A');
							else if (p1 == 3)
								cout << "*";
						}
					}
				}
			}
			else if (p3 == 2)
			{
				if (s[i - 1] + 1 < s[i + 1])
				{
					for (int j = s[i + 1] - 1; j > s[i - 1]; j--)
					{
						for (int k = 0; k < p2; k++)
						{
							if (p1 == 1)
								cout << (char)j;
							else if (p1 == 2)
								cout << (char)(j - 'a' + 'A');
							else if (p1 == 3)
								cout << "*";
						}
					}
				}
			}
		}
		else
		{
			cout << s[i];
		}
	}

	return 0;
}
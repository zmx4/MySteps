#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	bool canberemoved = true;
	while (canberemoved)
	{
		canberemoved = false;
		for (char c = 'z'; c >= 'a'; c--)
		{
			for (int i = 0; i < s.size();)
			{
				if (s[i] == c)
				{
					bool delete_now = false;
					if (i > 0 && s[i - 1] == s[i] - 1)
						delete_now = true;
					if (i + 1 < s.size() && s[i + 1] == s[i] - 1)
						delete_now = true;
					if (delete_now)
					{
						s.erase(s.begin() + i);
						ans++;
						canberemoved = true;
					}
					else
					{
						i++;
					}
				}
				else
				{
					i++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
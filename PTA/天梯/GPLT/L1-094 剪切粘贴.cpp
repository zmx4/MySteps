#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	getline(cin, s);
	int n;
	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;
		string clipboard = s.substr(a - 1, b - a + 1);
		s.erase(a - 1, b - a + 1);
		string be, af;
		cin >> be >> af;
		bool found = false;
		for (size_t pos = 0; pos <= s.size(); pos++)
		{
			bool before = pos >= be.size() && s.substr(pos - be.size(), be.size()) == be;
			bool after = pos + af.size() <= s.size() && s.substr(pos, af.size()) == af;
			if (before && after)
			{
				s.insert(pos, clipboard);
				found = true;
				break;
			}
		}

		if (!found)
		{
			s.append(clipboard);
		}
	}

	cout << s << endl;
	return 0;
}
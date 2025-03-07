#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	string str;
	cin >> str;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			string s;
			cin >> s;
			str += s;
			cout << str << endl;
		}
		else if (op == 2)
		{
			int a, b;
			cin >> a >> b;
			if (a < 0 || a >= (int)str.size())
			{
				str = "";
			}
			else
			{
				str = str.substr(a, b);
			}
			cout << str << endl;
		}
		else if (op == 3)
		{
			int a;
			string s;
			cin >> a >> s;
			if (a < 0 || a > (int)str.size())
				a = str.size();
			str.insert(a, s);
			cout << str << endl;
		}
		else if (op == 4)
		{
			string s;
			cin >> s;
			size_t pos = str.find(s);
			if (pos == string::npos)
				cout << -1 << endl;
			else
				cout << pos << endl;
		}
	}

	return 0;
}
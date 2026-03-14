#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cin.ignore();
	bool flag = false;
	while (a--)
	{
		string c;
		c.clear();
		getline(cin, c);
		auto position1 = c.find("qiandao");
		auto position2 = c.find("easy");
		if (position1 == string::npos && position2 == string::npos)
		{
			if (b > 0)
			{
				b--;
			}
			else
			{
				cout << c << endl;
				flag = true;
			}
		}
	}
	if (!flag)
		cout << "Wo AK le" << endl;
	return 0;
}
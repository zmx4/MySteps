#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int a, b;
	cin >> a >> b;
	if (b != 0)
		cout << "-" << endl;
	else
	{
		if (a == 0)
			cout << "biii" << endl;
		else if (a == 1)
			cout << "dudu" << endl;
		else
			cout << "-" << endl;
	}
	if (a == 0 || a == 2)
		cout << "stop" << endl;
	else
		cout << "move" << endl;
}
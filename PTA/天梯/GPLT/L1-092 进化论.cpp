#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b == c)
			cout << "Tu Dou" << endl;
		else if (a * b == c)
			cout << "Lv Yan" << endl;
		else
			cout << "zhe du shi sha ya!" << endl;
	}
}
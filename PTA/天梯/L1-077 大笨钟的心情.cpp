#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[25];
	for (int i = 0; i < 24; i++)
	{
		cin >> a[i];
	}
	int h = 0;
	while (1)
	{
		cin >> h;
		if (h < 0 || h > 23)
			break;
		if (a[h] > 50)
			cout << a[h] << " Yes" << endl;
		else
			cout << a[h] << " No" << endl;
	}
}
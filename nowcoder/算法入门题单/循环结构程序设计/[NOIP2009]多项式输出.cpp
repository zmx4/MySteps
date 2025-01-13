#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	int n;
	cin >> n;
	int a;
	int p = n;
	for (int i = n; i >= 0; i--)
	{
		cin >> a;
		if (a == 0)
		{
			p--;
		}
		if (p == -1)
		{
			cout << 0;
		}
		if (a != 0 && p == i)
		{
			if (a > 0 && a != 1)
			{
				if (i == n && n != 1)
				{
					cout << a << "x^" << i;
				}
				else if (i == 0)
				{
					cout << a;
				}
				else if (i == 1)
				{
					cout << a << 'x';
				}
				else
					cout << a << "x^" << i;
			}
			if (a == 1)
			{
				if (i == n && n != 1)
				{
					cout << "x^" << i;
				}
				else if (i == 0)
				{
					cout << a;
				}
				else if (i == 1)
				{
					cout << 'x';
				}
				else
					cout << "x^" << i;
			}
			if (a < 0 && a != -1)
			{
				if (i == n && n != 1)
				{
					cout << a << "x^" << i;
				}
				else if (i == 0)
				{
					cout << a;
				}
				else if (i == 1)
				{
					cout << a << 'x';
				}
				else
					cout << a << "x^" << i;
			}
			if (a == -1)
			{
				if (i == n && n != 1)
				{
					cout << "-x^" << i;
				}
				else if (i == 0)
				{
					cout << a;
				}
				else if (i == 1)
				{
					cout << "-x";
				}
				else
					cout << "-x^" << i;
			}
			continue;
		}
		if (a > 0 && a != 1)
		{
			if (i == n)
			{
				cout << a << "x^" << i;
			}
			else if (i == 0)
			{
				cout << '+' << a;
			}
			else if (i == 1)
			{
				cout << '+' << a << 'x';
			}
			else
				cout << '+' << a << "x^" << i;
		}
		if (a == 1)
		{
			if (i == n)
			{
				cout << "x^" << i;
			}
			else if (i == 0)
			{
				cout << '+' << a;
			}
			else if (i == 1)
			{
				cout << '+' << 'x';
			}
			else
				cout << '+' << "x^" << i;
		}
		if (a < 0 && a != -1)
		{
			if (i == n)
			{
				cout << a << "x^" << i;
			}
			else if (i == 0)
			{
				cout << a;
			}
			else if (i == 1)
			{
				cout << a << 'x';
			}
			else
				cout << a << "x^" << i;
		}
		if (a == -1)
		{
			if (i == n)
			{
				cout << "-x^" << i;
			}
			else if (i == 0)
			{
				cout << a;
			}
			else if (i == 1)
			{
				cout << "-x";
			}
			else
				cout << "-x^" << i;
		}
	}

	return 0;
}
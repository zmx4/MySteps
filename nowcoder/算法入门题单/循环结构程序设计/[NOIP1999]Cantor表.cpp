#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int N;
	cin >> N;
	int x = 1, y = 1;
	for (int i = 1; i < N; i++)
	{
		if (x == 1)
		{
			if ((x + y) % 2 == 0)
			{
				y++;
				while (x != 1)
				{
					cout << x << "/" << y << endl;
					x--;
					y++;
				}
			}
			else
			{
				x++;
				while (y != 1)
				{
					cout << x << "/" << y << endl;
					x++;
					y--;
				}
			}
		}
		else if (y == 1)
		{
			if ((x + y) % 2 == 0)
			{
				x++;
				while (y != 1)
				{
					cout << x << "/" << y << endl;
					x++;
					y--;
				}
			}
			else
			{
				y++;
				while (x != 1)
				{
					cout << x << "/" << y << endl;
					x--;
					y++;
				}
			}
		}
	}
	cout << x << "/" << y << endl;

	return 0;
}
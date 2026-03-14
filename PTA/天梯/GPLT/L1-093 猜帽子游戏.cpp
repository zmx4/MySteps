#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n;
	cin >> n;
	int a[n] = {0};

	// 读取数组 a 的值
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int t;
	cin >> t;

	while (t--)
	{
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			if (input == a[i])
			{
				p++;
			}
			else if (input != a[i] && input != 0)
			{
				p -= 100;
			}
		}

		if (p >= 1)
		{
			cout << "Da Jiang!!!" << endl;
		}
		else
		{
			cout << "Ai Ya" << endl;
		}
	}

	return 0;
}